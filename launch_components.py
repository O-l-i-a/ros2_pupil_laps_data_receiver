import launch
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode


def generate_launch_description():
    """Composable container for ZED + RGB & Depth recorder.

    * Alle drei Nodes laufen **im selben Prozess** (`component_container_mt`) →
      zero‑copy zwischen Publisher/Subscriber (intra‑process‑comms).
    * Benötigt, dass deine Python‑Pakete einen **ros2_nodes‑Entry‑Point**
      besitzen, z. B. in setup.cfg / setup.py:

          [options.entry_points]
          ros2_nodes =
              zed_wrapper_node = zed_wrapper_node:ZedWrapperNode
              depth_recorder   = depth_recorder:DepthRecorder
              rgb_recorder     = rgb_recorder:RGBRecorder

      Achte auf die **vollqualifizierten Modulnamen** unten im *plugin*‑Feld.
    """

    container = ComposableNodeContainer(
        name='launch_components',
        namespace='',
        package='rclcpp_components',     # ← keep this!
        executable='component_container_mt',  # or 'component_container_mt'
        composable_node_descriptions=[
            # ────────────────── ZED Wrapper ──────────────────
            ComposableNode(
                package='zed_mini',                # <‑‑ dein ROS‑2‑Pkg
                plugin='zed_mini:ZedWrapperNode', # modul:Klasse
                name='zed_wrapper',
                parameters=[
                    {'target_fps': 60.0},                # optional
                ],
                extra_arguments=[{'use_intra_process_comms': True}],
            ),
            # ────────────────── Depth Recorder ──────────────
            ComposableNode(
                package='recording_zed_depth',
                plugin='depth_recorder:DepthRecorder',
                name='depth_recorder',
                extra_arguments=[{'use_intra_process_comms': True}],
            ),
            # ────────────────── RGB Recorder ────────────────
            ComposableNode(
                package='recording_zed_rgb',
                plugin='rgb_recorder:RGBRecorder',
                name='rgb_recorder',
                extra_arguments=[{'use_intra_process_comms': True}],
            ),
        ],
        output='screen',  # oder 'both', wenn du stdout+stderr trennen willst
    )

    return launch.LaunchDescription([container])
