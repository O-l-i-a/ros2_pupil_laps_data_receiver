// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from imu_interface:msg/ImuData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "imu_interface/msg/imu_data.hpp"


#ifndef IMU_INTERFACE__MSG__DETAIL__IMU_DATA__TRAITS_HPP_
#define IMU_INTERFACE__MSG__DETAIL__IMU_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "imu_interface/msg/detail/imu_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'acceleration'
// Member 'gyroscope'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"
// Member 'quaternion'
#include "geometry_msgs/msg/detail/quaternion__traits.hpp"

namespace imu_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const ImuData & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: timestamp_unix_ns
  {
    out << "timestamp_unix_ns: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp_unix_ns, out);
    out << ", ";
  }

  // member: timestamp_unix_seconds
  {
    out << "timestamp_unix_seconds: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp_unix_seconds, out);
    out << ", ";
  }

  // member: acceleration
  {
    out << "acceleration: ";
    to_flow_style_yaml(msg.acceleration, out);
    out << ", ";
  }

  // member: gyroscope
  {
    out << "gyroscope: ";
    to_flow_style_yaml(msg.gyroscope, out);
    out << ", ";
  }

  // member: quaternion
  {
    out << "quaternion: ";
    to_flow_style_yaml(msg.quaternion, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ImuData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: timestamp_unix_ns
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp_unix_ns: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp_unix_ns, out);
    out << "\n";
  }

  // member: timestamp_unix_seconds
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp_unix_seconds: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp_unix_seconds, out);
    out << "\n";
  }

  // member: acceleration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acceleration:\n";
    to_block_style_yaml(msg.acceleration, out, indentation + 2);
  }

  // member: gyroscope
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gyroscope:\n";
    to_block_style_yaml(msg.gyroscope, out, indentation + 2);
  }

  // member: quaternion
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "quaternion:\n";
    to_block_style_yaml(msg.quaternion, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ImuData & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace imu_interface

namespace rosidl_generator_traits
{

[[deprecated("use imu_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const imu_interface::msg::ImuData & msg,
  std::ostream & out, size_t indentation = 0)
{
  imu_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use imu_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const imu_interface::msg::ImuData & msg)
{
  return imu_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<imu_interface::msg::ImuData>()
{
  return "imu_interface::msg::ImuData";
}

template<>
inline const char * name<imu_interface::msg::ImuData>()
{
  return "imu_interface/msg/ImuData";
}

template<>
struct has_fixed_size<imu_interface::msg::ImuData>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Quaternion>::value && has_fixed_size<geometry_msgs::msg::Vector3>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<imu_interface::msg::ImuData>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Quaternion>::value && has_bounded_size<geometry_msgs::msg::Vector3>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<imu_interface::msg::ImuData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // IMU_INTERFACE__MSG__DETAIL__IMU_DATA__TRAITS_HPP_
