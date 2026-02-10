cmake_minimum_required(VERSION 3.16)
project(recording_scene_cpp)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(scene_recorder_node src/scene_recorder_node.cpp)
target_include_directories(scene_recorder_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
ament_target_dependencies(scene_recorder_node
  rclcpp sensor_msgs std_srvs cv_bridge OpenCV
)

install(TARGETS scene_recorder_node
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

ament_package()
