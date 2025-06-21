// depth_recorder_component.cpp
// -----------------------------------------------------------------------------
// A minimal, self‑contained ROS 2 (Jazzy) component that records ZED depth images
// to an MP4/AVI file **and** logs exact ROS time stamps to a CSV file.
//
// Design notes (see discussion thread):
//   • The writer thread queues **ConstSharedPtr** messages, guaranteeing the
//     underlying pixel buffer lives long enough.
//   • A simple std::queue protected by a mutex/condition‑variable replaces the
//     lock‑free queue; this avoids UB with cv::Mat and keeps the code compact.
//   • The first frame arriving at the writer determines the video resolution;
//     the VideoWriter is opened lazily at that point.
//   • If the queue is full (4 s @ 60 Hz) the oldest frame is dropped to stay
//     real‑time.
// -----------------------------------------------------------------------------

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_components/register_node_macro.hpp>

#include <sensor_msgs/msg/image.hpp>
#include <std_srvs/srv/set_bool.hpp>
#include <builtin_interfaces/msg/time.hpp>

#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/opencv.hpp>

#include <filesystem>
#include <fstream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <thread>
#include <string>

namespace fs = std::filesystem;
using sensor_msgs::msg::Image;
using std_srvs::srv::SetBool;

namespace zed_recorder_cpp
{
// ─────────────────────────────────────────────────────────────────────────────
// Constants
static constexpr float  kDepthRangeMeters = 5.0f;   // 0 – 5 m  → 0 – 255
static constexpr size_t kQueueSize        = 240;    // 4 s @ 60 fps

// ─────────────────────────────────────────────────────────────────────────────
class DepthRecorder : public rclcpp::Node
{
public:
  explicit DepthRecorder(const rclcpp::NodeOptions & options);
  ~DepthRecorder() override;

private:
  // callbacks ---------------------------------------------------------------
  void depthCallback(const Image::SharedPtr msg);
  void srvCallback(const std::shared_ptr<SetBool::Request>,
                   std::shared_ptr<SetBool::Response>);

  // helpers -----------------------------------------------------------------
  void startRecording();
  void openVideoWriter(int width, int height);
  void writerLoop(std::stop_token token);

  // parameters --------------------------------------------------------------
  std::string topic_;
  bool        compressed_ {true};
  double      target_fps_ {60.0};

  // rclcpp entities ---------------------------------------------------------
  rclcpp::Subscription<Image>::SharedPtr sub_depth_;
  rclcpp::Service<SetBool>::SharedPtr    srv_rec_;

  // recording state ---------------------------------------------------------
  std::atomic<bool> recording_      {false};
  std::atomic<bool> running_        {true};
  std::atomic<bool> stop_requested_ {false};
  bool              first_frame_    {true};

  // data queue & sync -------------------------------------------------------
  std::queue<Image::ConstSharedPtr> frame_queue_;
  std::mutex                        mut_;
  std::condition_variable_any       cv_;

  // writer thread -----------------------------------------------------------
  std::jthread         writer_thread_;
  cv::VideoWriter      video_writer_;
  std::ofstream        csv_file_;
  fs::path             output_base_;
};

// ─────────────────────────────────────────────────────────────────────────────
DepthRecorder::DepthRecorder(const rclcpp::NodeOptions & options)
: Node("zed_depth_recorder", options)
{
  // parameters -------------------------------------------------------------
  topic_      = declare_parameter("topic",       "/zed_multi/myzed2i/depth/depth_registered");
  compressed_ = declare_parameter("compressed",  true);
  target_fps_ = declare_parameter("target_fps",  60.0);

  RCLCPP_INFO(get_logger(), "Starting ZED depth recorder component …");
  RCLCPP_INFO(get_logger(), " Subscribing to:  %s", topic_.c_str());

  // QoS --------------------------------------------------------------------
  auto qos = rclcpp::SensorDataQoS().keep_last(5).best_effort();

  sub_depth_ = create_subscription<Image>(
      topic_, qos,
      std::bind(&DepthRecorder::depthCallback, this, std::placeholders::_1));

  srv_rec_ = create_service<SetBool>(
      "record_zed_depth",
      std::bind(&DepthRecorder::srvCallback, this,
                std::placeholders::_1, std::placeholders::_2));

  // launch writer thread ---------------------------------------------------
  writer_thread_ = std::jthread(&DepthRecorder::writerLoop, this);
}

// ─────────────────────────────────────────────────────────────────────────────
DepthRecorder::~DepthRecorder()
{
  running_.store(false);
  cv_.notify_all();                    // wake writer so it can exit
}

// ─────────────────────────────────────────────────────────────────────────────
void DepthRecorder::depthCallback(const Image::SharedPtr msg)
{
  if (!recording_.load(std::memory_order_relaxed)) return;

  {
    std::lock_guard<std::mutex> lk(mut_);
    if (frame_queue_.size() == kQueueSize) frame_queue_.pop();   // drop oldest
    frame_queue_.push(msg);                                      // enqueue message
  }
  cv_.notify_one();
}

// ─────────────────────────────────────────────────────────────────────────────
void DepthRecorder::srvCallback(const std::shared_ptr<SetBool::Request> req,
                                std::shared_ptr<SetBool::Response>      resp)
{
  const bool want_start = req->data;
  if (want_start == recording_.load()) {
    resp->success = false;
    resp->message = "no change";
    return;
  }

  if (want_start)
    startRecording();          // synchronous
  else
    stop_requested_.store(true, std::memory_order_relaxed); // async flush/stop

  recording_.store(want_start);
  resp->success = true;
  resp->message = want_start ? "recording started" : "recording stopping";
}

// ─────────────────────────────────────────────────────────────────────────────
void DepthRecorder::startRecording()
{
  const uint64_t sec = get_clock()->now().seconds();
  fs::path base = fs::current_path() / "recordings" / ("recording_" + std::to_string(sec));
  fs::create_directories(base);

  csv_file_.open(base / (std::to_string(sec) + "_depth_times.csv"));
  csv_file_ << "sec,nanosec\n";

  output_base_  = base;
  first_frame_  = true;
  stop_requested_.store(false);
  RCLCPP_INFO(get_logger(), "Recording to %s", base.c_str());
}

// ─────────────────────────────────────────────────────────────────────────────
void DepthRecorder::openVideoWriter(int width, int height)
{
    const uint64_t ts = get_clock()->now().seconds();
                        // MP4-Pfad + H.264
    fs::path f = output_base_ /
                 (std::to_string(ts) + "_depth.mp4");

    int fourcc = cv::VideoWriter::fourcc('a','v','c','1');   // H.264
    video_writer_.open(f.string(),
                       fourcc, target_fps_, cv::Size(width, height), /*isColor=*/true);



if (!video_writer_.isOpened())
    RCLCPP_ERROR(get_logger(),
      "Unable to open video file! Check codec");

}

// ─────────────────────────────────────────────────────────────────────────────
void DepthRecorder::writerLoop(std::stop_token token)
{
  for (;;) {
    // wait for work ---------------------------------------------------------
    std::unique_lock<std::mutex> lk(mut_);
    cv_.wait(lk, token, [&] {
      return !frame_queue_.empty() || stop_requested_.load() || token.stop_requested();
    });

    if (token.stop_requested()) break;            // thread cancellation
    if (frame_queue_.empty())  continue;          // spurious wake‑up

    // pop exactly one message ----------------------------------------------
    auto ros_img = frame_queue_.front();
    frame_queue_.pop();
    lk.unlock();                                  // minimise critical section

    // convert to cv::Mat ----------------------------------------------------
    auto cv_ptr  = cv_bridge::toCvCopy(*ros_img, "32FC1");
    cv::Mat depth32 = cv_ptr->image;
    const auto & stamp = ros_img->header.stamp;

    // on first frame: open video writer ------------------------------------
    if (first_frame_) {
      openVideoWriter(depth32.cols, depth32.rows);
      first_frame_ = false;
    }
    if (!video_writer_.isOpened()) continue;      // give up this frame

    // Some H.264 builds need 3‑channel frames; uncomment if you still get
    // black frames:
    // cv::cvtColor(depth8, depth8, cv::COLOR_GRAY2BGR);
    cv::Mat depth8, depthBGR;
    depth32.convertTo(depth8, CV_8U, 255.f / kDepthRangeMeters);
    cv::cvtColor(depth8, depthBGR, cv::COLOR_GRAY2BGR);

    video_writer_.write(depthBGR);
    

    if (csv_file_.is_open())
      csv_file_ << stamp.sec << ',' << stamp.nanosec << '\n';

    // graceful stop ---------------------------------------------------------
    if (stop_requested_.load() && frame_queue_.empty()) {
      if (video_writer_.isOpened()) video_writer_.release();
      if (csv_file_.is_open())      csv_file_.close();
      recording_.store(false);
      RCLCPP_INFO(get_logger(), "Recording stopped.");
      stop_requested_.store(false);
    }
  }
}

// ─────────────────────────────────────────────────────────────────────────────
}  // namespace zed_recorder_cpp

RCLCPP_COMPONENTS_REGISTER_NODE(zed_recorder_cpp::DepthRecorder)
