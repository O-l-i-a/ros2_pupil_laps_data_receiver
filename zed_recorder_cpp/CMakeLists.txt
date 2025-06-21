cmake_minimum_required(VERSION 3.16)
project(zed_recorder_cpp)

# ──────────────── dependencies ───────────────────────────────────────────────
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(pluginlib REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)
find_package(std_srvs REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# ──────────────── 1. depth component lib ─────────────────────────────────────
add_library(depth_recorder_component SHARED
  src/depth_recorder_component.cpp
)
target_include_directories(depth_recorder_component PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
ament_target_dependencies(depth_recorder_component
  rclcpp rclcpp_components pluginlib
  sensor_msgs cv_bridge OpenCV std_srvs
)
rclcpp_components_register_nodes(depth_recorder_component
  "zed_recorder_cpp::DepthRecorder")

# optional depth executable
add_executable(depth_recorder_node src/depth_recorder_main.cpp)
target_link_libraries(depth_recorder_node depth_recorder_component)
ament_target_dependencies(depth_recorder_node
  rclcpp sensor_msgs cv_bridge OpenCV std_srvs)

# ──────────────── 2. rgb component lib ───────────────────────────────────────
add_library(rgb_recorder_component SHARED
  src/rgb_recorder_component.cpp
)
target_include_directories(rgb_recorder_component PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
ament_target_dependencies(rgb_recorder_component
  rclcpp rclcpp_components pluginlib
  sensor_msgs cv_bridge OpenCV std_srvs
)
rclcpp_components_register_nodes(rgb_recorder_component
  "zed_recorder_cpp::RGBRecorder")

# optional rgb executable (copy depth main → rgb_recorder_main.cpp
# and change the class name inside it)
add_executable(rgb_recorder_node src/rgb_recorder_main.cpp)
target_link_libraries(rgb_recorder_node rgb_recorder_component)
ament_target_dependencies(rgb_recorder_node
  rclcpp sensor_msgs cv_bridge OpenCV std_srvs)

# ──────────────── install ────────────────────────────────────────────────────
install(TARGETS
  depth_recorder_component
  rgb_recorder_component
  depth_recorder_node
  rgb_recorder_node
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)
install(DIRECTORY include/ DESTINATION include)

ament_package()
