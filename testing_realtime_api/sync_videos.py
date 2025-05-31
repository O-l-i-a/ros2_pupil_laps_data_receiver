import cv2
import pandas as pd
import numpy as np
import argparse
import sys

# ----------------------------------------------------------------------------
# Python-Skript: Zwei Videos basierend auf Zeitstempeln (sec + nanosec) synchron nebeneinander abspielen
# Mit Fortschrittsanzeige (Prozent) im Terminal.
#
# Nutzung:
# python sync_videos.py \
#   --video1 video1.mp4 \
#   --video2 video2.mp4 \
#   --csv1 timestamps1.csv \
#   --csv2 timestamps2.csv \
#   --output output_side_by_side.mp4 \
#   [--fps 60]
# ------------------------------------------------------------------------------

def parse_arguments():
    parser = argparse.ArgumentParser(
        description="Synchronisiere zwei Videos basierend auf Timestamp-CSV-Dateien und erstelle eine Side-by-Side-Ausgabe mit Fortschrittsbar."
    )
    parser.add_argument("--video1", type=str, required=True, help="Pfad zu Video 1 (z.B. 30 Hz)")
    parser.add_argument("--video2", type=str, required=True, help="Pfad zu Video 2 (z.B. 60 Hz)")
    parser.add_argument("--csv1", type=str, required=True, help="Pfad zu CSV 1 mit Zeitstempeln (sec,nanosec,...)")
    parser.add_argument("--csv2", type=str, required=True, help="Pfad zu CSV 2 mit Zeitstempeln (Frame_Index,sec,nanosec)")
    parser.add_argument("--output", type=str, required=True, help="Pfad zur Ausgabedatei (MP4) für Side-by-Side-Video")
    parser.add_argument("--fps", type=float, default=None,
                        help="(Optional) Ziel-FPS für Ausgabe. Wenn nicht angegeben, wird max(Hz1, Hz2) genutzt.")
    return parser.parse_args()


def load_timestamps(csv_path):
    """
    Lese CSV und konvertiere sec + nanosec zu einem Float-Zeitstempel in Sekunden.
    Unterstützt verschiedene Formate:
      - Spalten: sec,nanosec,...
      - Spalten: Frame_Index,sec,nanosec
      - Falls nur eine Spalte ohne Header: direkt als Float laden.
    """
    df = pd.read_csv(csv_path)
    # Wenn Spalte 'sec' und 'nanosec' vorhanden:
    if 'sec' in df.columns and 'nanosec' in df.columns:
        timestamps = df['sec'].astype(float) + df['nanosec'].astype(float) * 1e-9 # berechnen die sekunden und dann die nanosekunden nach der koma und dann damit weiter analysieren
    else:
        first_col = df.columns[0]
        timestamps = df[first_col].astype(float)
    return timestamps.values


def find_nearest_frame_index(timestamps, t):
    """
    Gibt den Index des Frames zurück, dessen Zeitstempel in 'timestamps' am nächsten bei 't' liegt.
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
    Zeige eine Fortschrittsanzeige (Prozente) im Terminal.

    :param percent_done: Prozentualer Fortschritt (0–100).
    :param bar_length: Länge der Leiste in Zeichen.
    """
    done_length = int(bar_length * percent_done / 100)
    bar = '=' * done_length + '-' * (bar_length - done_length)
    sys.stdout.write(f'[{bar}] {percent_done:6.2f}%\r')
    sys.stdout.flush()


def main():
    args = parse_arguments()
    video1_path = args.video1
    video2_path = args.video2
    csv1_path = args.csv1
    csv2_path = args.csv2
    output_path = args.output

    # ---------------------------------------------------------------------------
    # Schritt 1: Video-Captures öffnen
    # ---------------------------------------------------------------------------
    cap1 = cv2.VideoCapture(video1_path)
    cap2 = cv2.VideoCapture(video2_path)
    if not cap1.isOpened():
        raise IOError(f"Kann {video1_path} nicht öffnen.")
    if not cap2.isOpened():
        raise IOError(f"Kann {video2_path} nicht öffnen.")

    total_frames1 = int(cap1.get(cv2.CAP_PROP_FRAME_COUNT))
    total_frames2 = int(cap2.get(cv2.CAP_PROP_FRAME_COUNT))

    # ---------------------------------------------------------------------------
    # Schritt 2: CSV-Timestamps lesen und kombinieren zu Float
    # ---------------------------------------------------------------------------
    timestamps1 = load_timestamps(csv1_path)
    timestamps2 = load_timestamps(csv2_path)

    if len(timestamps1) != total_frames1:
        print(f"Warnung: Anzahl Timestamps1 ({len(timestamps1)}) != Gesamtframes Video1 ({total_frames1}).")
    if len(timestamps2) != total_frames2:
        print(f"Warnung: Anzahl Timestamps2 ({len(timestamps2)}) != Gesamtframes Video2 ({total_frames2}).")

    # ---------------------------------------------------------------------------
    # Schritt 3: Gemeinsame Zeitachse bestimmen
    # ---------------------------------------------------------------------------
    start_time = max(timestamps1[0], timestamps2[0])
    end_time = min(timestamps1[-1], timestamps2[-1])

    if args.fps is not None:
        output_fps = args.fps
    else:
        freq1 = 1.0 / np.mean(np.diff(timestamps1)) if len(timestamps1) > 1 else 30.0
        freq2 = 1.0 / np.mean(np.diff(timestamps2)) if len(timestamps2) > 1 else 60.0
        output_fps = max(freq1, freq2)
    time_step = 1.0 / output_fps
    timeline = np.arange(start_time, end_time, time_step)
    total_steps = len(timeline)

    # ---------------------------------------------------------------------------
    # Schritt 4: Output-Video-Writer vorbereiten
    # ---------------------------------------------------------------------------
    cap1.set(cv2.CAP_PROP_POS_FRAMES, 0)
    cap2.set(cv2.CAP_PROP_POS_FRAMES, 0)
    ret1, frame1_0 = cap1.read()
    ret2, frame2_0 = cap2.read()
    if not ret1 or not ret2:
        raise IOError("Fehler beim Einlesen des ersten Frames eines Videos.")

    h1, w1 = frame1_0.shape[:2]
    h2, w2 = frame2_0.shape[:2]
    target_height = min(h1, h2)
    scale1 = target_height / h1
    scale2 = target_height / h2
    target_width1 = int(w1 * scale1)
    target_width2 = int(w2 * scale2)
    combined_width = target_width1 + target_width2
    combined_height = target_height

    fourcc = cv2.VideoWriter_fourcc(*'mp4v')
    out = cv2.VideoWriter(output_path, fourcc, output_fps, (combined_width, combined_height))

    # ---------------------------------------------------------------------------
    # Schritt 5: Synchronisiertes Schreiben mit Fortschritt
    # ---------------------------------------------------------------------------
    last_frame1 = frame1_0
    last_frame2 = frame2_0
    last_idx1 = 0
    last_idx2 = 0

    print("Starte Synchronisation und Schreiben...")
    for i, t in enumerate(timeline):
        idx1 = find_nearest_frame_index(timestamps1, t)
        idx2 = find_nearest_frame_index(timestamps2, t)

        if idx1 != last_idx1:
            cap1.set(cv2.CAP_PROP_POS_FRAMES, idx1)
            ret1, frame1 = cap1.read()
            if not ret1:
                frame1 = last_frame1.copy()
            else:
                last_frame1 = frame1.copy()
            last_idx1 = idx1
        else:
            frame1 = last_frame1.copy()

        if idx2 != last_idx2:
            cap2.set(cv2.CAP_PROP_POS_FRAMES, idx2)
            ret2, frame2 = cap2.read()
            if not ret2:
                frame2 = last_frame2.copy()
            else:
                last_frame2 = frame2.copy()
            last_idx2 = idx2
        else:
            frame2 = last_frame2.copy()

        frame1_resized = cv2.resize(frame1, (target_width1, target_height))
        frame2_resized = cv2.resize(frame2, (target_width2, target_height))
        combined = np.hstack((frame1_resized, frame2_resized))
        out.write(combined)

        percent = (i + 1) / total_steps * 100
        progress_bar(percent)

    # Nach Fertigstellung Zeile beenden und Info ausgeben
    sys.stdout.write("\nFertig: '{}' wurde erstellt.\n".format(output_path))

    cap1.release()
    cap2.release()
    out.release()


if __name__ == "__main__":
    main()
