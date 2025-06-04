#!/usr/bin/env python3
import asyncio
import os
import csv
import cv2
import threading

import rclpy
from rclpy.node import Node
from rclpy.executors import SingleThreadedExecutor
from std_srvs.srv import SetBool
from sensor_msgs.msg import Image, CameraInfo
from cv_bridge import CvBridge
from pupil_labs.realtime_api.time_echo import Estimate

from pupil_labs.realtime_api import Network, Device, receive_gaze_data, receive_video_frames
from gaze_interface.msg import GazeDataAsync  # Passe hier dein Package/Msg an


class PupilAsyncRecorder(Node):
    def __init__(self):
        super().__init__('pupil_async_recorder')
        self.bridge = CvBridge()
        # Publisher für Gaze- und Scene-Daten
        self.gaze_pub = self.create_publisher(GazeDataAsync, 'pupil/gaze', 10)
        self.scene_pub = self.create_publisher(Image, 'pupil/scene/image_raw', 15)
        self.scene_info_pub = self.create_publisher(CameraInfo, 'pupil/scene/camera_info', 10)
        self.delayns = 0
        # Service-Server zum Start/Stoppen der lokalen Aufzeichnung

        self.get_logger().info('PupilAsyncRecorder bereit. Warte auf /record Service…')

    

    async def gaze_stream(self, url: str):
        """
        Asynchroner Iterator für Blickdaten.
        Schreibt in Gaze-CSV, wenn self.recording == True.
        """
        self.get_logger().info(f'Starting gaze stream: {url}')
        async for gaze in receive_gaze_data(url, run_loop=True):
            # 1) ROS-Publish
            msg = GazeDataAsync()
            current_time = self.get_clock().now().to_msg()
            delay_ns = self.delayns
            if current_time.nanosec >= delay_ns:
            # No need to borrow a second
                current_time.nanosec = current_time.nanosec - delay_ns
            else:
            # Need to borrow 1 second:
            #   new_nanosec = (old_nanosec + 1_000_000_000) - delay_ns
                current_time.sec -= 1
                current_time.nanosec = current_time.nanosec + 1_000_000_000 - delay_ns
            msg.header.stamp = current_time
            msg.header.frame_id = 'pupil_gaze'
            msg.norm_pos_x = gaze.x
            msg.norm_pos_y = gaze.y
            self.gaze_pub.publish(msg)


    async def scene_stream(self, url: str):
        """
        Asynchroner Iterator für Scene-Frames.
        Schreibt Video und Scene-CSV (Timestamp), wenn self.recording == True.
        """
        self.get_logger().info(f'Starting scene stream: {url}')
        async for frame in receive_video_frames(url, run_loop=True):
            img = frame.bgr_buffer()  # HxWx3 BGR numpy.ndarray
            current_time = self.get_clock().now().to_msg()
            delay_ns = self.delayns
            if current_time.nanosec >= delay_ns:
            # No need to borrow a second
                current_time.nanosec = current_time.nanosec - delay_ns
            else:
            # Need to borrow 1 second:
            #   new_nanosec = (old_nanosec + 1_000_000_000) - delay_ns
                current_time.sec -= 1
                current_time.nanosec = current_time.nanosec + 1_000_000_000 - delay_ns
            # 1) ROS-Publish
            ros_img = self.bridge.cv2_to_imgmsg(img, encoding='bgr8')
            ros_img.header.stamp = current_time
            ros_img.header.frame_id = 'pupil_scene'
            self.scene_pub.publish(ros_img)

            info = CameraInfo()
            info.header = ros_img.header
            info.height = img.shape[0]
            info.width = img.shape[1]
            self.scene_info_pub.publish(info)           

    async def run(self):
        """
        Device-Discovery und anschließendes Starten der Streams.
        """
        self.get_logger().info('Discovering Pupil device...')
        async with Network() as network:
            dev_info = await network.wait_for_new_device(timeout_seconds=20)
        if dev_info is None:
            self.get_logger().error('No Pupil device found, aborting')
            return
        else:
            self.get_logger().info('Pupil device connected')

        async with Device.from_discovered_device(dev_info) as device:
            status = await device.get_status()
            gaze_sensor = status.direct_gaze_sensor()
            world_sensor = status.direct_world_sensor()
            #async with Estimate(device) as time_estimate:
            #    offset, rtt = await time_estimate.get()
            #    self.delayns = int(rtt * 1_000_000_000)  # convert seconds to nanoseconds
            #    self.get_logger().info(f"Clock offset: {offset} s, RTT: {rtt} s")
            #self.delayns = int(device.time_echo().roundtrip_duration_ms.mean * 1_000_000)
            if not gaze_sensor.connected:
                self.get_logger().error('Gaze sensor not connected')
                return
            if not world_sensor.connected:
                self.get_logger().error('Scene camera not connected')
                return

            # Beide Streams parallel starten
            await asyncio.gather(
                self.gaze_stream(gaze_sensor.url),
                self.scene_stream(world_sensor.url),
            )

    def destroy_node(self):
        super().destroy_node()


def main():
    rclpy.init()

    # 1) Node-Instanz erstellen
    node = PupilAsyncRecorder()

    # 2) Executor anlegen und Node hinzufügen
    executor = SingleThreadedExecutor()
    executor.add_node(node)

    # 3) ROS-Spin in eigenem Thread starten
    spin_thread = threading.Thread(target=executor.spin, daemon=True)
    spin_thread.start()

    # 4) Asynchrone Device-Discovery und Streaming starten
    try:
        asyncio.run(node.run())
    except KeyboardInterrupt:
        pass
    finally:
        # 5) Sauber beenden
        executor.shutdown()
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
