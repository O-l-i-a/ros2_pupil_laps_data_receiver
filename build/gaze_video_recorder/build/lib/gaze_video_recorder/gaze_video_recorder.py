#!/usr/bin/env python3
#
#   gaze_video_recorder.py  –  nimmt Szene-Video + Gaze-CSV auf
#
import csv, cv2, pathlib, rclpy
from rclpy.node import Node
from cv_bridge import CvBridge                       # :contentReference[oaicite:2]{index=2}
from sensor_msgs.msg import Image
from egocentric_msg.msg import GazeData
from message_filters import Subscriber, ApproximateTimeSynchronizer

class GazeVideoRecorder(Node):
    def __init__(self):
        super().__init__('gaze_video_recorder')

        # Ausgabe-Verzeichnis
        self.declare_parameter('out_dir', 'recording')
        self.declare_parameter('fps',     30.0)       # Fallback-Framerate
        out  = pathlib.Path(self.get_parameter('out_dir').value)
        out.mkdir(parents=True, exist_ok=True)

        # CSV öffnen
        self.csv_file  = open(out / 'gaze_log.csv', 'w', newline='')
        self.writer    = csv.writer(self.csv_file)
        self.writer.writerow(['frame_idx','sec','nsec',
                              'gaze_x_px','gaze_y_px','confidence'])

        self.bridge = CvBridge()
        self.video  = None          # VideoWriter wird erst lazy erstellt
        self.fps    = self.get_parameter('fps').value
        self.frame_idx = 0

        # Synchronisierte Subscriber
        img_sub  = Subscriber(self, Image, '/pupil_lab/scene_img')
        gaze_sub = Subscriber(self, GazeData,  '/pupil_lab/gaze')
        self.sync = ApproximateTimeSynchronizer(
            [img_sub, gaze_sub], queue_size=30, slop=0.05, allow_headerless=False)
        self.sync.registerCallback(self._cb, out)

    def _cb(self, img, gaze, out):
        # VideoWriter bei erster Nachricht anlegen (Größe aus Bild)
        if self.video is None:
            h, w = img.height, img.width
            fourcc = cv2.VideoWriter_fourcc(*'mp4v')          # :contentReference[oaicite:3]{index=3}
            self.video = cv2.VideoWriter(
                str(out / 'scene.mp4'), fourcc, self.fps, (w, h))
            if not self.video.isOpened():
                self.get_logger().error('VideoWriter konnte nicht geöffnet werden')
                rclpy.shutdown(); return

        # Bild in Video schreiben
        frame = self.bridge.imgmsg_to_cv2(img, desired_encoding='bgr8')
        self.video.write(frame)

        # Gaze loggen
        self.writer.writerow([self.frame_idx,
                              img.header.stamp.sec,
                              img.header.stamp.nanosec,
                              gaze.x, gaze.y, gaze.confidence])
        self.frame_idx += 1

    # Sauber aufräumen
    def destroy_node(self):
        if self.video: self.video.release()
        self.csv_file.close()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = GazeVideoRecorder()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

