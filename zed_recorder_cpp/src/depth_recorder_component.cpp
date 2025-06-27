// depth_recorder_component.cpp
// -----------------------------------------------------------------------------
// ZED *depth* recorder (ROS 2 Jazzy).
// Writes Depthimage directly from Callback – because of 
// **intra-process-zero-copy** is the sensor\_msgs::Image not copied.  
// The 32-bit-Float-depth (0‒5 m) is scaled to 8-bit and is written as BGR-Frame
// in the MP4- (H.264/mp4v) or AVI-Datei (MJPG). A CSV File with timestamps of
// the header of the received ROS Image are written.
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
static constexpr float kDepthRangeMeters = 3.0f;   // 0-5 m → 0-255 TODO edit to 3

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

  // parameter callback ------------------------------------------------------
  rcl_interfaces::msg::SetParametersResult parameterCallback(
    const std::vector<rclcpp::Parameter> & parameters);

  // helpers -----------------------------------------------------------------
  void startRecording();
  void stopRecording();
  void openWriter(int width, int height);

  // parameters --------------------------------------------------------------
  std::string topic_;
  bool        compressed_ {true};
  double      target_fps_ {60.0};
  std::string participant_ {"default"};  // Standardwert

  // rclcpp entites ----------------------------------------------------------
  rclcpp::Subscription<Image>::SharedPtr sub_depth_;
  rclcpp::Service<SetBool>::SharedPtr    srv_rec_;
  rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr param_cb_handle_;

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
  compressed_ = declare_parameter("compressed", false);
  target_fps_ = declare_parameter("target_fps", 60.0);
  participant_ = declare_parameter("participant_name", "default");
  
  RCLCPP_INFO(get_logger(), "DepthRecorder subscribes to %s", topic_.c_str());
  RCLCPP_INFO(get_logger(), "Participant name: %s", participant_.c_str());
  
  // Parameter callback for dynamic update of participant name
  param_cb_handle_ = add_on_set_parameters_callback(
    std::bind(&DepthRecorder::parameterCallback, this, std::placeholders::_1));

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

// Editing the name of the participant in run time and logging the updated value
rcl_interfaces::msg::SetParametersResult DepthRecorder::parameterCallback(
  const std::vector<rclcpp::Parameter> & parameters)
{
  rcl_interfaces::msg::SetParametersResult result;
  result.successful = true;
  
  for (const auto & param : parameters) {
    if (param.get_name() == "participant_name") {
      if (param.get_type() == rclcpp::ParameterType::PARAMETER_STRING) {
        participant_ = param.as_string();
        RCLCPP_INFO(get_logger(), "Updated participant name to: %s", participant_.c_str());
      } else {
        RCLCPP_ERROR(get_logger(), "participant_name must be a string");
        result.successful = false;
        result.reason = "participant_name must be a string";
      }
    }
  }
  
  return result;
}

// ─────────────────────────────────────────────────────────────────────────────
void DepthRecorder::depthCallback(const Image::ConstSharedPtr & msg)
{
  if (!recording_) return;

  // first Frame → open VideoWriter -----------------------------------------
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
  // Verwende participant_ für Ordnername
  output_base_ = fs::current_path() / "recordings" / ("recording_" + participant_);

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
