// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gaze_interface:msg/GazeDataAsync.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gaze_interface/msg/gaze_data_async.hpp"


#ifndef GAZE_INTERFACE__MSG__DETAIL__GAZE_DATA_ASYNC__TRAITS_HPP_
#define GAZE_INTERFACE__MSG__DETAIL__GAZE_DATA_ASYNC__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "gaze_interface/msg/detail/gaze_data_async__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace gaze_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const GazeDataAsync & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: norm_pos_x
  {
    out << "norm_pos_x: ";
    rosidl_generator_traits::value_to_yaml(msg.norm_pos_x, out);
    out << ", ";
  }

  // member: norm_pos_y
  {
    out << "norm_pos_y: ";
    rosidl_generator_traits::value_to_yaml(msg.norm_pos_y, out);
    out << ", ";
  }

  // member: timestamp_unix_seconds
  {
    out << "timestamp_unix_seconds: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp_unix_seconds, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GazeDataAsync & msg,
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

  // member: norm_pos_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "norm_pos_x: ";
    rosidl_generator_traits::value_to_yaml(msg.norm_pos_x, out);
    out << "\n";
  }

  // member: norm_pos_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "norm_pos_y: ";
    rosidl_generator_traits::value_to_yaml(msg.norm_pos_y, out);
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GazeDataAsync & msg, bool use_flow_style = false)
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

}  // namespace gaze_interface

namespace rosidl_generator_traits
{

[[deprecated("use gaze_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const gaze_interface::msg::GazeDataAsync & msg,
  std::ostream & out, size_t indentation = 0)
{
  gaze_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gaze_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const gaze_interface::msg::GazeDataAsync & msg)
{
  return gaze_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<gaze_interface::msg::GazeDataAsync>()
{
  return "gaze_interface::msg::GazeDataAsync";
}

template<>
inline const char * name<gaze_interface::msg::GazeDataAsync>()
{
  return "gaze_interface/msg/GazeDataAsync";
}

template<>
struct has_fixed_size<gaze_interface::msg::GazeDataAsync>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<gaze_interface::msg::GazeDataAsync>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<gaze_interface::msg::GazeDataAsync>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GAZE_INTERFACE__MSG__DETAIL__GAZE_DATA_ASYNC__TRAITS_HPP_
