#!/usr/bin/env python3
import argparse
import os
import sys

import cv2
import numpy as np

try:
    from pupil_apriltags import Detector as PupilAprilTagDetector
except Exception:
    PupilAprilTagDetector = None

# Pupil Labs calibration defaults (plumb_bob / OpenCV compatible)
DEFAULT_K = [
    885.2742523870837, 0.0, 791.658709111015,
    0.0, 884.8206205602181, 608.7913039708213,
    0.0, 0.0, 1.0,
]
DEFAULT_D = [
    -0.1293166258801035,
    0.10818378184611264,
    -1.778223371550883e-05,
    -0.0003154490452726243,
    0.0007545474314415139,
    0.16908078572078886,
    0.051976233163505144,
    0.026203768965681915,
]


def parse_arguments():
    parser = argparse.ArgumentParser(
        description=(
            "Reads a video file, detects AprilTags in each frame, "
            "and writes an output video with tag detections overlaid."
        )
    )
    parser.add_argument(
        "--input_video", type=str, required=True,
        help="Path to input video file."
    )
    parser.add_argument(
        "--output_video", type=str, required=True,
        help="Path to output video file with tag overlays."
    )
    parser.add_argument(
        "--tag_family", type=str, default="36h11",
        help="AprilTag family: 16h5 | 25h9 | 36h10 | 36h11 (default: 36h11)."
    )
    parser.add_argument(
        "--tag_backend", type=str, default="pupil", choices=["aruco", "pupil"],
        help="Backend for tag detection: aruco (OpenCV) or pupil (pupil-apriltags)."
    )
    parser.add_argument(
        "--tag_size_m", type=float, default=0.05,
        help="Physical tag edge length in meters (default: 0.05)."
    )
    parser.add_argument(
        "--camera_matrix", type=str,
        default=",".join(str(v) for v in DEFAULT_K),
        help="3x3 camera matrix as 9 comma-separated values (row-major)."
    )
    parser.add_argument(
        "--dist_coeffs", type=str,
        default=",".join(str(v) for v in DEFAULT_D),
        help="Distortion coefficients as 8 comma-separated values (k1,k2,p1,p2,k3,k4,k5,k6)."
    )
    return parser.parse_args()


def parse_float_list(raw, expected_len, name):
    vals = [v.strip() for v in raw.split(",") if v.strip() != ""]
    if len(vals) != expected_len:
        raise ValueError(
            f"{name} needs {expected_len} values, got: {len(vals)} ({raw})"
        )
    return [float(v) for v in vals]


def build_camera_intrinsics(args):
    k_vals = parse_float_list(args.camera_matrix, 9, "camera_matrix")
    d_vals = parse_float_list(args.dist_coeffs, 8, "dist_coeffs")
    k_mat = np.array(k_vals, dtype=np.float64).reshape(3, 3)
    d_vec = np.array(d_vals, dtype=np.float64).reshape(-1, 1)
    return k_mat, d_vec


def get_apriltag_dictionary(tag_family):
    fam = tag_family.strip().lower().replace("_", "")
    fam_to_dict = {
        "16h5": "DICT_APRILTAG_16h5",
        "25h9": "DICT_APRILTAG_25h9",
        "36h10": "DICT_APRILTAG_36h10",
        "36h11": "DICT_APRILTAG_36h11",
    }
    if fam not in fam_to_dict:
        raise ValueError(f"Unknown tag_family '{tag_family}'.")

    dict_name = fam_to_dict[fam]
    if not hasattr(cv2, "aruco"):
        raise RuntimeError("cv2.aruco not available. Please use opencv-contrib-python.")
    if not hasattr(cv2.aruco, dict_name):
        raise RuntimeError(f"{dict_name} in cv2.aruco not available.")
    return cv2.aruco.getPredefinedDictionary(getattr(cv2.aruco, dict_name))


def estimate_tag_pose_from_corners(corner_pts, camera_matrix, dist_coeffs, tag_size_m):
    half = float(tag_size_m) / 2.0
    obj_pts = np.array(
        [
            [-half, +half, 0.0],  # TL
            [+half, +half, 0.0],  # TR
            [+half, -half, 0.0],  # BR
            [-half, -half, 0.0],  # BL
        ],
        dtype=np.float32,
    )
    img_pts = corner_pts.astype(np.float32)
    pnp_flag = getattr(cv2, "SOLVEPNP_IPPE_SQUARE", cv2.SOLVEPNP_ITERATIVE)
    ok, rvec, tvec = cv2.solvePnP(
        obj_pts,
        img_pts,
        camera_matrix,
        dist_coeffs,
        flags=pnp_flag,
    )
    if not ok:
        return None, None
    return rvec, tvec


def detect_tags_for_frame_aruco(frame_bgr, dictionary, camera_matrix, dist_coeffs, tag_size_m):
    if hasattr(cv2.aruco, "DetectorParameters"):
        params = cv2.aruco.DetectorParameters()
    else:
        params = cv2.aruco.DetectorParameters_create()

    if hasattr(cv2.aruco, "ArucoDetector"):
        detector = cv2.aruco.ArucoDetector(dictionary, params)
        corners, ids, _ = detector.detectMarkers(frame_bgr)
    else:
        corners, ids, _ = cv2.aruco.detectMarkers(frame_bgr, dictionary, parameters=params)

    tags = []
    if ids is None or len(ids) == 0:
        return tags

    rvecs = None
    tvecs = None
    if hasattr(cv2.aruco, "estimatePoseSingleMarkers"):
        pose_out = cv2.aruco.estimatePoseSingleMarkers(
            corners, tag_size_m, camera_matrix, dist_coeffs
        )
        if len(pose_out) >= 2:
            rvecs, tvecs = pose_out[0], pose_out[1]

    flat_ids = ids.flatten().tolist()
    for i, tag_id in enumerate(flat_ids):
        corner_pts = corners[i].reshape(4, 2)
        cx = float(np.mean(corner_pts[:, 0]))
        cy = float(np.mean(corner_pts[:, 1]))

        if rvecs is not None and tvecs is not None:
            rvec = rvecs[i].reshape(3, 1)
            tvec = tvecs[i].reshape(3, 1)
        else:
            # Fallback for OpenCV versions without estimatePoseSingleMarkers.
            rvec, tvec = estimate_tag_pose_from_corners(
                corner_pts, camera_matrix, dist_coeffs, tag_size_m
            )

        tags.append(
            {
                "id": int(tag_id),
                "corners": corner_pts,
                "center_px": (int(round(cx)), int(round(cy))),
                "rvec": rvec,
                "tvec": tvec,
            }
        )
    return tags


def pupil_family_string(tag_family):
    fam = tag_family.strip().lower().replace("_", "")
    valid = {"16h5", "25h9", "36h10", "36h11"}
    if fam not in valid:
        raise ValueError(f"Unknown tag_family '{tag_family}'.")
    return f"tag{fam}"


def detect_tags_for_frame_pupil(frame_bgr, detector, camera_matrix, dist_coeffs, tag_size_m):
    gray = cv2.cvtColor(frame_bgr, cv2.COLOR_BGR2GRAY)
    dets = detector.detect(gray, estimate_tag_pose=False)

    tags = []
    for det in dets:
        corner_pts = np.array(det.corners, dtype=np.float32).reshape(4, 2)
        center_xy = np.array(det.center, dtype=np.float32).flatten()
        cx = float(center_xy[0])
        cy = float(center_xy[1])
        rvec, tvec = estimate_tag_pose_from_corners(
            corner_pts, camera_matrix, dist_coeffs, tag_size_m
        )
        tags.append(
            {
                "id": int(det.tag_id),
                "corners": corner_pts,
                "center_px": (int(round(cx)), int(round(cy))),
                "rvec": rvec,
                "tvec": tvec,
            }
        )
    return tags


def detect_tags_for_frame(frame_bgr, tag_backend, tag_detector, camera_matrix, dist_coeffs, tag_size_m):
    if tag_backend == "pupil":
        return detect_tags_for_frame_pupil(
            frame_bgr, tag_detector, camera_matrix, dist_coeffs, tag_size_m
        )
    return detect_tags_for_frame_aruco(
        frame_bgr, tag_detector, camera_matrix, dist_coeffs, tag_size_m
    )


def draw_detected_tags(frame, tags, camera_matrix, dist_coeffs, tag_size_m):
    for tag in tags:
        pts = tag["corners"].astype(np.int32).reshape((-1, 1, 2))
        cv2.polylines(frame, [pts], True, (0, 255, 0), 2, cv2.LINE_AA)
        cx, cy = tag["center_px"]
        cv2.circle(frame, (cx, cy), 4, (0, 255, 255), -1, cv2.LINE_AA)

        label = f"id={tag['id']}"
        if tag["tvec"] is not None:
            tx, ty, tz = tag["tvec"].flatten().tolist()
            label = f"id={tag['id']} xyz=({tx:.3f},{ty:.3f},{tz:.3f})m"
        cv2.putText(frame, label, (cx + 8, cy - 8), cv2.FONT_HERSHEY_SIMPLEX,
                    0.5, (0, 0, 0), 3, cv2.LINE_AA)
        cv2.putText(frame, label, (cx + 8, cy - 8), cv2.FONT_HERSHEY_SIMPLEX,
                    0.5, (0, 255, 0), 1, cv2.LINE_AA)

        if tag["rvec"] is not None and tag["tvec"] is not None:
            axis_len = max(tag_size_m * 0.5, 0.01)
            cv2.drawFrameAxes(frame, camera_matrix, dist_coeffs, tag["rvec"], tag["tvec"], axis_len)


def progress_bar(percent_done, bar_length=50):
    done_length = int(bar_length * percent_done / 100)
    bar = "=" * done_length + "-" * (bar_length - done_length)
    sys.stdout.write(f"[{bar}] {percent_done:6.2f}%\r")
    sys.stdout.flush()


def main():
    args = parse_arguments()

    # Open input video
    cap = cv2.VideoCapture(args.input_video)
    if not cap.isOpened():
        raise IOError(f"Cannot open input video: '{args.input_video}'")

    total_frames = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))
    width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
    height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
    fps = cap.get(cv2.CAP_PROP_FPS)
    
    if fps == 0:
        fps = 30  # Default fallback
    
    print(f"[INFO] Input video: {total_frames} frames, {width}x{height}, {fps:.2f} FPS")

    # Setup tag detection
    camera_matrix, dist_coeffs = build_camera_intrinsics(args)
    
    if args.tag_backend == "pupil":
        if PupilAprilTagDetector is None:
            raise RuntimeError(
                "pupil_apriltags not installed. Install with: pip install pupil-apriltags"
            )
        tag_detector = PupilAprilTagDetector(
            families=pupil_family_string(args.tag_family),
            nthreads=1,
            quad_decimate=1.0,
            quad_sigma=0.0,
            refine_edges=1,
            decode_sharpening=0.25,
            debug=0,
        )
    else:
        tag_detector = get_apriltag_dictionary(args.tag_family)
    
    print(
        f"[INFO] Tag detection enabled: backend={args.tag_backend}, "
        f"family={args.tag_family}, size={args.tag_size_m}m"
    )

    # Setup output video writer
    fourcc = cv2.VideoWriter_fourcc(*'mp4v')
    out = cv2.VideoWriter(args.output_video, fourcc, fps, (width, height))
    if not out.isOpened():
        raise IOError(f"Cannot create output video: '{args.output_video}'")

    print(f"[INFO] Writing output video to: '{args.output_video}'")
    print("[INFO] Starting frame processing...")

    frame_idx = 0
    while True:
        ret, frame = cap.read()
        if not ret:
            break

        # Detect tags in frame
        tags = detect_tags_for_frame(
            frame, args.tag_backend, tag_detector,
            camera_matrix, dist_coeffs, args.tag_size_m
        )

        # Draw tag detections
        draw_detected_tags(frame, tags, camera_matrix, dist_coeffs, args.tag_size_m)

        # Write frame to output video
        out.write(frame)

        frame_idx += 1
        pct = (frame_idx / total_frames) * 100.0
        progress_bar(pct)

    cap.release()
    out.release()

    print(f"\n[INFO] Done! Processed {frame_idx} frames.")
    print(f"[INFO] Output video saved to: {args.output_video}")


if __name__ == "__main__":
    main()
