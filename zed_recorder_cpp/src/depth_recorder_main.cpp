#include "zed_recorder_cpp/depth_recorder_component.hpp"
#include <rclcpp/rclcpp.hpp>

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<zed_recorder_cpp::DepthRecorder>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
