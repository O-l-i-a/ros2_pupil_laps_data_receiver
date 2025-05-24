import sys
import threading
import os

import rclpy
from rclpy.node import Node
from std_srvs.srv import SetBool
from zed_msgs.srv import StartSvoRec
from std_srvs.srv import Trigger

from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton, QLabel, QVBoxLayout, QWidget
from PyQt5.QtCore import QTimer

class RecordingController(Node):
    def __init__(self):
        super().__init__('recording_controller_gui_node')
        # Clients
        self.pupil_client = self.create_client(SetBool, '/record')
        self.zed_start_client = self.create_client(StartSvoRec, '/zed/zed_node/start_svo_rec')
        self.zed_stop_client = self.create_client(Trigger, '/zed/zed_node/stop_svo_rec')

class MainWindow(QMainWindow):
    def __init__(self, rclpy_node):
        super().__init__()
        self.setWindowTitle('Recording Controller')
        self.node = rclpy_node
        # Widgets
        self.status_label = QLabel('Status: Idle')
        self.start_btn = QPushButton('Start Recording')
        self.stop_btn = QPushButton('Stop Recording')
        self.start_btn.clicked.connect(self.start_recording)
        self.stop_btn.clicked.connect(self.stop_recording)
        # Layout
        layout = QVBoxLayout()
        layout.addWidget(self.status_label)
        layout.addWidget(self.start_btn)
        layout.addWidget(self.stop_btn)
        container = QWidget()
        container.setLayout(layout)
        self.setCentralWidget(container)
        # Timer to spin ROS2
        self.timer = QTimer()
        self.timer.timeout.connect(self.ros_spin)
        self.timer.start(50)

    def ros_spin(self):
        rclpy.spin_once(self.node, timeout_sec=0)

    def call_service(self, client, req):
        if not client.wait_for_service(timeout_sec=2.0):
            return False, 'Service unavailable'
        future = client.call_async(req)
        rclpy.spin_until_future_complete(self.node, future)
        res = future.result()
        # different types have different attributes
        success = getattr(res, 'success', False)
        message = getattr(res, 'message', '')
        return success, message

    def start_recording(self):
        self.status_label.setText('Status: Starting...')
        #time
        # BASE-folder
        sec = int(self.node.get_clock().now().to_msg().sec)
        base_dir = os.path.expanduser('~/colcon_venv/recordings')
        #session folder:
        session_dir = os.path.join(base_dir, f'recording_{sec}')
        os.makedirs(session_dir, exist_ok=True)
        # Pupil
        pupil_req = SetBool.Request()
        pupil_req.data = True
        ok_pupil, msg_pupil = self.call_service(self.node.pupil_client, pupil_req)
        # ZED
        if ok_pupil:
            zed_req = StartSvoRec.Request(
            bitrate=0,
            compression_mode=0,
            target_framerate=30,
            input_transcode=False,
            svo_filename=os.path.join(session_dir, f"rec_{sec}.svo")
        )
            ok_zed, _ = self.call_service(self.node.zed_start_client, zed_req)
            if not ok_zed:
            # Pupil beenden, wenn ZED nicht startet
                self.call_service(self.node.pupil_client, SetBool.Request(data=False))
        # Statusanzeige
        self.status_label.setText('Recording' if ok_pupil and ok_zed else 'Error')

    def stop_recording(self):
        self.status_label.setText('Status: Stopping...')
        # Pupil
        pupil_req = SetBool.Request()
        pupil_req.data = False
        ok_pupil, msg_pupil = self.call_service(self.node.pupil_client, pupil_req)
        # ZED
        trigger_req = Trigger.Request()
        ok_zed, msg_zed = self.call_service(self.node.zed_stop_client, trigger_req)
        if ok_pupil and ok_zed:
            self.status_label.setText('Status: Stopped')
        else:
            self.status_label.setText(f'Error: Pupil({ok_pupil}), ZED({ok_zed})')

def main(args=None):
    rclpy.init(args=args)
    node = RecordingController()
    # run Qt in main thread
    app = QApplication(sys.argv)
    window = MainWindow(node)
    window.show()
    # ensure ROS spin in background
    exit_code = app.exec_()
    node.destroy_node()
    rclpy.shutdown()
    sys.exit(exit_code)

if __name__ == '__main__':
    main()
