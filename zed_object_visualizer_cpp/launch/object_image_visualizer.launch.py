from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            "image_topic",
            default_value="/zed_multi/myzed2i/rgb/image_rect_color",
        ),
        DeclareLaunchArgument(
            "objects_topic",
            default_value="/zed_multi/myzed2i/obj_det/objects",
        ),
        DeclareLaunchArgument(
            "output_topic",
            default_value="/zed_multi/myzed2i/obj_det/image_overlay",
        ),
        Node(
            package="zed_object_visualizer_cpp",
            executable="object_image_visualizer_node",
            name="zed_object_image_visualizer",
            output="screen",
            parameters=[{
                "image_topic": LaunchConfiguration("image_topic"),
                "objects_topic": LaunchConfiguration("objects_topic"),
                "output_topic": LaunchConfiguration("output_topic"),
            }],
        ),
    ])
