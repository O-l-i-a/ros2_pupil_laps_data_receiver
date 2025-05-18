#!/usr/bin/env python3
import contextlib, csv, pathlib, cv2, rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, DurabilityPolicy, ReliabilityPolicy, qos_profile_sensor_data
from std_msgs.msg import Bool
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
from message_filters import Subscriber, ApproximateTimeSynchronizer
from egocentric_msg.msg import GazeData

LATCH_QOS = QoSProfile(
    depth=1,
    reliability=ReliabilityPolicy.RELIABLE,
    durability=DurabilityPolicy.TRANSIENT_LOCAL)

class GazeVideoRecorder(Node):
    def __init__(self):
        super().__init__("gaze_video_recorder")

        # ---------- Parameter & Dateien -----------------------------------
        self.declare_parameter("out_dir", "recording")
        self.declare_parameter("fps", 30.0)
        self.out_dir = pathlib.Path(self.get_parameter("out_dir").value)
        self.out_dir.mkdir(parents=True, exist_ok=True)
        self.fps = float(self.get_parameter("fps").value)

        self.bridge = CvBridge()
        self.video  = None
        self.csv    = open(self.out_dir / "gaze_log.csv", "w", newline="")
        self.writer = csv.writer(self.csv)
        self.writer.writerow(["frame_idx", "sec", "nsec", "gaze_x_px", "gaze_y_px"])
        self.frame_idx = 0
        self.recording = False                     # wird im _state_cb gesetzt

        # ---------- Status-Topic abonnieren --------------------------------
        self.create_subscription(
            Bool, "recording_state", self._state_cb, qos_profile=LATCH_QOS)

        # ---------- Scene + Gaze Subscriber --------------------------------
        img_sub  = Subscriber(self, Image, "/pupil_labs/scene_img", qos_profile=qos_profile_sensor_data)
        gaze_sub = Subscriber(self, GazeData, "/pupil_labs/gaze", qos_profile=qos_profile_sensor_data)
        self.sync = ApproximateTimeSynchronizer([img_sub, gaze_sub], queue_size=60, slop=0.05)
        self.sync.registerCallback(self._sync_cb)

    # -------------------------- Status-Callback ---------------------------
    def _state_cb(self, msg: Bool):
        self.recording = bool(msg.data)
        self.get_logger().info(f"Recording flag set to {self.recording}")

        if not self.recording:
            self._stop_local()                     # schließt Video/CSV

    # -------------------------- Sync-Callback -----------------------------
    def _sync_cb(self, img: Image, gaze: GazeData):
        self.get_logger().debug(
            f"SYNC  rec={self.recording}  img=({img.width}×{img.height}, data={len(img.data)})")
        if not self.recording:
            return                                # Stand-by

        if not img.data or img.width == 0 or img.height == 0:
            self.get_logger().warning("Empty image skipped")
            return

        # VideoWriter bei erstem gültigen Frame anlegen
        if self.video is None:
            fourcc = cv2.VideoWriter_fourcc(*"mp4v")
            self.video = cv2.VideoWriter(
                str(self.out_dir / "scene.mp4"), fourcc, self.fps, (img.width, img.height))
            if not self.video.isOpened():
                self.get_logger().error("VideoWriter open failed – CSV only")
                self.recording = False
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
        self.writer.writerow([self.frame_idx,
                              img.header.stamp.sec,
                              img.header.stamp.nanosec,
                              gaze.x, gaze.y])
        self.frame_idx += 1

    # -------------------------- Aufräumen ---------------------------------
    def _stop_local(self):
        if self.video:
            print("before release")
            self.video.release()
            print("after release")

            self.video = None
        self.csv.flush()

    def destroy_node(self):
        self._stop_local()
        super().destroy_node()

# -------------------------- main ------------------------------------------
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
