import rclpy
from rclpy.node import Node
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from std_srvs.srv import SetBool
import cv2
import csv
import os
import threading
import queue
from rclpy.qos import QoSProfile, HistoryPolicy, ReliabilityPolicy
from rclpy.executors import MultiThreadedExecutor


class DepthRecorder(Node):
    def __init__(self):
        super().__init__('DepthRecorder')
        self.get_logger().info('DepthRecorder has been started!')

        # Initialize queue and writer thread
        self.frame_queue = queue.Queue(maxsize=100)
        self.writer_thread = threading.Thread(target=self._writer_loop, daemon=True)
        self.writer_thread.start()
        qos = QoSProfile(
            depth=10,
            history=HistoryPolicy.KEEP_LAST,
            reliability=ReliabilityPolicy.RELIABLE,
        )
        # Subscription and service
        self.subscription = self.create_subscription(
            Image,
            '/zed/zed_node/depth/depth_registered',
            self.listener_callback,
            qos
        )
        self.create_service(SetBool, 'record_zed_depth', self._srv_cb)

        # Members for recording
        self.bridge = CvBridge()
        self.video_writer = None
        self.csv_writer = None
        self.csv_file = None
        self.frame_width = 1280#1280
        self.frame_height = 720#720
        self.fps = 58.0
        self.fourcc = cv2.VideoWriter_fourcc(*'MJPG')
        self.recording = False

    def _srv_cb(self, req, resp):
        want_start = bool(req.data)
        if want_start == self.recording:
            resp.success = False
            resp.message = 'No change'
            return resp

        if want_start:
            self._start_file_recording()
        else:
            self._stop_file_recording()

        self.recording = want_start
        resp.success = True
        resp.message = 'started' if want_start else 'stopped'
        return resp

    def listener_callback(self, msg):
        if not self.recording:
            return
        try:
            # Quickly convert and enqueue
            depth_f32 = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
            self.frame_queue.put((depth_f32, msg.header.stamp), block=False)
        except queue.Full:
            self.get_logger().warn('Frame queue is full, dropping frame')
        except Exception as e:
            self.get_logger().error(f'Failed to enqueue frame: {e}')

    def _writer_loop(self):
        while rclpy.ok():
            try:
                depth_f32, stamp = self.frame_queue.get()
                # Normalize and write
                depth_u8 = cv2.normalize(
                    depth_f32, None,
                    alpha=0, beta=255,
                    norm_type=cv2.NORM_MINMAX,
                    dtype=cv2.CV_8U
                )
                self.video_writer.write(depth_u8)
                self.csv_writer.writerow([stamp.sec, stamp.nanosec])
                h, w = depth_u8.shape
                #self.get_logger().info(f'Wrote gray frame at {w}×{h}')
                self.frame_queue.task_done()
            except Exception as e:
                self.get_logger().error(f'Writer loop error: {e}')

    def _start_file_recording(self):
        ts = self.get_clock().now().to_msg()
        prefix = f"{ts.sec}"
        base_dir = 'recordings'
        session_dir = os.path.join(base_dir, f"recording_{ts.sec}")
        os.makedirs(session_dir, exist_ok=True)

        video_path = os.path.join(session_dir, f"{prefix}_depth.avi")
        self.video_writer = cv2.VideoWriter(
            video_path, self.fourcc, self.fps,
            (self.frame_width, self.frame_height), isColor=False
        )

        csv_path = os.path.join(session_dir, f"{prefix}_depth_times.csv")
        self.csv_file = open(csv_path, 'w', newline='')
        self.csv_writer = csv.writer(self.csv_file)
        self.csv_writer.writerow(['sec','nanosec'])
        self.get_logger().info(f'Started recording: {video_path}')

    def _stop_file_recording(self):
        # Wait until all frames are written
        self.get_logger().info('Stopping recording, waiting for queue to empty...')
        self.frame_queue.join()
        # Release video writer and CSV
        if self.video_writer:
            self.video_writer.release()
            self.video_writer = None
        if self.csv_file:
            self.csv_file.close()
            self.csv_file = None
        self.get_logger().info('Recording stopped and files closed.')


def main(args=None):
    rclpy.init(args=args)
    node = DepthRecorder()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
