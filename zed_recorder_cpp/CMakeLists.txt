cmake_minimum_required(VERSION 3.16)
project(zed_recorder_cpp)

# ── Abhängigkeiten ───────────────────────────────────────────────────────────
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)
find_package(std_srvs REQUIRED)
find_package(rclcpp_components REQUIRED)   # Für die Component-Registrierung
find_package(pluginlib REQUIRED)            # new – optional but recommended

# ── 1. Shared-Library (rclcpp-Component) ─────────────────────────────────────
add_library(depth_recorder_component SHARED
  src/depth_recorder_component.cpp 
)
target_include_directories(depth_recorder_component PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
ament_target_dependencies(depth_recorder_component
  rclcpp rclcpp_components pluginlib
  sensor_msgs cv_bridge OpenCV std_srvs
)

# Export des Komponenten-Plugins (für ros2 component load)
rclcpp_components_register_nodes(depth_recorder_component "zed_recorder_cpp::DepthRecorder")

# ── 2. (Optional) Executable, das dieselbe Quelle nutzt ─────────────────────
add_executable(depth_recorder_node src/depth_recorder_main.cpp)
target_link_libraries(depth_recorder_node depth_recorder_component)
target_include_directories(depth_recorder_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
ament_target_dependencies(depth_recorder_node
  rclcpp sensor_msgs cv_bridge OpenCV std_srvs)
target_compile_features(depth_recorder_component PUBLIC cxx_std_20)
target_compile_features(depth_recorder_node      PUBLIC cxx_std_20)
# ── Installation ────────────────────────────────────────────────────────────
install(TARGETS
  depth_recorder_component
  depth_recorder_node
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

ament_package()
