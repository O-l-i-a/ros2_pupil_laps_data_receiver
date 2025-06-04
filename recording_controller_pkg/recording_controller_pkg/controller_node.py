#!/usr/bin/env python3
import sys
import os

import rclpy
from rclpy.node import Node
from std_srvs.srv import SetBool, Trigger
from zed_msgs.srv import StartSvoRec

from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton, QLabel, QVBoxLayout, QWidget
from PyQt5.QtCore import QTimer

class RecordingController(Node):
    """
    ROS2 node that manages service clients for Pupil Labs and ZED recording.
    """
    def __init__(self):
        """
        Initialize the node and create service clients:
         - /record (std_srvs/SetBool) to start/stop Pupil recording
         - /zed/zed_node/start_svo_rec (zed_msgs/StartSvoRec) to start ZED recording
         - /zed/zed_node/stop_svo_rec (std_srvs/Trigger) to stop ZED recording
        """
        super().__init__('recording_controller_gui_node')
        # Client for Pupil Labs record service
        self.pupil_client = self.create_client(SetBool, 'record_pupil_scene_with_gaze')
        # Client for ZED start SVO recording service
        self.zed_start_client = self.create_client(StartSvoRec, '/zed/zed_node/start_svo_rec')
        # Client for ZED stop SVO recording service
        self.zed_stop_client = self.create_client(Trigger, '/zed/zed_node/stop_svo_rec')

class MainWindow(QMainWindow):
    """
    Qt MainWindow providing GUI to start and stop recordings.
    """
    def __init__(self, controller_node: RecordingController):
        """
        Initialize the GUI elements, connect button callbacks, and start a QTimer
        for spinning the ROS2 node.

        :param controller_node: The ROS2 node handling recording services.
        :type controller_node: RecordingController
        """
        super().__init__()
        self.node = controller_node
        self.setWindowTitle('Recording Controller')

        # Create widgets
        self.status_label = QLabel('Status: Idle')
        self.start_btn = QPushButton('Start Recording')
        self.stop_btn = QPushButton('Stop Recording')

        # Connect button signals to methods
        self.start_btn.clicked.connect(self.start_recording)
        self.stop_btn.clicked.connect(self.stop_recording)

        # Arrange widgets vertically
        layout = QVBoxLayout()
        layout.addWidget(self.status_label)
        layout.addWidget(self.start_btn)
        layout.addWidget(self.stop_btn)
        container = QWidget()
        container.setLayout(layout)
        self.setCentralWidget(container)

        # QTimer to periodically call ros_spin()
        self.timer = QTimer()
        self.timer.timeout.connect(self.ros_spin)
        self.timer.start(50)  # 50 ms interval

    def ros_spin(self):
        """
        Spin the ROS2 node once without blocking, to process service callbacks.
        """
        rclpy.spin_once(self.node, timeout_sec=0)

    def call_service(self, client, request, timeout=2.0):
        """
        Call a ROS2 service and wait for the response.

        :param client: The service client.
        :param request: The service request object.
        :param timeout: Seconds to wait for service availability.
        :returns: Tuple(success flag, message string)
        """
        if not client.wait_for_service(timeout_sec=timeout):
            return False, 'Service unavailable'
        future = client.call_async(request)
        rclpy.spin_until_future_complete(self.node, future)
        response = future.result()
        # Extract common attributes
        success = getattr(response, 'success', False)
        message = getattr(response, 'message', '')
        return success, message

    def start_recording(self):
        """
        Start both Pupil Labs and ZED recordings.
        Creates a timestamped session folder for ZED SVO files.
        If ZED fails to start, Pupil is stopped to maintain sync.
        Updates status label accordingly.
        """
        self.status_label.setText('Status: Starting...')

        # Determine session timestamp and create folder
        sec = int(self.node.get_clock().now().to_msg().sec)
        base_dir = os.path.expanduser('~/colcon_venv/recordings')
        session_dir = os.path.join(base_dir, f'recording_{sec}')
        os.makedirs(session_dir, exist_ok=True)

        # Start Pupil recording
        pupil_req = SetBool.Request()
        pupil_req.data = True
        ok_pupil, msg_pupil = self.call_service(self.node.pupil_client, pupil_req)

        # Start ZED recording only if Pupil started successfully
        ok_zed = False
        if ok_pupil:
            zed_req = StartSvoRec.Request(
                bitrate=0,
                compression_mode=1,
                target_framerate=30,
                input_transcode=False,
                svo_filename=os.path.join(session_dir, f"rec_{sec}.svo")
            )
            ok_zed, _ = self.call_service(self.node.zed_start_client, zed_req)
            # Stop Pupil if ZED failed to start
            if not ok_zed:
                stop_req = SetBool.Request()
                stop_req.data = False
                self.call_service(self.node.pupil_client, stop_req)

        # Update status label
        if ok_pupil and ok_zed:
            self.status_label.setText('Status: Recording')
        else:
            self.status_label.setText(f'Error starting: Pupil={ok_pupil}, ZED={ok_zed}')

    def stop_recording(self):
        """
        Stop both Pupil Labs and ZED recordings.
        Calls both stop services regardless of individual success, then updates status.
        """
        self.status_label.setText('Status: Stopping...')

        # Stop Pupil recording
        pupil_req = SetBool.Request()
        pupil_req.data = False
        ok_pupil, msg_pupil = self.call_service(self.node.pupil_client, pupil_req)

        # Stop ZED recording
        trigger_req = Trigger.Request()
        ok_zed, msg_zed = self.call_service(self.node.zed_stop_client, trigger_req)

        # Update status label
        if ok_pupil and ok_zed:
            self.status_label.setText('Status: Stopped')
        else:
            self.status_label.setText(f'Error stopping: Pupil={ok_pupil}, ZED={ok_zed}')

def main(args=None):
    """
    Entry point: initialize ROS2, create controller node and Qt application,
    and start the GUI event loop while spinning ROS in the background.
    """
    rclpy.init(args=args)
    node = RecordingController()

    # Handle Ctrl-C properly
    app = QApplication(sys.argv)
    window = MainWindow(node)
    window.show()

    # Start Qt event loop
    exit_code = app.exec_()

    # Clean up ROS2
    node.destroy_node()
    rclpy.shutdown()
    sys.exit(exit_code)

if __name__ == '__main__':
    main()
