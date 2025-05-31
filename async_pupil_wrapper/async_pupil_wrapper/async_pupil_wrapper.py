import asyncio
import rclpy
from rclpy.node import Node
from std_msgs.msg import Header
from sensor_msgs.msg import Image, CameraInfo
from cv_bridge import CvBridge

# Asynchronous API imports
from pupil_labs.realtime_api import Network, Device, receive_gaze_data, receive_video_frames
                                  # ■ siehe Code-Beispiel Streaming Gaze Data :contentReference[oaicite:0]{index=0}
                                  # ■ siehe Code-Beispiel Scene Camera Video :contentReference[oaicite:1]{index=1}

# Eigene Nachrichtendefinition für Blickdaten
from gaze_interface.msg import GazeDataAsync


class PupilAsyncNode(Node):
    def __init__(self):
        super().__init__('pupil_async_node')
        # Publisher für Gaze- und Scene-Daten
        self.gaze_pub = self.create_publisher(GazeDataAsync, 'pupil/gaze', 10)
        self.scene_pub = self.create_publisher(Image, 'pupil/scene/image_raw', 10)
        self.scene_info_pub = self.create_publisher(CameraInfo, 'pupil/scene/camera_info', 10)
        self.bridge = CvBridge()

    async def gaze_stream(self, url: str):
        """Streamed Gaze-Daten direkt vom Sensor-URL."""
        self.get_logger().info(f'Starting gaze stream: {url}')
        restart_on_disconnect = True
        async for gaze in receive_gaze_data(url, run_loop=restart_on_disconnect):
            msg = GazeDataAsync()
            msg.header.stamp = self.get_clock().now().to_msg()
            msg.header.frame_id = 'pupil_gaze'
            msg.norm_pos_x = gaze.x
            msg.norm_pos_y = gaze.y
            self.gaze_pub.publish(msg)

    async def scene_stream(self, url: str):
        """Streamed Scene-Frames direkt vom Sensor-URL."""
        self.get_logger().info(f'Starting scene stream: {url}')
        restart_on_disconnect = True
        async for frame in receive_video_frames(url, run_loop=restart_on_disconnect):
            ros_img.header.stamp = self.get_clock().now().to_msg()
            img = frame.bgr_buffer()  # numpy-Array HxWx3 BGR
            ros_img = self.bridge.cv2_to_imgmsg(img, encoding='bgr8')
            ros_img.header.frame_id = 'pupil_scene'
            self.scene_pub.publish(ros_img)
            info = CameraInfo()
            info.header = ros_img.header
            info.height = img.shape[0]
            info.width = img.shape[1]
            self.scene_info_pub.publish(info)

    async def run(self):
        # 1) Gerät finden
        self.get_logger().info('Discovering Pupil device...')
        async with Network() as network:
            dev_info = await network.wait_for_new_device(timeout_seconds=20)
        if dev_info is None:
            self.get_logger().error('No Pupil device found, aborting')
            return
        else:  self.get_logger().info('connected')

        # 2) Mit dem Device verbinden
        async with Device.from_discovered_device(dev_info) as device:
            status = await device.get_status()
            gaze_sensor = status.direct_gaze_sensor()
            world_sensor = status.direct_world_sensor()

            if not gaze_sensor.connected:
                self.get_logger().error('Gaze sensor not connected')
                return
            if not world_sensor.connected:
                self.get_logger().error('Scene camera not connected')
                return

            # 3) Beide Streams parallel starten
            await asyncio.gather(
                self.gaze_stream(gaze_sensor.url),
                self.scene_stream(world_sensor.url),
            )

def main():
    rclpy.init()
    node = PupilAsyncNode()
    try:
        # Starte den Async-Loop
        asyncio.run(node.run())
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
