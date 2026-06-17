// depth_recorder_component.cpp
// -----------------------------------------------------------------------------
// ZED *depth* recorder (ROS 2 Jazzy).
// Writes Depthimage directly from Callback – because of 
// **intra-process-zero-copy** is the sensor\_msgs::Image not copied.  
// The 32-bit-Float-depth (0.9-1.9 m) is converted to 16-bit grayscale and written
// as raw binary frames (gray16le format). A CSV File with timestamps and a
// metadata file with frame information are written.
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
static constexpr float kMinDepthMeters = 0.7f;
static constexpr float kMaxDepthMeters = 2.0f;
static constexpr float kDepthRangeMeters = kMaxDepthMeters - kMinDepthMeters;

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
  void openRawWriter(int width, int height);
  void writeMetadataFile(int width, int height, uint64_t start_timestamp);
  void convertRawToMKV(const fs::path & raw_file);

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

  std::ofstream depth_raw_file_;  // Raw 16-bit grayscale frames
  std::ofstream   csv_file_;
  fs::path        output_base_;
  fs::path        current_raw_file_;  // Path to current raw file for conversion
  int             frame_width_  {0};
  int             frame_height_ {0};
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
  // auto reentrant_cbg_ =
  // create_callback_group(rclcpp::CallbackGroupType::Reentrant);
  // sub_opts.callback_group = reentrant_cbg_;
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

  // first Frame → open raw writer -----------------------------------------
  if (first_frame_) {
    openRawWriter(static_cast<int>(msg->width), static_cast<int>(msg->height));
    first_frame_ = false;
    if (!depth_raw_file_.is_open()) return;
  }

  // 32FC1 → 16U (grayscale) --------------------------------------------------
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

  // Convert 32-bit float to 16-bit unsigned integer.
  // Scale: kMinDepthMeters-kMaxDepthMeters meters -> 0-65535.
  cv::Mat depth16u;
  cv::Mat depth_scaled = (depth32 - kMinDepthMeters) * (65535.f / kDepthRangeMeters);
  cv::threshold(depth_scaled, depth_scaled, 0.0, 0.0, cv::THRESH_TOZERO);
  cv::threshold(depth_scaled, depth_scaled, 65535.0, 65535.0, cv::THRESH_TRUNC);
  depth_scaled.convertTo(depth16u, CV_16U);

  // Write raw 16-bit data (little-endian format)
  if (depth_raw_file_.is_open()) {
    depth_raw_file_.write(reinterpret_cast<const char*>(depth16u.data),
                         depth16u.total() * depth16u.elemSize());
  }

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
  current_raw_file_.clear();  // Reset for new recording
  RCLCPP_INFO(get_logger(), "Recording depth to %s", output_base_.c_str());
}

// ─────────────────────────────────────────────────────────────────────────────
void DepthRecorder::stopRecording()
{
  fs::path raw_file_to_convert;

  if (depth_raw_file_.is_open()) {
    depth_raw_file_.close();
    raw_file_to_convert = current_raw_file_;
  }

  if (csv_file_.is_open()) csv_file_.close();

  recording_ = false;
  RCLCPP_INFO(get_logger(), "Depth recording stopped.");

  // Convert raw to MKV after closing files
  if (!raw_file_to_convert.empty() && fs::exists(raw_file_to_convert)) {
    RCLCPP_INFO(get_logger(), "Starting MKV conversion for: %s", raw_file_to_convert.c_str());
    convertRawToMKV(raw_file_to_convert);
  }
}

// ─────────────────────────────────────────────────────────────────────────────
void DepthRecorder::openRawWriter(int width, int height)
{
  const uint64_t ts = get_clock()->now().seconds();
  frame_width_  = width;
  frame_height_ = height;

  // Open raw depth file (16-bit grayscale frames)
  fs::path raw_file = output_base_ / (std::to_string(ts) + "_depth.raw16le");
  depth_raw_file_.open(raw_file, std::ios::binary);

  if (!depth_raw_file_.is_open()) {
    RCLCPP_ERROR(get_logger(), "Cannot open %s", raw_file.c_str());
    return;
  }

  current_raw_file_ = raw_file;  // Store for later conversion

  // Write metadata file with frame information
  writeMetadataFile(width, height, ts);
  RCLCPP_INFO(get_logger(), "Opened raw 16-bit depth writer: %s", raw_file.c_str());
}

// ─────────────────────────────────────────────────────────────────────────────
void DepthRecorder::writeMetadataFile(int width, int height, uint64_t start_timestamp)
{
  fs::path metadata_file = output_base_ / (std::to_string(start_timestamp) + "_depth.metadata");
  std::ofstream meta(metadata_file);

  if (!meta.is_open()) {
    RCLCPP_ERROR(get_logger(), "Cannot open metadata file: %s", metadata_file.c_str());
    return;
  }

  meta << "# 16-bit Grayscale Little-Endian Depth Video Metadata\n";
  meta << "width=" << width << "\n";
  meta << "height=" << height << "\n";
  meta << "min_depth_meters=" << kMinDepthMeters << "\n";
  meta << "max_depth_meters=" << kMaxDepthMeters << "\n";
  meta << "depth_range_meters=" << kDepthRangeMeters << "\n";
  meta << "format=gray16le\n";
  meta << "bytes_per_pixel=2\n";
  meta << "frame_size_bytes=" << (width * height * 2) << "\n";
  meta << "fps=" << target_fps_ << "\n";
  meta << "participant=" << participant_ << "\n";
  meta.close();
}

// ─────────────────────────────────────────────────────────────────────────────
void DepthRecorder::convertRawToMKV(const fs::path & raw_file)
{
  const fs::path mkv_file = raw_file.parent_path() / 
                            (raw_file.stem().string() + ".mkv");

  // Build FFmpeg command
  // FFV1 level 3 is lossless with best compression
  std::string cmd = "ffmpeg -f rawvideo "
                    "-pixel_format gray16le "
                    "-video_size " + std::to_string(frame_width_) + "x" + 
                                     std::to_string(frame_height_) + " "
                    "-framerate " + std::to_string(static_cast<int>(target_fps_)) + " "
                    "-i \"" + raw_file.string() + "\" "
                    "-c:v ffv1 "
                    "-level 3 "
                    "-y "  // Overwrite output file
                    "\"" + mkv_file.string() + "\" "
                    "2>&1";  // Capture stderr to stdout

  RCLCPP_INFO(get_logger(), "Converting raw to MKV with FFV1...");

  // Execute FFmpeg command
  int ret = system(cmd.c_str());

  if (ret != 0) {
    RCLCPP_ERROR(get_logger(), "FFmpeg conversion failed with return code: %d", ret);
    return;
  }

  RCLCPP_INFO(get_logger(), "MKV conversion completed: %s", mkv_file.c_str());

  // Delete raw file after successful conversion
  try {
    if (fs::exists(raw_file)) {
      fs::remove(raw_file);
      RCLCPP_INFO(get_logger(), "Removed raw file: %s", raw_file.c_str());
    }
  } catch (const fs::filesystem_error & e) {
    RCLCPP_ERROR(get_logger(), "Failed to remove raw file: %s", e.what());
  }
}

// ─────────────────────────────────────────────────────────────────────────────
} // namespace zed_recorder_cpp

RCLCPP_COMPONENTS_REGISTER_NODE(zed_recorder_cpp::DepthRecorder)
