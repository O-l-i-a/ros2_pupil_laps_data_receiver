#pragma once
//
// Depth-recorder component for ZED-2/2i/2X – fast, lock-free version
//

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_components/register_node_macro.hpp>
#include <sensor_msgs/msg/image.hpp>
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
using sensor_msgs::msg::Image;
using std_srvs::srv::SetBool;

namespace zed_recorder_cpp
{

// single-producer / single-consumer ring buffer
using FrameQueue = boost::lockfree::spsc_queue<
  std::pair<cv::Mat, builtin_interfaces::msg::Time>,
  boost::lockfree::capacity<240>>;          // 4 s @ 60 fps

class DepthRecorder : public rclcpp::Node
{
public:
  explicit DepthRecorder(const rclcpp::NodeOptions & = rclcpp::NodeOptions());
  ~DepthRecorder() override;

private:
  // ───────── ROS callbacks ─────────
  void depthCallback(const Image::SharedPtr);
  void srvCallback(const std::shared_ptr<SetBool::Request>,
                   std::shared_ptr<SetBool::Response>);

  // ───────── recording helpers ─────
  void startRecording();
  void openVideoWriter(int width, int height);

  // writer thread
  void writerLoop(std::stop_token);

  // ───────── runtime parameters ────
  std::string topic_;
  bool        compressed_{true};
  double      target_fps_{60.0};

  // ───────── ROS entities ──────────
  rclcpp::Subscription<Image>::SharedPtr sub_depth_;
  rclcpp::Service<SetBool>::SharedPtr    srv_rec_;

  // ───────── worker data ───────────
  std::unique_ptr<FrameQueue> frame_queue_;
  std::mutex                  mut_;
  std::condition_variable_any cv_;

  std::jthread            writer_thread_;
  std::atomic_bool        running_{true};
  std::atomic_bool        recording_{false};
  std::atomic_bool        stop_requested_{false};

  cv::VideoWriter video_writer_;
  std::ofstream   csv_file_;
  fs::path        output_base_;

  bool first_frame_{true};
};

}  // namespace zed_recorder_cpp
