// rgb_recorder_component.cpp
// -----------------------------------------------------------------------------
// ZED RGB recorder component for ROS 2 Jazzy.
// Records **uncompressed** color frames from
//     /zed_multi/myzed2i/left/image_rect_color  (sensor_msgs/msg/Image)
// into an MP4 (H.264) or raw AVI file and writes a CSV with exact ROS
// timestamps.  Implementation mirrors the depth‑recorder pattern: the writer
// thread queues only the original ROS message (ConstSharedPtr) to guarantee
// memory lifetime and avoid heavy copies between threads.
// -----------------------------------------------------------------------------

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_components/register_node_macro.hpp>

#include <sensor_msgs/msg/image.hpp>
#include <std_srvs/srv/set_bool.hpp>
#include <builtin_interfaces/msg/time.hpp>

#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/opencv.hpp>

#include <filesystem>
#include <queue>
#include <fstream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <atomic>
#include <string>

namespace fs = std::filesystem;
using sensor_msgs::msg::Image;
using std_srvs::srv::SetBool;

namespace zed_recorder_cpp
{
// ─────────────────────────────────────────────────────────────────────────────
static constexpr size_t kQueueSize = 240;   // 4 s @ 60 Hz

class RGBRecorder : public rclcpp::Node
{
public:
  explicit RGBRecorder(const rclcpp::NodeOptions & opt);
  ~RGBRecorder() override;

private:
  // callbacks ---------------------------------------------------------------
  void imgCallback(const Image::SharedPtr msg);
  void srvCallback(const std::shared_ptr<SetBool::Request>,
                   std::shared_ptr<SetBool::Response>);

  // helpers -----------------------------------------------------------------
  void startRecording();
  void openWriter(int w, int h);
  void writerLoop(std::stop_token token);

  // parameters --------------------------------------------------------------
  std::string topic_;
  bool        compressed_ {true};   // write H.264 vs raw AVI
  double      target_fps_     {60.0};

  // rclcpp entities ---------------------------------------------------------
  rclcpp::Subscription<Image>::SharedPtr sub_img_;
  rclcpp::Service<SetBool>::SharedPtr    srv_rec_;

  // state -------------------------------------------------------------------
  std::atomic<bool> recording_      {false};
  std::atomic<bool> running_        {true};
  std::atomic<bool> stop_requested_ {false};
  bool              first_frame_    {true};

  // queue & sync ------------------------------------------------------------
  std::queue<Image::ConstSharedPtr> frame_q_;
  std::mutex                        mut_;
  std::condition_variable_any       cv_;

  // writer ------------------------------------------------------------------
  std::jthread    writer_thr_;
  cv::VideoWriter vw_;
  std::ofstream   csv_;
  fs::path        base_dir_;
};

// ─────────────────────────────────────────────────────────────────────────────
RGBRecorder::RGBRecorder(const rclcpp::NodeOptions & opt)
: Node("zed_rgb_recorder", opt)
{
  topic_          = declare_parameter("topic",       "/zed_multi/myzed2i/rgb/image_rect_color");
  compressed_ = declare_parameter("compressed",  true);
  target_fps_     = declare_parameter("target_fps",  60.0);

  RCLCPP_INFO(get_logger(), "RGBRecorder subscribes to %s", topic_.c_str());

  auto qos = rclcpp::SensorDataQoS().keep_last(5).best_effort();
  sub_img_ = create_subscription<Image>(
      topic_, qos,
      std::bind(&RGBRecorder::imgCallback, this, std::placeholders::_1));

  srv_rec_ = create_service<SetBool>(
      "record_zed_rgb",
      std::bind(&RGBRecorder::srvCallback, this,
                std::placeholders::_1, std::placeholders::_2));

  writer_thr_ = std::jthread(&RGBRecorder::writerLoop, this);
}

// ─────────────────────────────────────────────────────────────────────────────
RGBRecorder::~RGBRecorder()
{
  running_.store(false);
  cv_.notify_all();       // wake writer so it can exit
}

// ─────────────────────────────────────────────────────────────────────────────
void RGBRecorder::imgCallback(const Image::SharedPtr msg)
{
  if (!recording_.load(std::memory_order_relaxed)) return;

  {
    std::lock_guard<std::mutex> lk(mut_);
    if (frame_q_.size() >= kQueueSize) frame_q_.pop();   // drop oldest
    frame_q_.push(msg);
  }
  cv_.notify_one();
}

// ─────────────────────────────────────────────────────────────────────────────
void RGBRecorder::srvCallback(const std::shared_ptr<SetBool::Request> req,
                              std::shared_ptr<SetBool::Response>      resp)
{
  const bool want_start = req->data;
  if (want_start == recording_.load()) {
    resp->success = false; resp->message = "no change"; return;
  }

  if (want_start)
    startRecording();
  else
    stop_requested_.store(true, std::memory_order_relaxed);

  recording_.store(want_start);
  resp->success = true;
  resp->message = want_start ? "started" : "stopping";
}

// ─────────────────────────────────────────────────────────────────────────────
void RGBRecorder::startRecording()
{
  const uint64_t sec = get_clock()->now().seconds();
  base_dir_ = fs::current_path() / "recordings" / ("recording_" + std::to_string(sec));
  fs::create_directories(base_dir_);

  csv_.open(base_dir_ / (std::to_string(sec) + "_rgb_times.csv"));
  csv_ << "sec,nanosec\n";

  first_frame_     = true;
  stop_requested_.store(false);
  RCLCPP_INFO(get_logger(), "Recording RGB to %s", base_dir_.c_str());
}

// ─────────────────────────────────────────────────────────────────────────────
void RGBRecorder::openWriter(int w, int h)
{
  const uint64_t sec = get_clock()->now().seconds();
  fs::path vid = base_dir_ / (std::to_string(sec) + (compressed_ ? "_rgb.mp4" : "_rgb.avi"));

  if (compressed_) {
    vw_.open(vid.string(), cv::VideoWriter::fourcc('M','J','P','G'), target_fps_, {w, h});
  } else {
    vw_.open(vid.string(), 0, target_fps_, {w, h});
  }

  if (!vw_.isOpened())
    RCLCPP_ERROR(get_logger(), "Cannot open %s", vid.c_str());
}

// ─────────────────────────────────────────────────────────────────────────────
void RGBRecorder::writerLoop(std::stop_token st)
{
  for (;;) {
    // wait until there is work or a stop request ---------------------------------
    std::unique_lock<std::mutex> lk(mut_);
    cv_.wait(lk, st, [&]{
      return !frame_q_.empty() || stop_requested_.load() || st.stop_requested();
    });

    if (st.stop_requested()) break;
    if (frame_q_.empty())    continue;      // spurious wake‑up

    // pop one message ------------------------------------------------------------
    auto msg = frame_q_.front();
    frame_q_.pop();
    lk.unlock();

    // Convert via cv_bridge ------------------------------------------------------
    cv_bridge::CvImageConstPtr cv_ptr;
    try {
      cv_ptr = cv_bridge::toCvShare(msg, "bgr8");
    } catch (const cv_bridge::Exception & e) {
      RCLCPP_ERROR_THROTTLE(get_logger(), *get_clock(), 3000,
                            "cv_bridge conversion failed: %s", e.what());
      continue;
    }
    const cv::Mat & img = cv_ptr->image;

    if (img.empty()) continue;

    // first frame? ----------------------------------------------------------------
    if (first_frame_) { openWriter(img.cols, img.rows); first_frame_ = false; }
    if (vw_.isOpened()) vw_.write(img);

    if (csv_.is_open())
      csv_ << msg->header.stamp.sec << ',' << msg->header.stamp.nanosec << '\n';

    // graceful stop --------------------------------------------------------------
    if (stop_requested_.load() && frame_q_.empty()) {
      if (vw_.isOpened()) vw_.release();
      if (csv_.is_open()) csv_.close();
      recording_.store(false);
      stop_requested_.store(false);
      RCLCPP_INFO(get_logger(), "RGB recording stopped.");
    }
  }
}

// ─────────────────────────────────────────────────────────────────────────────
} // namespace zed_recorder_cpp

RCLCPP_COMPONENTS_REGISTER_NODE(zed_recorder_cpp::RGBRecorder)
