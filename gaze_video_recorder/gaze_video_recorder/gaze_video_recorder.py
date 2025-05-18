#!/usr/bin/env python3
"""gaze_video_recorder.py – Topic‑gesteuerte Aufnahme (sync API‑Call)

Version **fix_async**
---------------------
* Entfernt `asyncio`‑Verwendung für die Pupil‑Realtime‑API, weil `Device()`
  im neues SDK blocking ist und intern `asyncio.run()` nutzt – das kollidierte
  mit unserem eigenen Event‑Loop.
* Stattdessen wird der API‑Call in einem separaten **ThreadPoolExecutor**
  ausgeführt → keine Blockade des ROS‑Threads und keine Loop‑Konflikte.
* `pupil_port` als Parameter wählbar (Default 8080).
* Scene‑ und Gaze‑Subscriber nutzen wieder `qos_profile_sensor_data` – Topic‑Befehle
  (`/record_cmd`, `/recording_state`) bleiben latched.

CLI‑Beispiel
------------
```bash
ros2 run gaze_video_recorder gaze_video_recorder \
        --ros-args -p out_dir:=run1 -p fps:=60.0 \
                   -p pupil_host:=192.168.4.1 -p pupil_port:=8080

# ▶ Start
ros2 topic pub /record_cmd std_msgs/Bool "data: true" --once
# ■ Stop
ros2 topic pub /record_cmd std_msgs/Bool "data: false" --once
```
"""
import contextlib
import csv
import pathlib
import threading
from concurrent.futures import ThreadPoolExecutor

import cv2
import rclpy
from cv_bridge import CvBridge, CvBridgeError
from message_filters import ApproximateTimeSynchronizer, Subscriber
from pupil_labs.realtime_api.simple import Device
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, QoSProfile, ReliabilityPolicy, qos_profile_sensor_data
from sensor_msgs.msg import Image
from std_msgs.msg import Bool

from egocentric_msg.msg import GazeData

# QoS für latched Topics
LATCH_QOS = QoSProfile(
    depth=1,
    reliability=ReliabilityPolicy.RELIABLE,
    durability=DurabilityPolicy.TRANSIENT_LOCAL,
)


class GazeVideoRecorder(Node):
    def __init__(self) -> None:
        super().__init__("gaze_video_recorder")

        # -------------------------------------------------- Parameter -----
        self.declare_parameter("out_dir", "recording")
        self.declare_parameter("fps", 30.0)
        self.declare_parameter("pupil_host", "192.168.4.1")
        self.declare_parameter("pupil_port", 8080)

        self.out_dir = pathlib.Path(self.get_parameter("out_dir").value)
        self.out_dir.mkdir(parents=True, exist_ok=True)
        self.fps         = float(self.get_parameter("fps").value)
        self.pupil_host  = str(self.get_parameter("pupil_host").value)
        self.pupil_port  = int(self.get_parameter("pupil_port").value)

        # -------------------------------------------------- I/O ----------
        self.bridge: CvBridge = CvBridge()
        self.video: cv2.VideoWriter | None = None
        self.csv_file = open(self.out_dir / "gaze_log.csv", "w", newline="")
        self.writer = csv.writer(self.csv_file)
        self.writer.writerow([
            "frame_idx", "sec", "nsec", "gaze_x_px", "gaze_y_px"
        ])
        self.frame_idx = 0
        self.recording = False

        # Executor für API‑Calls
        self.api_pool = ThreadPoolExecutor(max_workers=1)

        # -------------------------------------------------- Topics --------
        self.state_pub = self.create_publisher(Bool, "recording_state", LATCH_QOS)
        self.state_pub.publish(Bool(data=False))  # initial

        self.create_subscription(Bool, "record_cmd", self._cmd_cb, qos_profile=LATCH_QOS)

        img_sub  = Subscriber(self, Image, "/pupil_labs/scene_img", qos_profile=qos_profile_sensor_data)
        gaze_sub = Subscriber(self, GazeData, "/pupil_labs/gaze", qos_profile=qos_profile_sensor_data)
        self.sync = ApproximateTimeSynchronizer([img_sub, gaze_sub], 30, 0.05)
        self.sync.registerCallback(self._sync_cb)

    # -------------------------------------------------- cmd Topic --------
    def _cmd_cb(self, msg: Bool):
        want_start = bool(msg.data)
        if want_start == self.recording:
            return  # kein Zustandswechsel

        # API‑Call blockierend in separatem Thread
        self.api_pool.submit(self._pupil_cmd_sync, want_start)

        if want_start:
            self.recording = True
            self.get_logger().info("Recording STARTED")
        else:
            self._stop_local()
            self.recording = False
            self.get_logger().info("Recording STOPPED")

        self.state_pub.publish(Bool(data=self.recording))

    # -------------------------------------------------- Pupil API --------
    def _pupil_cmd_sync(self, start: bool):
        try:
            with Device(self.pupil_host, self.pupil_port) as dev:
                if start:
                    dev.recording_start(session_name="ros2_session")
                else:
                    dev.recording_stop()
        except Exception as e:
            self.get_logger().error(f"Pupil‑API error: {e}")

    # -------------------------------------------------- Scene/Gaze -------
    def _sync_cb(self, img: Image, gaze: GazeData):
        self.get_logger().info(f"CB fired. idx={self.frame_idx} img {img.width}×{img.height}")
        if not self.recording:
            return
        if not img.data or img.height == 0 or img.width == 0:
            self.get_logger().warning("Empty image – skipped")
            return

        if self.video is None:
            fourcc = cv2.VideoWriter_fourcc(*"mp4v")
            self.video = cv2.VideoWriter(str(self.out_dir / "scene.mp4"), fourcc, self.fps, (img.width, img.height))
            if not self.video.isOpened():
                self.get_logger().error("VideoWriter open failed – CSV only")
                self.recording = False
                self.state_pub.publish(Bool(data=False))
                return

        try:
            frame = self.bridge.imgmsg_to_cv2(img, desired_encoding=img.encoding)
        except CvBridgeError:
            try:
                frame = self.bridge.imgmsg_to_cv2(img, desired_encoding="bgr8")
            except CvBridgeError as e:
                self.get_logger().warning(f"cv_bridge: {e}")
                return

        self.video.write(frame)
        self.writer.writerow([
            self.frame_idx,
            img.header.stamp.sec,
            img.header.stamp.nanosec,
            gaze.x,
            gaze.y,
        ])
        self.frame_idx += 1

    # -------------------------------------------------- Helpers ----------
    def _stop_local(self):
        if self.video:
            print("before release")
            self.video.release()
            print("after release")

            self.video = None
        self.csv_file.flush()

    def destroy_node(self):
        self._stop_local()
        self.api_pool.shutdown(wait=False)
        super().destroy_node()


# ============================================================= main =====

def main(args=None):
    rclpy.init(args=args)
    node = GazeVideoRecorder()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        with contextlib.suppress(Exception):
            rclpy.shutdown()
        node.destroy_node()


if __name__ == "__main__":
    main()
