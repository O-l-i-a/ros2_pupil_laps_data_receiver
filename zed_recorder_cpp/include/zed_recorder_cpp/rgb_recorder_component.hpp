#pragma once
//
// High-throughput RGB recorder for ZED-2/2i/2X
//

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_components/register_node_macro.hpp>
#include <sensor_msgs/msg/compressed_image.hpp>
#include <std_srvs/srv/set_bool.hpp>
#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/opencv.hpp>
#include <boost/lockfree/spsc_queue.hpp>

#include <thread>
#include <mutex>
#include <condition_variable>
#include <filesystem>
#include <fstream>
#include <atomic>

namespace fs = std::filesystem;
using sensor_msgs::msg::CompressedImage;
using std_srvs::srv::SetBool;

namespace zed_recorder_cpp
{

using Frame         = std::pair<cv::Mat, builtin_interfaces::msg::Time>;
using FrameQueueRaw = boost::lockfree::spsc_queue<Frame,
                      boost::lockfree::capacity<240>>;   // 4 s @ 60 fps

class RGBRecorder : public rclcpp::Node
{
public:
  explicit RGBRecorder(const rclcpp::NodeOptions & = rclcpp::NodeOptions());
  ~RGBRecorder() override;

private:
  // ROS
  void imageCb(const CompressedImage::SharedPtr);
  void srvCb(const std::shared_ptr<SetBool::Request>,
             std::shared_ptr<SetBool::Response>);

  // helpers
  void startRecording();
  void openWriter(int w, int h);
  void writerLoop(std::stop_token);

  // parameters
  std::string topic_;
  bool        compressed_{true};          // H264 mp4  vs raw AVI
  double      target_fps_{60.0};

  // ROS handles
  rclcpp::Subscription<CompressedImage>::SharedPtr sub_img_;
  rclcpp::Service<SetBool>::SharedPtr             srv_rec_;

  // worker data
  std::unique_ptr<FrameQueueRaw> frame_q_;
  std::mutex                     mut_;
  std::condition_variable_any    cv_;
  std::jthread                   writer_thr_;

  std::atomic_bool running_{true};
  std::atomic_bool recording_{false};
  std::atomic_bool stop_requested_{false};

  cv::VideoWriter vw_;
  std::ofstream    csv_;
  fs::path         base_dir_;
  bool             first_frame_{true};
};

}  // namespace zed_recorder_cpp
