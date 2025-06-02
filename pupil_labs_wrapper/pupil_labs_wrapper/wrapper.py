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
    """
    Convert a Pupil Labs scene frame to a ROS2 Image message for further publishing in a topic.

    :param pl_image_msg: Object containing `bgr_pixels` 
    :type pl_image_msg: SimpleSceneFrame
    :param timestamp: ROS2 time stamp to assign to header.stamp
    :type timestamp: builtin_interfaces.msg.Time
    :returns: ROS2 Image message with BGR8 encoding and raw pixel data
    :rtype: sensor_msgs.msg.Image
    """
    ros_img = Image()
    ros_img.header.stamp.sec = timestamp.sec
    ros_img.header.stamp.nanosec = timestamp.nanosec
    ros_img.height = pl_image_msg.bgr_pixels.shape[0]
    ros_img.width = pl_image_msg.bgr_pixels.shape[1]
    ros_img.data = pl_image_msg.bgr_pixels.tobytes()
    ros_img.encoding = "bgr8"
    return ros_img

def populate_sensor_message(pl_gaze_msg, timestamp):
    """
    Create a GazeData message from a Pupil Labs gaze sample.

    :param pl_gaze_msg: Object with `x`, `y` (pixel coordinates) and `worn` (bool)
    :type pl_gaze_msg: SimpleGaze
    :param timestamp: ROS2 time stamp to assign to header.stamp
    :type timestamp: builtin_interfaces.msg.Time
    :returns: GazeData message populated with gaze coordinates and worn flag
    :rtype: egocentric_msg.msg.GazeData
    """
    msg = GazeData()
    msg.header.stamp.sec = timestamp.sec
    msg.header.stamp.nanosec = timestamp.nanosec
    msg.x = pl_gaze_msg.x
    msg.y = pl_gaze_msg.y
    msg.worn = pl_gaze_msg.worn
    return msg

class PupilLabsWrapper(Node):
    """
    ROS2 node that wraps Pupil Labs eye-tracking device,
    publishes gaze and scene image topics, and optionally records data to files.
    """
    def __init__(self):
        """
        Initialize the node:
         - Discover and connect to a Pupil Labs device
         - Create publishers for gaze, scene image, and recording state
         - Create the '/record' service
         - Start a ThreadPoolExecutor for blocking API calls
         - Start a timer at 30 Hz for data publishing
         - Initialize recording file handles

        :raises SystemExit: If no Pupil Labs device is found within the timeout
        """
        # Connecting to device
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

        latch_qos = QoSProfile(depth=1, # only the current state is saved, 
                               reliability=ReliabilityPolicy.RELIABLE,
                               durability=DurabilityPolicy.TRANSIENT_LOCAL)
        self.state_pub    = self.create_publisher(Bool, 'recording_state', latch_qos)
        self.state_pub.publish(Bool(data=False))

        self.create_service(SetBool, 'record', self._srv_cb)
        self.api_pool = ThreadPoolExecutor(max_workers=1) # to handle the delay in responses from API
        self.delayns = int(self.device.estimate_time_offset().roundtrip_duration_ms.mean * 1_000_000)
        self.timer    = self.create_timer(1.0/30.0, self.publish_pupil_labs_data) # publish_pupil_labs_data() will be called every 1/30 of sec
        
        # initialise the recording handles
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
        """
        Execute Pupil Labs API recording start/stop command. The recording on the phone starts too and it vibrates when it starts and ends

        :param start: True to start recording, False to stop and save
        :type start: bool
        :returns: True on success, False if an exception occurred
        :rtype: bool
        """
        try:
            if start:
                self.device.recording_start()
            else:
                self.device.recording_stop_and_save()
            return True
        except Exception as e:
            self.get_logger().error(f'Pupil-API error: {e}')
            return False

    def _start_file_recording(self): 
        """
        Open video and CSV writers for file recording.
        Creates 'recordings/' directory if necessary and initializes:
         - scene video (1088×1080, 30 FPS)
         - gaze CSV with header ['sec','nanosec','x','y','worn']
         - overlay video with gaze overlay
        """
        ts = self.get_clock().now().to_msg()
        prefix = f"{ts.sec}"
        #base folder
        base_dir = 'recordings'
        os.makedirs(base_dir, exist_ok=True)
        #session folder
        session_dir = os.path.join(base_dir, f"recording_{ts.sec}")
        session_dir = os.path.join(base_dir, f"recording_{ts.sec}")
        # Szene-Video 1088x1080px laut docs
        width, height = 1088, 1080  # anpassen falls nötig
        fourcc = cv2.VideoWriter_fourcc(*'mp4v')
        fps    = 30.0
        self.scene_writer = cv2.VideoWriter(
            os.path.join(session_dir, f"{prefix}_scene.mp4"), fourcc, fps, (width, height)
        )  # :contentReference[oaicite:3]{index=3}

        # Overlay-Video
        self.overlay_writer = cv2.VideoWriter(
            os.path.join(session_dir, f"{prefix}_scene_with_gaze.mp4"), fourcc, fps, (width, height)
        )

        # Gaze-CSV
        self.csv_file   = open(os.path.join(session_dir, f"{prefix}_gaze.csv"), 'w', newline='')
        self.csv_writer = csv.writer(self.csv_file)  # :contentReference[oaicite:4]{index=4}
        self.csv_writer.writerow(['sec','nanosec','x','y','worn'])

    def _stop_file_recording(self):
        """
        Close all open file handles (video writers and CSV file).
        """
        if self.scene_writer:
            self.scene_writer.release()
        if self.overlay_writer:
            self.overlay_writer.release()
        if self.csv_file:
            self.csv_file.close()

    def publish_pupil_labs_data(self):
        """
        Read synchronized scene and gaze data from the device and publish them.
        If recording is active, write video frames and gaze data to files.

        :raises: Logs any exception encountered during receive or publish
        """
        try:
            scene_sample, gaze_sample = (
                self.device.receive_matched_scene_video_frame_and_gaze()
            )  
            #experiment
            
            current_time = self.get_clock().now().to_msg() #timestramp of ROS2
            delay_ns = self.delayns
            if current_time.nanosec >= delay_ns:
            # No need to borrow a second
                current_time.nanosec = current_time.nanosec - delay_ns
            else:
            # Need to borrow 1 second:
            #   new_nanosec = (old_nanosec + 1_000_000_000) - delay_ns
                current_time.sec -= 1
                current_time.nanosec = current_time.nanosec + 1_000_000_000 - delay_ns

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
    """
    Entry point: initialize ROS2 and start the PupilLabsWrapper node.
    """
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
