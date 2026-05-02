#!/usr/bin/env python3
import asyncio
import os
import csv
import json
import cv2
import threading
import numpy as np
from urllib.parse import urlparse, urlunparse
import concurrent.futures


import rclpy
from rclpy.node import Node
from rclpy.executors import SingleThreadedExecutor, MultiThreadedExecutor
from std_srvs.srv import SetBool
from sensor_msgs.msg import CompressedImage, Image, CameraInfo
from cv_bridge import CvBridge

from pupil_labs.realtime_api import (
    Network,
    Device,
    receive_gaze_data,
    receive_video_frames,
    receive_eye_events_data,
    receive_imu_data,
    BlinkEventData,
    FixationEventData,
    FixationOnsetEventData,
)
from gaze_interface.msg import GazeDataAsync  
from blink_interface.msg import EyeStateData
from imu_interface.msg import ImuData
from rclpy.qos import QoSProfile, HistoryPolicy, ReliabilityPolicy, DurabilityPolicy
from rclpy.callback_groups import ReentrantCallbackGroup


from pupil_labs.realtime_api.time_echo import TimeEcho, TimeOffsetEstimator, time_ms
from rclpy.time import Time
from pupil_labs.realtime_api.device import DeviceError



def unix_ns_to_ros_time(unix_ns: int) -> Time:
    """Helper to build an rclpy Time from **host‑clock** nanoseconds."""
    sec = unix_ns // 1_000_000_000
    nanosec = unix_ns % 1_000_000_000
    return Time(seconds=sec, nanoseconds=nanosec)

class PupilAsync(Node):
    def __init__(self):
        super().__init__('pupil_async')
        self._encode_pool = concurrent.futures.ThreadPoolExecutor(max_workers=2, thread_name_prefix="scene_enc")
        self.bridge = CvBridge()
        self._gray_img = None
        # Publisher für Gaze- und Scene-Daten
        self.declare_parameter("participant_name", "default")
        self.declare_parameter("opencv_num_threads", 4)
        self.declare_parameter("rtsp_transport", "tcp")
        self.shutdown_event = asyncio.Event()
        self.participant_name = self.get_parameter("participant_name").value
        self.rtsp_transport = str(self.get_parameter("rtsp_transport").value).lower()
        #self.get_logger().info(f"Participant name: {self.participant_name}")

        # OpenCV CPU tuning for high-rate BGR->gray conversion.
        cv2.setUseOptimized(True)
        opencv_threads = int(self.get_parameter("opencv_num_threads").value)
        if opencv_threads > 0:
            cv2.setNumThreads(opencv_threads)
        self.get_logger().info(
            f"OpenCV optimized={cv2.useOptimized()} threads={cv2.getNumThreads()}"
        )
        self.get_logger().info(f"RTSP transport={self.rtsp_transport}")

        base_dir = "recordings"
        #self.session_dir = os.path.join(base_dir, f"recording_{self.participant_name}")
        #os.makedirs(self.session_dir, exist_ok=True)

        ts = self.get_clock().now().to_msg()
        prefix = f"{ts.sec}"
        #csv_path = os.path.join(self.session_dir, f"{prefix}_offset_log.csv")

        # ---------------- CSV logging ---------------------------
        #self._csv_file = open(csv_path, "w", newline="")
        #self._csv_writer = csv.writer(self._csv_file)
        #self._csv_writer.writerow(["host_time_ns", "offset_ns"])
        qos = QoSProfile(
            depth= 5,
            history=HistoryPolicy.KEEP_LAST,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability = DurabilityPolicy.VOLATILE
        )
        qos_scene = QoSProfile(
            depth= 10,
            history=HistoryPolicy.KEEP_LAST,
            reliability=ReliabilityPolicy.RELIABLE,
            durability = DurabilityPolicy.VOLATILE
        )
        self.cb_group = ReentrantCallbackGroup()
        #self.cb_group_scene = ReentrantCallbackGroup()
        self.gaze_pub = self.create_publisher(GazeDataAsync, 'pupil/gaze', qos, callback_group=self.cb_group)
        self.eye_state_pub = self.create_publisher(EyeStateData, 'pupil/eye_state', qos, callback_group=self.cb_group)
        self.imu_pub = self.create_publisher(ImuData, 'pupil/imu', qos, callback_group=self.cb_group)
        self.scene_pub = self.create_publisher(CompressedImage, '/pupil/scene/image_raw/compressed', qos_scene)
        #self.scene_info_pub = self.create_publisher(CameraInfo, 'pupil/scene/camera_info', qos_scene)
        self.delayns = 0
        self.calibration = None
        self._scene_k = None
        self._scene_d = None
        self._scene_fx = 0.0
        self._scene_fy = 0.0
        self._scene_cx = 0.0
        self._scene_cy = 0.0
        self._scene_calib_valid = False
        self.get_logger().info('PupilAsync bereit. Warte auf /record Service…')



    async def gaze_stream(self, url: str):
        self.get_logger().info(f'Starting gaze stream: {url}')
        try:
            async for gaze in receive_gaze_data(url, run_loop=True):
                if self.shutdown_event.is_set():
                    break

                msg = GazeDataAsync()
                host_ns = gaze.timestamp_unix_ns + self.delayns
                msg.header.stamp = unix_ns_to_ros_time(host_ns).to_msg()
                msg.header.frame_id = 'pupil_gaze'
                msg.norm_pos_x = gaze.x
                msg.norm_pos_y = gaze.y
                self.gaze_pub.publish(msg)

        except asyncio.CancelledError:
            self.get_logger().debug('gaze_stream cancelled')
            raise

    async def eye_events_stream(self, url: str):
        self.get_logger().info(f"Starting eye events stream: {url}")
        try:
            async for eye_event in receive_eye_events_data(url, run_loop=True):
                if self.shutdown_event.is_set():
                    break

                msg = EyeStateData()

                if isinstance(eye_event, BlinkEventData):
                    start_ns = eye_event.start_time_ns + self.delayns
                    end_ns = eye_event.end_time_ns + self.delayns
                    msg.header.stamp = unix_ns_to_ros_time(start_ns).to_msg()
                    msg.header.frame_id = "pupil_eye_state"
                    msg.event_name = "blink"
                    msg.event_type = int(eye_event.event_type)
                    msg.start_time_ns = float(start_ns)
                    msg.end_time_ns = float(end_ns)
                    msg.rtp_ts_unix_seconds = float(eye_event.rtp_ts_unix_seconds)
                    msg.has_end_time = True
                    self.eye_state_pub.publish(msg)
                    continue

                if isinstance(eye_event, FixationOnsetEventData):
                    start_ns = eye_event.start_time_ns + self.delayns
                    msg.header.stamp = unix_ns_to_ros_time(start_ns).to_msg()
                    msg.header.frame_id = "pupil_eye_state"
                    msg.event_type = int(eye_event.event_type)
                    msg.start_time_ns = float(start_ns)
                    msg.end_time_ns = float(start_ns)
                    msg.rtp_ts_unix_seconds = float(eye_event.rtp_ts_unix_seconds)
                    msg.has_end_time = False
                    msg.event_name = "fixation_onset" if int(eye_event.event_type) == 3 else "saccade_onset"
                    self.eye_state_pub.publish(msg)
                    continue

                if isinstance(eye_event, FixationEventData):
                    start_ns = eye_event.start_time_ns + self.delayns
                    end_ns = eye_event.end_time_ns + self.delayns
                    msg.header.stamp = unix_ns_to_ros_time(start_ns).to_msg()
                    msg.header.frame_id = "pupil_eye_state"
                    msg.event_type = int(eye_event.event_type)
                    msg.start_time_ns = float(start_ns)
                    msg.end_time_ns = float(end_ns)
                    msg.rtp_ts_unix_seconds = float(eye_event.rtp_ts_unix_seconds)
                    msg.has_end_time = True
                    msg.event_name = "fixation" if int(eye_event.event_type) == 1 else "saccade"
                    msg.start_gaze_x = float(eye_event.start_gaze_x)
                    msg.start_gaze_y = float(eye_event.start_gaze_y)
                    msg.end_gaze_x = float(eye_event.end_gaze_x)
                    msg.end_gaze_y = float(eye_event.end_gaze_y)
                    msg.mean_gaze_x = float(eye_event.mean_gaze_x)
                    msg.mean_gaze_y = float(eye_event.mean_gaze_y)
                    msg.amplitude_pixels = float(eye_event.amplitude_pixels)
                    msg.amplitude_angle_deg = float(eye_event.amplitude_angle_deg)
                    msg.mean_velocity = float(eye_event.mean_velocity)
                    msg.max_velocity = float(eye_event.max_velocity)
                    self.eye_state_pub.publish(msg)
        except asyncio.CancelledError:
            self.get_logger().debug("eye_events_stream cancelled")
            raise
        except Exception as e:
            self.get_logger().exception(f"eye_events_stream error: {e}")

    async def imu_stream(self, url: str):
        self.get_logger().info(f"Starting imu stream: {url}")
        while not self.shutdown_event.is_set():
            try:
                async for imu_data in receive_imu_data(url, run_loop=True):
                    if self.shutdown_event.is_set():
                        break

                    host_ns = imu_data.timestamp_unix_ns + self.delayns

                    accel = getattr(imu_data, "accel_data", None)
                    if accel is None:
                        accel = getattr(imu_data, "acceleration_data", None)

                    gyro = getattr(imu_data, "gyro_data", None)
                    if gyro is None:
                        gyro = getattr(imu_data, "gyroscope_data", None)

                    quat = getattr(imu_data, "quaternion", None)
                    if accel is None or gyro is None or quat is None:
                        self.get_logger().warning("Skipping IMU packet with missing fields")
                        continue

                    msg = ImuData()
                    msg.header.stamp = unix_ns_to_ros_time(host_ns).to_msg()
                    msg.header.frame_id = "pupil_imu"
                    msg.timestamp_unix_ns = int(host_ns)
                    msg.timestamp_unix_seconds = float(host_ns / 1_000_000_000.0)

                    msg.acceleration.x = float(accel.x)
                    msg.acceleration.y = float(accel.y)
                    msg.acceleration.z = float(accel.z)

                    msg.gyroscope.x = float(gyro.x)
                    msg.gyroscope.y = float(gyro.y)
                    msg.gyroscope.z = float(gyro.z)

                    msg.quaternion.x = float(quat.x)
                    msg.quaternion.y = float(quat.y)
                    msg.quaternion.z = float(quat.z)
                    msg.quaternion.w = float(quat.w)

                    self.imu_pub.publish(msg)
            except asyncio.CancelledError:
                self.get_logger().debug("imu_stream cancelled")
                raise
            except Exception as e:
                if self.shutdown_event.is_set():
                    break
                self.get_logger().warning(f"imu stream dropped ({e}); retrying in 1s")
                await asyncio.sleep(1.0)

    async def scene_stream(self, url: str):
        self.get_logger().info(f'Starting scene stream: {url}')
        try:
            async for frame in receive_video_frames(
                url, run_loop=True, transport=self.rtsp_transport
            ):
                img = frame.bgr_buffer()
                img = frame.bgr_buffer()
                if img is None or img.size == 0:
                    continue
                expected_pixels = 1600 * 1200
                if img.shape[0] * img.shape[1] != expected_pixels:
                    self.get_logger().warning(f"Bad frame shape: {img.shape}, skipping")
                    continue
                gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

                # RViz expects the ROS Image metadata to match the true buffer layout.
                # Some decoded frames may have padded rows, so don't assume step == width * 3.
                if not img.flags["C_CONTIGUOUS"]:
                    img = np.ascontiguousarray(img)
                h, w = img.shape[:2]
                step = int(img.strides[0])

                host_ns = frame.timestamp_unix_ns + self.delayns
                stamp = unix_ns_to_ros_time(host_ns).to_msg()

                loop = asyncio.get_event_loop()
                gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
                def encode_frame(gray):
                    cv2.setNumThreads(2)  # isolate from ZED's OpenCV
                    return cv2.imencode('.jpg', gray, [cv2.IMWRITE_JPEG_QUALITY, 75])

                ok, enc = await loop.run_in_executor(self._encode_pool, encode_frame, gray)
                if not ok:
                    self.get_logger().warning("JPEG encode failed")
                    continue

                ros_img = CompressedImage()
                ros_img.header.stamp = stamp
                ros_img.header.frame_id = "pupil_scene"
                ros_img.format = "jpeg"
                ros_img.data = enc.tobytes()

                self.scene_pub.publish(ros_img)

        except asyncio.CancelledError:
            self.get_logger().debug('scene_stream cancelled')
            raise
        except Exception as e:
            self.get_logger().exception(f"scene_stream error: {e}")


    async def run(self):
        """
        Device discovery and then spin up the gaze + scene streams as background tasks,
        blocking until the user interrupts (Ctrl-C).
        """
        self.get_logger().info('Discovering Pupil device...')
        async with Network() as network:
            dev_info = await network.wait_for_new_device(timeout_seconds=20)
        if dev_info is None:
            self.get_logger().error('No Pupil device found, aborting')
            return
        
        self.get_logger().info('Pupil device connected')
        async with Device.from_discovered_device(dev_info) as device:
            
            #self._prepare_scene_calibration()
            #self._write_scene_calibration_file()
            status = await device.get_status()
            gaze_sensor = status.direct_gaze_sensor()
            world_sensor = status.direct_world_sensor()
            
            
            if hasattr(status, "direct_eye_events_sensor"):
                eye_events_sensor = status.direct_eye_events_sensor()
            if hasattr(status, "direct_imu_sensor"):
                imu_sensor = status.direct_imu_sensor()
            #self.delayns = int(device.time_echo().roundtrip_duration_ms.mean * 1_000_000)
            if not gaze_sensor.connected:
                self.get_logger().error('Gaze sensor not connected')
                return
            if not world_sensor.connected:
                self.get_logger().error('Scene camera not connected')
                return

            # --- spawn both coroutines as background tasks ---
            offset_task = asyncio.create_task(self._offset_loop(status))
            gaze_url = gaze_sensor.url
            scene_url = world_sensor.url
            gaze_task  = asyncio.create_task(self.gaze_stream(gaze_url))
            scene_task = asyncio.create_task(self.scene_stream(scene_url))
            eye_events_task = None
            imu_task = None
            if eye_events_sensor is not None and eye_events_sensor.connected:
                eye_events_url = eye_events_sensor.url
                eye_events_task = asyncio.create_task(self.eye_events_stream(eye_events_url))
            else:
                self.get_logger().warning(
                    "Eye events sensor unavailable or not connected. Blink publishing disabled "
                    '(enable "Compute fixations" in Companion Device).'
                )
            
            if imu_sensor is not None and imu_sensor.connected:
                imu_url = imu_sensor.url
                imu_task = asyncio.create_task(self.imu_stream(imu_url))
            else:
                self.get_logger().warning("IMU sensor unavailable or not connected. IMU publishing disabled.")

            # --- block here until cancelled (e.g. Ctrl-C) ---
            try:
                await asyncio.Event().wait()
            except asyncio.CancelledError:
                self.get_logger().info('Shutdown requested, cancelling streams…')
            finally:
                # --- clean up both streams ---
                gaze_task.cancel()
                scene_task.cancel()
                offset_task.cancel()
                if eye_events_task is not None:
                    eye_events_task.cancel()
                if imu_task is not None:
                    imu_task.cancel()
                # optionally wait for them to finish cancelling
                tasks = [gaze_task, scene_task, offset_task]
                if eye_events_task is not None:
                    tasks.append(eye_events_task)
                if imu_task is not None:
                    tasks.append(imu_task)
                await asyncio.gather(*tasks, return_exceptions=True)

    def _prepare_scene_calibration(self):
        if self.calibration is None:
            self._scene_calib_valid = False
            return

        calib = self.calibration
        try:
            scene_k_raw = calib["scene_camera_matrix"]
            scene_d_raw = calib["scene_distortion_coefficients"]
        except Exception:
            scene_k_raw = calib.scene_camera_matrix
            scene_d_raw = calib.scene_distortion_coefficients

        scene_k_arr = np.array(scene_k_raw)
        scene_d_arr = np.array(scene_d_raw)
        k_flat = scene_k_arr.flatten()
        d_flat = scene_d_arr.flatten()

        self.get_logger().info(
            f"scene_K raw shape: {scene_k_arr.shape}, flattened len: {k_flat.size}; "
            f"scene_D raw shape: {scene_d_arr.shape}, flattened len: {d_flat.size}"
        )

        if k_flat.size != 9:
            self.get_logger().error(
                f"Expected 9 intrinsics values, got {k_flat.size}, CameraInfo disabled."
            )
            self._scene_calib_valid = False
            return

        self._scene_k = k_flat.tolist()
        self._scene_d = d_flat.tolist()
        self._scene_fx = float(k_flat[0])
        self._scene_cx = float(k_flat[2])
        self._scene_fy = float(k_flat[4])
        self._scene_cy = float(k_flat[5])
        self._scene_calib_valid = True

    def _write_scene_calibration_file(self):
        if not self._scene_calib_valid:
            self.get_logger().warning("Scene calibration invalid; file will not be written.")
            return

        base_dir = "recordings"
        session_dir = os.path.join(base_dir, f"recording_{self.participant_name}")
        os.makedirs(session_dir, exist_ok=True)
        calib_path = os.path.join(session_dir, "scene_calibration.json")

        calib_payload = {
            "participant_name": self.participant_name,
            "distortion_model": "plumb_bob",
            "k": self._scene_k,
            "d": self._scene_d,
            "r": [1.0, 0.0, 0.0,
                  0.0, 1.0, 0.0,
                  0.0, 0.0, 1.0],
            "p": [
                self._scene_fx, 0.0, self._scene_cx, 0.0,
                0.0, self._scene_fy, self._scene_cy, 0.0,
                0.0, 0.0, 1.0, 0.0,
            ],
        }

        with open(calib_path, "w", encoding="utf-8") as f:
            json.dump(calib_payload, f, indent=2)
        self.get_logger().info(f"Scene calibration written once to: {calib_path}")


    def destroy_node(self):
        #self._csv_file.close()
        super().destroy_node()

    async def _offset_loop(self, status):
        """Continuously refine clock offset every 5 minutes."""
        estimator = TimeOffsetEstimator(status.phone.ip, status.phone.time_echo_port)
        while True:
            estimates = await estimator.estimate()
            if estimates is None:
                await asyncio.sleep(1.0)
                continue
            self.delayns = int(estimates.time_offset_ms.mean * 1_000_000)

           # now_ns = self.get_clock().now().nanoseconds
           # self._csv_writer.writerow([now_ns, self.delayns])

            await asyncio.sleep(300.0)

def main():
    rclpy.init()
    node = PupilAsync()
    executor = MultiThreadedExecutor(num_threads=4)
    executor.add_node(node)

    # ROS spins in its own thread — never touches the asyncio loop
    ros_thread = threading.Thread(target=executor.spin, daemon=True)
    ros_thread.start()

    async def main_async():
        try:
            await node.run()
        finally:
            executor.shutdown()
            node.destroy_node()
            rclpy.shutdown()

    try:
        asyncio.run(main_async())
    except KeyboardInterrupt:
        pass

    ros_thread.join(timeout=5.0)

if __name__ == '__main__':
    main()
