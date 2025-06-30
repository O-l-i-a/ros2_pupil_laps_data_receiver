# Recording Suite for ZED 2i & Pupil Labs
This workspace provides tools to synchronize and record data from:

- Pupil Labs eye-tracking hardware (scene video + gaze data)

- Stereolabs ZED 2i stereo camera (depth and rgb videos)

# Tools for recordings:

**- A synchronizer app to put two recorded videos near each other**
Example of use:

python3 sync_videos.py \
  --video1 ~/home/olhamelnyk/colcon_venv/recordings/recording_1748613207/video_30Hz.mp4 \
  --video2 ~/home/olhamelnyk/colcon_venv/recordings/recording_1748613207/video_60Hz.mp4 \
  --csv1   ~/home/olhamelnyk/colcon_venv/recordings/recording_1748613207/timestamps_30Hz.csv \
  --csv2   ~/home/olhamelnyk/colcon_venv/recordings/recording_1748613207/timestamps_60Hz.csv \
  --output ~/home/olhamelnyk/colcon_venv/recordings/recording_1748613207/output_side_by_side.mp4 \
  --fps 60

**- A gaze overlap app, that merges gaze coordinates and scene video of pupil labs for visualization**
Example of use:

cd ~/colcon_venv/

source venv/bin/activate

cd src/testing_realtime_api

python async_gaze_scene.py \
  --scene_video /home/olhamelnyk/colcon_venv/recordings/recording_BAUL02/1751210368_scene.avi \
  --gaze_csv   /home/olhamelnyk/colcon_venv/recordings/recording_BAUL02/1751210368_gaze.csv\
  --scene_csv  /home/olhamelnyk/colcon_venv/recordings/recording_BAUL02/1751210368_scene_times.csv\
  --output     /home/olhamelnyk/colcon_venv/recordings/recording_BAUL02/Extra/1748795149_overlay.mp4 \
  --dot_radius 20 \
  --dot_color 0,255,0


**- A controller app to start all recordings together**
Example of use:

source install/setup.bash

ros2 run recording_controller_pkg controller_node

# It includes:

**async_pupil_wrapper:** (Python)
A ROS 2 node that discovers a Pupil Labs device, publishes:

pupil_labs/scene/img_raw (sensor_msgs/Image @ 30 Hz)

pupil/scene/camera_info (sensor_msgs/CameraInfo @ 30 Hz)

pupil/gaze (gaze_interface/GazeDataAsync @ 130 Hz)

**recording_gaze**: (Python)

A ROS 2 node that subscribes to pupil/gaze and records a .csv file with coordinates of gaze and timestamps

**recording_scene** (Python)

A ROS 2 node that subscribes to pupil_labs/scene/img_raw and records a .csv file with timestamps and .avi video recording of the published frames

**zed_wrapper** (C++)

A ROS 2 node that publishes data from the ZED2i camera - see more at https://github.com/stereolabs/zed-ros2-wrapper

**depth_recorder_component** (C++)

A ROS 2 node that subscribes to /zed_multi/myzed2i/depth/depth_registered and records a .csv file with timestamps and .avi video recording of the published frames

**rgb_recorder_component** (C++)

A ROS 2 node that subscribes to /zed_multi/myzed2i/rgb/image_rect_color and records a .csv file with timestamps and .avi video recording of the published frames

**zed_wrapper, depth_recorder_component and rgb_recorder_component are in the one component zed_multi for using interprocess memory** 

# Prerequisites
Ubuntu 22.04 LTS

ROS 2 Jazzy (or higher)

Python 3.12 with:

rclpy

pupil_labs.realtime_api

pyzed.sl

opencv-python

PyQt5
 

Ensure your $PYTHONPATH includes your ROS 2 venv.


**To start a Pupil labs wrapper** - that search for device and publishes data:
cd ~/colcon_venv

source venv/bin/activate

source /opt/ros/jazzy/setup.bash

export PYTHONPATH=/home/olhamelnyk/colcon_venv/venv/lib/python3.12/site-packages:$PYTHONPATH

source install/setup.bash

ros2 run async_pupil_wrapper async_pupil_wrapper


Lifehack: when the pupil wrapper does not find the glasses - go to the monitor website: 
http://pi.local:8080/

**To start recording scene** - that writes the video from a topic pupil_labs/scene/img_raw to avi and csv files (for timestamps of the frames) after request to the service record_pupil_scene: (run in different terminal)
source install/setup.bash
ros2 run recording_scene recording_scene

**To start recording gaze** - that writes the coordinates of the gaze with timestamps to csv after requesting the service record_pupil_gaze: (run in different terminal)

source install/setup.bash

ros2 run recording_gaze recording_gaze

**Testing:** To test the recording of pupil labs components:
Start recording:

ros2 service call /record_pupil_gaze std_srvs/srv/SetBool '{data: true}'

ros2 service call /record_pupil_scene std_srvs/srv/SetBool '{data: true}'

Stop recording:

ros2 service call /record_pupil_gaze std_srvs/srv/SetBool '{data: false}'

ros2 service call /record_pupil_scene std_srvs/srv/SetBool '{data: false}'

**To start the ZED wrapper and all its recording components**

source install/setup.bash

ros2 launch zed_ipc zed_ipc.launch.py cam_names:=[myzed2i] cam_models:=[zed2i] cam_serials:=[37866365] cam_ids:=[0]

**Testing:** to test if the recordings for ZED are working:

Start recording:

ros2 service call /zed_multi/record_zed_rgb std_srvs/srv/SetBool '{data: true}'

ros2 service call /zed_multi/record_zed_depth std_srvs/srv/SetBool '{data: true}'

Stop recording:

ros2 service call /zed_multi/record_zed_rgb std_srvs/srv/SetBool '{data: false}'

ros2 service call /zed_multi/record_zed_depth std_srvs/srv/SetBool '{data: false}'

**To start a controller that starts recordings for Zed and Pupil - recording initializer:**

source install/setup.bash

ros2 run recording_controller_pkg controller_node



When Updated don't forget to build in new Terminal:
colcon build --symlink-install
