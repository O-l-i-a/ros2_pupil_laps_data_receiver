#!/usr/bin/env python3
import sys, os, asyncio, threading, rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter
from rclpy.parameter_client import AsyncParameterClient
from std_srvs.srv import SetBool
from PyQt5.QtWidgets import (
    QApplication, QMainWindow, QPushButton, QLabel,
    QVBoxLayout, QWidget, QLineEdit
)
from PyQt5.QtCore import QTimer

# ────────────────────────────────────────────────────────  ROS node
class RecordingController(Node):
    def __init__(self):
        super().__init__('recording_controller_gui_node')

        # ---------- service clients ----------
        self.pupil_scene_cli = self.create_client(SetBool, 'record_pupil_scene')
        self.pupil_gaze_cli  = self.create_client(SetBool, 'record_pupil_gaze')
        self.pupil_blink_cli = self.create_client(SetBool, 'record_pupil_blink')
        self.pupil_imu_cli   = self.create_client(SetBool, 'record_pupil_imu')
        self.zed_depth_cli   = self.create_client(SetBool, '/zed_multi/record_zed_depth')
        self.zed_rgb_cli     = self.create_client(SetBool, '/zed_multi/record_zed_rgb')

        # ---------- parameter clients ----------
        self.recorder_nodes = [
            '/zed_multi/depth_recorder',
            '/zed_multi/rgb_recorder',
            '/pupil_scene_recorder',
            'pupil_gaze_recorder',
            'pupil_blink_recorder',
            'pupil_imu_recorder',
        ]
        self.param_clients = {
            name: AsyncParameterClient(self, remote_node_name=name)
            for name in self.recorder_nodes
        }

    # ---------------------------------------------------- broadcast parameter
    async def broadcast_participant(self, name: str, timeout=2.0):
        futures = {
            node: cli.set_parameters([
                Parameter('participant_name', Parameter.Type.STRING, name)
            ])
            for node, cli in self.param_clients.items()
        }

        done, _ = await asyncio.wait(futures.values(), timeout=timeout)
        ok, fail = [], []
        for node, fut in futures.items():
            try:
                if fut in done and fut.result().results[0].successful:
                    ok.append(node)
                else:
                    fail.append(node)
            except Exception:
                fail.append(node)
        return ok, fail


# ────────────────────────────────────────────────────────  Qt GUI
class MainWindow(QMainWindow):
    def __init__(self, node: RecordingController, loop: asyncio.AbstractEventLoop):
        super().__init__()
        self.node = node
        self.loop = loop
        self.setWindowTitle('Recording Controller')

        # ---------- widgets ----------
        self.status = QLabel('Status: Idle')
        self.start_btn = QPushButton('Start Recording')
        self.stop_btn  = QPushButton('Stop Recording')
        self.name_edit = QLineEdit(placeholderText='Participant name …')

        # ---------- layout ----------
        vbox = QVBoxLayout()
        for w in (self.status, self.start_btn, self.stop_btn, self.name_edit):
            vbox.addWidget(w)
        container = QWidget(); container.setLayout(vbox)
        self.setCentralWidget(container)

        # ---------- signals ----------
        self.start_btn.clicked.connect(self.start_recording)
        self.stop_btn.clicked.connect(self.stop_recording)
        self.name_edit.returnPressed.connect(self.on_name_entered)

        # ---------- periodic ROS spin ----------
        self.timer = QTimer(self); self.timer.timeout.connect(self.ros_spin)
        self.timer.start(40)

    # ---------------------------------------------------- helpers
    def ros_spin(self):
        rclpy.spin_once(self.node, timeout_sec=0.0)

    def _set_status(self, msg: str):
        # ensure execution in the Qt thread
        QTimer.singleShot(0, lambda m=msg: self.status.setText(m))

    async def _send_name(self, text):
        ok, fail = await self.node.broadcast_participant(text)
        if fail:
            self._set_status(f'❌ failed: {", ".join(fail)}')
        else:
            self._set_status(f'✓ sent to {len(ok)} nodes')

    def on_name_entered(self):
        text = self.name_edit.text().strip()
        if not text:
            self.status.setText('❗ empty participant name')
            return
        # schedule coroutine on background asyncio loop
        asyncio.run_coroutine_threadsafe(self._send_name(text), self.loop)

    # ---------------------------------------------------- start / stop
    def _call_service(self, client, data, timeout=2.0):
        if not client.wait_for_service(timeout_sec=timeout):
            return False
        req = SetBool.Request(); req.data = data
        fut = client.call_async(req)
        rclpy.spin_until_future_complete(self.node, fut)
        return getattr(fut.result(), 'success', False)

    def start_recording(self):
        self.status.setText('Status: Starting…')
        ts = self.node.get_clock().now().to_msg().sec
        base = os.path.expanduser('~/colcon_venv/recordings')
        os.makedirs(os.path.join(base, f'recording_{ts}'), exist_ok=True)

        ok = all([
            self._call_service(self.node.zed_depth_cli,  True),
            self._call_service(self.node.zed_rgb_cli,    True),
            self._call_service(self.node.pupil_scene_cli,True),
            self._call_service(self.node.pupil_gaze_cli, True),
            self._call_service(self.node.pupil_blink_cli, True),
            self._call_service(self.node.pupil_imu_cli,   True),
        ])
        self.status.setText('Status: Recording' if ok else '❌ start failed')

    def stop_recording(self):
        self.status.setText('Status: Stopping…')
        ok = all([
            self._call_service(self.node.zed_depth_cli,  False),
            self._call_service(self.node.zed_rgb_cli,    False),
            self._call_service(self.node.pupil_scene_cli,False),
            self._call_service(self.node.pupil_gaze_cli, False),
            self._call_service(self.node.pupil_blink_cli, False),
            self._call_service(self.node.pupil_imu_cli,   False),
        ])
        self.status.setText('Status: Stopped' if ok else '❌ stop failed')


# ────────────────────────────────────────────────────────  main
def main(argv=None):
    rclpy.init(args=argv)
    node = RecordingController()

    # ---------- dedicated asyncio loop ----------
    loop = asyncio.new_event_loop()
    threading.Thread(target=loop.run_forever, daemon=True).start()

    app = QApplication(sys.argv)
    win = MainWindow(node, loop); win.show()
    exit_code = app.exec_()

    # ---------- clean shutdown ----------
    loop.call_soon_threadsafe(loop.stop)
    node.destroy_node(); rclpy.shutdown()
    sys.exit(exit_code)

if __name__ == '__main__':
    main()
