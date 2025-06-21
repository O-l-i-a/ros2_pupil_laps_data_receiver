// rgb_recorder_component.cpp
// -----------------------------------------------------------------------------
// ZED RGB recorder component for ROS 2 Jazzy.
// Schreibt Farbbilder direkt aus dem ROS‑Callback in eine MP4‑ (H.264/mp4v)
// oder AVI‑Datei (MJPG).  Queue, Mutex & Hintergrund‑Thread wurden entfernt –
// stattdessen verwenden wir ROS 2 **intra‑process‑zero‑copy**.
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
class RGBRecorder : public rclcpp::Node
{
public:
  explicit RGBRecorder(const rclcpp::NodeOptions & opts);
  ~RGBRecorder() override;

private:
  // callbacks ---------------------------------------------------------------
  void imgCallback(const Image::ConstSharedPtr & msg);
  void srvCallback(const std::shared_ptr<SetBool::Request>,
                   std::shared_ptr<SetBool::Response>);

  // helpers -----------------------------------------------------------------
  void startRecording();
  void stopRecording();
  void openWriter(int width, int height);

  // parameters --------------------------------------------------------------
  std::string topic_;
  bool        compressed_ {true};            // MP4(H.264/mp4v) vs. AVI(MJPG)
  double      target_fps_ {60.0};

  // rclcpp entities ---------------------------------------------------------
  rclcpp::Subscription<Image>::SharedPtr sub_img_;
  rclcpp::Service<SetBool>::SharedPtr    srv_rec_;

  // state -------------------------------------------------------------------
  std::atomic<bool> recording_   {false};
  bool              first_frame_ {true};

  cv::VideoWriter vw_;
  std::ofstream   csv_;
  fs::path        base_dir_;
};

// ─────────────────────────────────────────────────────────────────────────────
RGBRecorder::RGBRecorder(const rclcpp::NodeOptions & opts_in)
: Node("zed_rgb_recorder", rclcpp::NodeOptions(opts_in).use_intra_process_comms(true))
{
  // Parameter -----------------------------------------------------------------
  topic_      = declare_parameter("topic",      "/zed_multi/myzed2i/rgb/image_rect_color");
  compressed_ = declare_parameter("compressed", true);
  target_fps_ = declare_parameter("target_fps", 60.0);

  RCLCPP_INFO(get_logger(), "RGBRecorder subscribes to %s", topic_.c_str());

  // Subscription (zero‑copy) ---------------------------------------------------
  auto qos = rclcpp::SensorDataQoS().keep_last(5).best_effort();
  rclcpp::SubscriptionOptions sub_opts;

  sub_img_ = create_subscription<Image>(
      topic_, qos,
      std::bind(&RGBRecorder::imgCallback, this, std::placeholders::_1),
      sub_opts);

  // Service --------------------------------------------------------------------
  srv_rec_ = create_service<SetBool>(
      "record_zed_rgb",
      std::bind(&RGBRecorder::srvCallback, this,
                std::placeholders::_1, std::placeholders::_2));
}

// ─────────────────────────────────────────────────────────────────────────────
RGBRecorder::~RGBRecorder()
{
  stopRecording();
}

// ─────────────────────────────────────────────────────────────────────────────
void RGBRecorder::imgCallback(const Image::ConstSharedPtr & msg)
{
  if (!recording_) return;                       // nichts zu tun

  // erster Frame → VideoWriter öffnen -----------------------------------------
  if (first_frame_) {
    openWriter(static_cast<int>(msg->width), static_cast<int>(msg->height));
    first_frame_ = false;
    if (!vw_.isOpened()) return;                // Codec nicht verfügbar?
  }

  // share‑Konvertierung ohne Kopie -------------------------------------------
  cv_bridge::CvImageConstPtr cv_ptr;
  try {
    cv_ptr = cv_bridge::toCvShare(msg, "bgr8");
  } catch (const cv_bridge::Exception & e) {
    RCLCPP_ERROR_THROTTLE(get_logger(), *get_clock(), 3000,
                          "cv_bridge conversion failed: %s", e.what());
    return;
  }

  vw_.write(cv_ptr->image);

  if (csv_.is_open())
    csv_ << msg->header.stamp.sec << ',' << msg->header.stamp.nanosec << '\n';
}

// ─────────────────────────────────────────────────────────────────────────────
void RGBRecorder::srvCallback(const std::shared_ptr<SetBool::Request> req,
                              std::shared_ptr<SetBool::Response>      resp)
{
  if (req->data == recording_) {
    resp->success = false; resp->message = "no change"; return;
  }

  if (req->data)  startRecording();
  else            stopRecording();

  recording_    = req->data;
  resp->success = true;
  resp->message = req->data ? "started" : "stopped";
}

// ─────────────────────────────────────────────────────────────────────────────
void RGBRecorder::startRecording()
{
  const uint64_t ts = get_clock()->now().seconds();
  base_dir_ = fs::current_path() / "recordings" / ("recording_" + std::to_string(ts));
  fs::create_directories(base_dir_);

  csv_.open(base_dir_ / (std::to_string(ts) + "_rgb_times.csv"));
  csv_ << "sec,nanosec\n";

  first_frame_ = true;
  RCLCPP_INFO(get_logger(), "Recording RGB to %s", base_dir_.c_str());
}

// ─────────────────────────────────────────────────────────────────────────────
void RGBRecorder::stopRecording()
{
  if (vw_.isOpened())  vw_.release();            // MP4‑Header schreiben
  if (csv_.is_open())  csv_.close();
  recording_ = false;
  RCLCPP_INFO(get_logger(), "RGB recording stopped.");
}

// ─────────────────────────────────────────────────────────────────────────────
void RGBRecorder::openWriter(int width, int height)
{
  const uint64_t ts = get_clock()->now().seconds();
  fs::path file;
  int      fourcc;

  if (compressed_) {
    file   = base_dir_ / (std::to_string(ts) + "_rgb.mp4");
    fourcc = cv::VideoWriter::fourcc('m','p','4','v');   // libx264? → 'a','v','c','1'
  } else {
    file   = base_dir_ / (std::to_string(ts) + "_rgb.avi");
    fourcc = cv::VideoWriter::fourcc('M','J','P','G');
  }

  vw_.open(file.string(), fourcc, target_fps_,
           cv::Size(width, height), /*isColor=*/true);

  if (!vw_.isOpened())
    RCLCPP_ERROR(get_logger(), "Cannot open %s", file.c_str());
}

// ─────────────────────────────────────────────────────────────────────────────
} // namespace zed_recorder_cpp

RCLCPP_COMPONENTS_REGISTER_NODE(zed_recorder_cpp::RGBRecorder)
