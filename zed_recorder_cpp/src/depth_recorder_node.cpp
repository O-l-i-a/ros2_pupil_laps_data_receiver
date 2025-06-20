// zed_depth_recorder_node.cpp
// ROS 2 Jazzy – C++ depth recorder for ZED‑2/2i/2X cameras
// - subscribes to /zed/depth/image_raw (encoding 32FC1)
// - provides a std_srvs/SetBool service "record_zed_depth" to start/stop recording
// - writes normalised 8‑bit depth video (H264 or raw) plus CSV timestamps
//
// Build deps: rclcpp, sensor_msgs, cv_bridge, OpenCV
//   add_executable(zed_depth_recorder_node src/zed_depth_recorder_node.cpp)
//   ament_target_dependencies(zed_depth_recorder_node rclcpp sensor_msgs cv_bridge OpenCV)
//
// Author: ChatGPT (2025‑06‑20)

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <builtin_interfaces/msg/time.hpp>
#include <std_srvs/srv/set_bool.hpp>
#include <cv_bridge/cv_bridge.hpp>

#include <opencv2/opencv.hpp>

#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <filesystem>
#include <fstream>
#include <chrono>

namespace fs = std::filesystem;
using sensor_msgs::msg::Image;
using std_srvs::srv::SetBool;

class DepthRecorder : public rclcpp::Node
{
public:
  DepthRecorder() : Node("zed_depth_recorder"), running_(true)
  {
    RCLCPP_INFO(get_logger(), "Starting ZED depth recorder (C++) …");

    // QoS: keep a few frames, best effort, sensor data profile
    auto qos = rclcpp::SensorDataQoS().keep_last(5).best_effort();

    sub_depth_ = create_subscription<Image>(
      "/zed/zed_node/depth/depth_registered", qos,//"/zed/depth/image_raw", qos,
      std::bind(&DepthRecorder::depthCallback, this, std::placeholders::_1));

    srv_rec_ = create_service<SetBool>(
      "record_zed_depth",
      std::bind(&DepthRecorder::srvCallback, this, std::placeholders::_1, std::placeholders::_2));

    // launch writer thread
    writer_thread_ = std::thread(&DepthRecorder::writerLoop, this);
  }

  ~DepthRecorder() override
  {
    running_.store(false);
    cv_.notify_all();
    if (writer_thread_.joinable()) writer_thread_.join();
  }

private:
  // ---------------- subscription ----------------
  void depthCallback(const Image::SharedPtr msg)
  {
    if (!recording_) return;

    try {
      // Convert to CV Mat (32FC1)
      auto cv_ptr = cv_bridge::toCvShare(msg, "32FC1");

      // enqueue image + original ROS timestamp (sec/nanosec)
      {
        std::lock_guard<std::mutex> lk(mut_);
        frame_queue_.emplace(cv_ptr->image.clone(), msg->header.stamp);
      }
      cv_.notify_one();
    } catch (const cv_bridge::Exception &e) {
      RCLCPP_ERROR_THROTTLE(get_logger(), *get_clock(), 3000, "cv_bridge: %s", e.what());
    }
  }

  // ---------------- service ----------------
  void srvCallback(const std::shared_ptr<SetBool::Request> req,
                   std::shared_ptr<SetBool::Response>      resp)
  {
    bool want_start = req->data;
    if (want_start == recording_) {
      resp->success = false;
      resp->message = "no change";
      return;
    }

    if (want_start) {
      startRecording();
    } else {
      stopRecording();
    }

    recording_    = want_start;
    resp->success = true;
    resp->message = want_start ? "recording started" : "recording stopped";
  }

  // ---------------- recording control ----------------
  void startRecording()
  {
    // output directory: $PWD/recordings/recording_<unixsec>/
    auto now = get_clock()->now();
    uint64_t sec = now.seconds();
    fs::path base = fs::current_path() / "recordings" / ("recording_" + std::to_string(sec));
    fs::create_directories(base);

    // video file (H264, greyscale)
    fs::path video_path = base / (std::to_string(sec) + "_depth.mp4");
    video_writer_.open(video_path.string(),
                       cv::VideoWriter::fourcc('H','2','6','4'),
                       60.0,  // FPS
                       {1280, 720},  // size; adjust to actual depth size
                       false); // grayscale
    if (!video_writer_.isOpened()) {
      RCLCPP_ERROR(get_logger(), "Failed to open video file %s", video_path.c_str());
      return;
    }

    // csv timestamps
    fs::path csv_path = base / (std::to_string(sec) + "_depth_times.csv");
    csv_file_.open(csv_path);
    csv_file_ << "sec,nanosec\n";

    RCLCPP_INFO(get_logger(), "Recording to %s", base.c_str());
  }

  void stopRecording()
  {
    {
      // wait for queue flush
      std::unique_lock<std::mutex> lk(mut_);
      cv_.wait(lk, [&]{ return frame_queue_.empty(); });
    }

    if (video_writer_.isOpened()) video_writer_.release();
    if (csv_file_.is_open())      csv_file_.close();
  }

  // ---------------- writer thread ----------------
  void writerLoop()
  {
    while (running_) {
      std::unique_lock<std::mutex> lk(mut_);
      cv_.wait(lk, [&]{ return !frame_queue_.empty() || !running_; });
      if (!running_) break;

      auto [depth32, stamp] = std::move(frame_queue_.front());
      frame_queue_.pop();
      lk.unlock();

      if (!video_writer_.isOpened()) continue;  // not recording yet

      // normalise 0‑5 m → 0‑255 8‑bit
      cv::Mat depth8;
      depth32.convertTo(depth8, CV_8U, 255.0 / 5.0);

      video_writer_.write(depth8);
      if (csv_file_.is_open())
        csv_file_ << stamp.sec << ',' << stamp.nanosec << '\n';
    }
  }

  // ---------------- data ----------------
  rclcpp::Subscription<Image>::SharedPtr sub_depth_;
  rclcpp::Service<SetBool>::SharedPtr    srv_rec_;

  // queue & writer
  std::queue<std::pair<cv::Mat, builtin_interfaces::msg::Time>> frame_queue_;
  std::mutex mut_;
  std::condition_variable cv_;
  std::thread writer_thread_;
  std::atomic<bool> running_;
  std::atomic<bool> recording_{false};

  // outputs
  cv::VideoWriter video_writer_;
  std::ofstream   csv_file_;
};

// ---------------- main ----------------
int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<DepthRecorder>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
