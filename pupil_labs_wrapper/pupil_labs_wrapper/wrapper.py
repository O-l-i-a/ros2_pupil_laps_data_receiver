#!/home/kysh/venv/pupil_labs/bin/python

import os
import csv
import cv2
import rclpy
from rclpy.node import Node
from pupil_labs.realtime_api.simple import discover_one_device
from egocentric_msg.msg import GazeData
from sensor_msgs.msg import Image
from std_srvs.srv import SetBool
from std_msgs.msg import Bool
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy
from concurrent.futures import ThreadPoolExecutor

def populate_image_message(pl_image_msg, timestamp):
    ros_img = Image()
    ros_img.header.stamp.sec = timestamp.sec
    ros_img.header.stamp.nanosec = timestamp.nanosec
    ros_img.height = pl_image_msg.bgr_pixels.shape[0]
    ros_img.width = pl_image_msg.bgr_pixels.shape[1]
    ros_img.data = pl_image_msg.bgr_pixels.tobytes()
    ros_img.encoding = "bgr8"
    return ros_img

def populate_sensor_message(pl_gaze_msg, timestamp):
    msg = GazeData()
    msg.header.stamp.sec = timestamp.sec
    msg.header.stamp.nanosec = timestamp.nanosec
    msg.x = pl_gaze_msg.x
    msg.y = pl_gaze_msg.y
    msg.worn = pl_gaze_msg.worn
    return msg

class PupilLabsWrapper(Node):
    def __init__(self):
        super().__init__('pupil_labs_wrapper')
        self.get_logger().info("Looking for the next best device...")
        self.device = discover_one_device(max_search_duration_seconds=10)
        if self.device is None:
            self.get_logger().error("No device found.")
            raise SystemExit(-1)
        self.get_logger().info(f"Connecting to {self.device}...")
        # Publisher & Service
        self.pub_gaze = self.create_publisher(GazeData, 'pupil_labs/gaze', 10)
        self.pub_rgb  = self.create_publisher(Image,    'pupil_labs/scene_img', 10)

        latch_qos = QoSProfile(depth=1,
                               reliability=ReliabilityPolicy.RELIABLE,
                               durability=DurabilityPolicy.TRANSIENT_LOCAL)
        self.state_pub    = self.create_publisher(Bool, 'recording_state', latch_qos)
        self.state_pub.publish(Bool(data=False))

        self.create_service(SetBool, 'record', self._srv_cb)
        self.api_pool = ThreadPoolExecutor(max_workers=1)
        self.timer    = self.create_timer(1.0/30.0, self.publish_pupil_labs_data)

        # Aufnahme-Handles initialisieren
        self.recording       = False
        self.scene_writer    = None
        self.overlay_writer  = None
        self.csv_file        = None
        self.csv_writer      = None

    def _srv_cb(self, req, resp):
        want_start = bool(req.data)
        if want_start == self.recording:
            resp.success = False; resp.message = 'No change'
            return resp

        ok = self.api_pool.submit(self._pupil_record_cmd, want_start).result()
        if not ok:
            resp.success = False; resp.message = 'API failed'
            return resp

        # Dateien öffnen bzw. schließen
        if want_start:
            self._start_file_recording()
        else:
            self._stop_file_recording()

        self.recording = want_start
        self.state_pub.publish(Bool(data=self.recording))
        resp.success = True
        resp.message = 'started' if want_start else 'stopped'
        return resp

    def _pupil_record_cmd(self, start: bool) -> bool:
        try:
            if start:
                self.device.recording_start()
            else:
                self.device.recording_stop_and_save()
            return True
        except Exception as e:
            self.get_logger().error(f'Pupil-API error: {e}')
            return False

    def _start_file_recording(self): #TODO ins getrennter Ordner packen
        """Öffnet VideoWriter und CSV-Writer"""
        ts = self.get_clock().now().to_msg()
        prefix = f"{ts.sec}.{ts.nanosec}"
        os.makedirs('recordings', exist_ok=True)

        # Szene-Video 1088x1080px laut docs
        width, height = 1088, 1080  # anpassen falls nötig
        fourcc = cv2.VideoWriter_fourcc(*'mp4v')
        fps    = 30.0
        self.scene_writer = cv2.VideoWriter(
            f"recordings/{prefix}_scene.mp4", fourcc, fps, (width, height)
        )  # :contentReference[oaicite:3]{index=3}

        # Overlay-Video
        self.overlay_writer = cv2.VideoWriter(
            f"recordings/{prefix}_scene_with_gaze.mp4", fourcc, fps, (width, height)
        )

        # Gaze-CSV
        self.csv_file   = open(f"recordings/{prefix}_gaze.csv", 'w', newline='')
        self.csv_writer = csv.writer(self.csv_file)  # :contentReference[oaicite:4]{index=4}
        self.csv_writer.writerow(['sec','nanosec','x','y','worn'])

    def _stop_file_recording(self):
        """Schließt alle Datei-Handles"""
        if self.scene_writer:
            self.scene_writer.release()
        if self.overlay_writer:
            self.overlay_writer.release()
        if self.csv_file:
            self.csv_file.close()

    def publish_pupil_labs_data(self):
        try:
            scene_sample, gaze_sample = (
                self.device.receive_matched_scene_video_frame_and_gaze()
            )  # :contentReference[oaicite:5]{index=5}
            #TODO: Fragen ob es dann genau ist oder nicht
            #TODO: convertieren die zeit aus der Brille zum msg 
            current_time = self.get_clock().now().to_msg() #- das ist der timestramp von ROS2
            # ROS-Publish
            self.pub_gaze.publish(populate_sensor_message(gaze_sample, current_time))
            self.pub_rgb.publish(populate_image_message(scene_sample, current_time))
            
            if self.recording:
                if not self.scene_writer.isOpened():
                    self.get_logger().error("Scene VideoWriter konnte nicht geöffnet werden")
                if not self.overlay_writer.isOpened():
                    self.get_logger().error("Overlay VideoWriter konnte nicht geöffnet werden")
                frame = scene_sample.bgr_pixels
                # Szene-Video schreiben
                self.scene_writer.write(frame)

                # CSV-Zeile
                self.csv_writer.writerow([
                    current_time.sec,
                    current_time.nanosec,
                    gaze_sample.x,
                    gaze_sample.y,
                    gaze_sample.worn
                ])

                # Overlay: roter Kreis an (x, y)
                h, w = frame.shape[:2]
                pt = (int(gaze_sample.x), int(gaze_sample.y))
                overlay = frame.copy()
                cv2.circle(overlay, pt, 10, (0,0,255), 2)
                self.overlay_writer.write(overlay)

        except Exception as e:
            self.get_logger().error(f"Error receiving or publishing data: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = PupilLabsWrapper()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
