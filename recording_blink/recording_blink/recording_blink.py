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

from blink_interface.msg import EyeStateData


class EyeStateRecorder(Node):
    def __init__(self):
        super().__init__("pupil_eye_state_recorder")
        self.get_logger().info("EyeStateRecorder has been started!")

        self.declare_parameter("participant_name", "default")
        self.declare_parameter("queue_size", 2000)
        self.declare_parameter("batch_size", 200)
        self.participant_name = self.get_parameter("participant_name").value
        self.queue_size = int(self.get_parameter("queue_size").value)
        self.batch_size = int(self.get_parameter("batch_size").value)
        self.get_logger().info(f"Participant name: {self.participant_name}")

        self.add_on_set_parameters_callback(self._parameter_callback)

        qos = QoSProfile(
            depth=20,
            history=HistoryPolicy.KEEP_LAST,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
        )
        self.subscription = self.create_subscription(
            EyeStateData, "pupil/eye_state", self.listener_callback, qos
        )
        self.create_service(SetBool, "record_pupil_eye_state", self._srv_cb)
        self.create_service(SetBool, "record_pupil_blink", self._srv_cb)

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
            msg.event_name,
            int(msg.event_type),
            bool(msg.has_end_time),
            float(msg.start_time_ns),
            float(msg.end_time_ns),
            float(msg.rtp_ts_unix_seconds),
            float(msg.start_gaze_x),
            float(msg.start_gaze_y),
            float(msg.end_gaze_x),
            float(msg.end_gaze_y),
            float(msg.mean_gaze_x),
            float(msg.mean_gaze_y),
            float(msg.amplitude_pixels),
            float(msg.amplitude_angle_deg),
            float(msg.mean_velocity),
            float(msg.max_velocity),
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

        path = os.path.join(session_dir, f"{prefix}_eye_state.csv")
        with self.file_lock:
            self.csv_file = open(path, "w", newline="")
            self.csv_writer = csv.writer(self.csv_file)
            self.csv_writer.writerow(
                [
                    "sec",
                    "nanosec",
                    "event_name",
                    "event_type",
                    "has_end_time",
                    "start_time_ns",
                    "end_time_ns",
                    "rtp_ts_unix_seconds",
                    "start_gaze_x",
                    "start_gaze_y",
                    "end_gaze_x",
                    "end_gaze_y",
                    "mean_gaze_x",
                    "mean_gaze_y",
                    "amplitude_pixels",
                    "amplitude_angle_deg",
                    "mean_velocity",
                    "max_velocity",
                ]
            )

        self.msg_received = 0
        self.msg_written = 0
        self.msg_dropped = 0
        self.recording = True
        self.get_logger().info(f"Started recording eye state to: {path}")

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
            f"Stopped eye state recording. received={self.msg_received}, "
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
    node = EyeStateRecorder()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
