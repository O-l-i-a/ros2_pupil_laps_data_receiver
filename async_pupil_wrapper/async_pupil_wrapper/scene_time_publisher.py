#!/usr/bin/env python3
import asyncio
import contextlib
import threading

import cv2
import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, HistoryPolicy, QoSProfile, ReliabilityPolicy
from builtin_interfaces.msg import Time
from sensor_msgs.msg import Image

try:
    from pupil_labs.realtime_api import Device, Network, receive_video_frames
except ModuleNotFoundError as exc:
    Device = None
    Network = None
    receive_video_frames = None
    PUPIL_IMPORT_ERROR = exc
else:
    PUPIL_IMPORT_ERROR = None


def draw_time(frame, frame_time):
    """Draw the frame datetime on top of the BGR image."""
    cv2.putText(
        frame,
        str(frame_time),
        (20, 50),
        cv2.FONT_HERSHEY_SIMPLEX,
        1.0,
        (255, 255, 255),
        thickness=1,
        lineType=cv2.LINE_8,
    )


class SceneTimePublisher(Node):
    """Discover a Pupil device, read scene frames, annotate them, and publish them."""

    def __init__(self):
        super().__init__("scene_time_publisher")
        self.declare_parameter("topic", "/pupil/scene/image_time")
        self.declare_parameter("frame_id", "pupil_scene")
        self.declare_parameter("discovery_timeout_seconds", 5.0)
        self.declare_parameter("restart_on_disconnect", True)
        self.declare_parameter("show_preview", False)

        topic = str(self.get_parameter("topic").value)
        self.frame_id = str(self.get_parameter("frame_id").value)
        self.discovery_timeout_seconds = float(
            self.get_parameter("discovery_timeout_seconds").value
        )
        self.restart_on_disconnect = bool(
            self.get_parameter("restart_on_disconnect").value
        )
        self.show_preview = bool(self.get_parameter("show_preview").value)
        self._preview_initialized = False

        qos = QoSProfile(
            depth=5,
            history=HistoryPolicy.KEEP_LAST,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
        )
        self.publisher = self.create_publisher(Image, topic, qos)
        self._stop_event = threading.Event()
        self._worker = threading.Thread(target=self._run_asyncio, daemon=True)
        self._worker.start()

        self.get_logger().info(f"Publishing annotated scene frames on {topic}")

    def _run_asyncio(self):
        with contextlib.suppress(asyncio.CancelledError):
            asyncio.run(self._stream_loop())

    async def _stream_loop(self):
        while not self._stop_event.is_set():
            try:
                await self._connect_and_stream()
            except Exception as exc:
                if self._stop_event.is_set():
                    break
                self.get_logger().error(f"Scene stream error: {exc}")
                await asyncio.sleep(1.0)

    async def _connect_and_stream(self):
        if PUPIL_IMPORT_ERROR is not None:
            raise RuntimeError(
                "The Python package 'pupil-labs-realtime-api' is not installed in the "
                "interpreter used by ROS 2. Install it with "
                "'python3 -m pip install pupil-labs-realtime-api'."
            ) from PUPIL_IMPORT_ERROR

        self.get_logger().info("Searching for a Pupil device...")
        async with Network() as network:
            dev_info = await network.wait_for_new_device(
                timeout_seconds=self.discovery_timeout_seconds
            )

        if dev_info is None:
            self.get_logger().warning("No device could be found. Retrying...")
            await asyncio.sleep(1.0)
            return

        async with Device.from_discovered_device(dev_info) as device:
            status = await device.get_status()
            sensor_world = status.direct_world_sensor()
            if not sensor_world.connected:
                self.get_logger().error(f"Scene camera is not connected to {device}")
                await asyncio.sleep(1.0)
                return

            async for frame in receive_video_frames(
                sensor_world.url, run_loop=self.restart_on_disconnect
            ):
                if self._stop_event.is_set():
                    return

                bgr_buffer = frame.bgr_buffer()
                if bgr_buffer is None:
                    continue

                if not bgr_buffer.flags["C_CONTIGUOUS"]:
                    bgr_buffer = np.ascontiguousarray(bgr_buffer)

                self.publisher.publish(
                    self._to_ros_image(
                        bgr_buffer, self._unix_ns_to_msg(int(frame.timestamp_unix_ns))
                    )
                )

                

    def _ensure_preview_initialized(self):
        if self._preview_initialized:
            return
        # Workaround for https://github.com/opencv/opencv/issues/21952.
        # Keep it out of module import so headless runs don't trigger Qt thread warnings.
        cv2.imshow("cv/av bug", np.zeros((1,), dtype=np.uint8))
        cv2.destroyAllWindows()
        self._preview_initialized = True

    def _unix_ns_to_msg(self, unix_ns: int) -> Time:
        stamp = Time()
        stamp.sec = unix_ns // 1_000_000_000
        stamp.nanosec = unix_ns % 1_000_000_000
        return stamp

    def _to_ros_image(self, image: np.ndarray, stamp: Time) -> Image:
        msg = Image()
        msg.header.stamp = stamp
        msg.header.frame_id = self.frame_id
        msg.height = int(image.shape[0])
        msg.width = int(image.shape[1])
        msg.encoding = "bgr8"
        msg.is_bigendian = 0
        msg.step = int(image.strides[0])
        msg.data = image.tobytes()
        return msg

    def destroy_node(self):
        self._stop_event.set()
        if self._worker.is_alive():
            self._worker.join(timeout=2.0)
        cv2.destroyAllWindows()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = SceneTimePublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
