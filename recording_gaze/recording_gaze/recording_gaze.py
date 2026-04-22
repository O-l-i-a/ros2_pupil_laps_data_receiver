import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter
from rcl_interfaces.msg import SetParametersResult
from rclpy.callback_groups import ReentrantCallbackGroup
import csv
import os
from gaze_interface.msg import GazeDataAsync
from std_srvs.srv import SetBool
from rclpy.qos import QoSProfile, HistoryPolicy, ReliabilityPolicy, DurabilityPolicy
import collections # For deque
import shutil

class GazeRecorder(Node):
    def __init__(self):
        super().__init__('pupil_gaze_recorder')
        self.get_logger().info('GazeRecorder has been started!')

        # Parameter für participant name
        self.declare_parameter('participant_name', 'default')
        self.participant_name = self.get_parameter('participant_name').get_parameter_value().string_value
        self.get_logger().info(f'Participant name: {self.participant_name}')
        self.temp_path = None
        self.final_path = None
        # Parameter callback für dynamische Updates
        self.add_on_set_parameters_callback(self._parameter_callback)

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
        self.buffer_size_threshold = 700 # Write to file every 500 messages
        self.flush_timer = self.create_timer(1.0, self._flush_buffer) # Flush every 1 second

    def _parameter_callback(self, params):
        """Callback für Parameter Updates"""
        for param in params:
            if param.name == 'participant_name':
                if param.type_ == Parameter.Type.STRING:
                    self.participant_name = param.value
                    self.get_logger().info(f'Updated participant name to: {self.participant_name}')
                else:
                    self.get_logger().error('participant_name must be a string')
                    return SetParametersResult(successful=False, reason="participant_name must be a string")
        
        return SetParametersResult(successful=True)

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
        
        ram_dir = f"/home/olhamelnyk/colcon_venv/ramdisk/recording_{self.participant_name}"
        final_dir = os.path.join("recordings", f"recording_{self.participant_name}")

        os.makedirs(ram_dir, exist_ok=True)
        os.makedirs(final_dir, exist_ok=True)

        self.temp_path = os.path.join(ram_dir, f"{prefix}_gaze.csv")
        self.final_path = os.path.join(final_dir, f"{prefix}_gaze.csv")
        
        self.csv_file = open(self.temp_path, 'w', newline='')

        self.csv_writer = csv.writer(self.csv_file)
        self.csv_writer.writerow(['sec','nanosec', "x", "y"])
        self.get_logger().info(f"Started recording gaze to {os.path.join(ram_dir, f'{self.temp_path}')}")

    def _stop_file_recording(self):
        self._flush_buffer() # Flush any remaining data before closing
        if self.csv_file:
            self.csv_file.close()
            self.csv_file = None
        self.get_logger().info("Stopped recording gaze.")
        if self.temp_path and self.final_path:
            shutil.move(self.temp_path, self.final_path)

        self.temp_path = None
        self.final_path = None

def main(args=None):
    rclpy.init(args=args)
    node = GazeRecorder()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()