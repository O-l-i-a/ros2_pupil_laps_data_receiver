import rclpy
from rclpy.node import Node
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from cv_bridge import CvBridge
from sensor_msgs.msg import Image, CompressedImage
from std_srvs.srv import SetBool
import cv2
import csv
import os
import threading
import queue
from rclpy.qos import QoSProfile, HistoryPolicy, ReliabilityPolicy


class CombinedRecorder(Node):
    def __init__(self):
        # Enable intra-process comms for zero-copy between pub/sub in this node
        super().__init__('combined_recorder')
        self.get_logger().info('CombinedRecorder has been started!')

        # Queues and writer threads for RGB and Depth
        self.rgb_queue = queue.Queue(maxsize=500)
        self.depth_queue = queue.Queue(maxsize=500)
        threading.Thread(target=self._rgb_writer_loop, daemon=True).start()
        threading.Thread(target=self._depth_writer_loop, daemon=True).start()

        # Bridge for image conversions
        self.bridge = CvBridge()

        # Recording state and resources
        self.recording = False
        self.session_dir = None
        self.rgb_writer = None
        self.depth_writer = None
        self.rgb_csv = None
        self.depth_csv = None

        # Video parameters
        self.rgb_width = 1280
        self.rgb_height = 720
        self.depth_width = 1280
        self.depth_height = 720
        self.fps = 50.0
        self.rgb_fourcc = cv2.VideoWriter_fourcc(*'XVID')
        self.depth_fourcc = cv2.VideoWriter_fourcc(*'MJPG')

        # QoS
        qos = QoSProfile(
            depth=30,
            history=HistoryPolicy.KEEP_LAST,
            reliability=ReliabilityPolicy.BEST_EFFORT,
        )
        # Callback group for concurrent callbacks
        cbg = ReentrantCallbackGroup()

        # RGB subscription (compressed image)
        self.create_subscription(
            CompressedImage,
            '/zed/zed_node/left/image_rect_color/compressed',
            self._rgb_cb,
            qos,
            callback_group=cbg
        )
        # Depth subscription (raw image)
        self.create_subscription(
            Image,
            '/zed/zed_node/depth/depth_registered',
            self._depth_cb,
            qos,
            callback_group=cbg
        )
        # Single service to start/stop both recordings
        self.create_service(
            SetBool,
            'record_zed_both',
            self._srv_cb,
            callback_group=cbg
        )

    def _srv_cb(self, req, resp):
        # Start or stop combined recording
        want = bool(req.data)
        if want == self.recording:
            resp.success = False
            resp.message = 'No change'
            return resp

        if want:
            self._start_recording()
            self.recording = True
            resp.message = 'Recording started'
        else:
            self.recording = False
            self._stop_recording()
            resp.message = 'Recording stopped'

        self.recording = want
        resp.success = True
        return resp

    def _start_recording(self):
        # Create session directory with timestamp
        ts = self.get_clock().now().to_msg().sec
        self.session_dir = os.path.join('recordings', f'recording_{ts}')
        os.makedirs(self.session_dir, exist_ok=True)

        # RGB video writer and CSV
        rgb_path = os.path.join(self.session_dir, f'{ts}_rgb.avi')
        self.rgb_writer = cv2.VideoWriter(
            rgb_path, self.rgb_fourcc, self.fps,
            (self.rgb_width, self.rgb_height)
        )
        rgb_csv_path = os.path.join(self.session_dir, f'{ts}_rgb_times.csv')
        self.rgb_csv = open(rgb_csv_path, 'w', newline='')
        self.rgb_csv_writer = csv.writer(self.rgb_csv)
        self.rgb_csv_writer.writerow(['sec', 'nanosec'])
        self.get_logger().info(f'Started RGB recording: {rgb_path}')

        # Depth video writer and CSV
        depth_path = os.path.join(self.session_dir, f'{ts}_depth.avi')
        self.depth_writer = cv2.VideoWriter(
            depth_path, self.depth_fourcc, self.fps,
            (self.depth_width, self.depth_height), isColor=False
        )
        depth_csv_path = os.path.join(self.session_dir, f'{ts}_depth_times.csv')
        self.depth_csv = open(depth_csv_path, 'w', newline='')
        self.depth_csv_writer = csv.writer(self.depth_csv)
        self.depth_csv_writer.writerow(['sec', 'nanosec'])
        self.get_logger().info(f'Started Depth recording: {depth_path}')

    def _stop_recording(self):
        # Wait for queues to empty
        self.get_logger().info('Stopping recording, waiting for queues...')
        self.rgb_queue.join()
        self.depth_queue.join()
        # Release writers and CSVs
        if self.rgb_writer:
            self.rgb_writer.release()
            self.rgb_writer = None
        if self.rgb_csv:
            self.rgb_csv.close()
            self.rgb_csv = None
        if self.depth_writer:
            self.depth_writer.release()
            self.depth_writer = None
        if self.depth_csv:
            self.depth_csv.close()
            self.depth_csv = None
        self.get_logger().info('Recording stopped and resources released.')

    def _rgb_cb(self, msg: CompressedImage):
        if not self.recording or not self.rgb_writer:
            return
        try:
            # Decode compressed image
            cv_img = self.bridge.compressed_imgmsg_to_cv2(msg, desired_encoding='bgr8')
            self.rgb_queue.put((cv_img, msg.header.stamp), block=False)
        except queue.Full:
            self.get_logger().warn('RGB queue full, dropping frame')
        except Exception as e:
            self.get_logger().error(f'RGB enqueue error: {e}')

    def _depth_cb(self, msg: Image):
        if not self.recording or not self.depth_writer:
            return
        try:
            depth_f32 = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
            self.depth_queue.put((depth_f32, msg.header.stamp), block=False)
        except queue.Full:
            self.get_logger().warn('Depth queue full, dropping frame')
        except Exception as e:
            self.get_logger().error(f'Depth enqueue error: {e}')

    def _rgb_writer_loop(self):
        while rclpy.ok():
            try:
                img, stamp = self.rgb_queue.get()
                self.rgb_writer.write(img)
                self.rgb_csv_writer.writerow([stamp.sec, stamp.nanosec])
                self.rgb_queue.task_done()
            except Exception as e:
                self.get_logger().error(f'RGB writer error: {e}')

    def _depth_writer_loop(self):
        while rclpy.ok():
            try:
                depth_f32, stamp = self.depth_queue.get()
                # Normalize to 8-bit for video
                depth_u8 = cv2.normalize(
                    depth_f32, None, 0, 255,
                    cv2.NORM_MINMAX, cv2.CV_8U
                )
                self.depth_writer.write(depth_u8)
                self.depth_csv_writer.writerow([stamp.sec, stamp.nanosec])
                self.depth_queue.task_done()
            except Exception as e:
                self.get_logger().error(f'Depth writer error: {e}')


def main(args=None):
    rclpy.init(args=args)
    # Enable intra-process comms for zero-copy
    
    node = CombinedRecorder()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    executor.spin()
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
