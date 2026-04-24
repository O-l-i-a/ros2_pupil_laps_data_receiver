#!/usr/bin/env python3
import argparse
import csv
import os
import sys

import cv2
import numpy as np
import pandas as pd

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
            "Erzeugt pro Gaze-Punkt ein Bild mit Overlay (Punkt + Infos). "
            "Für jeden Gaze-Zeitstempel wird der letzte verfügbare Scene-Frame "
            "mit scene_ts <= gaze_ts verwendet (Realtime-Verhalten)."
        )
    )
    parser.add_argument(
        "--scene_video", type=str, required=True,
        help="Pfad zum Scene-Video."
    )
    parser.add_argument(
        "--gaze_csv", type=str, required=True,
        help="Pfad zur Gaze-CSV mit Spalten: sec,nanosec,x,y."
    )
    parser.add_argument(
        "--scene_csv", type=str, required=True,
        help="Pfad zur Scene-CSV mit Spalten: sec,nanosec (pro Frame)."
    )
    parser.add_argument(
        "--output_dir", type=str, required=True,
        help="Ausgabeordner für PNG-Frames + info.csv."
    )
    parser.add_argument(
        "--dot_radius", type=int, default=10,
        help="Radius des Gaze-Dots in Pixeln (Standard: 10)."
    )
    parser.add_argument(
        "--dot_color", type=str, default="0,0,255",
        help="Farbe des Gaze-Dots als B,G,R (Standard: 0,0,255 = Rot)."
    )
    parser.add_argument(
        "--alpha", type=float, default=0.6,
        help="Alpha-Wert für Overlay [0..1] (Standard: 0.6)."
    )
    parser.add_argument(
        "--enable_tags", action="store_true",
        help="Aktiviert AprilTag-Detektion + 3D-Pose-Overlay."
    )
    parser.add_argument(
        "--tag_family", type=str, default="36h11",
        help="AprilTag-Familie: 16h5 | 25h9 | 36h10 | 36h11 (Standard: 36h11)."
    )
    parser.add_argument(
        "--tag_backend", type=str, default="pupil", choices=["aruco", "pupil"],
        help="Backend fuer Tag-Detektion: aruco (OpenCV) oder pupil (pupil-apriltags)."
    )
    parser.add_argument(
        "--tag_size_m", type=float, default=0.05,
        help="Physische Tag-Kantenlaenge in Metern (Standard: 0.05)."
    )
    parser.add_argument(
        "--camera_matrix", type=str,
        default=",".join(str(v) for v in DEFAULT_K),
        help="3x3 Kamera-Matrix als 9 Komma-Werte (row-major)."
    )
    parser.add_argument(
        "--dist_coeffs", type=str,
        default=",".join(str(v) for v in DEFAULT_D),
        help="Distortion-Koeffizienten als 8 Komma-Werte (k1,k2,p1,p2,k3,k4,k5,k6)."
    )
    return parser.parse_args()


def load_gaze_data(csv_path):
    df = pd.read_csv(csv_path)
    required = {"sec", "nanosec", "x", "y"}
    if not required.issubset(df.columns):
        raise ValueError(f"Gaze-CSV braucht Spalten {required}, gefunden: {set(df.columns)}")

    gaze_abs_ts = df["sec"].astype(float) + df["nanosec"].astype(float) * 1e-9
    xs = df["x"].to_numpy(dtype=float)
    ys = df["y"].to_numpy(dtype=float)

    print(f"[DEBUG] Erste 5 Gaze-AbsTimes: {gaze_abs_ts.to_numpy()[:5]}")
    print(f"[DEBUG] Erste 5 Gaze-x:        {xs[:5]}")
    print(f"[DEBUG] Erste 5 Gaze-y:        {ys[:5]}")
    return gaze_abs_ts.to_numpy(dtype=float), xs, ys


def load_scene_timestamps(csv_path):
    df = pd.read_csv(csv_path)
    required = {"sec", "nanosec"}
    if not required.issubset(df.columns):
        raise ValueError(f"Scene-CSV braucht Spalten {required}, gefunden: {set(df.columns)}")

    scene_abs_ts = df["sec"].astype(float) + df["nanosec"].astype(float) * 1e-9
    print(f"[DEBUG] Erste 5 Scene-AbsTimes: {scene_abs_ts.to_numpy()[:5]}")
    return scene_abs_ts.to_numpy(dtype=float)


def find_latest_scene_idx(scene_abs_ts, gaze_t):
    """
    Liefert den Index des letzten Scene-Frames mit scene_ts <= gaze_t.
    Falls gaze_t vor dem ersten Scene-Frame liegt, wird 0 zurückgegeben.
    """
    idx = int(np.searchsorted(scene_abs_ts, gaze_t, side="right")) - 1
    if idx < 0:
        return 0
    if idx >= len(scene_abs_ts):
        return len(scene_abs_ts) - 1
    return idx


def progress_bar(percent_done, bar_length=50):
    done_length = int(bar_length * percent_done / 100)
    bar = "=" * done_length + "-" * (bar_length - done_length)
    sys.stdout.write(f"[{bar}] {percent_done:6.2f}%\r")
    sys.stdout.flush()


def parse_float_list(raw, expected_len, name):
    vals = [v.strip() for v in raw.split(",") if v.strip() != ""]
    if len(vals) != expected_len:
        raise ValueError(
            f"{name} braucht {expected_len} Werte, bekommen: {len(vals)} ({raw})"
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
        raise ValueError(f"Unbekannte tag_family '{tag_family}'.")

    dict_name = fam_to_dict[fam]
    if not hasattr(cv2, "aruco"):
        raise RuntimeError("cv2.aruco nicht verfuegbar. Bitte opencv-contrib-python nutzen.")
    if not hasattr(cv2.aruco, dict_name):
        raise RuntimeError(f"{dict_name} in cv2.aruco nicht verfuegbar.")
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
            # Fallback fuer OpenCV-Versionen ohne estimatePoseSingleMarkers.
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
        raise ValueError(f"Unbekannte tag_family '{tag_family}'.")
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


def draw_info_text(frame, gaze_idx, gaze_ts, scene_idx, scene_ts, x_pix, y_pix, in_bounds,
                   enable_tags, tag_family, tag_backend, tag_size_m, tag_count):
    font = cv2.FONT_HERSHEY_SIMPLEX
    scale = 0.55
    color = (255, 255, 255)
    thickness = 1
    line_type = cv2.LINE_AA

    lines = [
        f"gaze_idx={gaze_idx} scene_idx={scene_idx} in_bounds={in_bounds}",
        f"gaze_ts={gaze_ts:.6f}s scene_ts={scene_ts:.6f}s",
        f"gaze_xy=({x_pix},{y_pix})",
    ]
    if enable_tags:
        lines.append(
            f"tags=on backend={tag_backend} family={tag_family} size_m={tag_size_m:.4f} count={tag_count}"
        )
    else:
        lines.append("tags=off")

    y0 = 24
    for line in lines:
        cv2.putText(frame, line, (12, y0), font, scale, (0, 0, 0), thickness + 2, line_type)
        cv2.putText(frame, line, (12, y0), font, scale, color, thickness, line_type)
        y0 += 24


def main():
    args = parse_arguments()
    args.alpha = max(0.0, min(1.0, args.alpha))

    gaze_abs_ts, xs, ys = load_gaze_data(args.gaze_csv)
    total_gaze = len(gaze_abs_ts)
    if total_gaze == 0:
        print("Keine Gaze-Daten gefunden.")
        return

    scene_abs_ts = load_scene_timestamps(args.scene_csv)
    total_scene_ts = len(scene_abs_ts)
    if total_scene_ts == 0:
        print("Keine Scene-Timestamps gefunden.")
        return

    cap = cv2.VideoCapture(args.scene_video)
    if not cap.isOpened():
        raise IOError(f"Kann '{args.scene_video}' nicht öffnen.")

    total_frames = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))
    width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
    height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))

    if total_frames != total_scene_ts:
        print(f"[WARNUNG] Video-Frames ({total_frames}) != Scene-CSV-Zeilen ({total_scene_ts}).")

    scene_frames = []
    cap.set(cv2.CAP_PROP_POS_FRAMES, 0)
    for _ in range(total_scene_ts):
        ret, frame = cap.read()
        if not ret:
            break
        scene_frames.append(frame.copy())
    cap.release()

    if len(scene_frames) == 0:
        raise RuntimeError("Keine Frames aus dem Scene-Video gelesen.")
    if len(scene_frames) != total_scene_ts:
        print(f"[WARNUNG] Nur {len(scene_frames)} von {total_scene_ts} Frames geladen.")

    # Falls CSV mehr Einträge hat als geladene Frames, auf geladene Länge begrenzen.
    if len(scene_abs_ts) > len(scene_frames):
        scene_abs_ts = scene_abs_ts[: len(scene_frames)]
        total_scene_ts = len(scene_abs_ts)
        print(f"[WARNUNG] Scene-Timestamps auf {total_scene_ts} gekürzt (entspricht geladenen Frames).")

    try:
        b, g, r = [int(v) for v in args.dot_color.split(",")]
    except Exception:
        b, g, r = 0, 0, 255

    radius = args.dot_radius
    circle_thickness = max(2, radius // 4)
    detect_tags_enabled = bool(args.enable_tags)
    tag_cache = {}

    camera_matrix = None
    dist_coeffs = None
    tag_detector = None
    if detect_tags_enabled:
        if args.tag_size_m <= 0:
            raise ValueError("--tag_size_m muss > 0 sein.")
        camera_matrix, dist_coeffs = build_camera_intrinsics(args)
        if args.tag_backend == "pupil":
            if PupilAprilTagDetector is None:
                raise RuntimeError(
                    "pupil_apriltags nicht installiert. Installiere mit: pip install pupil-apriltags"
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
            f"[INFO] Tag-Detektion aktiv: backend={args.tag_backend}, "
            f"family={args.tag_family}, size={args.tag_size_m}m"
        )

    os.makedirs(args.output_dir, exist_ok=True)
    info_csv_path = os.path.join(args.output_dir, "info.csv")

    print("[INFO] Starte Export: pro Gaze-Punkt ein Bild im Output-Ordner.")

    drawn_count = 0
    with open(info_csv_path, "w", newline="", encoding="utf-8") as f_info:
        writer = csv.writer(f_info)
        writer.writerow(
            [
                "gaze_idx",
                "gaze_ts",
                "scene_idx",
                "scene_ts",
                "x",
                "y",
                "in_bounds",
                "tag_count",
                "tag_ids",
                "tag_centers_xyz_m",
                "image_path",
            ]
        )

        for gaze_idx in range(total_gaze):
            gaze_t = float(gaze_abs_ts[gaze_idx])
            scene_idx = find_latest_scene_idx(scene_abs_ts, gaze_t)

            frame = scene_frames[scene_idx].copy()
            scene_t = float(scene_abs_ts[scene_idx])
            x_pix = int(xs[gaze_idx])
            y_pix = int(ys[gaze_idx])

            in_bounds = 0 <= x_pix < width and 0 <= y_pix < height
            if in_bounds:
                overlay = frame.copy()
                cv2.circle(overlay, (x_pix, y_pix), radius, (b, g, r), circle_thickness)
                cv2.addWeighted(overlay, args.alpha, frame, 1 - args.alpha, 0, frame)
                drawn_count += 1
            elif gaze_idx < 5:
                print(
                    f"[DEBUG] Gaze #{gaze_idx} außerhalb: x={x_pix}, y={y_pix}, "
                    f"SceneFrame={scene_idx}"
                )

            tag_count = 0
            tag_ids_str = ""
            tag_xyz_str = ""
            if detect_tags_enabled:
                if scene_idx not in tag_cache:
                    tag_cache[scene_idx] = detect_tags_for_frame(
                        scene_frames[scene_idx], args.tag_backend, tag_detector,
                        camera_matrix, dist_coeffs, args.tag_size_m
                    )
                tags = tag_cache[scene_idx]
                draw_detected_tags(frame, tags, camera_matrix, dist_coeffs, args.tag_size_m)
                tag_count = len(tags)
                tag_ids_str = ";".join(str(t["id"]) for t in tags)
                tag_xyz_values = []
                for t in tags:
                    if t["tvec"] is None:
                        continue
                    tx, ty, tz = t["tvec"].flatten().tolist()
                    tag_xyz_values.append(f"id{t['id']}:{tx:.6f},{ty:.6f},{tz:.6f}")
                tag_xyz_str = ";".join(tag_xyz_values)

            draw_info_text(
                frame, gaze_idx, gaze_t, scene_idx, scene_t, x_pix, y_pix, in_bounds,
                detect_tags_enabled, args.tag_family, args.tag_backend, args.tag_size_m, tag_count
            )

            image_name = f"frame_{gaze_idx:06d}.png"
            image_path = os.path.join(args.output_dir, image_name)
            ok = cv2.imwrite(image_path, frame)
            if not ok:
                raise IOError(f"Konnte Bild nicht schreiben: {image_path}")

            writer.writerow(
                [
                    gaze_idx,
                    f"{gaze_t:.9f}",
                    scene_idx,
                    f"{scene_t:.9f}",
                    x_pix,
                    y_pix,
                    int(in_bounds),
                    tag_count,
                    tag_ids_str,
                    tag_xyz_str,
                    image_name,
                ]
            )

            pct = (gaze_idx + 1) / total_gaze * 100.0
            progress_bar(pct)

    sys.stdout.write(
        f"\nFertig: {total_gaze} Bilder erstellt in '{args.output_dir}'. "
        f"Kreise gezeichnet: {drawn_count}/{total_gaze}\n"
    )
    print(f"[INFO] Mapping-Infos gespeichert: {info_csv_path}")


if __name__ == "__main__":
    main()
