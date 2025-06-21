#include "zed_recorder_cpp/rgb_recorder_component.hpp"
#include <rclcpp/rclcpp.hpp>

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<zed_recorder_cpp::RGBRecorder>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}