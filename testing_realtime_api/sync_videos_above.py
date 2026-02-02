import cv2
import pandas as pd
import numpy as np
import argparse
import sys
from bisect import bisect_left

# ----------------------------------------------------------------------------
# Python-Skript: Zwei Videos basierend auf Zeitstempeln (sec + nanosec)
# synchron nebeneinander abspielen (Basis = weniger Frames) UND zusätzlich
# eine Mapping-CSV erzeugen:
#   short_sec, short_nanosec, long_sec, long_nanosec
#
# Nutzung:
# python sync_videos.py \
#   --video1 video1.mp4 \
#   --video2 video2.mp4 \
#   --csv1 timestamps1.csv \
#   --csv2 timestamps2.csv \
#   --output output_side_by_side.mp4 \
#   --map_csv matched_timestamps.csv
# ----------------------------------------------------------------------------

def parse_arguments():
    parser = argparse.ArgumentParser(
        description="Synchronisiere zwei Videos per Timestamps und erzeuge Side-by-Side-Video + Mapping-CSV."
    )
    parser.add_argument("--video1", type=str, required=True, help="Pfad zu Video 1")
    parser.add_argument("--video2", type=str, required=True, help="Pfad zu Video 2")
    parser.add_argument("--csv1", type=str, required=True, help="Pfad zu CSV 1 mit Zeitstempeln (sec,nanosec).")
    parser.add_argument("--csv2", type=str, required=True, help="Pfad zu CSV 2 mit Zeitstempeln (sec,nanosec).")
    parser.add_argument("--output", type=str, required=True, help="Zieldatei für das Side-by-Side-Video (MP4).")
    parser.add_argument("--map_csv", type=str, required=True, help="Ausgabedatei für Mapping-CSV.")
    return parser.parse_args()

def load_sec_nanosec_and_float(csv_path):
    """
    Lese CSV mit Spalten 'sec' und 'nanosec' und gib zurück:
      - sec_array (wie eingelesen)
      - nanosec_array (wie eingelesen)
      - ts_float (Sekunden als float für Suche)
    """
    df = pd.read_csv(csv_path)
    if not {'sec', 'nanosec'}.issubset(set(df.columns)):
        raise ValueError(f"{csv_path} muss die Spalten 'sec' und 'nanosec' enthalten.")
    sec = df['sec'].to_numpy()
    nsec = df['nanosec'].to_numpy()
    ts = sec.astype(np.float64) + nsec.astype(np.float64) * 1e-9
    return sec, nsec, ts

def load_timestamps(csv_path):
    """(Beibehalten für das Video; nutzt float-Sekunden)"""
    df = pd.read_csv(csv_path)
    if 'sec' in df.columns and 'nanosec' in df.columns:
        ts = df['sec'].astype(float) + df['nanosec'].astype(float) * 1e-9
    else:
        first_col = df.columns[0]
        ts = df[first_col].astype(float)
    return ts.values

def find_nearest_frame_index(timestamps, t):
    """
    Index des Frames in 'timestamps', dessen Zeit am nächsten zu 't' ist.
    """
    pos = bisect_left(timestamps, t)
    if pos == 0:
        return 0
    if pos >= len(timestamps):
        return len(timestamps) - 1
    before = timestamps[pos - 1]
    after  = timestamps[pos]
    return pos if (after - t) < (t - before) else (pos - 1)

def progress_bar(percent_done, bar_length=50):
    done_length = int(bar_length * percent_done / 100)
    bar = '=' * done_length + '-' * (bar_length - done_length)
    sys.stdout.write(f'[{bar}] {percent_done:6.2f}%\r')
    sys.stdout.flush()

def main():
    args = parse_arguments()
    video1_path = args.video1
    video2_path = args.video2
    csv1_path   = args.csv1
    csv2_path   = args.csv2
    output_path = args.output
    map_csv_path= args.map_csv

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
    # 2. Timestamps laden (zusätzlich Original-sec/nanosec für CSV-Ausgabe)
    # ----------------------------------------------------------------------------
    # Für Videoarbeit (float):
    timestamps1 = load_timestamps(csv1_path)
    timestamps2 = load_timestamps(csv2_path)

    # Für Mapping-CSV (Originalwerte + float):
    sec1, nsec1, ts1 = load_sec_nanosec_and_float(csv1_path)
    sec2, nsec2, ts2 = load_sec_nanosec_and_float(csv2_path)

    if len(timestamps1) != total_frames1:
        print(f"Warnung: Anzahl Timestamps1 ({len(timestamps1)}) != Gesamtframes Video1 ({total_frames1}).")
    if len(timestamps2) != total_frames2:
        print(f"Warnung: Anzahl Timestamps2 ({len(timestamps2)}) != Gesamtframes Video2 ({total_frames2}).")

    # ----------------------------------------------------------------------------
    # 3. Basis = Video mit weniger Timestamps (niedrigere Rate)
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
        # Mapping-Arrays:
        short_sec, short_nsec, short_ts = sec1, nsec1, ts1
        long_sec,  long_nsec,  long_ts  = sec2, nsec2, ts2
    else:
        # Video2 ist Basis (niedrigere Rate)
        cap_base        = cap2
        ts_base         = timestamps2
        total_base      = total_frames2
        cap_high        = cap1
        ts_high         = timestamps1
        total_high      = total_frames1
        label_base      = "Video2 (niedrig)"
        label_high      = "Video1 (hoch)"
        # Mapping-Arrays:
        short_sec, short_nsec, short_ts = sec2, nsec2, ts2
        long_sec,  long_nsec,  long_ts  = sec1, nsec1, ts1

    print(f"Basis: {label_base}, Frames: {total_base}, Timestamps: {len(ts_base)}")
    print(f"Schnell: {label_high}, Frames: {total_high}, Timestamps: {len(ts_high)}")

    # Sicherstellen, dass long_ts monoton ist (für bisect)
    if not np.all(np.diff(long_ts) >= 0):
        print("Warnung: Schnell-Video-Timestamps nicht monoton. Sortiere für Mapping-CSV …")
        order = np.argsort(long_ts)
        long_ts   = long_ts[order]
        long_sec  = long_sec[order]
        long_nsec = long_nsec[order]

    # ----------------------------------------------------------------------------
    # 4. Ersten Frame aus Basis/Schnell lesen -> Größen bestimmen
    # ----------------------------------------------------------------------------
    cap_base.set(cv2.CAP_PROP_POS_FRAMES, 0)
    cap_high.set(cv2.CAP_PROP_POS_FRAMES, 0)
    ret_base, frame_base_0 = cap_base.read()
    ret_high, frame_high_0 = cap_high.read()
    if not ret_base or frame_base_0 is None:
        raise IOError("Fehler beim Einlesen des ersten Frames des Basis-Videos.")
    if not ret_high or frame_high_0 is None:
        raise IOError("Fehler beim Einlesen des ersten Frames des schnellen Videos.")

    hb, wb = frame_base_0.shape[:2]
    hh, wh = frame_high_0.shape[:2]

    # Gleiche Zielbreite für beide
    target_width = min(wb, wh)
    scale_base_w = target_width / float(wb)
    scale_high_w = target_width / float(wh)

    target_height_base = int(round(hb * scale_base_w))
    target_height_high = int(round(hh * scale_high_w))

    combined_width  = target_width
    combined_height = target_height_base + target_height_high

    # ----------------------------------------------------------------------------
    # 5. Output-Video mit FIXEN 30 FPS
    # ----------------------------------------------------------------------------
    output_fps = 30.0
    print(f"Output-FPS fix: {output_fps:.2f}")
    fourcc = cv2.VideoWriter_fourcc(*'mp4v')
    out = cv2.VideoWriter(output_path, fourcc, output_fps, (combined_width, combined_height))
    if not out.isOpened():
        raise IOError(f"Konnte Output-Video nicht erstellen: {output_path}")

    # ----------------------------------------------------------------------------
    # 6. Loop über alle Basis-Frames + Mapping-CSV vorbereiten
    # ----------------------------------------------------------------------------
    print("Starte Synchronisation und Mapping-CSV-Erstellung …")
    last_frame_base = frame_base_0.copy()
    last_frame_high = frame_high_0.copy()

    # Precompute nearest indices for mapping & faster video reading
    nearest_idx = np.empty(len(ts_base), dtype=np.int64)
    for i, t_base in enumerate(ts_base):
        nearest_idx[i] = find_nearest_frame_index(long_ts, t_base)

    # Build mapping columns (short->nearest long) preserving input row order of the base
    map_long_sec  = long_sec[nearest_idx]
    map_long_nsec = long_nsec[nearest_idx]

    for i in range(len(ts_base)):
        # Basis-Frame i lesen
        cap_base.set(cv2.CAP_PROP_POS_FRAMES, i)
        ret_base, frame_base = cap_base.read()
        if not ret_base or frame_base is None:
            frame_base = last_frame_base.copy()
        else:
            last_frame_base = frame_base.copy()

        # Schnell-Frame nach nächstem Index lesen
        idx_high = find_nearest_frame_index(ts_high, ts_base[i])  # für Bildauswahl im Video
        cap_high.set(cv2.CAP_PROP_POS_FRAMES, idx_high)
        ret_high, frame_high = cap_high.read()
        if not ret_high or frame_high is None:
            frame_high = last_frame_high.copy()
        else:
            last_frame_high = frame_high.copy()

        # Resize + schreiben
        frameb_resized = cv2.resize(frame_base, (target_width, target_height_base))
        frameh_resized = cv2.resize(frame_high, (target_width, target_height_high))
        combined = np.vstack((frameb_resized, frameh_resized))
        out.write(combined)
        # Fortschritt
        progress_bar((i + 1) / len(ts_base) * 100)

    # ----------------------------------------------------------------------------
    # 7. Mapping-CSV speichern
    #    Reihenfolge = Basis-Reihenfolge (1:1 zu deren Frames/Zeilen)
    # ----------------------------------------------------------------------------
    map_df = pd.DataFrame({
        "short_sec": short_sec[:len(ts_base)],
        "short_nanosec": short_nsec[:len(ts_base)],
        "long_sec": map_long_sec,
        "long_nanosec": map_long_nsec,
    })
    map_df.to_csv(map_csv_path, index=False)

    sys.stdout.write(f"\nFertig: Video '{output_path}' und Mapping-CSV '{map_csv_path}' wurden erstellt.\n")

    cap1.release()
    cap2.release()
    out.release()

if __name__ == "__main__":
    main()
