#!/usr/bin/env python3
import csv
import os
import shutil
import signal
import subprocess
import threading
import tempfile
import time
from pathlib import Path

import cv2
import numpy as np
import rclpy
import rosbag2_py
from cv_bridge import CvBridge
from rcl_interfaces.msg import SetParametersResult
from rclpy.node import Node
from rclpy.parameter import Parameter
from rclpy.serialization import deserialize_message
from sensor_msgs.msg import Image, CompressedImage
from std_srvs.srv import SetBool


def _open_reader(bag_dir: str):
    converter_options = rosbag2_py.ConverterOptions(
        input_serialization_format="cdr",
        output_serialization_format="cdr",
    )
    reader = rosbag2_py.SequentialReader()
    storage_options = rosbag2_py.StorageOptions(uri=bag_dir, storage_id="mcap")
    reader.open(storage_options, converter_options)
    return reader

def _img_to_mono8(msg: Image, bridge: CvBridge):
    if msg.encoding == "mono8":
        flat = np.frombuffer(msg.data, dtype=np.uint8)
        return flat.reshape((msg.height, msg.step))[:, : msg.width]
    return bridge.imgmsg_to_cv2(msg, desired_encoding="mono8")



class SceneBagRecorder(Node):
    def __init__(self):
        super().__init__("pupil_scene_bag_recorder")
        self.get_logger().info("SceneBagRecorder has been started!")

        self.declare_parameter("participant_name", "default")
        self.declare_parameter("topic", "/pupil/scene/image_raw/compressed")
        self.declare_parameter("target_fps", 30.0)
        self.declare_parameter("output_codec", "mp4v")
        self.declare_parameter("delete_bag_after_convert", True)

        self.participant_name = self.get_parameter("participant_name").value
        self.topic = self.get_parameter("topic").value
        self.target_fps = float(self.get_parameter("target_fps").value)
        self.output_codec = self.get_parameter("output_codec").value
        self.delete_bag_after_convert = bool(self.get_parameter("delete_bag_after_convert").value)

        self.add_on_set_parameters_callback(self._parameter_callback)
        self.create_service(SetBool, "record_pupil_scene_bag", self._srv_cb)

        self.recording = False
        self.bag_proc = None
        self.bag_dir = None
        self.qos_override_path = None
        self._convert_thread = None
        self._lock = threading.Lock()

    def _parameter_callback(self, params):
        for param in params:
            if param.name == "participant_name":
                if param.type_ == Parameter.Type.STRING:
                    self.participant_name = param.value
                    self.get_logger().info(f"Updated participant name to: {self.participant_name}")
                else:
                    return SetParametersResult(
                        successful=False,
                        reason="participant_name must be a string",
                    )
        return SetParametersResult(successful=True)

    def _srv_cb(self, req, resp):
        want_start = bool(req.data)
        if want_start == self.recording:
            resp.success = False
            resp.message = "No change"
            return resp

        if want_start:
            ok, msg = self._start_recording()
        else:
            ok, msg = self._stop_recording()

        resp.success = ok
        resp.message = msg
        return resp

    def _session_dir(self):
        return Path("recordings") / f"recording_{self.participant_name}"

    def _start_recording(self):
        with self._lock:
            if self._convert_thread is not None and self._convert_thread.is_alive():
                return False, "Conversion still running; wait before starting a new recording"

            ts = int(self.get_clock().now().seconds_nanoseconds()[0])
            session_dir = self._session_dir()
            session_dir.mkdir(parents=True, exist_ok=True)
            self.bag_dir = session_dir / f"{ts}_scene_bag"
            qos_yaml = (
                f"{self.topic}:\n"
                "  reliability: reliable\n"
                "  history: keep_last\n"
                "  depth: 10\n"
                "  durability: volatile\n"
            )
            qos_file = tempfile.NamedTemporaryFile(
                mode="w", suffix="_scene_qos.yaml", delete=False
            )
            qos_file.write(qos_yaml)
            qos_file.flush()
            qos_file.close()
            self.qos_override_path = qos_file.name

            cmd = [
                "ros2",
                "bag",
                "record",
                "--storage",
                "mcap",
                "--qos-profile-overrides-path",
                self.qos_override_path,
                "-o",
                str(self.bag_dir),
                "--topics",
                self.topic
            ]
            try:
                self.bag_proc = subprocess.Popen(cmd)
            except Exception as e:  # noqa: BLE001
                self.bag_proc = None
                self.bag_dir = None
                if self.qos_override_path:
                    try:
                        os.unlink(self.qos_override_path)
                    except OSError:
                        pass
                    self.qos_override_path = None
                return False, f"Failed to start ros2 bag: {e}"

            self.recording = True
            self.get_logger().info(f"Started ros2 bag recording: {self.bag_dir}")
            return True, "started"

    def _stop_recording(self):
        with self._lock:
            proc = self.bag_proc
            bag_dir = self.bag_dir
            qos_override_path = self.qos_override_path
            self.bag_proc = None
            self.bag_dir = None
            self.qos_override_path = None
            self.recording = False

        if proc is None or bag_dir is None:
            return False, "Bag process was not running"

        try:
            proc.send_signal(signal.SIGINT)
            proc.wait(timeout=10.0)
        except subprocess.TimeoutExpired:
            self.get_logger().warning("ros2 bag did not stop on SIGINT, terminating...")
            proc.terminate()
            try:
                proc.wait(timeout=5.0)
            except subprocess.TimeoutExpired:
                self.get_logger().warning("ros2 bag terminate timeout, killing...")
                proc.kill()
                proc.wait(timeout=5.0)

        # Allow time for OS to flush the bag file to disk
        time.sleep(2.0)

        self._convert_thread = threading.Thread(
            target=self._convert_and_cleanup, args=(Path(bag_dir), qos_override_path), daemon=True
        )
        self._convert_thread.start()
        return True, "stopped (conversion started in background)"
    
    

    def _convert_and_cleanup(self, bag_dir: Path, qos_override_path: str | None):
        def _compressed_to_mono8(msg: CompressedImage):
            arr = np.frombuffer(msg.data, dtype=np.uint8)
            frame = cv2.imdecode(arr, cv2.IMREAD_GRAYSCALE)
            if frame is None:
                raise RuntimeError("Failed to decode CompressedImage frame")
            return frame
        try:
            self.get_logger().info(f"Converting bag: {bag_dir}")
            reader = _open_reader(str(bag_dir))
            topic_types = {t.name: t.type for t in reader.get_all_topics_and_types()}
            
            if self.topic not in topic_types:
                raise RuntimeError(f"Topic {self.topic} not found in bag")
            
            t = topic_types[self.topic]
            if t not in ("sensor_msgs/msg/Image", "sensor_msgs/msg/CompressedImage"):
                raise RuntimeError(f"Unsupported topic type: {t}")
            output_mp4 = bag_dir.with_suffix(".mp4")
            output_csv = bag_dir.parent / f"{bag_dir.name}_timestamps.csv"

            bridge = CvBridge()
            writer = None
            frame_count = 0
            total_frames = 0
            last_progress_percent = -1
            self.get_logger().info(
                f"CONVERT_START bag={bag_dir} total_frames={total_frames} codec={self.output_codec}"
            )

            with open(output_csv, "w", newline="", encoding="utf-8") as csv_file:
                csv_writer = csv.writer(csv_file)
                csv_writer.writerow(["sec", "nanosec", "frame_idx"])

                while reader.has_next():
                    topic_name, serialized_data, _ = reader.read_next()
                    if topic_name != self.topic:
                        continue
                    if t == "sensor_msgs/msg/CompressedImage":
                        msg = deserialize_message(serialized_data, CompressedImage)
                        frame = _compressed_to_mono8(msg)
                    else:
                        msg = deserialize_message(serialized_data, Image)
                        frame = _img_to_mono8(msg, bridge)

                    if writer is None:
                        h, w = frame.shape[:2]
                        fourcc = cv2.VideoWriter_fourcc(*self.output_codec)
                        writer = cv2.VideoWriter(
                            str(output_mp4), fourcc, self.target_fps, (w, h), False
                        )
                        if not writer.isOpened():
                            raise RuntimeError(f"Failed to open VideoWriter: {output_mp4}")

                    writer.write(frame)
                    csv_writer.writerow([msg.header.stamp.sec, msg.header.stamp.nanosec, frame_count])
                    frame_count += 1
                    if total_frames > 0:
                        progress_percent = min(100, int((frame_count * 100) / total_frames))
                        if progress_percent != last_progress_percent and (
                            progress_percent == 100 or progress_percent % 5 == 0
                        ):
                            last_progress_percent = progress_percent
                            self.get_logger().info(
                                f"CONVERT_PROGRESS percent={progress_percent} frame={frame_count} total={total_frames}"
                            )

            if writer is not None:
                writer.release()

            if frame_count == 0:
                raise RuntimeError("No frames found in bag for scene topic")

            self.get_logger().info(
                f"Conversion finished: frames={frame_count}, mp4={output_mp4}, csv={output_csv}"
            )
            self.get_logger().info(
                f"CONVERT_DONE percent=100 frame={frame_count} total={total_frames} video={output_mp4} csv={output_csv}"
            )

            if self.delete_bag_after_convert:
                shutil.rmtree(bag_dir)
                self.get_logger().info(f"Deleted bag directory: {bag_dir}")
        except Exception as e:  # noqa: BLE001
            self.get_logger().error(f"Bag conversion failed: {e}")
            self.get_logger().error(f"CONVERT_FAILED error={e}")
        finally:
            if qos_override_path:
                try:
                    os.unlink(qos_override_path)
                except OSError:
                    pass

    def destroy_node(self):
        with self._lock:
            proc = self.bag_proc
            qos_override_path = self.qos_override_path
            self.bag_proc = None
            self.qos_override_path = None
            self.recording = False
        if proc is not None and proc.poll() is None:
            try:
                proc.send_signal(signal.SIGINT)
                proc.wait(timeout=5.0)
            except Exception:  # noqa: BLE001
                proc.kill()
        if qos_override_path:
            try:
                os.unlink(qos_override_path)
            except OSError:
                pass
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = SceneBagRecorder()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
