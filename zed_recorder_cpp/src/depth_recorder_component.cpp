// depth_recorder_component.cpp
// -----------------------------------------------------------------------------
// ZED *depth* recorder (ROS 2 Jazzy) ohne Queue, Mutex oder Writer-Thread.
// Schreibt Tiefenbilder direkt aus dem Callback – dank
// **intra-process-zero-copy** wird der sensor\_msgs::Image nicht kopiert.  
// Die 32-bit-Float-Tiefe (0‒5 m) wird auf 8-bit skaliert und als BGR-Frame
// in eine MP4- (H.264/mp4v) oder AVI-Datei (MJPG) kodiert.  Ein CSV mit den
// exakten ROS-Zeitstempeln wird parallel erzeugt.
// -----------------------------------------------------------------------------

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_components/register_node_macro.hpp>

#include <sensor_msgs/msg/image.hpp>
#include <std_srvs/srv/set_bool.hpp>

#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/opencv.hpp>

#include <filesystem>
#include <fstream>
#include <atomic>
#include <string>

namespace fs = std::filesystem;
using sensor_msgs::msg::Image;
using std_srvs::srv::SetBool;

namespace zed_recorder_cpp
{
// ─────────────────────────────────────────────────────────────────────────────
static constexpr float kDepthRangeMeters = 5.0f;   // 0-5 m → 0-255

class DepthRecorder : public rclcpp::Node
{
public:
  explicit DepthRecorder(const rclcpp::NodeOptions & opts);
  ~DepthRecorder() override;

private:
  // callbacks ---------------------------------------------------------------
  void depthCallback(const Image::ConstSharedPtr & msg);
  void srvCallback(const std::shared_ptr<SetBool::Request>,
                   std::shared_ptr<SetBool::Response>);

  // helpers -----------------------------------------------------------------
  void startRecording();
  void stopRecording();
  void openWriter(int width, int height);

  // parameters --------------------------------------------------------------
  std::string topic_;
  bool        compressed_ {true};
  double      target_fps_ {60.0};

  // rclcpp entites ----------------------------------------------------------
  rclcpp::Subscription<Image>::SharedPtr sub_depth_;
  rclcpp::Service<SetBool>::SharedPtr    srv_rec_;

  // state -------------------------------------------------------------------
  std::atomic<bool> recording_   {false};
  bool              first_frame_ {true};

  cv::VideoWriter video_writer_;
  std::ofstream   csv_file_;
  fs::path        output_base_;
};

// ─────────────────────────────────────────────────────────────────────────────
DepthRecorder::DepthRecorder(const rclcpp::NodeOptions & opts_in)
: Node("zed_depth_recorder", rclcpp::NodeOptions(opts_in).use_intra_process_comms(true))
{
  // Parameter ----------------------------------------------------------------
  topic_      = declare_parameter("topic",      "/zed_multi/myzed2i/depth/depth_registered");
  compressed_ = declare_parameter("compressed", true);
  target_fps_ = declare_parameter("target_fps", 60.0);

  RCLCPP_INFO(get_logger(), "DepthRecorder subscribes to %s", topic_.c_str());

  // Subscription (zero-copy) --------------------------------------------------
  auto qos = rclcpp::SensorDataQoS().keep_last(5).best_effort();
  rclcpp::SubscriptionOptions sub_opts;

  sub_depth_ = create_subscription<Image>(
      topic_, qos,
      std::bind(&DepthRecorder::depthCallback, this, std::placeholders::_1),
      sub_opts);

  // Service -------------------------------------------------------------------
  srv_rec_ = create_service<SetBool>(
      "record_zed_depth",
      std::bind(&DepthRecorder::srvCallback, this,
                std::placeholders::_1, std::placeholders::_2));
}

// ─────────────────────────────────────────────────────────────────────────────
DepthRecorder::~DepthRecorder()
{
  stopRecording();
}

// ─────────────────────────────────────────────────────────────────────────────
void DepthRecorder::depthCallback(const Image::ConstSharedPtr & msg)
{
  if (!recording_) return;

  // erstes Frame → VideoWriter öffnen -----------------------------------------
  if (first_frame_) {
    openWriter(static_cast<int>(msg->width), static_cast<int>(msg->height));
    first_frame_ = false;
    if (!video_writer_.isOpened()) return;
  }

  // 32FC1 → 8U → BGR ----------------------------------------------------------
  cv_bridge::CvImageConstPtr cv_ptr;
  try {
    cv_ptr = cv_bridge::toCvShare(msg, "32FC1");
  } catch (const cv_bridge::Exception & e) {
    RCLCPP_ERROR_THROTTLE(get_logger(), *get_clock(), 3000,
                          "cv_bridge conversion failed: %s", e.what());
    return;
  }

  cv::Mat depth32 = cv_ptr->image;
  if (depth32.empty()) return;

  cv::Mat depth8, depthBGR;
  depth32.convertTo(depth8, CV_8U, 255.f / kDepthRangeMeters);
  cv::cvtColor(depth8, depthBGR, cv::COLOR_GRAY2BGR);

  video_writer_.write(depthBGR);

  if (csv_file_.is_open())
    csv_file_ << msg->header.stamp.sec << ',' << msg->header.stamp.nanosec << '\n';
}

// ─────────────────────────────────────────────────────────────────────────────
void DepthRecorder::srvCallback(const std::shared_ptr<SetBool::Request> req,
                                std::shared_ptr<SetBool::Response>      resp)
{
  // Antwort sofort – schwere I/O im Hintergrund
  if (req->data == recording_) {
    resp->success = false;
    resp->message = "no change";
    return;
  }

  if (req->data) {
    std::thread([this]{ startRecording(); }).detach();
  } else {
    std::thread([this]{ stopRecording(); }).detach();
  }

  recording_   = req->data;
  resp->success = true;
  resp->message = req->data ? "started" : "stopped";
}

// ─────────────────────────────────────────────────────────────────────────────
void DepthRecorder::startRecording()
{
  const uint64_t ts = get_clock()->now().seconds();
  output_base_ = fs::current_path() / "recordings" / ("recording_" + std::to_string(ts));
  fs::create_directories(output_base_);

  csv_file_.open(output_base_ / (std::to_string(ts) + "_depth_times.csv"));
  csv_file_ << "sec,nanosec\n";

  first_frame_ = true;
  RCLCPP_INFO(get_logger(), "Recording depth to %s", output_base_.c_str());
}

// ─────────────────────────────────────────────────────────────────────────────
void DepthRecorder::stopRecording()
{
  if (video_writer_.isOpened()) video_writer_.release();
  if (csv_file_.is_open())      csv_file_.close();
  recording_ = false;
  RCLCPP_INFO(get_logger(), "Depth recording stopped.");
}

// ─────────────────────────────────────────────────────────────────────────────
void DepthRecorder::openWriter(int width, int height)
{
  const uint64_t ts = get_clock()->now().seconds();
  fs::path file;
  int      fourcc;

  if (compressed_) {
    file   = output_base_ / (std::to_string(ts) + "_depth.mp4");
    fourcc = cv::VideoWriter::fourcc('m','p','4','v'); // oder 'a','v','c','1'
  } else {
    file   = output_base_ / (std::to_string(ts) + "_depth.avi");
    fourcc = cv::VideoWriter::fourcc('M','J','P','G');
  }

  video_writer_.open(file.string(), fourcc, target_fps_,
                     cv::Size(width, height), /*isColor=*/true);

  if (!video_writer_.isOpened())
    RCLCPP_ERROR(get_logger(), "Cannot open %s", file.c_str());
}

// ─────────────────────────────────────────────────────────────────────────────
} // namespace zed_recorder_cpp

RCLCPP_COMPONENTS_REGISTER_NODE(zed_recorder_cpp::DepthRecorder)
