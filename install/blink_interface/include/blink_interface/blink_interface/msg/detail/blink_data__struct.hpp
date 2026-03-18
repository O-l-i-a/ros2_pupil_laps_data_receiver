// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from blink_interface:msg/BlinkData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "blink_interface/msg/blink_data.hpp"


#ifndef BLINK_INTERFACE__MSG__DETAIL__BLINK_DATA__STRUCT_HPP_
#define BLINK_INTERFACE__MSG__DETAIL__BLINK_DATA__STRUCT_HPP_

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
# define DEPRECATED__blink_interface__msg__BlinkData __attribute__((deprecated))
#else
# define DEPRECATED__blink_interface__msg__BlinkData __declspec(deprecated)
#endif

namespace blink_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BlinkData_
{
  using Type = BlinkData_<ContainerAllocator>;

  explicit BlinkData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->end_time_ns = 0.0f;
      this->start_time_ns = 0.0f;
    }
  }

  explicit BlinkData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->end_time_ns = 0.0f;
      this->start_time_ns = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _end_time_ns_type =
    float;
  _end_time_ns_type end_time_ns;
  using _start_time_ns_type =
    float;
  _start_time_ns_type start_time_ns;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__end_time_ns(
    const float & _arg)
  {
    this->end_time_ns = _arg;
    return *this;
  }
  Type & set__start_time_ns(
    const float & _arg)
  {
    this->start_time_ns = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    blink_interface::msg::BlinkData_<ContainerAllocator> *;
  using ConstRawPtr =
    const blink_interface::msg::BlinkData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<blink_interface::msg::BlinkData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<blink_interface::msg::BlinkData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      blink_interface::msg::BlinkData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<blink_interface::msg::BlinkData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      blink_interface::msg::BlinkData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<blink_interface::msg::BlinkData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<blink_interface::msg::BlinkData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<blink_interface::msg::BlinkData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__blink_interface__msg__BlinkData
    std::shared_ptr<blink_interface::msg::BlinkData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__blink_interface__msg__BlinkData
    std::shared_ptr<blink_interface::msg::BlinkData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BlinkData_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->end_time_ns != other.end_time_ns) {
      return false;
    }
    if (this->start_time_ns != other.start_time_ns) {
      return false;
    }
    return true;
  }
  bool operator!=(const BlinkData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BlinkData_

// alias to use template instance with default allocator
using BlinkData =
  blink_interface::msg::BlinkData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace blink_interface

#endif  // BLINK_INTERFACE__MSG__DETAIL__BLINK_DATA__STRUCT_HPP_
