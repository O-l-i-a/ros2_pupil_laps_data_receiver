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
import collections

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

        # Producer-Consumer buffer with drop-oldest policy
        self.queue_size = 500
        self.frame_queue = collections.deque(maxlen=self.queue_size)
        self.queue_lock = threading.Lock()
        self.queue_cv = threading.Condition(self.queue_lock)
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
        self.video_path = None
        self.fps = 30.0
        self.fourcc = cv2.VideoWriter_fourcc(*'MJPG')
        self.recording = False
        self.draining = False
        self.running = True
        self.frames_received = 0
        self.frames_written = 0
        self.frames_dropped = 0

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

        resp.success = True
        resp.message = 'started' if want_start else 'stopped'
        return resp

    def listener_callback(self, msg):
        if not self.recording:
            return
        try:
            self.frames_received += 1
            # Keep callback lightweight: queue ROS message, convert in writer thread.
            with self.queue_cv:
                if len(self.frame_queue) >= self.queue_size:
                    self.frame_queue.popleft()
                    self.frames_dropped += 1
                self.frame_queue.append(msg)
                self.queue_cv.notify()
        except Exception as e:
            self.get_logger().error(f'Failed to enqueue frame: {e}')

    def _writer_loop(self):
        while self.running and rclpy.ok():
            try:
                with self.queue_cv:
                    while not self.frame_queue and self.running:
                        # finalize asynchronous stop when queue is drained
                        if self.draining:
                            self._finalize_stop_locked()
                            break
                        self.queue_cv.wait(timeout=0.2)
                    if not self.running:
                        break
                    if not self.frame_queue:
                        continue
                    msg = self.frame_queue.popleft()

                cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='mono8')
                stamp = msg.header.stamp
                if self.video_writer is None and self.video_path is not None:
                    h, w = cv_image.shape[:2]
                    self.video_writer = cv2.VideoWriter(
                        self.video_path, self.fourcc, self.fps, (w, h), False
                    )
                    if not self.video_writer.isOpened():
                        self.get_logger().error(f'Failed to open VideoWriter: {self.video_path}')
                        self.video_writer = None
                        continue
                # Write video frame and CSV timestamp
                self.video_writer.write(cv_image)
                self.csv_writer.writerow([stamp.sec, stamp.nanosec])
                self.frames_written += 1

                with self.queue_cv:
                    if self.draining and not self.frame_queue:
                        self._finalize_stop_locked()
            except Exception as e:
                self.get_logger().error(f'Writer loop error: {e}')

    def _start_file_recording(self):
        ts = self.get_clock().now().to_msg()
        prefix = f"{ts.sec}"
        base_dir = 'recordings'
        # Verwende participant name für Ordnername
        session_dir = os.path.join(base_dir, f"recording_{self.participant_name}")
        os.makedirs(session_dir, exist_ok=True)

        with self.queue_cv:
            self.frame_queue.clear()
            self.draining = False

        self.video_path = os.path.join(session_dir, f"{prefix}_scene.avi")
        self.video_writer = None

        csv_path = os.path.join(session_dir, f"{prefix}_scene_times.csv")
        self.csv_file = open(csv_path, 'w', newline='')
        self.csv_writer = csv.writer(self.csv_file)
        self.csv_writer.writerow(['sec','nanosec'])
        self.frames_received = 0
        self.frames_written = 0
        self.frames_dropped = 0
        self.recording = True
        self.get_logger().info(f'Started recording scene to: {session_dir}')

    def _stop_file_recording(self):
        self.recording = False
        with self.queue_cv:
            self.draining = True
            self.queue_cv.notify_all()
        self.get_logger().info('Stopping scene recording asynchronously; buffer will drain in background.')

    def _finalize_stop_locked(self):
        if self.video_writer:
            self.video_writer.release()
            self.video_writer = None
        self.video_path = None
        if self.csv_file:
            self.csv_file.flush()
            self.csv_file.close()
            self.csv_file = None
        self.csv_writer = None
        self.draining = False
        self.get_logger().info(
            f'Scene recording stopped. received={self.frames_received}, '
            f'written={self.frames_written}, dropped={self.frames_dropped}'
        )

    def destroy_node(self):
        self.recording = False
        with self.queue_cv:
            self.draining = True
            self.running = False
            self.queue_cv.notify_all()
        if self.writer_thread.is_alive():
            self.writer_thread.join(timeout=2.0)
        if self.video_writer:
            self.video_writer.release()
            self.video_writer = None
        if self.csv_file:
            self.csv_file.close()
            self.csv_file = None
        self.csv_writer = None
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = SceneRecorder()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
