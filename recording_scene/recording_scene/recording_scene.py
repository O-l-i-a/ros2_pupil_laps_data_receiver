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

class MyNode(Node):
    def __init__(self):
        super().__init__('my_node')
        self.get_logger().info('MyNode has been started!')

        # Producer-Consumer queue for frames
        self.frame_queue = queue.Queue(maxsize=200)
        self.writer_thread = threading.Thread(target=self._writer_loop, daemon=True)
        self.writer_thread.start()

        # Subscription and service
        self.subscription = self.create_subscription(
            Image,
            '/pupil/scene/image_raw',
            self.listener_callback,
            15
        )
        self.create_service(SetBool, 'record_pupil_scene', self._srv_cb)

        # Members for recording
        self.bridge = CvBridge()
        self.video_writer = None
        self.csv_writer = None
        self.csv_file = None
        self.frame_width = 1088  # Replace with actual width
        self.frame_height = 1080  # Replace with actual height
        self.fps = 30.0
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
            # Convert image and enqueue for writing
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
            self.frame_queue.put((cv_image, msg.header.stamp), block=False)
        except queue.Full:
            self.get_logger().warn('Frame queue is full, dropping frame')
        except Exception as e:
            self.get_logger().error(f'Failed to enqueue frame: {e}')

    def _writer_loop(self):
        while rclpy.ok():
            try:
                cv_image, stamp = self.frame_queue.get()
                # Write video frame and CSV timestamp
                self.video_writer.write(cv_image)
                self.csv_writer.writerow([stamp.sec, stamp.nanosec])
                h, w = cv_image.shape[:2]
                #self.get_logger().info(f'Wrote frame at {w}×{h}')
                self.frame_queue.task_done()
            except Exception as e:
                self.get_logger().error(f'Writer loop error: {e}')

    def _start_file_recording(self):
        ts = self.get_clock().now().to_msg()
        prefix = f"{ts.sec}"
        base_dir = 'recordings'
        session_dir = os.path.join(base_dir, f"recording_{ts.sec}")
        os.makedirs(session_dir, exist_ok=True)

        video_path = os.path.join(session_dir, f"{prefix}_scene.avi")
        self.video_writer = cv2.VideoWriter(
            video_path, self.fourcc, self.fps,
            (self.frame_width, self.frame_height)
        )

        csv_path = os.path.join(session_dir, f"{prefix}_scene_times.csv")
        self.csv_file = open(csv_path, 'w', newline='')
        self.csv_writer = csv.writer(self.csv_file)
        self.csv_writer.writerow(['sec','nanosec'])
        self.get_logger().info(f'Started recording scene: {video_path}')

    def _stop_file_recording(self):
        # Wait until all frames are processed
        self.get_logger().info('Stopping scene recording, waiting for queue to empty...')
        self.frame_queue.join()
        # Release writers
        if self.video_writer:
            self.video_writer.release()
            self.video_writer = None
        if self.csv_file:
            self.csv_file.close()
            self.csv_file = None
        self.get_logger().info('Scene recording stopped and files closed.')


def main(args=None):
    rclpy.init(args=args)
    node = MyNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
