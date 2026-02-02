#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.time import Time
from tf2_msgs.msg import TFMessage
import csv
from pathlib import Path


class TagLatencyLogger(Node):
    def __init__(self):
        super().__init__("tag_latency_logger")

        # You can adapt this pattern to your frame naming scheme
        self.tag_frame_prefix = "tag36h11:"  
        # Create subscriber to /tf
        self.tf_sub = self.create_subscription(
            TFMessage,
            "/tf",
            self.tf_callback,
            10,
        )

        # Prepare CSV file
        log_path = Path("tag_latency_log.csv")
        self._csv_file = log_path.open("w", newline="")
        self._csv_writer = csv.writer(self._csv_file)
        self._csv_writer.writerow([
            "tf_child_frame_id",
            "tf_parent_frame_id",
            "stamp_sec",
            "stamp_nanosec",
            "now_sec",
            "now_nanosec",
            "latency_ms",
        ])

        self.get_logger().info(f"TagLatencyLogger started, writing to {log_path.resolve()}")

    def tf_callback(self, msg: TFMessage):
        now = self.get_clock().now()

        for t in msg.transforms:
            child = t.child_frame_id

            # Only log Apriltag-related frames
            if not child.startswith(self.tag_frame_prefix):
                continue

            stamp = Time.from_msg(t.header.stamp)
            latency_ns = (now - stamp).nanoseconds
            latency_ms = latency_ns / 1e6

            # Write a line to CSV
            self._csv_writer.writerow([
                child,
                t.header.frame_id,
                stamp.seconds_nanoseconds()[0],
                stamp.seconds_nanoseconds()[1],
                now.seconds_nanoseconds()[0],
                now.seconds_nanoseconds()[1],
                latency_ms,
            ])

            # Optional: log occasionally
            self.get_logger().info(
                f"TF for {child} latency: {latency_ms:.2f} ms "
                f"(stamp={stamp.nanoseconds}, now={now.nanoseconds})"
            )

    def destroy_node(self):
        try:
            self._csv_file.close()
        except Exception:
            pass
        super().destroy_node()


def main():
    rclpy.init()
    node = TagLatencyLogger()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
