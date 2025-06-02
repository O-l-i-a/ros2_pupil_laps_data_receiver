#!/usr/bin/env python3
import cv2
import pandas as pd
import numpy as np
import argparse
import sys
import os


def parse_arguments():
    parser = argparse.ArgumentParser(
        description="Overlay Gaze-Punkte (in Pixel-Koordinaten) auf ein Scene-Video, "
                    "wobei das Ausgabe-Video exakt dieselbe Länge behält wie das Original-Scene-Video."
    )
    parser.add_argument(
        "--scene_video", type=str, required=True,
        help="Pfad zum Scene-Video (z. B. 30 Hz)."
    )
    parser.add_argument(
        "--gaze_csv", type=str, required=True,
        help="Pfad zur Gaze-CSV mit Spalten: sec,nanosec,x,y."
    )
    parser.add_argument(
        "--scene_csv", type=str, required=True,
        help="Pfad zur Scene-CSV mit Spalten: sec,nanosec (je Frame)."
    )
    parser.add_argument(
        "--output", type=str, required=True,
        help="Pfad zur Ausgabedatei (MP4) mit Gaze-Overlay."
    )
    parser.add_argument(
        "--dot_radius", type=int, default=10,
        help="Radius des Gaze-Dots in Pixeln (Standard: 10)."
    )
    parser.add_argument(
        "--dot_color", type=str, default="0,0,255",
        help="Farbe des Gaze-Dots als B,G,R (Standard: 0,0,255 = Rot)."
    )
    return parser.parse_args()


def load_gaze_data(csv_path):
    """
    Liest die Gaze-CSV und gibt zurück:
      gaze_rel_ts (np.ndarray): relative Gaze-Zeitstempel in Sekunden
      xs, ys      (np.ndarray): Pixel-Koordinaten (x, y)
    Erwartet Spalten: 'sec','nanosec','x','y'.
    """
    df = pd.read_csv(csv_path)
    required = {'sec', 'nanosec', 'x', 'y'}
    if not required.issubset(df.columns):
        raise ValueError(f"Gaze-CSV braucht die Spalten {required}, gefunden: {set(df.columns)}")

    abs_ts = df['sec'].astype(float) + df['nanosec'].astype(float) * 1e-9
    ts0 = abs_ts.iloc[0]
    rel_ts = (abs_ts - ts0).to_numpy(dtype=float)
    xs = df['x'].to_numpy(dtype=float)
    ys = df['y'].to_numpy(dtype=float)

    # Debug-Ausgaben (erste Werte)
    print(f"[DEBUG] Erste 5 Gaze-RelTimes: {rel_ts[:5]}")
    print(f"[DEBUG] Erste 5 Gaze-Pixel x:    {xs[:5]}")
    print(f"[DEBUG] Erste 5 Gaze-Pixel y:    {ys[:5]}")

    return rel_ts, xs, ys


def load_scene_timestamps(csv_path):
    """
    Liest die Scene-CSV und gibt zurück:
      scene_rel_ts (np.ndarray): relative Scene-Zeitstempel in Sekunden pro Frame.
    Erwartet Spalten: 'sec','nanosec'.
    """
    df = pd.read_csv(csv_path)
    required = {'sec', 'nanosec'}
    if not required.issubset(df.columns):
        raise ValueError(f"Scene-CSV braucht die Spalten {required}, gefunden: {set(df.columns)}")

    abs_ts = df['sec'].astype(float) + df['nanosec'].astype(float) * 1e-9
    ts0 = abs_ts.iloc[0]
    rel_ts = (abs_ts - ts0).to_numpy(dtype=float)

    # Debug-Ausgaben (erste Werte)
    print(f"[DEBUG] Erste 5 Scene-RelTimes: {rel_ts[:5]}")

    return rel_ts


def find_nearest_idx(timestamps, t):
    """
    Gibt den Index in 'timestamps' zurück, dessen Wert am nächsten zu t liegt.
    timestamps muss aufsteigend sortiert sein.
    """
    idx = np.searchsorted(timestamps, t, side="left")
    if idx == 0:
        return 0
    if idx >= len(timestamps):
        return len(timestamps) - 1
    prev_diff = abs(timestamps[idx - 1] - t)
    curr_diff = abs(timestamps[idx] - t)
    return idx if curr_diff < prev_diff else (idx - 1)


def progress_bar(percent_done, bar_length=50):
    """
    Zeigt eine Fortschrittsanzeige (Prozent) im Terminal.
    """
    done_length = int(bar_length * percent_done / 100)
    bar = '=' * done_length + '-' * (bar_length - done_length)
    sys.stdout.write(f'[{bar}] {percent_done:6.2f}%\r')
    sys.stdout.flush()


def main():
    args = parse_arguments()

    # --- 1) Gaze-Daten laden ---
    gaze_rel_ts, xs, ys = load_gaze_data(args.gaze_csv)
    total_gaze = len(gaze_rel_ts)
    if total_gaze == 0:
        print("Keine Gaze-Daten gefunden.")
        return

    # --- 2) Scene-Timestamps laden ---
    scene_rel_ts = load_scene_timestamps(args.scene_csv)
    total_scene_ts = len(scene_rel_ts)
    if total_scene_ts == 0:
        print("Keine Scene-Timestamps gefunden.")
        return

    # --- 3) Scene-Video öffnen ---
    cap = cv2.VideoCapture(args.scene_video)
    if not cap.isOpened():
        raise IOError(f"Kann '{args.scene_video}' nicht öffnen.")

    total_frames = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))
    scene_fps = cap.get(cv2.CAP_PROP_FPS)
    if scene_fps <= 0 or np.isnan(scene_fps):
        scene_fps = 30.0  # Fallback
    width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
    height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))

    if total_frames != total_scene_ts:
        print(f"[WARNUNG] Video-Frames ({total_frames}) ≠ Scene-CSV-Zeilen ({total_scene_ts}).")

    # Alle Scene-Frames in Liste laden (random access)
    scene_frames = []
    cap.set(cv2.CAP_PROP_POS_FRAMES, 0)
    for _ in range(total_scene_ts):
        ret, frame = cap.read()
        if not ret:
            break
        scene_frames.append(frame.copy())
    cap.release()

    if len(scene_frames) != total_scene_ts:
        print(f"[WARNUNG] Nur {len(scene_frames)} von {total_scene_ts} Frames geladen.")

    # --- 4) Output-FPS übernehmen (gleiche Framerate wie Scene-Video) ---
    output_fps = scene_fps
    print(f"[INFO] Scene-FPS = {scene_fps:.2f}, Output-FPS wird auf {output_fps:.2f} gesetzt.")

    # --- 5) Dot-Farbe und -Radius ---
    try:
        b, g, r = [int(x) for x in args.dot_color.split(',')]
    except:
        b, g, r = 0, 0, 255
    radius = args.dot_radius
    thickness = max(2, radius // 4)

    # --- 6) VideoWriter vorbereiten (Breite × Höhe beibehalten) ---
    fourcc = cv2.VideoWriter_fourcc(*'mp4v')
    out_dir = os.path.dirname(args.output) or '.'
    os.makedirs(out_dir, exist_ok=True)

    out = cv2.VideoWriter(args.output, fourcc, output_fps, (width, height))
    if not out.isOpened():
        raise IOError(f"Kann '{args.output}' nicht zum Schreiben öffnen.")

    print("[INFO] Starte Overlay-Erstellung – Ausgabe wird dieselbe Länge haben wie das Scene-Video.")

    # --- 7) Für jedes Scene-Frame: Gaze-Punkt suchen und überlagern ---
    drawn_count = 0
    for frame_idx in range(len(scene_frames)):
        t_scene = scene_rel_ts[frame_idx]
        # nächstliegenden Gaze-Index finden
        gaze_idx = find_nearest_idx(gaze_rel_ts, t_scene)

        frame = scene_frames[frame_idx].copy()
        x_pix = int(xs[gaze_idx])
        y_pix = int(ys[gaze_idx])

        # Überprüfen, ob Pixel-Koordinaten gültig
        if 0 <= x_pix < width and 0 <= y_pix < height:
            overlay = frame.copy()
            cv2.circle(overlay, (x_pix, y_pix), radius, (b, g, r), thickness)
            alpha = 0.6
            cv2.addWeighted(overlay, alpha, frame, 1 - alpha, 0, frame)
            drawn_count += 1
        else:
            if frame_idx < 5:
                print(f"[DEBUG] Gaze #{gaze_idx} für Frame #{frame_idx} außerhalb: x={x_pix}, y={y_pix}")

        out.write(frame)

        pct = (frame_idx + 1) / len(scene_frames) * 100
        progress_bar(pct)

    # --- 8) Aufräumen ---
    sys.stdout.write(f"\nFertig: '{args.output}' erstellt. Kreise gezeichnet: {drawn_count}/{len(scene_frames)}\n")
    out.release()


if __name__ == "__main__":
    main()
