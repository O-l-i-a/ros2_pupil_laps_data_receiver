#!/usr/bin/env python3
import os
import csv

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, HistoryPolicy, ReliabilityPolicy, DurabilityPolicy
from rclpy.duration import Duration

from tf2_ros import Buffer, TransformListener, LookupException, ConnectivityException, ExtrapolationException

from apriltag_msgs.msg import AprilTagDetectionArray   # or apriltag_ros.msg.AprilTagDetectionArray


class TagDetectionsToCsv(Node):
    def __init__(self):
        super().__init__('tag_detections_to_csv')

        # Parameters
        self.declare_parameter('output_path', 'tag_detections_with_pose.csv')
        self.declare_parameter('camera_frame', 'pupil_scene')

        output_path = self.get_parameter('output_path').get_parameter_value().string_value
        self.camera_frame = self.get_parameter('camera_frame').get_parameter_value().string_value

        os.makedirs(os.path.dirname(output_path) or '.', exist_ok=True)
        self.get_logger().info(f'Writing detections + pose to: {output_path}')

        # CSV setup
        self._csv_file = open(output_path, 'w', newline='')
        self._csv_writer = csv.writer(self._csv_file)

        # NOTE: added tf_* columns
        self._csv_writer.writerow([
            'det_stamp_sec',
            'det_stamp_nanosec',
            'family',
            'id',
            'decision_margin',
            'hamming',
            'goodness',
            'center_x',
            'center_y',
            'tf_stamp_sec',
            'tf_stamp_nanosec',
            'tf_parent_frame',
            'tf_child_frame',
            'tx', 'ty', 'tz',
            'qx', 'qy', 'qz', 'qw',
        ])

        # TF2 buffer + listener (subscribes to /tf and /tf_static internally)
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # QoS similar to your apriltag node
        qos = QoSProfile(
            depth=10,
            history=HistoryPolicy.KEEP_LAST,
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
        )

        self.sub = self.create_subscription(
            AprilTagDetectionArray,
            '/detections',
            self.detections_callback,
            qos
        )

    def detections_callback(self, msg: AprilTagDetectionArray):
        det_stamp = msg.header.stamp

        for det in msg.detections:
            family = det.family
            tag_id = det.id
            dm = det.decision_margin
            hamm = det.hamming
            good = det.goodness
            cx = det.centre.x
            cy = det.centre.y

            child_frame = f'{family}:{tag_id}'

            try:
                # lookup at detection time
                tf = self.tf_buffer.lookup_transform(
                    self.camera_frame,      # target frame
                    child_frame,            # source frame
                    rclpy.time.Time.from_msg(det_stamp),
                    timeout=Duration(seconds=0.1)
                )
            except (LookupException, ConnectivityException, ExtrapolationException) as e:
                self.get_logger().warn(
                    f'No TF for {child_frame} at time {det_stamp.sec}.{det_stamp.nanosec}: {e}'
                )
                continue

            # ----- TF topic info -----
            tf_header = tf.header
            tf_stamp = tf_header.stamp
            tf_parent = tf_header.frame_id
            tf_child = tf.child_frame_id

            trans = tf.transform.translation
            rot = tf.transform.rotation

            self._csv_writer.writerow([
                det_stamp.sec,
                det_stamp.nanosec,
                family,
                tag_id,
                dm,
                hamm,
                good,
                cx,
                cy,
                tf_stamp.sec,
                tf_stamp.nanosec,
                tf_parent,
                tf_child,
                trans.x, trans.y, trans.z,
                rot.x, rot.y, rot.z, rot.w,
            ])

        self._csv_file.flush()

    def destroy_node(self):
        try:
            self._csv_file.close()
        except Exception:
            pass
        super().destroy_node()


def main(args=None):
    rclpy.init()
    node = TagDetectionsToCsv()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
