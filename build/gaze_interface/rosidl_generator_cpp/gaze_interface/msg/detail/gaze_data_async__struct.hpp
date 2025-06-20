// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gaze_interface:msg/GazeDataAsync.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gaze_interface/msg/gaze_data_async.hpp"


#ifndef GAZE_INTERFACE__MSG__DETAIL__GAZE_DATA_ASYNC__STRUCT_HPP_
#define GAZE_INTERFACE__MSG__DETAIL__GAZE_DATA_ASYNC__STRUCT_HPP_

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
# define DEPRECATED__gaze_interface__msg__GazeDataAsync __attribute__((deprecated))
#else
# define DEPRECATED__gaze_interface__msg__GazeDataAsync __declspec(deprecated)
#endif

namespace gaze_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GazeDataAsync_
{
  using Type = GazeDataAsync_<ContainerAllocator>;

  explicit GazeDataAsync_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->norm_pos_x = 0.0f;
      this->norm_pos_y = 0.0f;
      this->timestamp_unix_seconds = 0.0f;
    }
  }

  explicit GazeDataAsync_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->norm_pos_x = 0.0f;
      this->norm_pos_y = 0.0f;
      this->timestamp_unix_seconds = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _norm_pos_x_type =
    float;
  _norm_pos_x_type norm_pos_x;
  using _norm_pos_y_type =
    float;
  _norm_pos_y_type norm_pos_y;
  using _timestamp_unix_seconds_type =
    float;
  _timestamp_unix_seconds_type timestamp_unix_seconds;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__norm_pos_x(
    const float & _arg)
  {
    this->norm_pos_x = _arg;
    return *this;
  }
  Type & set__norm_pos_y(
    const float & _arg)
  {
    this->norm_pos_y = _arg;
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
    gaze_interface::msg::GazeDataAsync_<ContainerAllocator> *;
  using ConstRawPtr =
    const gaze_interface::msg::GazeDataAsync_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gaze_interface::msg::GazeDataAsync_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gaze_interface::msg::GazeDataAsync_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gaze_interface::msg::GazeDataAsync_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gaze_interface::msg::GazeDataAsync_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gaze_interface::msg::GazeDataAsync_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gaze_interface::msg::GazeDataAsync_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gaze_interface::msg::GazeDataAsync_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gaze_interface::msg::GazeDataAsync_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gaze_interface__msg__GazeDataAsync
    std::shared_ptr<gaze_interface::msg::GazeDataAsync_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gaze_interface__msg__GazeDataAsync
    std::shared_ptr<gaze_interface::msg::GazeDataAsync_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GazeDataAsync_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->norm_pos_x != other.norm_pos_x) {
      return false;
    }
    if (this->norm_pos_y != other.norm_pos_y) {
      return false;
    }
    if (this->timestamp_unix_seconds != other.timestamp_unix_seconds) {
      return false;
    }
    return true;
  }
  bool operator!=(const GazeDataAsync_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GazeDataAsync_

// alias to use template instance with default allocator
using GazeDataAsync =
  gaze_interface::msg::GazeDataAsync_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace gaze_interface

#endif  // GAZE_INTERFACE__MSG__DETAIL__GAZE_DATA_ASYNC__STRUCT_HPP_
