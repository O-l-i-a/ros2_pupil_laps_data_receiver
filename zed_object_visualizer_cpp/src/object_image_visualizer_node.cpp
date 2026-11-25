#include <algorithm>
#include <array>
#include <cmath>
#include <mutex>
#include <sstream>
#include <string>
#include <vector>

#include <cv_bridge/cv_bridge.hpp>
#include <image_transport/image_transport.hpp>
#include <opencv2/imgproc.hpp>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <zed_msgs/msg/object.hpp>
#include <zed_msgs/msg/objects_stamped.hpp>

namespace
{
using sensor_msgs::msg::Image;
using zed_msgs::msg::Object;
using zed_msgs::msg::ObjectsStamped;

cv::Scalar colorForId(const int id)
{
  static const std::array<cv::Scalar, 10> colors = {
    cv::Scalar(20, 180, 255),
    cv::Scalar(50, 220, 80),
    cv::Scalar(255, 130, 40),
    cv::Scalar(220, 80, 220),
    cv::Scalar(80, 210, 210),
    cv::Scalar(255, 90, 90),
    cv::Scalar(160, 220, 40),
    cv::Scalar(80, 150, 255),
    cv::Scalar(200, 200, 80),
    cv::Scalar(180, 120, 255),
  };

  const auto index = static_cast<size_t>(std::abs(id)) % colors.size();
  return colors[index];
}

cv::Point clampPoint(const cv::Point & point, const cv::Size & size)
{
  return cv::Point{
    std::clamp(point.x, 0, std::max(size.width - 1, 0)),
    std::clamp(point.y, 0, std::max(size.height - 1, 0))};
}

std::vector<cv::Point> boundingBoxPoints(const Object & object, const cv::Size & image_size)
{
  std::vector<cv::Point> points;
  points.reserve(object.bounding_box_2d.corners.size());

  for (const auto & corner : object.bounding_box_2d.corners) {
    points.emplace_back(
      clampPoint(
        cv::Point{
          static_cast<int>(corner.kp[0]),
          static_cast<int>(corner.kp[1])},
        image_size));
  }

  return points;
}

bool validBox(const std::vector<cv::Point> & points)
{
  if (points.size() < 4) {
    return false;
  }

  const auto [min_x_it, max_x_it] = std::minmax_element(
    points.begin(), points.end(), [](const auto & lhs, const auto & rhs) {
      return lhs.x < rhs.x;
    });
  const auto [min_y_it, max_y_it] = std::minmax_element(
    points.begin(), points.end(), [](const auto & lhs, const auto & rhs) {
      return lhs.y < rhs.y;
    });

  return (max_x_it->x - min_x_it->x) > 1 && (max_y_it->y - min_y_it->y) > 1;
}

std::string objectText(const Object & object)
{
  std::ostringstream text;
  text << (object.label.empty() ? "object" : object.label);

  if (!object.sublabel.empty()) {
    text << "/" << object.sublabel;
  }

  if (object.confidence > 0.0F) {
    text << " " << static_cast<int>(std::round(object.confidence)) << "%";
  }

  if (object.tracking_available) {
    text << " id:" << object.label_id;
  }

  return text.str();
}

void drawLabel(cv::Mat & image, const std::string & text, const cv::Point & anchor, const cv::Scalar & color)
{
  constexpr int font_face = cv::FONT_HERSHEY_SIMPLEX;
  constexpr double font_scale = 0.55;
  constexpr int thickness = 1;
  int baseline = 0;
  const cv::Size text_size = cv::getTextSize(text, font_face, font_scale, thickness, &baseline);

  cv::Point origin{anchor.x, std::max(anchor.y - 8, text_size.height + 6)};
  const cv::Rect background{
    std::max(origin.x - 3, 0),
    std::max(origin.y - text_size.height - 5, 0),
    std::min(text_size.width + 6, image.cols),
    std::min(text_size.height + baseline + 7, image.rows)};

  cv::rectangle(image, background, color, cv::FILLED);
  cv::putText(
    image,
    text,
    origin,
    font_face,
    font_scale,
    cv::Scalar(20, 20, 20),
    thickness,
    cv::LINE_AA);
}

void drawSkeleton(cv::Mat & image, const Object & object, const cv::Scalar & color)
{
  if (!object.skeleton_available) {
    return;
  }

  for (const auto & keypoint : object.skeleton_2d.keypoints) {
    const auto x = keypoint.kp[0];
    const auto y = keypoint.kp[1];
    if (std::isfinite(x) && std::isfinite(y) && x > 0.0F && y > 0.0F &&
      x < static_cast<float>(image.cols) && y < static_cast<float>(image.rows))
    {
      cv::circle(image, cv::Point{static_cast<int>(x), static_cast<int>(y)}, 3, color, cv::FILLED, cv::LINE_AA);
    }
  }
}
}  // namespace

class ZedObjectImageVisualizer : public rclcpp::Node
{
public:
  explicit ZedObjectImageVisualizer(const rclcpp::NodeOptions & options = rclcpp::NodeOptions())
  : Node("zed_object_image_visualizer", options)
  {
    const auto image_topic =
      declare_parameter<std::string>("image_topic", "/zed_multi/myzed2i/rgb/image_rect_color");
    const auto objects_topic =
      declare_parameter<std::string>("objects_topic", "/zed_multi/myzed2i/obj_det/objects");
    const auto output_topic =
      declare_parameter<std::string>("output_topic", "/zed_multi/myzed2i/obj_det/image_overlay");
    draw_skeleton_ = declare_parameter<bool>("draw_skeleton", true);
    draw_tracking_state_ = declare_parameter<bool>("draw_tracking_state", false);

    auto image_qos = rclcpp::SensorDataQoS().keep_last(5);
    auto object_qos = rclcpp::SensorDataQoS().keep_last(10);

    image_sub_ = image_transport::create_subscription(
      this,
      image_topic,
      std::bind(&ZedObjectImageVisualizer::imageCallback, this, std::placeholders::_1),
      "raw",
      image_qos.get_rmw_qos_profile());

    objects_sub_ = create_subscription<ObjectsStamped>(
      objects_topic,
      object_qos,
      std::bind(&ZedObjectImageVisualizer::objectsCallback, this, std::placeholders::_1));

    image_pub_ = image_transport::create_publisher(this, output_topic);

    RCLCPP_INFO(get_logger(), "Subscribing to image topic: %s", image_topic.c_str());
    RCLCPP_INFO(get_logger(), "Subscribing to objects topic: %s", objects_topic.c_str());
    RCLCPP_INFO(get_logger(), "Publishing overlay image: %s", output_topic.c_str());
  }

private:
  void objectsCallback(const ObjectsStamped::ConstSharedPtr msg)
  {
    std::lock_guard<std::mutex> lock(objects_mutex_);
    latest_objects_ = msg;
  }

  void imageCallback(const Image::ConstSharedPtr msg)
  {
    ObjectsStamped::ConstSharedPtr objects;
    {
      std::lock_guard<std::mutex> lock(objects_mutex_);
      objects = latest_objects_;
    }

    cv_bridge::CvImagePtr cv_image;
    try {
      cv_image = cv_bridge::toCvCopy(msg, "bgr8");
    } catch (const cv_bridge::Exception & error) {
      RCLCPP_WARN_THROTTLE(
        get_logger(),
        *get_clock(),
        2000,
        "Could not convert image to bgr8: %s",
        error.what());
      return;
    }

    if (objects) {
      drawObjects(cv_image->image, *objects);
    }

    cv_image->header = msg->header;
    cv_image->encoding = "bgr8";
    image_pub_.publish(cv_image->toImageMsg());
  }

  void drawObjects(cv::Mat & image, const ObjectsStamped & objects)
  {
    const cv::Size image_size{image.cols, image.rows};

    for (const auto & object : objects.objects) {
      auto points = boundingBoxPoints(object, image_size);
      if (!validBox(points)) {
        continue;
      }

      const auto color = colorForId(object.label_id);
      for (size_t i = 0; i < points.size(); ++i) {
        cv::line(image, points[i], points[(i + 1) % points.size()], color, 2, cv::LINE_AA);
      }

      if (draw_skeleton_) {
        drawSkeleton(image, object, color);
      }

      auto text = objectText(object);
      if (draw_tracking_state_) {
        text += " trk:" + std::to_string(object.tracking_state);
      }
      drawLabel(image, text, points.front(), color);
    }
  }

  image_transport::Subscriber image_sub_;
  image_transport::Publisher image_pub_;
  rclcpp::Subscription<ObjectsStamped>::SharedPtr objects_sub_;
  std::mutex objects_mutex_;
  ObjectsStamped::ConstSharedPtr latest_objects_;
  bool draw_skeleton_{true};
  bool draw_tracking_state_{false};
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ZedObjectImageVisualizer>());
  rclcpp::shutdown();
  return 0;
}
