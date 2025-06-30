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
from sensor_msgs.msg import CompressedImage, Image, CameraInfo
from cv_bridge import CvBridge

from pupil_labs.realtime_api import Network, Device, receive_gaze_data, receive_video_frames, receive_eye_events_data, BlinkEventData, FixationEventData, FixationOnsetEventData
from gaze_interface.msg import GazeDataAsync  
from rclpy.qos import QoSProfile, HistoryPolicy, ReliabilityPolicy, DurabilityPolicy



from pupil_labs.realtime_api.time_echo import TimeEcho, TimeOffsetEstimator, time_ms


class PupilAsync(Node):
    def __init__(self):
        super().__init__('pupil_async')
        self.bridge = CvBridge()
        # Publisher für Gaze- und Scene-Daten
        qos = QoSProfile(
            depth= 5,
            history=HistoryPolicy.KEEP_LAST,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability = DurabilityPolicy.VOLATILE
        )
        self.gaze_pub = self.create_publisher(GazeDataAsync, 'pupil/gaze', qos)
        self.scene_pub = self.create_publisher(CompressedImage, 'pupil/scene/image_raw', 15)
        self.scene_info_pub = self.create_publisher(CameraInfo, 'pupil/scene/camera_info', 10)
        
        self.delayns = 0
        self.deviceOffsetns = 0
        self.get_logger().info('PupilAsync bereit. Warte auf /record Service…')

    async def gaze_stream(self, url: str):
        """
        Asynchroner Iterator für Blickdaten.
        Publiziert GazeDataAsync.
        """
        self.get_logger().info(f'Starting gaze stream: {url}')
        async for gaze in receive_gaze_data(url, run_loop=True):
            current_time = self.get_clock().now().to_msg()
            msg = GazeDataAsync()
            # Adjust for time offset
            if current_time.nanosec >= self.delayns:
                current_time.nanosec -= self.delayns
            else:
                current_time.sec -= 1
                current_time.nanosec += 1_000_000_000 - self.delayns
            msg.header.stamp = current_time
            msg.header.frame_id = 'pupil_gaze'
            msg.norm_pos_x = gaze.x
            msg.norm_pos_y = gaze.y
            self.gaze_pub.publish(msg)

    async def scene_stream(self, url: str):
        """
        Asynchroner Iterator für Scene-Frames.
        Publiziert CompressedImage und CameraInfo.
        """
        self.get_logger().info(f'Starting scene stream: {url}')
        async for frame in receive_video_frames(url, run_loop=True):
            current_time = self.get_clock().now().to_msg()
            img = frame.bgr_buffer()
            # Adjust for time offset
            if current_time.nanosec >= self.delayns:
                current_time.nanosec -= self.delayns
            else:
                current_time.sec -= 1
                current_time.nanosec += 1_000_000_000 - self.delayns
            # Publish image
            ros_img = self.bridge.cv2_to_compressed_imgmsg(img)
            ros_img.header.stamp = current_time
            ros_img.header.frame_id = 'pupil_scene'
            self.scene_pub.publish(ros_img)

            # Publish camera info
            info = CameraInfo()
            info.header = ros_img.header
            info.height = img.shape[0]
            info.width = img.shape[1]
            self.scene_info_pub.publish(info)

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
            status = await device.get_status()
            gaze_sensor = status.direct_gaze_sensor()
            world_sensor = status.direct_world_sensor()
            #self.delayns = int(device.time_echo().roundtrip_duration_ms.mean * 1_000_000)
            if not gaze_sensor.connected:
                self.get_logger().error('Gaze sensor not connected')
                return
            if not world_sensor.connected:
                self.get_logger().error('Scene camera not connected')
                return

            # --- spawn both coroutines as background tasks ---
            offset_task = asyncio.create_task(self._offset_loop(status))
            gaze_task  = asyncio.create_task(self.gaze_stream(gaze_sensor.url))
            scene_task = asyncio.create_task(self.scene_stream(world_sensor.url))

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
                # optionally wait for them to finish cancelling
                await asyncio.gather(gaze_task, scene_task, return_exceptions=True)


    def destroy_node(self):
        super().destroy_node()

    async def _offset_loop(self, status):
        estimator = TimeOffsetEstimator(
                status.phone.ip,
                status.phone.time_echo_port
            )
        while True:
            est = await estimator.estimate()
            # convert ms → ns
            self.delayns      = int(est.roundtrip_duration_ms.mean * 1_000_000)
            #self.deviceOffset = int(est.time_offset_ms.mean       * 1_000_000)
            #self.get_logger().info(f'estimate roundtrip: {self.delayns} ns')
            await asyncio.sleep(1.0)
def main():
    rclpy.init()
    node = PupilAsync()
    executor = SingleThreadedExecutor()
    executor.add_node(node)
    spin_thread = threading.Thread(target=executor.spin, daemon=True)
    spin_thread.start()

    try:
        asyncio.run(node.run())
    except KeyboardInterrupt:
        pass
    finally:
        executor.shutdown()
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
