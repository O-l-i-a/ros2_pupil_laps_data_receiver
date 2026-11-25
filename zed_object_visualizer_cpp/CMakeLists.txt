cmake_minimum_required(VERSION 3.16)
project(zed_object_visualizer_cpp)

find_package(ament_cmake REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_transport REQUIRED)
find_package(OpenCV REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(zed_msgs REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(object_image_visualizer_node src/object_image_visualizer_node.cpp)
ament_target_dependencies(object_image_visualizer_node
  cv_bridge
  image_transport
  OpenCV
  rclcpp
  sensor_msgs
  zed_msgs
)

install(TARGETS object_image_visualizer_node
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
