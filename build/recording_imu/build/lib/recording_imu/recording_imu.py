import csv
import os
import queue
import threading

import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter
from rcl_interfaces.msg import SetParametersResult
from rclpy.qos import QoSProfile, HistoryPolicy, ReliabilityPolicy, DurabilityPolicy
from std_srvs.srv import SetBool

from imu_interface.msg import ImuData


class ImuRecorder(Node):
    def __init__(self):
        super().__init__("pupil_imu_recorder")
        self.get_logger().info("ImuRecorder has been started!")

        self.declare_parameter("participant_name", "default")
        self.declare_parameter("queue_size", 30000)
        self.declare_parameter("batch_size", 1000)
        self.participant_name = self.get_parameter("participant_name").value
        self.queue_size = int(self.get_parameter("queue_size").value)
        self.batch_size = int(self.get_parameter("batch_size").value)
        self.get_logger().info(f"Participant name: {self.participant_name}")

        self.add_on_set_parameters_callback(self._parameter_callback)

        qos = QoSProfile(
            depth=100,
            history=HistoryPolicy.KEEP_LAST,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
        )
        self.subscription = self.create_subscription(
            ImuData, "pupil/imu", self.listener_callback, qos
        )
        self.create_service(SetBool, "record_pupil_imu", self._srv_cb)

        self.recording = False
        self.csv_file = None
        self.csv_writer = None
        self.file_lock = threading.Lock()

        self.data_queue = queue.Queue(maxsize=self.queue_size)
        self.running = True
        self.writer_thread = threading.Thread(target=self._writer_loop, daemon=True)
        self.writer_thread.start()

        self.msg_received = 0
        self.msg_written = 0
        self.msg_dropped = 0

    def _parameter_callback(self, params):
        for param in params:
            if param.name == "participant_name":
                if param.type_ == Parameter.Type.STRING:
                    self.participant_name = param.value
                    self.get_logger().info(
                        f"Updated participant name to: {self.participant_name}"
                    )
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
            self._start_file_recording()
        else:
            self._stop_file_recording()

        resp.success = True
        resp.message = "started" if want_start else "stopped"
        return resp

    def listener_callback(self, msg):
        if not self.recording:
            return

        row = [
            msg.header.stamp.sec,
            msg.header.stamp.nanosec,
            int(msg.timestamp_unix_ns),
            float(msg.timestamp_unix_seconds),
            float(msg.acceleration.x),
            float(msg.acceleration.y),
            float(msg.acceleration.z),
            float(msg.gyroscope.x),
            float(msg.gyroscope.y),
            float(msg.gyroscope.z),
            float(msg.quaternion.x),
            float(msg.quaternion.y),
            float(msg.quaternion.z),
            float(msg.quaternion.w),
        ]
        try:
            self.msg_received += 1
            self.data_queue.put_nowait(row)
        except queue.Full:
            self.msg_dropped += 1

    def _writer_loop(self):
        while self.running:
            try:
                first = self.data_queue.get(timeout=0.2)
            except queue.Empty:
                continue

            if first is None:
                self.data_queue.task_done()
                break

            batch = [first]
            while len(batch) < self.batch_size:
                try:
                    item = self.data_queue.get_nowait()
                except queue.Empty:
                    break
                if item is None:
                    self.data_queue.task_done()
                    self.running = False
                    break
                batch.append(item)

            with self.file_lock:
                if self.csv_writer is not None:
                    self.csv_writer.writerows(batch)
                    self.msg_written += len(batch)

            for _ in batch:
                self.data_queue.task_done()

    def _start_file_recording(self):
        ts = self.get_clock().now().to_msg()
        prefix = f"{ts.sec}"
        base_dir = "recordings"
        session_dir = os.path.join(base_dir, f"recording_{self.participant_name}")
        os.makedirs(session_dir, exist_ok=True)

        path = os.path.join(session_dir, f"{prefix}_imu.csv")
        with self.file_lock:
            self.csv_file = open(path, "w", newline="")
            self.csv_writer = csv.writer(self.csv_file)
            self.csv_writer.writerow(
                [
                    "sec",
                    "nanosec",
                    "timestamp_unix_ns",
                    "timestamp_unix_seconds",
                    "accel_x",
                    "accel_y",
                    "accel_z",
                    "gyro_x",
                    "gyro_y",
                    "gyro_z",
                    "quat_x",
                    "quat_y",
                    "quat_z",
                    "quat_w",
                ]
            )

        self.msg_received = 0
        self.msg_written = 0
        self.msg_dropped = 0
        self.recording = True
        self.get_logger().info(f"Started recording IMU to: {path}")

    def _stop_file_recording(self):
        self.recording = False
        self.data_queue.join()

        with self.file_lock:
            if self.csv_file:
                self.csv_file.flush()
                self.csv_file.close()
            self.csv_file = None
            self.csv_writer = None

        self.get_logger().info(
            f"Stopped IMU recording. received={self.msg_received}, "
            f"written={self.msg_written}, dropped={self.msg_dropped}"
        )

    def destroy_node(self):
        self.recording = False
        self.data_queue.join()
        self.running = False
        try:
            self.data_queue.put_nowait(None)
        except queue.Full:
            pass
        if self.writer_thread.is_alive():
            self.writer_thread.join(timeout=2.0)
        with self.file_lock:
            if self.csv_file:
                self.csv_file.close()
            self.csv_file = None
            self.csv_writer = None
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = ImuRecorder()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
