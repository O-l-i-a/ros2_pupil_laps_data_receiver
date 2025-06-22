import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter
from rcl_interfaces.msg import SetParametersResult  # Correct import
from cv_bridge import CvBridge
from sensor_msgs.msg import Image, CompressedImage
from std_srvs.srv import SetBool
import cv2
import csv
import os
import threading
import queue

class SceneRecorder(Node):
    def __init__(self):
        super().__init__('pupil_scene_recorder')
        self.get_logger().info('SceneRecorder has been started!')

        # Parameter für participant name
        self.declare_parameter('participant_name', 'default')
        self.participant_name = self.get_parameter('participant_name').get_parameter_value().string_value
        self.get_logger().info(f'Participant name: {self.participant_name}')

        # Parameter callback für dynamische Updates
        self.add_on_set_parameters_callback(self._parameter_callback)

        # Producer-Consumer queue for frames
        self.frame_queue = queue.Queue(maxsize=200)
        self.writer_thread = threading.Thread(target=self._writer_loop, daemon=True)
        self.writer_thread.start()

        # Subscription and service
        self.subscription = self.create_subscription(
            CompressedImage,
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

    def _parameter_callback(self, params):
        """Callback für Parameter Updates"""
        for param in params:
            if param.name == 'participant_name':
                if param.type_ == Parameter.Type.STRING:
                    self.participant_name = param.value
                    self.get_logger().info(f'Updated participant name to: {self.participant_name}')
                else:
                    self.get_logger().error('participant_name must be a string')
                    return SetParametersResult(successful=False, reason="participant_name must be a string")
        
        return SetParametersResult(successful=True)

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
        # Verwende participant name für Ordnername
        session_dir = os.path.join(base_dir, f"recording_{self.participant_name}")
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
        self.get_logger().info(f'Started recording scene to: {session_dir}')

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
    node = SceneRecorder()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()