import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from egocentric_msg.msg import GazeData
from rclpy.duration import Duration

class SystemController(Node):
    def __init__(self):
        super().__init__('system_controller')

        # Letzter Empfangszeitpunkt je Topic
        self.last_gaze_time = None
        self.last_scene_img_time = None
        self.last_eye_img_time = None

        # Flags, ob wir bereits gewarnt haben (damit Warnung nur einmal kommt)
        self.warned_gaze = False
        self.warned_scene = False
        self.warned_eye = False

        # Timeout: 2 Sekunden ohne neue Daten -> Warnung
        self.timeout = Duration(seconds=2.0)

        # Subscriber
        self.create_subscription(GazeData, '/pupil_labs/gaze', self.gaze_callback, 10)
        self.create_subscription(Image, '/pupil_labs/scene_img', self.scene_img_callback, 10)
        self.create_subscription(Image, '/pupil_labs/eye_img', self.eye_img_callback, 10)

        # Timer alle 0.5 Sekunden
        self.create_timer(0.5, self.check_status)

    def gaze_callback(self, msg):
        self.last_gaze_time = self.get_clock().now()
        self.warned_gaze = False  # Empfang -> Warnung zurücksetzen

    def scene_img_callback(self, msg):
        self.last_scene_img_time = self.get_clock().now()
        self.warned_scene = False

    def eye_img_callback(self, msg):
        self.last_eye_img_time = self.get_clock().now()
        self.warned_eye = False

    def check_status(self):
        now = self.get_clock().now()

        self.check_device("Gaze", self.last_gaze_time, now, 'gaze')
        self.check_device("Scene Camera", self.last_scene_img_time, now, 'scene')
        self.check_device("Eye Camera", self.last_eye_img_time, now, 'eye')

    def check_device(self, name, last_time, now, device_type):
        warned_attr = f"warned_{device_type}"
        warned = getattr(self, warned_attr)

        if last_time is None:
            if not warned:
                self.get_logger().warn(self.color_text(f"{name}: Noch keine Daten empfangen!", 'yellow'))
                setattr(self, warned_attr, True)
            return

        elapsed = now - last_time

        if elapsed > self.timeout:
            if not warned:
                self.get_logger().warn(self.color_text(f"{name}: Keine neuen Daten seit {elapsed.nanoseconds * 1e-9:.2f}s!", 'red'))
                setattr(self, warned_attr, True)
        else:
            # Nur dann OK-Message, wenn vorher gewarnt wurde
            if warned:
                self.get_logger().info(self.color_text(f"{name}: OK", 'green'))
                setattr(self, warned_attr, False)

    def color_text(self, text, color):
        colors = {
            'red': '\033[91m',
            'green': '\033[92m',
            'yellow': '\033[93m',
            'reset': '\033[0m'
        }
        return f"{colors[color]}{text}{colors['reset']}"

def main(args=None):
    rclpy.init(args=args)
    node = SystemController()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
