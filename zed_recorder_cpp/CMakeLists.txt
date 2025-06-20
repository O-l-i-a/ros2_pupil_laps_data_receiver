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

# ── 1. Shared-Library (rclcpp-Component) ─────────────────────────────────────
add_library(depth_recorder_component SHARED
  src/depth_recorder_node.cpp 
)

ament_target_dependencies(depth_recorder_component
  rclcpp sensor_msgs cv_bridge OpenCV std_srvs
)

# Export des Komponenten-Plugins (für ros2 component load)
rclcpp_components_register_nodes(depth_recorder_component "DepthRecorder")

# ── 2. (Optional) Executable, das dieselbe Quelle nutzt ─────────────────────
add_executable(depth_recorder_node
  src/depth_recorder_node.cpp 
)
target_link_libraries(depth_recorder_node depth_recorder_component)

ament_target_dependencies(depth_recorder_node
  rclcpp sensor_msgs cv_bridge OpenCV std_srvs
)

# ── Installation ────────────────────────────────────────────────────────────
install(TARGETS
  depth_recorder_component
  depth_recorder_node
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

ament_package()
