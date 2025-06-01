#!/usr/bin/env python3
import asyncio
import os
import csv
import cv2
import threading

import rclpy
from rclpy.node import Node
from rclpy.executors import SingleThreadedExecutor
from std_srvs.srv import SetBool
from sensor_msgs.msg import Image, CameraInfo
from cv_bridge import CvBridge

from pupil_labs.realtime_api import Network, Device, receive_gaze_data, receive_video_frames
from gaze_interface.msg import GazeDataAsync  # Passe hier dein Package/Msg an


class PupilAsyncRecorder(Node):
    def __init__(self):
        super().__init__('pupil_async_recorder')

        # Publisher für Gaze- und Scene-Daten
        self.gaze_pub = self.create_publisher(GazeDataAsync, 'pupil/gaze', 10)
        self.scene_pub = self.create_publisher(Image, 'pupil/scene/image_raw', 10)
        self.scene_info_pub = self.create_publisher(CameraInfo, 'pupil/scene/camera_info', 10)

        self.bridge = CvBridge()

        # Aufnahme-Status und File-Handles
        self.recording = False
        self.csv_file = None
        self.csv_writer = None
        self.scene_writer = None
        self.session_dir = ''
        self.prefix = ''

        # Ein Lock, das jeden Zugriff auf csv_writer bzw. scene_writer synchronisiert
        self._writer_lock = threading.Lock()

        # Service-Server zum Start/Stoppen der lokalen Aufzeichnung
        self.create_service(SetBool, 'record', self.record_callback)

        self.get_logger().info('PupilAsyncRecorder bereit. Warte auf /record Service…')

    def record_callback(self, request, response):
        """
        Callback für den /record-Service (std_srvs/SetBool).
        Startet oder stoppt CSV- und Video-Aufzeichnung lokal.
        """
        want_start = bool(request.data)
        if want_start == self.recording:
            response.success = False
            response.message = 'No change'
            return response

        if want_start:
            # === Aufnahme STARTEN ===
            now = self.get_clock().now().to_msg()
            self.prefix = str(now.sec)
            base_dir = 'recordings'
            os.makedirs(base_dir, exist_ok=True)
            self.session_dir = os.path.join(base_dir, f'recording_{self.prefix}')
            os.makedirs(self.session_dir, exist_ok=True)

            # CSV vorbereiten
            csv_path = os.path.join(self.session_dir, f'{self.prefix}_gaze.csv')
            try:
                self.csv_file = open(csv_path, 'w', newline='')
                self.csv_writer = csv.writer(self.csv_file)
                self.csv_writer.writerow([
                    'sec',
                    'nanosec',
                    'norm_pos_x',
                    'norm_pos_y'
                ])
            except Exception as e:
                response.success = False
                response.message = f'Fehler beim Öffnen der CSV-Datei: {e}'
                self.get_logger().error(response.message)
                return response

            # VideoWriter wird erst beim ersten Frame angelegt; hier nur Dummy-Zuweisung
            with self._writer_lock:
                self.scene_writer = None

            self.recording = True
            response.success = True
            response.message = f'Recording started in {self.session_dir}'
            self.get_logger().info(response.message)
        else:
            # === Aufnahme STOPPEN ===
            # 1) CSV schließen (unter Lock, damit kein write mehr parallel reinkommt)
            with self._writer_lock:
                if self.csv_file:
                    try:
                        self.csv_file.close()
                        self.get_logger().info('Gaze-CSV geschlossen.')
                    except Exception:
                        pass
                    self.csv_file = None
                    self.csv_writer = None

                # 2) VideoWriter freigeben
                if self.scene_writer:
                    try:
                        self.scene_writer.release()
                        self.get_logger().info('Scene-VideoWriter freigegeben.')
                    except Exception as e:
                        self.get_logger().error(f'Fehler beim Release des VideoWriters: {e}')
                    finally:
                        self.scene_writer = None

            self.recording = False
            response.success = True
            response.message = 'Recording stopped'
            self.get_logger().info(response.message)

        return response

    async def gaze_stream(self, url: str):
        """
        Asynchroner Iterator für Blickdaten.
        Schreibt in CSV, wenn self.recording == True.
        """
        self.get_logger().info(f'Starting gaze stream: {url}')
        async for gaze in receive_gaze_data(url, run_loop=True):
            # 1) ROS-Publish
            msg = GazeDataAsync()
            msg.header.stamp = self.get_clock().now().to_msg()
            msg.header.frame_id = 'pupil_gaze'
            msg.norm_pos_x = gaze.x
            msg.norm_pos_y = gaze.y
            self.gaze_pub.publish(msg)

            # 2) CSV-Schreiben nur, wenn recording=True
            if self.recording:
                with self._writer_lock:
                    # Zusätzliche Prüfung: csv_writer könnte inzwischen None sein
                    if self.csv_writer:
                        try:
                            ts = msg.header.stamp
                            self.csv_writer.writerow([
                                ts.sec,
                                ts.nanosec,
                                gaze.x,
                                gaze.y
                            ])
                        except Exception as e:
                            self.get_logger().error(f'Fehler beim Schreiben in CSV: {e}')
                    # Wenn csv_writer None ist, überspringen wir einfach

    async def scene_stream(self, url: str):
        """
        Asynchroner Iterator für Scene-Frames.
        Schreibt Video, wenn self.recording == True.
        """
        self.get_logger().info(f'Starting scene stream: {url}')
        async for frame in receive_video_frames(url, run_loop=True):
            img = frame.bgr_buffer()  # HxWx3 BGR numpy.ndarray

            # 1) ROS-Publish
            ros_img = self.bridge.cv2_to_imgmsg(img, encoding='bgr8')
            ros_img.header.stamp = self.get_clock().now().to_msg()
            ros_img.header.frame_id = 'pupil_scene'
            self.scene_pub.publish(ros_img)

            info = CameraInfo()
            info.header = ros_img.header
            info.height = img.shape[0]
            info.width = img.shape[1]
            self.scene_info_pub.publish(info)

            # 2) Video-Schreiben nur, wenn recording=True
            if self.recording:
                with self._writer_lock:
                    # Writer lazy anlegen, falls None
                    if self.scene_writer is None:
                        height, width = img.shape[:2]
                        fourcc = cv2.VideoWriter_fourcc(*'mp4v')
                        fps = 30.0  # typische Scene-FPS
                        video_path = os.path.join(self.session_dir, f'{self.prefix}_scene.mp4')
                        try:
                            self.scene_writer = cv2.VideoWriter(video_path, fourcc, fps, (width, height))
                            if not self.scene_writer.isOpened():
                                raise RuntimeError('VideoWriter konnte nicht geöffnet werden')
                            self.get_logger().info(f'Scene-Writer geöffnet: {video_path}')
                        except Exception as e:
                            self.get_logger().error(f'Fehler beim Erstellen des VideoWriters: {e}')
                            self.scene_writer = None

                    # Wenn Writer nutzbar, schreibe
                    if self.scene_writer is not None:
                        try:
                            self.scene_writer.write(img)
                        except Exception as e:
                            # FFmpeg-Fehler abfangen und nur loggen
                            self.get_logger().error(f'FFmpeg-Error beim write(): {e}')

    async def run(self):
        """
        Device-Discovery und anschließendes Starten der Streams.
        """
        self.get_logger().info('Discovering Pupil device...')
        async with Network() as network:
            dev_info = await network.wait_for_new_device(timeout_seconds=20)
        if dev_info is None:
            self.get_logger().error('No Pupil device found, aborting')
            return
        else:
            self.get_logger().info('Pupil device connected')

        async with Device.from_discovered_device(dev_info) as device:
            status = await device.get_status()
            gaze_sensor = status.direct_gaze_sensor()
            world_sensor = status.direct_world_sensor()

            if not gaze_sensor.connected:
                self.get_logger().error('Gaze sensor not connected')
                return
            if not world_sensor.connected:
                self.get_logger().error('Scene camera not connected')
                return

            # Beide Streams parallel starten
            await asyncio.gather(
                self.gaze_stream(gaze_sensor.url),
                self.scene_stream(world_sensor.url),
            )

    def destroy_node(self):
        # Beim Shutdown: CSV und VideoWriter schließen
        with self._writer_lock:
            if self.csv_file:
                try:
                    self.csv_file.close()
                except Exception:
                    pass
                self.csv_file = None
                self.csv_writer = None

            if self.scene_writer:
                try:
                    self.scene_writer.release()
                except Exception:
                    pass
                self.scene_writer = None

        super().destroy_node()


def main():
    rclpy.init()

    # 1) Node-Instanz erstellen
    node = PupilAsyncRecorder()

    # 2) Executor anlegen und Node hinzufügen
    executor = SingleThreadedExecutor()
    executor.add_node(node)

    # 3) ROS-Spin in eigenem Thread starten
    spin_thread = threading.Thread(target=executor.spin, daemon=True)
    spin_thread.start()

    # 4) Asynchrone Device-Discovery und Streaming starten
    try:
        asyncio.run(node.run())
    except KeyboardInterrupt:
        pass
    finally:
        # 5) Sauber beenden
        executor.shutdown()
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
