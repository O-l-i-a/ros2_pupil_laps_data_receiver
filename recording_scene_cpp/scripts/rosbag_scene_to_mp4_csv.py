#!/usr/bin/env python3
import argparse
import csv
import os
import shutil
import sys

import cv2
import numpy as np
import rosbag2_py
from cv_bridge import CvBridge
from rclpy.serialization import deserialize_message
from sensor_msgs.msg import Image


def open_reader(bag_dir: str):
    converter_options = rosbag2_py.ConverterOptions(
        input_serialization_format="cdr",
        output_serialization_format="cdr",
    )
    last_err = None
    for storage_id in ("sqlite3", "mcap"):
        reader = rosbag2_py.SequentialReader()
        storage_options = rosbag2_py.StorageOptions(uri=bag_dir, storage_id=storage_id)
        try:
            reader.open(storage_options, converter_options)
            return reader, storage_id
        except Exception as e:  # noqa: BLE001
            last_err = e
    raise RuntimeError(f"Could not open bag '{bag_dir}' (tried sqlite3/mcap): {last_err}")


def image_to_mono8(msg: Image, bridge: CvBridge):
    if msg.encoding == "mono8":
        flat = np.frombuffer(msg.data, dtype=np.uint8)
        return flat.reshape((msg.height, msg.step))[:, : msg.width]
    cv_img = bridge.imgmsg_to_cv2(msg, desired_encoding="mono8")
    return cv_img


def convert_bag(
    bag_dir: str,
    topic: str,
    fps: float,
    output_mp4: str,
    output_csv: str,
):
    if fps <= 0.0:
        raise ValueError("fps must be > 0")

    reader, storage_id = open_reader(bag_dir)
    topic_types = {t.name: t.type for t in reader.get_all_topics_and_types()}
    if topic not in topic_types:
        raise RuntimeError(f"Topic '{topic}' not found in bag. Available: {list(topic_types.keys())}")
    if topic_types[topic] != "sensor_msgs/msg/Image":
        raise RuntimeError(f"Topic '{topic}' has type {topic_types[topic]}, expected sensor_msgs/msg/Image")

    print(f"Opened bag '{bag_dir}' with storage '{storage_id}'")
    print(f"Reading topic: {topic}")
    print(f"Writing video: {output_mp4}")
    print(f"Writing csv:   {output_csv}")

    bridge = CvBridge()
    writer = None
    frame_count = 0

    os.makedirs(os.path.dirname(output_mp4) or ".", exist_ok=True)
    os.makedirs(os.path.dirname(output_csv) or ".", exist_ok=True)

    with open(output_csv, "w", newline="", encoding="utf-8") as csv_file:
        csv_writer = csv.writer(csv_file)
        csv_writer.writerow(["sec", "nanosec", "frame_idx"])

        while reader.has_next():
            topic_name, serialized_data, _ = reader.read_next()
            if topic_name != topic:
                continue

            msg = deserialize_message(serialized_data, Image)
            frame = image_to_mono8(msg, bridge)

            if writer is None:
                h, w = frame.shape[:2]
                fourcc = cv2.VideoWriter_fourcc(*"mp4v")
                writer = cv2.VideoWriter(output_mp4, fourcc, fps, (w, h), False)
                if not writer.isOpened():
                    raise RuntimeError(f"Failed to open VideoWriter: {output_mp4}")

            writer.write(frame)
            csv_writer.writerow([msg.header.stamp.sec, msg.header.stamp.nanosec, frame_count])
            frame_count += 1

            if frame_count % 300 == 0:
                print(f"Processed {frame_count} frames...")

    if writer is not None:
        writer.release()

    if frame_count == 0:
        raise RuntimeError("No frames were found on the requested topic.")

    print(f"Done. Total frames: {frame_count}")


def main():
    parser = argparse.ArgumentParser(
        description="Convert ROS2 bag scene images to MP4 + CSV timestamps."
    )
    parser.add_argument("--bag-dir", required=True, help="Path to rosbag directory (e.g. pupil_scene_bag)")
    parser.add_argument("--topic", default="/pupil/scene/image_raw", help="Image topic in bag")
    parser.add_argument("--fps", type=float, default=30.0, help="Output MP4 FPS")
    parser.add_argument("--output-mp4", default=None, help="Output mp4 path")
    parser.add_argument("--output-csv", default=None, help="Output csv path")
    parser.add_argument(
        "--delete-bag",
        action="store_true",
        help="Delete bag directory after successful conversion",
    )
    args = parser.parse_args()

    bag_dir = os.path.abspath(args.bag_dir)
    if not os.path.isdir(bag_dir):
        print(f"Bag directory not found: {bag_dir}", file=sys.stderr)
        sys.exit(2)

    base_name = os.path.basename(os.path.normpath(bag_dir))
    out_dir = os.path.dirname(bag_dir)
    output_mp4 = args.output_mp4 or os.path.join(out_dir, f"{base_name}.mp4")
    output_csv = args.output_csv or os.path.join(out_dir, f"{base_name}_timestamps.csv")

    try:
        convert_bag(
            bag_dir=bag_dir,
            topic=args.topic,
            fps=args.fps,
            output_mp4=output_mp4,
            output_csv=output_csv,
        )
    except Exception as e:  # noqa: BLE001
        print(f"Conversion failed: {e}", file=sys.stderr)
        sys.exit(1)

    if args.delete_bag:
        try:
            shutil.rmtree(bag_dir)
            print(f"Deleted bag directory: {bag_dir}")
        except Exception as e:  # noqa: BLE001
            print(f"Converted, but failed to delete bag: {e}", file=sys.stderr)
            sys.exit(3)


if __name__ == "__main__":
    main()
