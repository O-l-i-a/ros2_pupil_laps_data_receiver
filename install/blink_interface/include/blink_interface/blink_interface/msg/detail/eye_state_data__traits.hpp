// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from blink_interface:msg/EyeStateData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "blink_interface/msg/eye_state_data.hpp"


#ifndef BLINK_INTERFACE__MSG__DETAIL__EYE_STATE_DATA__TRAITS_HPP_
#define BLINK_INTERFACE__MSG__DETAIL__EYE_STATE_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "blink_interface/msg/detail/eye_state_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace blink_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const EyeStateData & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: event_name
  {
    out << "event_name: ";
    rosidl_generator_traits::value_to_yaml(msg.event_name, out);
    out << ", ";
  }

  // member: event_type
  {
    out << "event_type: ";
    rosidl_generator_traits::value_to_yaml(msg.event_type, out);
    out << ", ";
  }

  // member: start_time_ns
  {
    out << "start_time_ns: ";
    rosidl_generator_traits::value_to_yaml(msg.start_time_ns, out);
    out << ", ";
  }

  // member: end_time_ns
  {
    out << "end_time_ns: ";
    rosidl_generator_traits::value_to_yaml(msg.end_time_ns, out);
    out << ", ";
  }

  // member: rtp_ts_unix_seconds
  {
    out << "rtp_ts_unix_seconds: ";
    rosidl_generator_traits::value_to_yaml(msg.rtp_ts_unix_seconds, out);
    out << ", ";
  }

  // member: has_end_time
  {
    out << "has_end_time: ";
    rosidl_generator_traits::value_to_yaml(msg.has_end_time, out);
    out << ", ";
  }

  // member: start_gaze_x
  {
    out << "start_gaze_x: ";
    rosidl_generator_traits::value_to_yaml(msg.start_gaze_x, out);
    out << ", ";
  }

  // member: start_gaze_y
  {
    out << "start_gaze_y: ";
    rosidl_generator_traits::value_to_yaml(msg.start_gaze_y, out);
    out << ", ";
  }

  // member: end_gaze_x
  {
    out << "end_gaze_x: ";
    rosidl_generator_traits::value_to_yaml(msg.end_gaze_x, out);
    out << ", ";
  }

  // member: end_gaze_y
  {
    out << "end_gaze_y: ";
    rosidl_generator_traits::value_to_yaml(msg.end_gaze_y, out);
    out << ", ";
  }

  // member: mean_gaze_x
  {
    out << "mean_gaze_x: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_gaze_x, out);
    out << ", ";
  }

  // member: mean_gaze_y
  {
    out << "mean_gaze_y: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_gaze_y, out);
    out << ", ";
  }

  // member: amplitude_pixels
  {
    out << "amplitude_pixels: ";
    rosidl_generator_traits::value_to_yaml(msg.amplitude_pixels, out);
    out << ", ";
  }

  // member: amplitude_angle_deg
  {
    out << "amplitude_angle_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.amplitude_angle_deg, out);
    out << ", ";
  }

  // member: mean_velocity
  {
    out << "mean_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_velocity, out);
    out << ", ";
  }

  // member: max_velocity
  {
    out << "max_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.max_velocity, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EyeStateData & msg,
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

  // member: event_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "event_name: ";
    rosidl_generator_traits::value_to_yaml(msg.event_name, out);
    out << "\n";
  }

  // member: event_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "event_type: ";
    rosidl_generator_traits::value_to_yaml(msg.event_type, out);
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

  // member: end_time_ns
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "end_time_ns: ";
    rosidl_generator_traits::value_to_yaml(msg.end_time_ns, out);
    out << "\n";
  }

  // member: rtp_ts_unix_seconds
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rtp_ts_unix_seconds: ";
    rosidl_generator_traits::value_to_yaml(msg.rtp_ts_unix_seconds, out);
    out << "\n";
  }

  // member: has_end_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "has_end_time: ";
    rosidl_generator_traits::value_to_yaml(msg.has_end_time, out);
    out << "\n";
  }

  // member: start_gaze_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_gaze_x: ";
    rosidl_generator_traits::value_to_yaml(msg.start_gaze_x, out);
    out << "\n";
  }

  // member: start_gaze_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_gaze_y: ";
    rosidl_generator_traits::value_to_yaml(msg.start_gaze_y, out);
    out << "\n";
  }

  // member: end_gaze_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "end_gaze_x: ";
    rosidl_generator_traits::value_to_yaml(msg.end_gaze_x, out);
    out << "\n";
  }

  // member: end_gaze_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "end_gaze_y: ";
    rosidl_generator_traits::value_to_yaml(msg.end_gaze_y, out);
    out << "\n";
  }

  // member: mean_gaze_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mean_gaze_x: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_gaze_x, out);
    out << "\n";
  }

  // member: mean_gaze_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mean_gaze_y: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_gaze_y, out);
    out << "\n";
  }

  // member: amplitude_pixels
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "amplitude_pixels: ";
    rosidl_generator_traits::value_to_yaml(msg.amplitude_pixels, out);
    out << "\n";
  }

  // member: amplitude_angle_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "amplitude_angle_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.amplitude_angle_deg, out);
    out << "\n";
  }

  // member: mean_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mean_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_velocity, out);
    out << "\n";
  }

  // member: max_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.max_velocity, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EyeStateData & msg, bool use_flow_style = false)
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
  const blink_interface::msg::EyeStateData & msg,
  std::ostream & out, size_t indentation = 0)
{
  blink_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use blink_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const blink_interface::msg::EyeStateData & msg)
{
  return blink_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<blink_interface::msg::EyeStateData>()
{
  return "blink_interface::msg::EyeStateData";
}

template<>
inline const char * name<blink_interface::msg::EyeStateData>()
{
  return "blink_interface/msg/EyeStateData";
}

template<>
struct has_fixed_size<blink_interface::msg::EyeStateData>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<blink_interface::msg::EyeStateData>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<blink_interface::msg::EyeStateData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BLINK_INTERFACE__MSG__DETAIL__EYE_STATE_DATA__TRAITS_HPP_
