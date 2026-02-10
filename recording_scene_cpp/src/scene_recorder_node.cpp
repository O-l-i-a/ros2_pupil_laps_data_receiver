#include <rclcpp/rclcpp.hpp>

#include <sensor_msgs/msg/image.hpp>
#include <std_srvs/srv/set_bool.hpp>

#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/opencv.hpp>

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstdint>
#include <deque>
#include <filesystem>
#include <fstream>
#include <mutex>
#include <string>
#include <thread>

namespace fs = std::filesystem;
using sensor_msgs::msg::Image;
using std_srvs::srv::SetBool;

struct FramePacket
{
  cv::Mat frame_mono;
  builtin_interfaces::msg::Time stamp;
};

class PupilSceneRecorderCpp : public rclcpp::Node
{
public:
  explicit PupilSceneRecorderCpp(const rclcpp::NodeOptions & options = rclcpp::NodeOptions())
  : Node("pupil_scene_recorder_cpp", rclcpp::NodeOptions(options).use_intra_process_comms(true))
  {
    topic_ = declare_parameter<std::string>("topic", "/pupil/scene/image_raw");
    participant_name_ = declare_parameter<std::string>("participant_name", "default");
    target_fps_ = declare_parameter<double>("target_fps", 30.0);
    compressed_ = declare_parameter<bool>("compressed", false);
    max_queue_size_ = declare_parameter<int>("max_queue_size", 300);

    auto qos = rclcpp::SensorDataQoS().keep_last(5).best_effort();
    sub_scene_ = create_subscription<Image>(
      topic_, qos, std::bind(&PupilSceneRecorderCpp::sceneCallback, this, std::placeholders::_1));

    srv_record_ = create_service<SetBool>(
      "record_pupil_scene",
      std::bind(
        &PupilSceneRecorderCpp::recordCallback,
        this,
        std::placeholders::_1,
        std::placeholders::_2));

    writer_thread_ = std::thread(&PupilSceneRecorderCpp::writerLoop, this);

    RCLCPP_INFO(get_logger(), "C++ scene recorder subscribed to %s", topic_.c_str());
    RCLCPP_INFO(get_logger(), "Participant name: %s", participant_name_.c_str());
  }

  ~PupilSceneRecorderCpp() override
  {
    stopRecordingInternal();
    running_.store(false);
    queue_cv_.notify_all();
    if (writer_thread_.joinable()) {
      writer_thread_.join();
    }
  }

private:
  void sceneCallback(const Image::ConstSharedPtr msg)
  {
    if (!recording_.load(std::memory_order_relaxed)) {
      return;
    }

    if (first_frame_.load(std::memory_order_relaxed)) {
      openWriter(static_cast<int>(msg->width), static_cast<int>(msg->height));
      first_frame_.store(false, std::memory_order_relaxed);
      if (!video_writer_.isOpened()) {
        return;
      }
    }

    cv::Mat mono_frame;
    if (msg->encoding == "mono8") {
      cv::Mat wrapped(
        static_cast<int>(msg->height),
        static_cast<int>(msg->width),
        CV_8UC1,
        const_cast<unsigned char *>(msg->data.data()),
        msg->step);
      mono_frame = wrapped.clone();
    } else {
      try {
        auto cv_ptr = cv_bridge::toCvCopy(msg, "mono8");
        mono_frame = cv_ptr->image;
      } catch (const cv_bridge::Exception & e) {
        RCLCPP_ERROR_THROTTLE(
          get_logger(),
          *get_clock(),
          3000,
          "cv_bridge conversion failed: %s",
          e.what());
        return;
      }
    }

    FramePacket packet{std::move(mono_frame), msg->header.stamp};
    {
      std::lock_guard<std::mutex> lk(queue_mtx_);
      if (static_cast<int>(queue_.size()) >= max_queue_size_) {
        queue_.pop_front();
        ++dropped_frames_;
      }
      queue_.push_back(std::move(packet));
    }
    queue_cv_.notify_one();
  }

  void recordCallback(
    const std::shared_ptr<SetBool::Request> req,
    std::shared_ptr<SetBool::Response> resp)
  {
    if (req->data == recording_.load()) {
      resp->success = false;
      resp->message = "no change";
      return;
    }

    if (req->data) {
      startRecordingInternal();
      resp->success = true;
      resp->message = "started";
    } else {
      stopRecordingInternal();
      resp->success = true;
      resp->message = "stopped";
    }
  }

  void startRecordingInternal()
  {
    dropped_frames_ = 0;
    const uint64_t ts = static_cast<uint64_t>(get_clock()->now().seconds());
    base_dir_ = fs::current_path() / "recordings" / ("recording_" + participant_name_);
    fs::create_directories(base_dir_);

    if (compressed_) {
      video_path_ = base_dir_ / (std::to_string(ts) + "_scene.mp4");
    } else {
      video_path_ = base_dir_ / (std::to_string(ts) + "_scene.avi");
    }

    csv_.open(base_dir_ / (std::to_string(ts) + "_scene_times.csv"));
    csv_ << "sec,nanosec\n";

    {
      std::lock_guard<std::mutex> lk(queue_mtx_);
      queue_.clear();
    }

    first_frame_.store(true, std::memory_order_relaxed);
    recording_.store(true, std::memory_order_relaxed);

    RCLCPP_INFO(get_logger(), "Started C++ grayscale scene recording to %s", base_dir_.c_str());
  }

  void stopRecordingInternal()
  {
    recording_.store(false, std::memory_order_relaxed);

    while (true) {
      bool queue_empty = false;
      {
        std::lock_guard<std::mutex> lk(queue_mtx_);
        queue_empty = queue_.empty();
      }
      if (queue_empty) {
        break;
      }
      queue_cv_.notify_one();
      std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }

    {
      std::lock_guard<std::mutex> io_lk(io_mtx_);
      if (video_writer_.isOpened()) {
        video_writer_.release();
      }
      if (csv_.is_open()) {
        csv_.close();
      }
    }

    if (dropped_frames_ > 0) {
      RCLCPP_WARN(
        get_logger(),
        "Scene recorder dropped %zu frame(s) due to full queue.",
        dropped_frames_);
    }
    RCLCPP_INFO(get_logger(), "Stopped C++ grayscale scene recording.");
  }

  void openWriter(int width, int height)
  {
    const int fourcc = compressed_
      ? cv::VideoWriter::fourcc('m', 'p', '4', 'v')
      : cv::VideoWriter::fourcc('M', 'J', 'P', 'G');
    {
      std::lock_guard<std::mutex> io_lk(io_mtx_);
      video_writer_.open(
        video_path_.string(),
        fourcc,
        target_fps_,
        cv::Size(width, height),
        false);
    }

    if (!video_writer_.isOpened()) {
      RCLCPP_ERROR(get_logger(), "Failed to open video writer: %s", video_path_.c_str());
    }
  }

  void writerLoop()
  {
    while (running_.load()) {
      FramePacket packet;
      {
        std::unique_lock<std::mutex> lk(queue_mtx_);
        queue_cv_.wait(lk, [this]() { return !running_.load() || !queue_.empty(); });
        if (!running_.load() && queue_.empty()) {
          break;
        }
        packet = std::move(queue_.front());
        queue_.pop_front();
      }

      {
        std::lock_guard<std::mutex> io_lk(io_mtx_);
        if (video_writer_.isOpened()) {
          video_writer_.write(packet.frame_mono);
        }
        if (csv_.is_open()) {
          csv_ << packet.stamp.sec << ',' << packet.stamp.nanosec << '\n';
        }
      }
    }
  }

private:
  std::string topic_;
  std::string participant_name_;
  double target_fps_;
  bool compressed_;
  int max_queue_size_;

  rclcpp::Subscription<Image>::SharedPtr sub_scene_;
  rclcpp::Service<SetBool>::SharedPtr srv_record_;

  std::atomic_bool running_{true};
  std::atomic_bool recording_{false};
  std::atomic_bool first_frame_{true};

  std::mutex queue_mtx_;
  std::condition_variable queue_cv_;
  std::deque<FramePacket> queue_;
  std::thread writer_thread_;
  size_t dropped_frames_{0};
  std::mutex io_mtx_;

  cv::VideoWriter video_writer_;
  std::ofstream csv_;
  fs::path base_dir_;
  fs::path video_path_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<PupilSceneRecorderCpp>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
