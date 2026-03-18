// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from blink_interface:msg/EyeStateData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "blink_interface/msg/eye_state_data.hpp"


#ifndef BLINK_INTERFACE__MSG__DETAIL__EYE_STATE_DATA__STRUCT_HPP_
#define BLINK_INTERFACE__MSG__DETAIL__EYE_STATE_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__blink_interface__msg__EyeStateData __attribute__((deprecated))
#else
# define DEPRECATED__blink_interface__msg__EyeStateData __declspec(deprecated)
#endif

namespace blink_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EyeStateData_
{
  using Type = EyeStateData_<ContainerAllocator>;

  explicit EyeStateData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->event_name = "";
      this->event_type = 0l;
      this->start_time_ns = 0.0;
      this->end_time_ns = 0.0;
      this->rtp_ts_unix_seconds = 0.0;
      this->has_end_time = false;
      this->start_gaze_x = 0.0f;
      this->start_gaze_y = 0.0f;
      this->end_gaze_x = 0.0f;
      this->end_gaze_y = 0.0f;
      this->mean_gaze_x = 0.0f;
      this->mean_gaze_y = 0.0f;
      this->amplitude_pixels = 0.0f;
      this->amplitude_angle_deg = 0.0f;
      this->mean_velocity = 0.0f;
      this->max_velocity = 0.0f;
    }
  }

  explicit EyeStateData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    event_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->event_name = "";
      this->event_type = 0l;
      this->start_time_ns = 0.0;
      this->end_time_ns = 0.0;
      this->rtp_ts_unix_seconds = 0.0;
      this->has_end_time = false;
      this->start_gaze_x = 0.0f;
      this->start_gaze_y = 0.0f;
      this->end_gaze_x = 0.0f;
      this->end_gaze_y = 0.0f;
      this->mean_gaze_x = 0.0f;
      this->mean_gaze_y = 0.0f;
      this->amplitude_pixels = 0.0f;
      this->amplitude_angle_deg = 0.0f;
      this->mean_velocity = 0.0f;
      this->max_velocity = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _event_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _event_name_type event_name;
  using _event_type_type =
    int32_t;
  _event_type_type event_type;
  using _start_time_ns_type =
    double;
  _start_time_ns_type start_time_ns;
  using _end_time_ns_type =
    double;
  _end_time_ns_type end_time_ns;
  using _rtp_ts_unix_seconds_type =
    double;
  _rtp_ts_unix_seconds_type rtp_ts_unix_seconds;
  using _has_end_time_type =
    bool;
  _has_end_time_type has_end_time;
  using _start_gaze_x_type =
    float;
  _start_gaze_x_type start_gaze_x;
  using _start_gaze_y_type =
    float;
  _start_gaze_y_type start_gaze_y;
  using _end_gaze_x_type =
    float;
  _end_gaze_x_type end_gaze_x;
  using _end_gaze_y_type =
    float;
  _end_gaze_y_type end_gaze_y;
  using _mean_gaze_x_type =
    float;
  _mean_gaze_x_type mean_gaze_x;
  using _mean_gaze_y_type =
    float;
  _mean_gaze_y_type mean_gaze_y;
  using _amplitude_pixels_type =
    float;
  _amplitude_pixels_type amplitude_pixels;
  using _amplitude_angle_deg_type =
    float;
  _amplitude_angle_deg_type amplitude_angle_deg;
  using _mean_velocity_type =
    float;
  _mean_velocity_type mean_velocity;
  using _max_velocity_type =
    float;
  _max_velocity_type max_velocity;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__event_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->event_name = _arg;
    return *this;
  }
  Type & set__event_type(
    const int32_t & _arg)
  {
    this->event_type = _arg;
    return *this;
  }
  Type & set__start_time_ns(
    const double & _arg)
  {
    this->start_time_ns = _arg;
    return *this;
  }
  Type & set__end_time_ns(
    const double & _arg)
  {
    this->end_time_ns = _arg;
    return *this;
  }
  Type & set__rtp_ts_unix_seconds(
    const double & _arg)
  {
    this->rtp_ts_unix_seconds = _arg;
    return *this;
  }
  Type & set__has_end_time(
    const bool & _arg)
  {
    this->has_end_time = _arg;
    return *this;
  }
  Type & set__start_gaze_x(
    const float & _arg)
  {
    this->start_gaze_x = _arg;
    return *this;
  }
  Type & set__start_gaze_y(
    const float & _arg)
  {
    this->start_gaze_y = _arg;
    return *this;
  }
  Type & set__end_gaze_x(
    const float & _arg)
  {
    this->end_gaze_x = _arg;
    return *this;
  }
  Type & set__end_gaze_y(
    const float & _arg)
  {
    this->end_gaze_y = _arg;
    return *this;
  }
  Type & set__mean_gaze_x(
    const float & _arg)
  {
    this->mean_gaze_x = _arg;
    return *this;
  }
  Type & set__mean_gaze_y(
    const float & _arg)
  {
    this->mean_gaze_y = _arg;
    return *this;
  }
  Type & set__amplitude_pixels(
    const float & _arg)
  {
    this->amplitude_pixels = _arg;
    return *this;
  }
  Type & set__amplitude_angle_deg(
    const float & _arg)
  {
    this->amplitude_angle_deg = _arg;
    return *this;
  }
  Type & set__mean_velocity(
    const float & _arg)
  {
    this->mean_velocity = _arg;
    return *this;
  }
  Type & set__max_velocity(
    const float & _arg)
  {
    this->max_velocity = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    blink_interface::msg::EyeStateData_<ContainerAllocator> *;
  using ConstRawPtr =
    const blink_interface::msg::EyeStateData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<blink_interface::msg::EyeStateData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<blink_interface::msg::EyeStateData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      blink_interface::msg::EyeStateData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<blink_interface::msg::EyeStateData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      blink_interface::msg::EyeStateData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<blink_interface::msg::EyeStateData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<blink_interface::msg::EyeStateData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<blink_interface::msg::EyeStateData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__blink_interface__msg__EyeStateData
    std::shared_ptr<blink_interface::msg::EyeStateData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__blink_interface__msg__EyeStateData
    std::shared_ptr<blink_interface::msg::EyeStateData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EyeStateData_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->event_name != other.event_name) {
      return false;
    }
    if (this->event_type != other.event_type) {
      return false;
    }
    if (this->start_time_ns != other.start_time_ns) {
      return false;
    }
    if (this->end_time_ns != other.end_time_ns) {
      return false;
    }
    if (this->rtp_ts_unix_seconds != other.rtp_ts_unix_seconds) {
      return false;
    }
    if (this->has_end_time != other.has_end_time) {
      return false;
    }
    if (this->start_gaze_x != other.start_gaze_x) {
      return false;
    }
    if (this->start_gaze_y != other.start_gaze_y) {
      return false;
    }
    if (this->end_gaze_x != other.end_gaze_x) {
      return false;
    }
    if (this->end_gaze_y != other.end_gaze_y) {
      return false;
    }
    if (this->mean_gaze_x != other.mean_gaze_x) {
      return false;
    }
    if (this->mean_gaze_y != other.mean_gaze_y) {
      return false;
    }
    if (this->amplitude_pixels != other.amplitude_pixels) {
      return false;
    }
    if (this->amplitude_angle_deg != other.amplitude_angle_deg) {
      return false;
    }
    if (this->mean_velocity != other.mean_velocity) {
      return false;
    }
    if (this->max_velocity != other.max_velocity) {
      return false;
    }
    return true;
  }
  bool operator!=(const EyeStateData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EyeStateData_

// alias to use template instance with default allocator
using EyeStateData =
  blink_interface::msg::EyeStateData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace blink_interface

#endif  // BLINK_INTERFACE__MSG__DETAIL__EYE_STATE_DATA__STRUCT_HPP_
