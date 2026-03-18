// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from blink_interface:msg/BlinkData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "blink_interface/msg/blink_data.hpp"


#ifndef BLINK_INTERFACE__MSG__DETAIL__BLINK_DATA__TRAITS_HPP_
#define BLINK_INTERFACE__MSG__DETAIL__BLINK_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "blink_interface/msg/detail/blink_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace blink_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const BlinkData & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: end_time_ns
  {
    out << "end_time_ns: ";
    rosidl_generator_traits::value_to_yaml(msg.end_time_ns, out);
    out << ", ";
  }

  // member: start_time_ns
  {
    out << "start_time_ns: ";
    rosidl_generator_traits::value_to_yaml(msg.start_time_ns, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BlinkData & msg,
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

  // member: end_time_ns
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "end_time_ns: ";
    rosidl_generator_traits::value_to_yaml(msg.end_time_ns, out);
    out << "\n";
  }

  // member: start_time_ns
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_time_ns: ";
    rosidl_generator_traits::value_to_yaml(msg.start_time_ns, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BlinkData & msg, bool use_flow_style = false)
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

}  // namespace blink_interface

namespace rosidl_generator_traits
{

[[deprecated("use blink_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const blink_interface::msg::BlinkData & msg,
  std::ostream & out, size_t indentation = 0)
{
  blink_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use blink_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const blink_interface::msg::BlinkData & msg)
{
  return blink_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<blink_interface::msg::BlinkData>()
{
  return "blink_interface::msg::BlinkData";
}

template<>
inline const char * name<blink_interface::msg::BlinkData>()
{
  return "blink_interface/msg/BlinkData";
}

template<>
struct has_fixed_size<blink_interface::msg::BlinkData>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<blink_interface::msg::BlinkData>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<blink_interface::msg::BlinkData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BLINK_INTERFACE__MSG__DETAIL__BLINK_DATA__TRAITS_HPP_
