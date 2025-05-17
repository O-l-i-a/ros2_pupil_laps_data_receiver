// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from egocentric_msg:msg/GazeData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "egocentric_msg/msg/gaze_data.hpp"


#ifndef EGOCENTRIC_MSG__MSG__DETAIL__GAZE_DATA__STRUCT_HPP_
#define EGOCENTRIC_MSG__MSG__DETAIL__GAZE_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__egocentric_msg__msg__GazeData __attribute__((deprecated))
#else
# define DEPRECATED__egocentric_msg__msg__GazeData __declspec(deprecated)
#endif

namespace egocentric_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GazeData_
{
  using Type = GazeData_<ContainerAllocator>;

  explicit GazeData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->worn = false;
      this->pupil_diameter_left = 0.0f;
      this->eyeball_center_left_x = 0.0f;
      this->eyeball_center_left_y = 0.0f;
      this->eyeball_center_left_z = 0.0f;
      this->optical_axis_left_x = 0.0f;
      this->optical_axis_left_y = 0.0f;
      this->optical_axis_left_z = 0.0f;
      this->pupil_diameter_right = 0.0f;
      this->eyeball_center_right_x = 0.0f;
      this->eyeball_center_right_y = 0.0f;
      this->eyeball_center_right_z = 0.0f;
      this->optical_axis_right_x = 0.0f;
      this->optical_axis_right_y = 0.0f;
      this->optical_axis_right_z = 0.0f;
      this->timestamp_unix_seconds = 0.0f;
    }
  }

  explicit GazeData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->worn = false;
      this->pupil_diameter_left = 0.0f;
      this->eyeball_center_left_x = 0.0f;
      this->eyeball_center_left_y = 0.0f;
      this->eyeball_center_left_z = 0.0f;
      this->optical_axis_left_x = 0.0f;
      this->optical_axis_left_y = 0.0f;
      this->optical_axis_left_z = 0.0f;
      this->pupil_diameter_right = 0.0f;
      this->eyeball_center_right_x = 0.0f;
      this->eyeball_center_right_y = 0.0f;
      this->eyeball_center_right_z = 0.0f;
      this->optical_axis_right_x = 0.0f;
      this->optical_axis_right_y = 0.0f;
      this->optical_axis_right_z = 0.0f;
      this->timestamp_unix_seconds = 0.0f;
    }
  }

  // field types and members
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _worn_type =
    bool;
  _worn_type worn;
  using _pupil_diameter_left_type =
    float;
  _pupil_diameter_left_type pupil_diameter_left;
  using _eyeball_center_left_x_type =
    float;
  _eyeball_center_left_x_type eyeball_center_left_x;
  using _eyeball_center_left_y_type =
    float;
  _eyeball_center_left_y_type eyeball_center_left_y;
  using _eyeball_center_left_z_type =
    float;
  _eyeball_center_left_z_type eyeball_center_left_z;
  using _optical_axis_left_x_type =
    float;
  _optical_axis_left_x_type optical_axis_left_x;
  using _optical_axis_left_y_type =
    float;
  _optical_axis_left_y_type optical_axis_left_y;
  using _optical_axis_left_z_type =
    float;
  _optical_axis_left_z_type optical_axis_left_z;
  using _pupil_diameter_right_type =
    float;
  _pupil_diameter_right_type pupil_diameter_right;
  using _eyeball_center_right_x_type =
    float;
  _eyeball_center_right_x_type eyeball_center_right_x;
  using _eyeball_center_right_y_type =
    float;
  _eyeball_center_right_y_type eyeball_center_right_y;
  using _eyeball_center_right_z_type =
    float;
  _eyeball_center_right_z_type eyeball_center_right_z;
  using _optical_axis_right_x_type =
    float;
  _optical_axis_right_x_type optical_axis_right_x;
  using _optical_axis_right_y_type =
    float;
  _optical_axis_right_y_type optical_axis_right_y;
  using _optical_axis_right_z_type =
    float;
  _optical_axis_right_z_type optical_axis_right_z;
  using _timestamp_unix_seconds_type =
    float;
  _timestamp_unix_seconds_type timestamp_unix_seconds;

  // setters for named parameter idiom
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__worn(
    const bool & _arg)
  {
    this->worn = _arg;
    return *this;
  }
  Type & set__pupil_diameter_left(
    const float & _arg)
  {
    this->pupil_diameter_left = _arg;
    return *this;
  }
  Type & set__eyeball_center_left_x(
    const float & _arg)
  {
    this->eyeball_center_left_x = _arg;
    return *this;
  }
  Type & set__eyeball_center_left_y(
    const float & _arg)
  {
    this->eyeball_center_left_y = _arg;
    return *this;
  }
  Type & set__eyeball_center_left_z(
    const float & _arg)
  {
    this->eyeball_center_left_z = _arg;
    return *this;
  }
  Type & set__optical_axis_left_x(
    const float & _arg)
  {
    this->optical_axis_left_x = _arg;
    return *this;
  }
  Type & set__optical_axis_left_y(
    const float & _arg)
  {
    this->optical_axis_left_y = _arg;
    return *this;
  }
  Type & set__optical_axis_left_z(
    const float & _arg)
  {
    this->optical_axis_left_z = _arg;
    return *this;
  }
  Type & set__pupil_diameter_right(
    const float & _arg)
  {
    this->pupil_diameter_right = _arg;
    return *this;
  }
  Type & set__eyeball_center_right_x(
    const float & _arg)
  {
    this->eyeball_center_right_x = _arg;
    return *this;
  }
  Type & set__eyeball_center_right_y(
    const float & _arg)
  {
    this->eyeball_center_right_y = _arg;
    return *this;
  }
  Type & set__eyeball_center_right_z(
    const float & _arg)
  {
    this->eyeball_center_right_z = _arg;
    return *this;
  }
  Type & set__optical_axis_right_x(
    const float & _arg)
  {
    this->optical_axis_right_x = _arg;
    return *this;
  }
  Type & set__optical_axis_right_y(
    const float & _arg)
  {
    this->optical_axis_right_y = _arg;
    return *this;
  }
  Type & set__optical_axis_right_z(
    const float & _arg)
  {
    this->optical_axis_right_z = _arg;
    return *this;
  }
  Type & set__timestamp_unix_seconds(
    const float & _arg)
  {
    this->timestamp_unix_seconds = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    egocentric_msg::msg::GazeData_<ContainerAllocator> *;
  using ConstRawPtr =
    const egocentric_msg::msg::GazeData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<egocentric_msg::msg::GazeData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<egocentric_msg::msg::GazeData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      egocentric_msg::msg::GazeData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<egocentric_msg::msg::GazeData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      egocentric_msg::msg::GazeData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<egocentric_msg::msg::GazeData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<egocentric_msg::msg::GazeData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<egocentric_msg::msg::GazeData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__egocentric_msg__msg__GazeData
    std::shared_ptr<egocentric_msg::msg::GazeData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__egocentric_msg__msg__GazeData
    std::shared_ptr<egocentric_msg::msg::GazeData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GazeData_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->worn != other.worn) {
      return false;
    }
    if (this->pupil_diameter_left != other.pupil_diameter_left) {
      return false;
    }
    if (this->eyeball_center_left_x != other.eyeball_center_left_x) {
      return false;
    }
    if (this->eyeball_center_left_y != other.eyeball_center_left_y) {
      return false;
    }
    if (this->eyeball_center_left_z != other.eyeball_center_left_z) {
      return false;
    }
    if (this->optical_axis_left_x != other.optical_axis_left_x) {
      return false;
    }
    if (this->optical_axis_left_y != other.optical_axis_left_y) {
      return false;
    }
    if (this->optical_axis_left_z != other.optical_axis_left_z) {
      return false;
    }
    if (this->pupil_diameter_right != other.pupil_diameter_right) {
      return false;
    }
    if (this->eyeball_center_right_x != other.eyeball_center_right_x) {
      return false;
    }
    if (this->eyeball_center_right_y != other.eyeball_center_right_y) {
      return false;
    }
    if (this->eyeball_center_right_z != other.eyeball_center_right_z) {
      return false;
    }
    if (this->optical_axis_right_x != other.optical_axis_right_x) {
      return false;
    }
    if (this->optical_axis_right_y != other.optical_axis_right_y) {
      return false;
    }
    if (this->optical_axis_right_z != other.optical_axis_right_z) {
      return false;
    }
    if (this->timestamp_unix_seconds != other.timestamp_unix_seconds) {
      return false;
    }
    return true;
  }
  bool operator!=(const GazeData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GazeData_

// alias to use template instance with default allocator
using GazeData =
  egocentric_msg::msg::GazeData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace egocentric_msg

#endif  // EGOCENTRIC_MSG__MSG__DETAIL__GAZE_DATA__STRUCT_HPP_
