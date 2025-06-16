import rclpy
from rclpy.node import Node
from rclpy.callback_groups import ReentrantCallbackGroup
import csv
import os
from gaze_interface.msg import GazeDataAsync
from std_srvs.srv import SetBool
from rclpy.qos import QoSProfile, HistoryPolicy, ReliabilityPolicy, DurabilityPolicy
import collections # For deque

class GazeRecorder(Node):
    def __init__(self):
        super().__init__('GazeRecorder')
        self.get_logger().info('GazeRecorder has been started!')
        qos = QoSProfile(
            depth=5,
            history=HistoryPolicy.KEEP_LAST,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability = DurabilityPolicy.VOLATILE

        )
        self.cb_group = ReentrantCallbackGroup()
        self.subscription = self.create_subscription(
            GazeDataAsync,
            'pupil/gaze',
            self.listener_callback,
            qos,
            callback_group= self.cb_group
        )
        self.create_service(SetBool, 'record_pupil_gaze', self._srv_cb)
        self.recording = False
        self.csv_file = None
        self.csv_writer = None
        self.gaze_buffer = collections.deque(maxlen=5000) # Buffer for gaze data
        self.buffer_size_threshold = 500 # Write to file every 500 messages
        self.flush_timer = self.create_timer(1.0, self._flush_buffer) # Flush every 1 second

    def _srv_cb(self, req, resp):
        want_start = bool(req.data)
        if want_start == self.recording:
            resp.success = False; resp.message = 'No change'
            return resp

        if want_start:
            self._start_file_recording()
        else:
            self._stop_file_recording()

        self.recording = want_start
        resp.success = True
        resp.message = 'started' if want_start else 'stopped'
        return resp

    def listener_callback(self, msg):
        if not self.recording:
            return
        try:
            # Append to buffer instead of immediate write
            self.gaze_buffer.append([msg.header.stamp.sec, msg.header.stamp.nanosec, msg.norm_pos_x, msg.norm_pos_y])
            if len(self.gaze_buffer) >= self.buffer_size_threshold:
                self._flush_buffer()
        except Exception as e:
            self.get_logger().error(f"Failed to process gaze: {e}")

    def _flush_buffer(self):
        if self.csv_writer and self.gaze_buffer:
            try:
                # Write all buffered data in one go
                self.csv_writer.writerows(list(self.gaze_buffer))
                self.gaze_buffer.clear()
                self.csv_file.flush() # Ensure data is written to disk
            except Exception as e:
                self.get_logger().error(f"Failed to flush gaze buffer: {e}")

    def _start_file_recording(self):
        ts = self.get_clock().now().to_msg()
        prefix = f"{ts.sec}"
        base_dir = 'recordings'
        session_dir = os.path.join(base_dir, f"recording_{ts.sec}")
        os.makedirs(session_dir, exist_ok=True)
        self.csv_file = open(os.path.join(session_dir, f"{prefix}_gaze.csv"), 'w', newline='')
        self.csv_writer = csv.writer(self.csv_file)
        self.csv_writer.writerow(['sec','nanosec', "x", "y"])
        self.get_logger().info(f"Started recording gaze to {os.path.join(session_dir, f'{prefix}_gaze.csv')}")

    def _stop_file_recording(self):
        self._flush_buffer() # Flush any remaining data before closing
        if self.csv_file:
            self.csv_file.close()
            self.csv_file = None
        self.get_logger().info("Stopped recording gaze.")

def main(args=None):
    rclpy.init(args=args)
    node = GazeRecorder()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()