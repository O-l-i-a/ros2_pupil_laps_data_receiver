import rclpy
from rclpy.node import Node
from cv_bridge import CvBridge
from sensor_msgs.msg import Image, CameraInfo
from std_srvs.srv import SetBool
import cv2

import csv
import os

class DepthRecorder(Node):
    def __init__(self):
        super().__init__('my_node')
        self.get_logger().info('MyNode has been started!')
        self.subscription = self.create_subscription(
            Image,
            '/zed/zed_node/depth/depth_registered',
            self.listener_callback,
            20
        )
        self.create_service(SetBool, 'record_pupil_scene_with_gaze', self._srv_cb)

        self.bridge = CvBridge()
        self.video_writer = None
        self.frame_width = 1280  # Replace with actual width 1280x720
        self.frame_height = 720  # Replace with actual height
        self.fps = 60.0

        # Output video file
        self.fourcc = cv2.VideoWriter_fourcc(*'MJPG')  # Or  mp4v 'XVID', 'MJPG'
        #out_path = os.path.expanduser('~/ros2_recorded_video.mp4')
        self.video_writer = None
        self.recording       = False
        self.scene_writer    = None
        self.csv_frame_times = None
        #self.get_logger().info(f"Recording to {out_path}")
    
    def _srv_cb(self, req, resp):
       
        want_start = bool(req.data)
        if want_start == self.recording:
            resp.success = False; resp.message = 'No change'
            return resp

        # Dateien öffnen bzw. schließen
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
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
            h, w = cv_image.shape[:2]
            self.get_logger().info(f"Writing frame #{msg.header.stamp.sec}.{msg.header.stamp.nanosec} at {w}×{h}")
            self.video_writer.write(cv_image)
            self.csv_writer.writerow([msg.header.stamp.sec, msg.header.stamp.nanosec])
        except Exception as e:
            self.get_logger().error(f"Failed to process frame: {e}")

    def _start_file_recording(self): 
        """
        Open video and CSV writers for file recording.
        Creates 'recordings/' directory if necessary and initializes:
         - scene video (1280x720, 30 FPS)
         - gaze CSV with header ['sec','nanosec','x','y','worn']
         - overlay video with gaze overlay
        """
        ts = self.get_clock().now().to_msg()
        prefix = f"{ts.sec}"
        #base folder
        base_dir = 'recordings'
        #session folder
        session_dir = os.path.join(base_dir, f"recording_{ts.sec}")
        os.makedirs(session_dir, exist_ok=True)
        # Szene-Video 1088x1080px laut docs
        self.video_writer = cv2.VideoWriter(
            os.path.join(session_dir, f"{prefix}_scene.avi"), self.fourcc, self.fps, (self.frame_width, self.frame_height)
        )  # :contentReference[oaicite:3]{index=3}

        # Gaze-CSV
        self.csv_file   = open(os.path.join(session_dir, f"{prefix}_scene_times.csv"), 'w', newline='')
        self.csv_writer = csv.writer(self.csv_file)  # :contentReference[oaicite:4]{index=4}
        self.csv_writer.writerow(['sec','nanosec'])

    def _stop_file_recording(self):
        """
        Close all open file handles (video writers and CSV file).
        """
        if self.video_writer is not None:
            print("before release")
            self.video_writer.release()
            print("after release")
            self.video_writer = None
        if self.csv_file:
            self.csv_file.close()
            self.csv_file = None
def main(args=None):
    rclpy.init(args=args)
    node = DepthRecorder()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()