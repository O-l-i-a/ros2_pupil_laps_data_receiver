import rclpy
from rclpy.node import Node
from cv_bridge import CvBridge
from sensor_msgs.msg import Image, CameraInfo
from std_srvs.srv import SetBool
import cv2
from gaze_interface.msg import GazeDataAsync  


import csv
import os

class GazeRecorder(Node):
    def __init__(self):
        super().__init__('GazeRecorder')
        self.get_logger().info('GazeRecorder has been started!')
        self.subscription = self.create_subscription(
            GazeDataAsync,
            'pupil/gaze',
            self.listener_callback,
            15
        )
        self.create_service(SetBool, 'record_pupil_gaze', self._srv_cb)
        #out_path = os.path.expanduser('~/ros2_recorded_video.mp4')
        self.recording  = False
        self.csv_file = None
        self.csv_writer = None
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
            
            self.csv_writer.writerow([msg.header.stamp.sec, msg.header.stamp.nanosec, msg.norm_pos_x, msg.norm_pos_y])
        except Exception as e:
            self.get_logger().error(f"Failed to process gaze: {e}")

    def _start_file_recording(self): 
        """
        Open video and CSV writers for file recording.
        Creates 'recordings/' directory if necessary and initializes:
         - gaze CSV with header ['sec','nanosec','x','y','worn']
        """
        ts = self.get_clock().now().to_msg()
        prefix = f"{ts.sec}"
        #base folder
        base_dir = 'recordings'
        #session folder
        session_dir = os.path.join(base_dir, f"recording_{ts.sec}")
        os.makedirs(session_dir, exist_ok=True)
        # Gaze-CSV
        self.csv_file   = open(os.path.join(session_dir, f"{prefix}_gaze.csv"), 'w', newline='')
        self.csv_writer = csv.writer(self.csv_file)
        self.csv_writer.writerow(['sec','nanosec', "x", "y"])

    def _stop_file_recording(self):
        """
        Close all open file handles (CSV file).
        """
        if self.csv_file:
            self.csv_file.close()
            self.csv_file = None
def main(args=None):
    rclpy.init(args=args)
    node = GazeRecorder()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()