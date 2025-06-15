import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CompressedImage
from cv_bridge import CvBridge, CvBridgeError
import pyzed.sl as sl
from rclpy.qos import QoSProfile, HistoryPolicy, ReliabilityPolicy

class ZedWrapperNode(Node):
    def __init__(self):
        super().__init__('zed_wrapper_node')
        self.bridge = CvBridge()
        qos = QoSProfile(
            depth=5,
            history=HistoryPolicy.KEEP_LAST,
            reliability=ReliabilityPolicy.RELIABLE,
        )
        # Publishers for color and depth
        self.color_pub = self.create_publisher(CompressedImage, 'zed/color/image_raw', qos)
        self.depth_pub = self.create_publisher(Image, 'zed/depth/image_raw', qos)

        # Initialize ZED camera for HD720 at 60 FPS
        init_params = sl.InitParameters()
        init_params.camera_resolution = sl.RESOLUTION.HD720
        init_params.camera_fps = 60
        init_params.depth_mode = sl.DEPTH_MODE.NEURAL  # deprecated, consider NEURAL
        init_params.coordinate_units = sl.UNIT.METER

        self.zed = sl.Camera()
        status = self.zed.open(init_params)
        if status != sl.ERROR_CODE.SUCCESS:
            self.get_logger().error(f"Failed to open ZED camera: {status}")
            rclpy.shutdown()
            return

        # Timer for ~60Hz capturing loop
        self.create_timer(1.0/120.0, self.timer_callback)

    def timer_callback(self):
        # Grab a new frame
        if self.zed.grab() != sl.ERROR_CODE.SUCCESS:
            return

        # Timestamp for both images
        timestamp = self.get_clock().now().to_msg()

        # Retrieve and publish color image
        mat_color = sl.Mat()
        self.zed.retrieve_image(mat_color, sl.VIEW.LEFT)
        color_img = mat_color.get_data()  # ZED returns 8UC4 (BGRA)
        try:
            # Use 'bgra8' encoding to match 4-channel BGRA data
            color_msg = self.bridge.cv2_to_compressed_imgmsg(color_img, dst_format='jpeg')
        except CvBridgeError as e:
            self.get_logger().error(f"Failed to convert color image: {e}")
            return
        color_msg.header.stamp = timestamp
        color_msg.header.frame_id = 'zed_camera'
        self.color_pub.publish(color_msg)

        # Retrieve and publish depth image
        mat_depth = sl.Mat()
        self.zed.retrieve_image(mat_depth, sl.VIEW.DEPTH)
        depth_img = mat_depth.get_data()  # float32 single channel
        try:
            depth_msg = self.bridge.cv2_to_imgmsg(depth_img, encoding='8UC4')
        except CvBridgeError as e:
            self.get_logger().error(f"Failed to convert depth image: {e}")
            return
        depth_msg.header = color_msg.header
        self.depth_pub.publish(depth_msg)

    def destroy_node(self):
        # Cleanup camera
        self.zed.close()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = ZedWrapperNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
