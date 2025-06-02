#!/usr/bin/env python3
import sys
import pyzed.sl as sl
import numpy as np
import cv2
import enum
import argparse
import os
import csv


class AppType(enum.Enum):
    """Enumeration der Ausgabemodi für die SVO-Konvertierung."""
    LEFT_AND_RIGHT    = 0
    LEFT_AND_DEPTH    = 1
    LEFT_AND_DEPTH_16 = 2


def progress_bar(percent_done, bar_length=50):
    """
    Textueller Fortschrittsbalken in der Konsole.

    :param percent_done: Anteil der erledigten Arbeit (0–100).
    :type percent_done: float oder int
    :param bar_length: Breite des Balkens in Zeichen.
    :type bar_length: int
    """
    done_length = int(bar_length * percent_done / 100)
    bar = '=' * done_length + '-' * (bar_length - done_length)
    sys.stdout.write(f'[{bar}] {percent_done:6.0f}%\r')
    sys.stdout.flush()


def main(opt):
    """
    Ein einziger Durchlauf über alle Frames der SVO-Datei:
      1) ZED öffnen
      2) Zwei Frames grabben → echte Framerate berechnen
      3) SVO-Position zurücksetzen
      4) CSV-Datei + Video-Writer anlegen
      5) Für jedes Frame: grab → Timestamp in CSV schreiben → Bilder in MP4 schreiben → Fortschritt
      6) Aufräumen

    :param opt: Geparste Kommandozeilenargumente
    :type opt: argparse.Namespace
    :return: Exitcode (0 bei Erfolg)
    :rtype: int
    """
    # 1) Argumente einlesen
    svo_input_path        = opt.input_svo_file
    output_dir           = opt.output_path_dir
    left_output_path     = opt.output_left_mp4
    right_output_path    = opt.output_right_mp4
    combined_output_path = opt.output_combined_mp4
    mode                 = opt.mode

    if mode not in [0, 1, 2]:
        print("Mode muss 0, 1 oder 2 sein.")
        return 1
    app_type = AppType(mode)

    # 2) Output-Verzeichnis anlegen (falls nicht existiert)
    if not os.path.isdir(output_dir):
        os.makedirs(output_dir)

    # 3) ZED initialisieren
    init_params = sl.InitParameters()
    init_params.set_from_svo_file(svo_input_path)
    init_params.svo_real_time_mode = False
    init_params.coordinate_units = sl.UNIT.MILLIMETER

    zed = sl.Camera()
    err = zed.open(init_params)
    if err != sl.ERROR_CODE.SUCCESS:
        sys.stdout.write(f"[ERROR] Konnte ZED nicht öffnen: {err}\n")
        zed.close()
        return 1

    # 4) Basis-Infos auslesen
    nb_frames = zed.get_svo_number_of_frames()
    cam_info  = zed.get_camera_information().camera_configuration
    width     = cam_info.resolution.width
    height    = cam_info.resolution.height

    print(f"[INFO] SVO-Datei: '{svo_input_path}'")
    print(f"[INFO] Anzahl Frames im SVO: {nb_frames}")
    print(f"[INFO] Bildauflösung: {width}×{height}")

    # 5) Zwei Frames grabben, um Framerate zu berechnen
    rt_param = sl.RuntimeParameters()
    zed.set_svo_position(0)  # auf Frame 0 zurücksetzen

    # Erstes Frame
    err = zed.grab(rt_param)
    if err != sl.ERROR_CODE.SUCCESS:
        sys.stdout.write(f"[ERROR] Konnte ersten Frame nicht grabben: {err}\n")
        zed.close()
        return 1
    ts0 = zed.get_timestamp(sl.TIME_REFERENCE.IMAGE)
    sec0 = ts0.get_seconds()
    nsec0 = int(ts0.get_nanoseconds() - sec0 * 1_000_000_000)

    # Zweites Frame
    err = zed.grab(rt_param)
    if err != sl.ERROR_CODE.SUCCESS:
        sys.stdout.write(f"[ERROR] Konnte zweiten Frame nicht grabben: {err}\n")
        zed.close()
        return 1
    ts1 = zed.get_timestamp(sl.TIME_REFERENCE.IMAGE)
    sec1 = ts1.get_seconds()
    nsec1 = int(ts1.get_nanoseconds() - sec1 * 1_000_000_000)

    # Framerate berechnen
    t0 = sec0 + nsec0 * 1e-9
    t1 = sec1 + nsec1 * 1e-9
    delta = t1 - t0
    if delta > 0:
        fps = 1.0 / delta
    else:
        fps = 30.0  # Fallback
    fps = max(1.0, min(fps, 120.0))
    print(f"[INFO] Timestamp0 = {t0:.6f}s, Timestamp1 = {t1:.6f}s, Δ = {delta:.6f}s")
    print(f"[INFO] Errechnete SVO-Framerate: {fps:.2f} FPS")

    # SVO-Position zurück auf 0
    zed.set_svo_position(0)

    # 6) Video-Writer anlegen
    codec = cv2.VideoWriter_fourcc(*'mp4v')
    left_writer     = None
    right_writer    = None
    combined_writer = None

    if left_output_path:
        left_writer = cv2.VideoWriter(left_output_path, codec, fps, (width, height))
        if not left_writer.isOpened():
            sys.stdout.write("[ERROR] Konnte linken MP4-Writer nicht öffnen. Pfad/Perms prüfen.\n")
            zed.close()
            return 1

    if right_output_path:
        right_writer = cv2.VideoWriter(right_output_path, codec, fps, (width, height))
        if not right_writer.isOpened():
            sys.stdout.write("[ERROR] Konnte rechten/depth MP4-Writer nicht öffnen. Pfad/Perms prüfen.\n")
            zed.close()
            return 1

    if combined_output_path:
        combined_writer = cv2.VideoWriter(
            combined_output_path, codec, fps, (width * 2, height)
        )
        if not combined_writer.isOpened():
            sys.stdout.write("[ERROR] Konnte kombinierten MP4-Writer nicht öffnen. Pfad/Perms prüfen.\n")
            zed.close()
            return 1

    # 7) CSV-Datei öffnen und Kopfzeile schreiben
    csv_path   = os.path.join(output_dir, "timestamps.csv")
    csv_file   = open(csv_path, mode='w', newline='')
    csv_writer = csv.writer(csv_file)
    csv_writer.writerow(["Frame_Index", "sec", "nanosec"])

    # 8) EIN EINZIGER LOOP über alle Frames
    print("\nEinzelner Durchlauf: Video + Timestamps schreiben …")
    left_image  = sl.Mat()
    right_image = sl.Mat()
    depth_image = sl.Mat()
    frame_count = 0

    while frame_count < nb_frames-10:
        err = zed.grab(rt_param)
        if err == sl.ERROR_CODE.SUCCESS:
            # a) Timestamp holen
            ts   = zed.get_timestamp(sl.TIME_REFERENCE.IMAGE)
            sec  = ts.get_seconds()
            nsec = int(ts.get_nanoseconds() - sec * 1_000_000_000)

            # b) In CSV schreiben (0-basiert)
            csv_writer.writerow([frame_count, sec, nsec])

            # c) Linkes Bild holen und schreiben (BGRA → BGR)
            zed.retrieve_image(left_image, sl.VIEW.LEFT)
            left_ocv = left_image.get_data()
            if left_ocv is not None:
                if left_ocv.shape[2] == 4:  # falls BGRA
                    left_bgr = cv2.cvtColor(left_ocv, cv2.COLOR_BGRA2BGR)
                else:
                    left_bgr = left_ocv
                if left_writer:
                    left_writer.write(left_bgr)
            else:
                left_bgr = None

            # d) Rechtes Bild (Stereo/Depth) holen und schreiben
            if app_type == AppType.LEFT_AND_RIGHT:
                zed.retrieve_image(right_image, sl.VIEW.RIGHT)
                right_raw = right_image.get_data()
                if right_raw is not None:
                    if right_raw.shape[2] == 4:
                        right_bgr = cv2.cvtColor(right_raw, cv2.COLOR_BGRA2BGR)
                    else:
                        right_bgr = right_raw
                else:
                    right_bgr = None

            else:
                # Depth-Modi: retrieve_measure() + Normalisierung
                zed.retrieve_measure(depth_image, sl.MEASURE.DEPTH)
                depth_data = depth_image.get_data()
                if depth_data is not None:
                    depth_norm = cv2.normalize(
                        depth_data, None, 0, 255, cv2.NORM_MINMAX
                    ).astype(np.uint8)
                    if app_type == AppType.LEFT_AND_DEPTH:
                        right_bgr = cv2.cvtColor(depth_norm, cv2.COLOR_GRAY2BGR)
                    else:  # LEFT_AND_DEPTH_16
                        right_bgr = cv2.applyColorMap(depth_norm, cv2.COLORMAP_JET)
                else:
                    right_bgr = None

            if right_writer and right_bgr is not None:
                right_writer.write(right_bgr)

            # e) Optional kombiniertes Side-by-Side schreiben
            if combined_writer and left_bgr is not None and right_bgr is not None:
                combined = np.hstack((left_bgr, right_bgr))
                combined_writer.write(combined)

            # f) Fortschrittsbalken aktualisieren und Frame-Zähler hochzählen
            frame_count += 1
            progress_bar(frame_count / nb_frames * 100)

        else:
            # Ende oder Fehler abfangen
            if err == sl.ERROR_CODE.END_OF_SVOFILE_REACHED:
                progress_bar(100)
                print("\n[INFO] Ende des Durchlaufs. Fertig.")
                break
            else:
                print(f"\n[ERROR] Unerwarteter Fehler beim grab(): {err}")
                break

    # 9) Aufräumen: Writer & CSV schließen, ZED schließen
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
    parser.add_argument(
        '--mode', type=int, required=True,
        help="Mode 0: LEFT+RIGHT. Mode 1: LEFT+DEPTH. Mode 2: LEFT+DEPTH_16-bit."
    )
    parser.add_argument(
        '--input_svo_file', type=str, required=True,
        help='Pfad zu .svo/.svo2 Datei'
    )
    parser.add_argument(
        '--output_left_mp4', type=str, required=True,
        help='Pfad zum linken .mp4'
    )
    parser.add_argument(
        '--output_right_mp4', type=str, required=True,
        help='Pfad zum rechten/depth .mp4'
    )
    parser.add_argument(
        '--output_combined_mp4', type=str, default='',
        help='(Optional) Pfad zum kombinierten Side-by-Side .mp4'
    )
    parser.add_argument(
        '--output_path_dir', type=str, required=True,
        help='Output-Ordner für timestamps.csv'
    )
    opt = parser.parse_args()

    # Validierung
    if opt.mode < 0 or opt.mode > 2:
        print("Mode sollte 0, 1 oder 2 sein.")
        exit(1)
    if not opt.input_svo_file.endswith(('.svo', '.svo2')) or not os.path.isfile(opt.input_svo_file):
        print("Ungültige Eingabe-SVO-Datei.")
        exit(1)
    if not opt.output_left_mp4.endswith('.mp4') or not opt.output_right_mp4.endswith('.mp4'):
        print("Output-Dateien müssen auf .mp4 enden.")
        exit(1)
    if not os.path.isdir(opt.output_path_dir):
        print("Output-Verzeichnis existiert nicht.")
        exit(1)

    sys.exit(main(opt))
