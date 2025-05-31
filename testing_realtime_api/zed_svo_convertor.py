import sys
import pyzed.sl as sl
import numpy as np
import cv2
from pathlib import Path
import enum
import argparse
import os
import csv

class AppType(enum.Enum):
    """Enumeration of output modes for SVO conversion."""
    LEFT_AND_RIGHT = 0
    LEFT_AND_DEPTH = 1
    LEFT_AND_DEPTH_16 = 2


def progress_bar(percent_done, bar_length=50):
    """
    Display a textual progress bar in the console.

    :param percent_done: Percentage of work completed (0–100).
    :type percent_done: float or int
    :param bar_length: Total width of the progress bar in characters.
    :type bar_length: int
    """
    done_length = int(bar_length * percent_done / 100)
    bar = '=' * done_length + '-' * (bar_length - done_length)
    sys.stdout.write(f'[{bar}] {percent_done:.0f}%\r')
    sys.stdout.flush()


def main(opt):
    """
    Convert an SVO/SVO2 file into separate left and right/depth MP4s (and optionally a combined side-by-side MP4),
    while extracting per-frame timestamps into a CSV.

    :param opt: Parsed command‐line arguments.
    :type opt: argparse.Namespace
    :raises SystemExit: On file open or writer initialization failure.
    :return: Exit code (0 on success).
    :rtype: int
    """
    # Get input parameters
    svo_input_path = opt.input_svo_file
    output_dir = opt.output_path_dir
    left_output_path = opt.output_left_mp4
    right_output_path = opt.output_right_mp4
    combined_output_path = opt.output_combined_mp4
    mode = opt.mode
    if mode not in [0, 1, 2]:
        print("Mode muss 0, 1 oder 2 sein.")
        exit(1)

    app_type = AppType(mode)

    # Ensure output directory exists
    if not os.path.isdir(output_dir):
        os.makedirs(output_dir)

    # Specify SVO path parameter
    init_params = sl.InitParameters()
    init_params.set_from_svo_file(svo_input_path)
    init_params.svo_real_time_mode = False  # Don't convert in realtime
    init_params.coordinate_units = sl.UNIT.MILLIMETER  # Use millimeter units (for depth measurements)

    # Create ZED objects
    zed = sl.Camera()

    # Open the SVO file specified as a parameter
    err = zed.open(init_params)
    if err != sl.ERROR_CODE.SUCCESS:
        sys.stdout.write(repr(err) + "\n")
        zed.close()
        exit(1)
    
    # Get image size
    image_info = zed.get_camera_information().camera_configuration.resolution
    width = image_info.width
    height = image_info.height

    # Prepare Mat objects
    left_image = sl.Mat()
    right_image = sl.Mat()
    depth_image = sl.Mat()

    # Prepare VideoWriters
    left_writer = None
    right_writer = None
    combined_writer = None

    # Choose codec and fps
    codec = cv2.VideoWriter_fourcc(*'mp4v')
    target_fps = max(zed.get_camera_information().camera_configuration.fps, 25)

    # Create writers if paths provided
    if left_output_path:
        left_writer = cv2.VideoWriter(left_output_path, codec, target_fps, (width, height))
        if not left_writer.isOpened():
            sys.stdout.write("Cannot open left MP4 writer. Check path and permissions.\n")
            zed.close()
            exit(1)
    if right_output_path:
        right_writer = cv2.VideoWriter(right_output_path, codec, target_fps, (width, height))
        if not right_writer.isOpened():
            sys.stdout.write("Cannot open right/depth MP4 writer. Check path and permissions.\n")
            zed.close()
            exit(1)
    if combined_output_path:
        # Combined side-by-side has width doubled
        combined_writer = cv2.VideoWriter(combined_output_path, codec, target_fps, (width * 2, height))
        if not combined_writer.isOpened():
            sys.stdout.write("Cannot open combined MP4 writer. Check path and permissions.\n")
            zed.close()
            exit(1)

    rt_param = sl.RuntimeParameters()

    # Prepare CSV for timestamps
    csv_path = os.path.join(output_dir, "timestamps.csv")
    csv_file = open(csv_path, mode='w', newline='')
    csv_writer = csv.writer(csv_file)
    csv_writer.writerow(["Frame_Index", "sec", "nanosec"]);

    nb_frames = zed.get_svo_number_of_frames()
    print("Starting SVO conversion...")
    while True:
        err = zed.grab(rt_param)
        if err == sl.ERROR_CODE.SUCCESS:
            idx = zed.get_svo_position()
            ts = zed.get_timestamp(sl.TIME_REFERENCE.IMAGE)
            total_ns = ts.get_nanoseconds()
            sec = ts.get_seconds()
            nsec = int(total_ns - sec * 1_000_000_000)
            csv_writer.writerow([idx, sec, nsec])

            # Retrieve left image
            zed.retrieve_image(left_image, sl.VIEW.LEFT)
            # Retrieve right/depth based on app_type
            if app_type == AppType.LEFT_AND_RIGHT:
                zed.retrieve_image(right_image, sl.VIEW.RIGHT)
            elif app_type == AppType.LEFT_AND_DEPTH:
                zed.retrieve_image(right_image, sl.VIEW.DEPTH)
            elif app_type == AppType.LEFT_AND_DEPTH_16:
                zed.retrieve_measure(depth_image, sl.MEASURE.DEPTH)

            # Convert left to OpenCV format (BGR)
            left_ocv = left_image.get_data()
            if left_ocv is not None:
                if left_ocv.shape[2] == 4:
                    left_bgr = cv2.cvtColor(left_ocv, cv2.COLOR_RGBA2BGR)
                else:
                    left_bgr = left_ocv
                if left_writer:
                    left_writer.write(left_bgr)

            # Prepare right_ocv and write
            if app_type == AppType.LEFT_AND_DEPTH_16:
                # Depth16 retrieval: convert to 8-bit for writing
                depth_uint16 = depth_image.get_data().astype(np.uint16)
                depth_norm = cv2.normalize(depth_uint16, None, 0, 255, cv2.NORM_MINMAX).astype(np.uint8)
                right_bgr = cv2.cvtColor(depth_norm, cv2.COLOR_GRAY2BGR)
            else:
                right_ocv_raw = right_image.get_data()
                if right_ocv_raw is not None:
                    if right_ocv_raw.shape[2] == 4:
                        right_bgr = cv2.cvtColor(right_ocv_raw, cv2.COLOR_RGBA2BGR)
                    else:
                        right_bgr = right_ocv_raw
                else:
                    right_bgr = None
            if right_writer and right_bgr is not None:
                right_writer.write(right_bgr)

            # Write combined side-by-side if writer exists and both frames available
            if combined_writer and left_bgr is not None and right_bgr is not None:
                combined_frame = np.hstack((left_bgr, right_bgr))
                combined_writer.write(combined_frame)

            progress_bar((idx + 1) / nb_frames * 100, 30)

        if err == sl.ERROR_CODE.END_OF_SVOFILE_REACHED:
            progress_bar(100, 30)
            print("\nConversion complete. Exiting.")
            break

    # Release resources
    if left_writer:
        left_writer.release()
    if right_writer:
        right_writer.release()
    if combined_writer:
        combined_writer.release()
    csv_file.close()
    zed.close()
    return 0


if __name__ == "__main__":
    parser = argparse.ArgumentParser(formatter_class=argparse.RawTextHelpFormatter)
    parser.add_argument('--mode', type=int, required=True,
                        help="Mode 0: LEFT+RIGHT. Mode 1: LEFT+DEPTH. Mode 2: LEFT+DEPTH_16-bit.")
    parser.add_argument('--input_svo_file', type=str, required=True, help='Path to the .svo file')
    parser.add_argument('--output_left_mp4', type=str, required=True, help='Path to the output left .mp4 file')
    parser.add_argument('--output_right_mp4', type=str, required=True, help='Path to the output right/depth .mp4 file')
    parser.add_argument('--output_combined_mp4', type=str, default='',
                        help='(Optional) Path to combined side-by-side .mp4 file')
    parser.add_argument('--output_path_dir', type=str, required=True,
                        help='Directory for timestamps CSV')
    opt = parser.parse_args()

    # Validate inputs
    if opt.mode < 0 or opt.mode > 2:
        print("Mode should be 0, 1, or 2.")
        exit(1)
    if not opt.input_svo_file.endswith(('.svo', '.svo2')) or not os.path.isfile(opt.input_svo_file):
        print("Invalid input SVO file.")
        exit(1)
    # Validate MP4 extensions
    if not opt.output_left_mp4.endswith('.mp4') or not opt.output_right_mp4.endswith('.mp4'):
        print("Output files must have .mp4 extension.")
        exit(1)
    # Ensure output directory exists
    if not os.path.isdir(opt.output_path_dir):
        print("Output directory does not exist.")
        exit(1)

    main(opt)
