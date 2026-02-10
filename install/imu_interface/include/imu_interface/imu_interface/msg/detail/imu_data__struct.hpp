// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from imu_interface:msg/ImuData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "imu_interface/msg/imu_data.hpp"


#ifndef IMU_INTERFACE__MSG__DETAIL__IMU_DATA__STRUCT_HPP_
#define IMU_INTERFACE__MSG__DETAIL__IMU_DATA__STRUCT_HPP_

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
// Member 'acceleration'
// Member 'gyroscope'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"
// Member 'quaternion'
#include "geometry_msgs/msg/detail/quaternion__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__imu_interface__msg__ImuData __attribute__((deprecated))
#else
# define DEPRECATED__imu_interface__msg__ImuData __declspec(deprecated)
#endif

namespace imu_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ImuData_
{
  using Type = ImuData_<ContainerAllocator>;

  explicit ImuData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    acceleration(_init),
    gyroscope(_init),
    quaternion(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->timestamp_unix_ns = 0ull;
      this->timestamp_unix_seconds = 0.0;
    }
  }

  explicit ImuData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    acceleration(_alloc, _init),
    gyroscope(_alloc, _init),
    quaternion(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->timestamp_unix_ns = 0ull;
      this->timestamp_unix_seconds = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _timestamp_unix_ns_type =
    uint64_t;
  _timestamp_unix_ns_type timestamp_unix_ns;
  using _timestamp_unix_seconds_type =
    double;
  _timestamp_unix_seconds_type timestamp_unix_seconds;
  using _acceleration_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _acceleration_type acceleration;
  using _gyroscope_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _gyroscope_type gyroscope;
  using _quaternion_type =
    geometry_msgs::msg::Quaternion_<ContainerAllocator>;
  _quaternion_type quaternion;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__timestamp_unix_ns(
    const uint64_t & _arg)
  {
    this->timestamp_unix_ns = _arg;
    return *this;
  }
  Type & set__timestamp_unix_seconds(
    const double & _arg)
  {
    this->timestamp_unix_seconds = _arg;
    return *this;
  }
  Type & set__acceleration(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->acceleration = _arg;
    return *this;
  }
  Type & set__gyroscope(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->gyroscope = _arg;
    return *this;
  }
  Type & set__quaternion(
    const geometry_msgs::msg::Quaternion_<ContainerAllocator> & _arg)
  {
    this->quaternion = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    imu_interface::msg::ImuData_<ContainerAllocator> *;
  using ConstRawPtr =
    const imu_interface::msg::ImuData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<imu_interface::msg::ImuData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<imu_interface::msg::ImuData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      imu_interface::msg::ImuData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<imu_interface::msg::ImuData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      imu_interface::msg::ImuData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<imu_interface::msg::ImuData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<imu_interface::msg::ImuData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<imu_interface::msg::ImuData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__imu_interface__msg__ImuData
    std::shared_ptr<imu_interface::msg::ImuData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__imu_interface__msg__ImuData
    std::shared_ptr<imu_interface::msg::ImuData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ImuData_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->timestamp_unix_ns != other.timestamp_unix_ns) {
      return false;
    }
    if (this->timestamp_unix_seconds != other.timestamp_unix_seconds) {
      return false;
    }
    if (this->acceleration != other.acceleration) {
      return false;
    }
    if (this->gyroscope != other.gyroscope) {
      return false;
    }
    if (this->quaternion != other.quaternion) {
      return false;
    }
    return true;
  }
  bool operator!=(const ImuData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ImuData_

// alias to use template instance with default allocator
using ImuData =
  imu_interface::msg::ImuData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace imu_interface

#endif  // IMU_INTERFACE__MSG__DETAIL__IMU_DATA__STRUCT_HPP_
