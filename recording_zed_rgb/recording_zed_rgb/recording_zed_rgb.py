import rclpy
from rclpy.node import Node
from cv_bridge import CvBridge
from sensor_msgs.msg import Image, CompressedImage
from std_srvs.srv import SetBool
import cv2
import csv
import os
import threading
import queue
from rclpy.qos import QoSProfile, HistoryPolicy, ReliabilityPolicy
from rclpy.executors import MultiThreadedExecutor


class RGBRecorder(Node):
    def __init__(self):
        super().__init__('rgb_recorder')
        self.get_logger().info('RGBRecorder has been started!')

        # Producer-Consumer queue for frames
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
            CompressedImage,
            'zed/color/image_raw',
            self.listener_callback,
            qos  # QoS depth
        )
        self.create_service(SetBool, 'record_zed_rgb', self._srv_cb)

        # Members for recording
        self.bridge = CvBridge()
        self.video_writer = None
        self.csv_writer = None
        self.csv_file = None
        self.frame_width = 1280#1280
        self.frame_height = 720#720
        self.fps = 50.0
        self.fourcc = cv2.VideoWriter_fourcc(*'XVID')
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
        if not self.recording or self.video_writer is None:
            return
        try:
            # Convert image and enqueue for writing
            cv_image = self.bridge.compressed_imgmsg_to_cv2(msg, desired_encoding='bgr8')
            self.frame_queue.put((cv_image, msg.header.stamp), block=False)
        except queue.Full:
            self.get_logger().warn('Frame queue is full, dropping frame')
        except Exception as e:
            self.get_logger().error(f'Failed to enqueue frame: {e}')

    def _writer_loop(self):
        while rclpy.ok():
            try:
                cv_image, stamp = self.frame_queue.get()
                # Write video frame
                self.video_writer.write(cv_image)
                # Record timestamp
                self.csv_writer.writerow([stamp.sec, stamp.nanosec])
                self.frame_queue.task_done()
            except Exception as e:
                self.get_logger().error(f'Writer loop error: {e}')

    def _start_file_recording(self):
        ts = self.get_clock().now().to_msg()
        prefix = f"{ts.sec}"
        base_dir = 'recordings'
        session_dir = os.path.join(base_dir, f"recording_{ts.sec}")
        os.makedirs(session_dir, exist_ok=True)

        # Open video writer
        video_path = os.path.join(session_dir, f"{prefix}_rgb.avi")
        self.video_writer = cv2.VideoWriter(
            video_path,
            self.fourcc,
            self.fps,
            (self.frame_width, self.frame_height)
        )

        # Open CSV file for timestamps
        csv_path = os.path.join(session_dir, f"{prefix}_rgb_times.csv")
        self.csv_file = open(csv_path, 'w', newline='')
        self.csv_writer = csv.writer(self.csv_file)
        self.csv_writer.writerow(['sec', 'nanosec'])

        self.get_logger().info(f'Started RGB recording: {video_path}')

    def _stop_file_recording(self):
        # Wait until all queued frames are written
        self.get_logger().info('Stopping RGB recording, waiting for queue to empty...')
        self.frame_queue.join()

        # Release resources
        if self.video_writer:
            self.video_writer.release()
            self.video_writer = None
        if self.csv_file:
            self.csv_file.close()
            self.csv_file = None

        self.get_logger().info('RGB recording stopped and files closed.')


def main(args=None):
    rclpy.init(args=args)
    node = RGBRecorder()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
