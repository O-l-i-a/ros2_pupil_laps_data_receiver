import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from egocentric_msg.msg import GazeData
from sensor_msgs.msg import Image

from PyQt5.QtWidgets import QApplication, QLabel, QWidget, QVBoxLayout, QMainWindow, QFrame
from PyQt5.QtCore import QTimer, Qt
import sys
import threading


class SystemController(Node):
    def __init__(self, gui):
        super().__init__('system_controller')
        self.gui = gui

        self.gaze_received = False
        self.scene_received = False
        self.eye_received = False

        self.sub_gaze = self.create_subscription(
            GazeData,
            '/pupil_labs/gaze',
            self.gaze_callback,
            qos_profile_sensor_data
        )

        self.sub_scene = self.create_subscription(
            Image,
            '/pupil_labs/scene_img',
            self.scene_callback,
            qos_profile_sensor_data
        )

        self.sub_eye = self.create_subscription(
            Image,
            '/pupil_labs/eye_img',
            self.eye_callback,
            qos_profile_sensor_data
        )

        self.timer = self.create_timer(2.0, self.check_topics)

    def gaze_callback(self, msg):
        self.gaze_received = True

    def scene_callback(self, msg):
        self.scene_received = True

    def eye_callback(self, msg):
        self.eye_received = True

    def check_topics(self):
        self.gui.update_status("Gaze", self.gaze_received)
        self.gui.update_status("Scene", self.scene_received)
        self.gui.update_status("Eye", self.eye_received)

        self.gaze_received = False
        self.scene_received = False
        self.eye_received = False


class StatusGUI(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("ROS2 System Controller Status")
        self.setGeometry(100, 100, 400, 200)

        self.status_labels = {
            "Gaze": QLabel("Gaze-Stream: ⏳"),
            "Scene": QLabel("Scene-Kamera-Stream: ⏳"),
            "Eye": QLabel("Eye-Kamera-Stream: ⏳")
        }

        for label in self.status_labels.values():
            label.setStyleSheet("font-size: 16px; padding: 4px")

        layout = QVBoxLayout()
        for label in self.status_labels.values():
            layout.addWidget(label)

        container = QWidget()
        container.setLayout(layout)
        self.setCentralWidget(container)

    def update_status(self, stream_name, is_active):
        label = self.status_labels[stream_name]
        if is_active:
            label.setText(f"{stream_name}-Stream: ✅ Aktiv")
            label.setStyleSheet("color: green; font-size: 16px")
        else:
            label.setText(f"{stream_name}-Stream: ❌ Keine Daten")
            label.setStyleSheet("color: red; font-size: 16px")


def ros_spin_thread(node):
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


def main():
    rclpy.init()

    app = QApplication(sys.argv)
    gui = StatusGUI()
    gui.show()

    node = SystemController(gui)

    thread = threading.Thread(target=ros_spin_thread, args=(node,), daemon=True)
    thread.start()

    sys.exit(app.exec_())


if __name__ == '__main__':
    main()
