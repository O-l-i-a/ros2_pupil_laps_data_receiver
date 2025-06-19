import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CompressedImage
from cv_bridge import CvBridge, CvBridgeError
import pyzed.sl as sl
from rclpy.qos import QoSProfile, HistoryPolicy, ReliabilityPolicy, DurabilityPolicy
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
import threading
import time


class ZedWrapperNode(Node):
    """ZED‑2/2i/2X wrapper that **grabs exactly once per frame** and then publishes
    RGB **and** depth topics at the *same* 60 Hz using two separate threads /
    callback‑groups.  The workflow is:

    1. A dedicated Python thread (`self._capture_thread`) performs
       `zed.grab()` at 60 Hz, retrieves both colour *and* depth from that same
       grab, and stores the numpy arrays in shared variables.
    2. Two `rclpy` timers – one for RGB, one for depth – each run in their own
       `ReentrantCallbackGroup` so the MultiThreadedExecutor gives them their
       own OS thread.  They simply take the most‑recent frame and publish it.

    Thanks to the shared grab, both topics carry frames with identical
    timestamps → perfect synchronisation without redundant camera access.
    """

    TARGET_FPS = 60.0

    def __init__(self, args=None):
        super().__init__('zed_wrapper_node')
        self.bridge = CvBridge()

        # QoS profile (tune depth if you need larger buffer)
        qos = QoSProfile(
            depth=2,
            history=HistoryPolicy.KEEP_LAST,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
        )

        # Independent callback‑groups for concurrent publishing
        self.cb_group_color = ReentrantCallbackGroup()
        self.cb_group_depth = ReentrantCallbackGroup()

        # ROS2 publishers
        self.color_pub = self.create_publisher(
            CompressedImage,
            'zed/color/image_raw/compressed',
            qos,
            callback_group=self.cb_group_color,
        )
        self.depth_pub = self.create_publisher(
            Image,
            'zed/depth/image_raw',
            qos,
            callback_group=self.cb_group_depth,
        )

        # ZED initialisation
        init_params = sl.InitParameters()
        init_params.camera_resolution = sl.RESOLUTION.HD720
        init_params.camera_fps = int(self.TARGET_FPS)  # enforce 60 Hz sensor rate
        init_params.depth_mode = sl.DEPTH_MODE.NEURAL  # fast, accurate enough
        init_params.coordinate_units = sl.UNIT.METER

        self.zed = sl.Camera()
        if self.zed.open(init_params) != sl.ERROR_CODE.SUCCESS:
            self.get_logger().error('Failed to open ZED camera')
            rclpy.shutdown()
            return

        # Shared state guarded by a mutex
        self._lock = threading.Lock()
        self._latest_color = None  # numpy array   (BGRA)
        self._latest_depth = None  # numpy array   (float32 depth in m)
        self._latest_stamp = None  # rclpy Time

        # Start capture thread (daemon so it ends with the process)
        self._running = True
        self._capture_thread = threading.Thread(
            target=self._capture_loop, daemon=True
        )
        self._capture_thread.start()

        # 60 Hz publishing timers
        self.create_timer(1.0 / self.TARGET_FPS, self._publish_color, callback_group=self.cb_group_color)
        self.create_timer(1.0 / self.TARGET_FPS, self._publish_depth, callback_group=self.cb_group_depth)

    # ---------------------------------------------------------------------
    # Capture loop (separate Python thread)
    # ---------------------------------------------------------------------

    def _capture_loop(self):
        period = 1.0 / self.TARGET_FPS
        while rclpy.ok() and self._running:

            if self.zed.grab() == sl.ERROR_CODE.SUCCESS:
                timestamp  = self.get_clock().now()
                mat_color = sl.Mat()
                mat_depth = sl.Mat()

                # Both pulled from the SAME grab
                self.zed.retrieve_image(mat_color, sl.VIEW.LEFT)
                self.zed.retrieve_measure(mat_depth, sl.MEASURE.DEPTH)

                with self._lock:
                    self._latest_color = mat_color.get_data().copy()
                    self._latest_depth = mat_depth.get_data().copy()
                    self._latest_stamp = timestamp
            else:
                self.get_logger().warning('ZED: grab() failed – skipping frame')

            # Simple sleep to match TARGET_FPS (use time‑budget left)
            #elapsed = time.time() - start_t
            #remaining = period - elapsed
            #if remaining > 0:
            #    time.sleep(remaining)

    # ---------------------------------------------------------------------
    # Publishing callbacks (run in executor threads)
    # ---------------------------------------------------------------------

    def _publish_color(self):
        with self._lock:
            if self._latest_color is None:
                return  # not ready yet
            color_img = self._latest_color.copy()
            stamp = self._latest_stamp

        try:
            msg = self.bridge.cv2_to_compressed_imgmsg(color_img, dst_format='jpeg')
        except CvBridgeError as e:
            self.get_logger().error(f'RGB CvBridge error: {e}')
            return

        msg.header.stamp = stamp.to_msg()
        msg.header.frame_id = 'zed_camera'
        self.color_pub.publish(msg)

    def _publish_depth(self):
        with self._lock:
            if self._latest_depth is None:
                return  # not ready yet
            depth_img = self._latest_depth.copy()
            stamp = self._latest_stamp

        try:
            msg = self.bridge.cv2_to_imgmsg(depth_img, encoding='32FC1')
        except CvBridgeError as e:
            self.get_logger().error(f'Depth CvBridge error: {e}')
            return

        msg.header.stamp = stamp.to_msg()
        msg.header.frame_id = 'zed_camera'
        self.depth_pub.publish(msg)

    # ---------------------------------------------------------------------

    def destroy_node(self):
        self._running = False
        if self._capture_thread.is_alive():
            self._capture_thread.join(timeout=1.0)
        self.zed.close()
        super().destroy_node()


# -------------------------------------------------------------------------
# Main entrypoint
# -------------------------------------------------------------------------

def main(args=None):
    rclpy.init(args=args)
    node = ZedWrapperNode()
    executor = MultiThreadedExecutor()
    executor.add_node(node)

    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
