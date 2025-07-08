import cv2
import pandas as pd
import numpy as np
import argparse
import sys
from bisect import bisect_left

# ----------------------------------------------------------------------------
# Python-Skript: Zwei Videos basierend auf Zeitstempeln (sec + nanosec) synchron nebeneinander abspielen
#               (Basis: niedrigere Framerate, für jedes Basis-Frame das
#                nächstgelegene Frame im schnelleren Video auswählen)
#
# Mit Fortschrittsanzeige (Prozent) im Terminal.
#
# Nutzung:
# python sync_videos.py \
#   --video1 video1.mp4 \
#   --video2 video2.mp4 \
#   --csv1 timestamps1.csv \
#   --csv2 timestamps2.csv \
#   --output output_side_by_side.mp4
# ----------------------------------------------------------------------------

def parse_arguments():
    parser = argparse.ArgumentParser(
        description="Synchronisiere zwei Videos, indem Du für jeden Frame des langsamen Videos "
                    "das zeitnächste Frame im schnellen Video wählst, und erstelle eine "
                    "Side-by-Side-Ausgabe mit Fortschrittsanzeige."
    )
    parser.add_argument("--video1", type=str, required=True, help="Pfad zu Video 1")
    parser.add_argument("--video2", type=str, required=True, help="Pfad zu Video 2")
    parser.add_argument("--csv1", type=str, required=True, help="Pfad zu CSV 1 mit Zeitstempeln (sec,nanosec,...).")
    parser.add_argument("--csv2", type=str, required=True, help="Pfad zu CSV 2 mit Zeitstempeln (sec,nanosec,...).")
    parser.add_argument("--output", type=str, required=True, help="Zieldatei für das Side-by-Side-Video (MP4).")
    return parser.parse_args()


def load_timestamps(csv_path):
    """
    Lese CSV und konvertiere sec + nanosec zu einem Float-Zeitstempel in Sekunden.
    Unterstützt diese Formate:
      - Spalte 'sec' und 'nanosec'
      - Falls nur eine Spalte ohne Header: direkt als Float lesen.
    """
    df = pd.read_csv(csv_path)
    if 'sec' in df.columns and 'nanosec' in df.columns:
        ts = df['sec'].astype(float) + df['nanosec'].astype(float) * 1e-9
    else:
        # Fallback: nehme erste Spalte als Float-Zeitstempel
        first_col = df.columns[0]
        ts = df[first_col].astype(float)
    return ts.values


def find_nearest_frame_index(timestamps, t):
    """
    Gibt den Index des Frames zurück, dessen Zeitstempel in 'timestamps'
    am nächsten bei 't' liegt.
    """
    pos = bisect_left(timestamps, t)
    if pos == 0:
        return 0
    if pos >= len(timestamps):
        return len(timestamps) - 1
    before = timestamps[pos - 1]
    after  = timestamps[pos]
    if (after - t) < (t - before):
        return pos
    return pos - 1


def progress_bar(percent_done, bar_length=50):
    """
    Zeige Fortschrittsanzeige im Terminal.

    :param percent_done: Prozentualer Fortschritt (0–100).
    :param bar_length: Länge der Leiste in Zeichen.
    """
    done_length = int(bar_length * percent_done / 100)
    bar = '=' * done_length + '-' * (bar_length - done_length)
    sys.stdout.write(f'[{bar}] {percent_done:6.2f}%\r')
    sys.stdout.flush()

def average_fps_from_timestamps(timestamps):
    """Berechne die durchschnittliche Bildrate (FPS) als Mittelwert der Frames pro Sekunde."""
    if len(timestamps) < 2:
        return 25.0  # Fallback

    # Sekundenzuordnung relativ zum ersten Timestamp
    elapsed = timestamps - timestamps[0]
    sec_bins = np.floor(elapsed).astype(int)
    # Zähle Frames pro Sekunde
    _, counts = np.unique(sec_bins, return_counts=True)
    fps = counts.mean()

    # Sicherheitsprüfungen
    if fps <= 0 or fps > 240:  # unrealistische Werte filtern
        fps = 25.0
    return float(fps)

def main():
    args = parse_arguments()
    video1_path = args.video1
    video2_path = args.video2
    csv1_path   = args.csv1
    csv2_path   = args.csv2
    output_path = args.output

    # ----------------------------------------------------------------------------
    # 1. Videos öffnen
    # ----------------------------------------------------------------------------
    cap1 = cv2.VideoCapture(video1_path)
    cap2 = cv2.VideoCapture(video2_path)
    if not cap1.isOpened():
        raise IOError(f"Kann '{video1_path}' nicht öffnen.")
    if not cap2.isOpened():
        raise IOError(f"Kann '{video2_path}' nicht öffnen.")

    total_frames1 = int(cap1.get(cv2.CAP_PROP_FRAME_COUNT))
    total_frames2 = int(cap2.get(cv2.CAP_PROP_FRAME_COUNT))

    # ----------------------------------------------------------------------------
    # 2. Timestamps laden
    # ----------------------------------------------------------------------------
    timestamps1 = load_timestamps(csv1_path)
    timestamps2 = load_timestamps(csv2_path)

    if len(timestamps1) != total_frames1:
        print(f"Warnung: Anzahl Timestamps1 ({len(timestamps1)}) != Gesamtframes Video1 ({total_frames1}).")
    if len(timestamps2) != total_frames2:
        print(f"Warnung: Anzahl Timestamps2 ({len(timestamps2)}) != Gesamtframes Video2 ({total_frames2}).")

    # ----------------------------------------------------------------------------
    # 3. Welche ist die "langsamere" (Basis) und welche die "schnellere"? 
    #    Wir nehmen das Video mit weniger Frames als Basis.
    # ----------------------------------------------------------------------------
    if len(timestamps1) <= len(timestamps2):
        # Video1 ist Basis (niedrigere Rate)
        cap_base        = cap1
        ts_base         = timestamps1
        total_base      = total_frames1
        cap_high        = cap2
        ts_high         = timestamps2
        total_high      = total_frames2
        label_base      = "Video1 (niedrig)"
        label_high      = "Video2 (hoch)"
    else:
        # Video2 ist Basis, Video1 hat mehr Frames (höhere Rate)
        cap_base        = cap2
        ts_base         = timestamps2
        total_base      = total_frames2
        cap_high        = cap1
        ts_high         = timestamps1
        total_high      = total_frames1
        label_base      = "Video2 (niedrig)"
        label_high      = "Video1 (hoch)"

    print(f"Basis: {label_base}, Frames: {total_base}, Timestamps: {len(ts_base)}")
    print(f"Schnell: {label_high}, Frames: {total_high}, Timestamps: {len(ts_high)}")

    # ----------------------------------------------------------------------------
    # 4. Ersten Frame aus Basis und Schnell lesen, um Größe zu ermitteln
    # ----------------------------------------------------------------------------
    cap_base.set(cv2.CAP_PROP_POS_FRAMES, 0)
    cap_high.set(cv2.CAP_PROP_POS_FRAMES, 0)
    ret_base, frame_base_0 = cap_base.read()
    ret_high, frame_high_0 = cap_high.read()
    if not ret_base or frame_base_0 is None:
        raise IOError("Fehler beim Einlesen des ersten Frames des Basis-Videos.")
    if not ret_high or frame_high_0 is None:
        raise IOError("Fehler beim Einlesen des ersten Frames des schnellen Videos.")

    # Dimensionen ermitteln
    hb, wb = frame_base_0.shape[:2]
    hh, wh = frame_high_0.shape[:2]
    target_height = min(hb, hh)
    scale_base = target_height / hb
    scale_high = target_height / hh
    target_width_base = int(wb * scale_base)
    target_width_high = int(wh * scale_high)
    combined_width  = target_width_base + target_width_high
    combined_height = target_height

    # Output-Writer einrichten (wir wählen als FPS einfach die niedrigere Rate,
    # damit wir pro Basis-Frame genau ein Bild schreiben)
    # (Man könnte hier auch abs(len(ts_base)/(timestamps_base[-1]-timestamps_base[0])) rechnen,
    #   aber dafür ist es in der Praxis genug, einfach total_base/(Gesamtdauer) zu nehmen.)
    # Einfacher: FPS = total_base / (ts_base[-1] - ts_base[0])
    output_fps = average_fps_from_timestamps(ts_base)

    # Sicherstellen, dass output_fps > 0 und nicht extrem groß/small
    if output_fps <= 0 or output_fps > 120:
        output_fps = 25.0

    print(f"Berechne Output-FPS für Basis-Video: {output_fps:.2f}")

    fourcc = cv2.VideoWriter_fourcc(*'mp4v')
    out = cv2.VideoWriter(output_path, fourcc, output_fps, (combined_width, combined_height))

    # ----------------------------------------------------------------------------
    # 5. Loop über alle Basis-Frames
    # ----------------------------------------------------------------------------
    print("Starte Synchronisation mit Basis-Raten-Loop …")

    last_frame_base = frame_base_0.copy()
    last_frame_high = frame_high_0.copy()

    for i in range(len(ts_base)):
        t_base = ts_base[i]  # Zeitstempel des i-ten Basis-Frames

        # 5.1 Basis-Frame auslesen
        cap_base.set(cv2.CAP_PROP_POS_FRAMES, i)
        ret_base, frame_base = cap_base.read()
        if not ret_base or frame_base is None:
            frame_base = last_frame_base.copy()
        else:
            last_frame_base = frame_base.copy()

        # 5.2 Im schnellen Video den nächstgelegenen Frame finden
        idx_high = find_nearest_frame_index(ts_high, t_base)
        cap_high.set(cv2.CAP_PROP_POS_FRAMES, idx_high)
        ret_high, frame_high = cap_high.read()
        if not ret_high or frame_high is None:
            frame_high = last_frame_high.copy()
        else:
            last_frame_high = frame_high.copy()

        # 5.3 Auf gemeinsame Höhe skalieren
        frameb_resized = cv2.resize(frame_base, (target_width_base, target_height))
        frameh_resized = cv2.resize(frame_high, (target_width_high, target_height))
        combined = np.hstack((frameb_resized, frameh_resized))

        out.write(combined)

        # Fortschrittsanzeige
        percent = (i + 1) / len(ts_base) * 100
        progress_bar(percent)

    # Fertig
    sys.stdout.write(f"\nFertig: '{output_path}' wurde erstellt.\n")

    cap1.release()
    cap2.release()
    out.release()


if __name__ == "__main__":
    main()
