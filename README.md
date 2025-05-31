# Recording Suite for ZED 2i & Pupil Labs
This workspace provides tools to synchronize and record data from:

Pupil Labs eye-tracking hardware (scene video + gaze data)

Stereolabs ZED 2i stereo camera (SVO recording)

SVO-converter (Converting SVO to mp4 or png for eachh frame)


# It includes:

pupil_labs_wrapper (inspired by https://github.com/UW-CTRL/pupil_labs_ros2_wrapper)
A ROS 2 node that discovers a Pupil Labs device, publishes:

/pupil_labs/scene_img (sensor_msgs/Image @ 30 Hz)

/pupil_labs/gaze (egocentric_msg/GazeData @ 30 Hz)
…and exposes a /record service (std_srvs/SetBool) to start/stop on-disk recording of both streams (MP4 + CSV).

recording_controller_pkg
A PyQt5 GUI that calls:

/record on the Pupil wrapper

/zed/zed_node/start_svo_rec and /zed/zed_node/stop_svo_rec on the ZED wrapper
…so both devices start/stop together, into a timestamped session folder (SVO + CSV).

zed_svo_convertor.py (adapted from https://github.com/stereolabs/zed-sdk/tree/master/recording)
A standalone Python script that reads an .svo or .svo2 file, extracts per‐frame timestamps into a CSV, and either:

Builds a side-by-side MP4 (LEFT+RIGHT or LEFT+DEPTH)

Or outputs per-frame PNGs


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


To start a Pupillabs wrapper - that search for device:
cd ~/colcon_venv

#Virtuelles Environment aktivieren
source venv/bin/activate

#ROS 2 Umgebung aktivieren
source /opt/ros/jazzy/setup.bash
export PYTHONPATH=/home/olhamelnyk/colcon_venv/venv/lib/python3.12/site-packages:$PYTHONPATH

#ROS 2 Workspace Umgebung aktivieren
source install/setup.bash

#Jetzt das Node starten
ros2 run pupil_labs_wrapper wrapper
Lifehack: when the pupil wrapper does not find the glasses - go to the monitor website: 
http://pi.local:8080/

To start the ZEd wrapper that connected to camera:
source install/setup.bash
ros2 launch zed_wrapper zed_camera.launch.py camera_model:=zed2i 

To start a controller that starts recordings for Zed and Pupil - recording initializer:
source install/setup.bash
ros2 run recording_controller_pkg controller_node

To convert the svo file to mp4

cd ~/colcon_venv/
#Virtuelles Environment aktivieren
source venv/bin/activate
cd src/testing_realtime_api
#den convertor ausführen - dafür die richtige paramter auch machen
python3 zed_svo_convertor.py \
  --mode 1 \
  --input_svo_file /home/olhamelnyk/colcon_venv/recordings/recording_1748287204/rec_1748287204.svo2 \
  --output_mp4_file /home/olhamelnyk/colcon_venv/recordings/recording_1748287204/rec_1748287204_converted.mp4 \
  --output_path_dir /home/olhamelnyk/colcon_venv/recordings/recording_1748287204


Arguments:
--mode Mode 0 is to export LEFT+RIGHT AVI.
Mode 1 is to export LEFT+DEPTH_VIEW Avi.
Mode 2 is to export LEFT+RIGHT image sequence.
Mode 3 is to export LEFT+DEPTH_View image sequence.
Mode 4 is to export LEFT+DEPTH_16BIT image sequence.
--input_svo_file Path to an existing .svo file
--output_avi_file Path to a .avi file that will be created
--output_path_dir Path to an existing folder where .png and csv will be saved

Hints:
The recording of Zed starts ~1 second after Pupil Invisible
All system use the ROS Time:
in Pupil Labs wrapper I call self.get_clock().now() when the start file recording 
in Zed i set parameters:
use_svo_timestamps: false # Use the SVO timestamps to publish data. If false, data will be published at the system time. (I assume the system Time is ROS - it looks like that)
publish_svo_clock: false # [overwritten by launch file options] When use_svo_timestamps is true allows to publish the SVO clock to the `/clock` topic. This is useful for synchronous rosbag playback.

When Updated dont forget to build in neuen Terminal:
colcon build 