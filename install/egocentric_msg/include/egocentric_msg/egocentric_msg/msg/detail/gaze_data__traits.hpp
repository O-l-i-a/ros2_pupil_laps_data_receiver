// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from egocentric_msg:msg/GazeData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "egocentric_msg/msg/gaze_data.hpp"


#ifndef EGOCENTRIC_MSG__MSG__DETAIL__GAZE_DATA__TRAITS_HPP_
#define EGOCENTRIC_MSG__MSG__DETAIL__GAZE_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "egocentric_msg/msg/detail/gaze_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace egocentric_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const GazeData & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: worn
  {
    out << "worn: ";
    rosidl_generator_traits::value_to_yaml(msg.worn, out);
    out << ", ";
  }

  // member: pupil_diameter_left
  {
    out << "pupil_diameter_left: ";
    rosidl_generator_traits::value_to_yaml(msg.pupil_diameter_left, out);
    out << ", ";
  }

  // member: eyeball_center_left_x
  {
    out << "eyeball_center_left_x: ";
    rosidl_generator_traits::value_to_yaml(msg.eyeball_center_left_x, out);
    out << ", ";
  }

  // member: eyeball_center_left_y
  {
    out << "eyeball_center_left_y: ";
    rosidl_generator_traits::value_to_yaml(msg.eyeball_center_left_y, out);
    out << ", ";
  }

  // member: eyeball_center_left_z
  {
    out << "eyeball_center_left_z: ";
    rosidl_generator_traits::value_to_yaml(msg.eyeball_center_left_z, out);
    out << ", ";
  }

  // member: optical_axis_left_x
  {
    out << "optical_axis_left_x: ";
    rosidl_generator_traits::value_to_yaml(msg.optical_axis_left_x, out);
    out << ", ";
  }

  // member: optical_axis_left_y
  {
    out << "optical_axis_left_y: ";
    rosidl_generator_traits::value_to_yaml(msg.optical_axis_left_y, out);
    out << ", ";
  }

  // member: optical_axis_left_z
  {
    out << "optical_axis_left_z: ";
    rosidl_generator_traits::value_to_yaml(msg.optical_axis_left_z, out);
    out << ", ";
  }

  // member: pupil_diameter_right
  {
    out << "pupil_diameter_right: ";
    rosidl_generator_traits::value_to_yaml(msg.pupil_diameter_right, out);
    out << ", ";
  }

  // member: eyeball_center_right_x
  {
    out << "eyeball_center_right_x: ";
    rosidl_generator_traits::value_to_yaml(msg.eyeball_center_right_x, out);
    out << ", ";
  }

  // member: eyeball_center_right_y
  {
    out << "eyeball_center_right_y: ";
    rosidl_generator_traits::value_to_yaml(msg.eyeball_center_right_y, out);
    out << ", ";
  }

  // member: eyeball_center_right_z
  {
    out << "eyeball_center_right_z: ";
    rosidl_generator_traits::value_to_yaml(msg.eyeball_center_right_z, out);
    out << ", ";
  }

  // member: optical_axis_right_x
  {
    out << "optical_axis_right_x: ";
    rosidl_generator_traits::value_to_yaml(msg.optical_axis_right_x, out);
    out << ", ";
  }

  // member: optical_axis_right_y
  {
    out << "optical_axis_right_y: ";
    rosidl_generator_traits::value_to_yaml(msg.optical_axis_right_y, out);
    out << ", ";
  }

  // member: optical_axis_right_z
  {
    out << "optical_axis_right_z: ";
    rosidl_generator_traits::value_to_yaml(msg.optical_axis_right_z, out);
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
  const GazeData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: worn
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "worn: ";
    rosidl_generator_traits::value_to_yaml(msg.worn, out);
    out << "\n";
  }

  // member: pupil_diameter_left
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pupil_diameter_left: ";
    rosidl_generator_traits::value_to_yaml(msg.pupil_diameter_left, out);
    out << "\n";
  }

  // member: eyeball_center_left_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "eyeball_center_left_x: ";
    rosidl_generator_traits::value_to_yaml(msg.eyeball_center_left_x, out);
    out << "\n";
  }

  // member: eyeball_center_left_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "eyeball_center_left_y: ";
    rosidl_generator_traits::value_to_yaml(msg.eyeball_center_left_y, out);
    out << "\n";
  }

  // member: eyeball_center_left_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "eyeball_center_left_z: ";
    rosidl_generator_traits::value_to_yaml(msg.eyeball_center_left_z, out);
    out << "\n";
  }

  // member: optical_axis_left_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "optical_axis_left_x: ";
    rosidl_generator_traits::value_to_yaml(msg.optical_axis_left_x, out);
    out << "\n";
  }

  // member: optical_axis_left_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "optical_axis_left_y: ";
    rosidl_generator_traits::value_to_yaml(msg.optical_axis_left_y, out);
    out << "\n";
  }

  // member: optical_axis_left_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "optical_axis_left_z: ";
    rosidl_generator_traits::value_to_yaml(msg.optical_axis_left_z, out);
    out << "\n";
  }

  // member: pupil_diameter_right
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pupil_diameter_right: ";
    rosidl_generator_traits::value_to_yaml(msg.pupil_diameter_right, out);
    out << "\n";
  }

  // member: eyeball_center_right_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "eyeball_center_right_x: ";
    rosidl_generator_traits::value_to_yaml(msg.eyeball_center_right_x, out);
    out << "\n";
  }

  // member: eyeball_center_right_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "eyeball_center_right_y: ";
    rosidl_generator_traits::value_to_yaml(msg.eyeball_center_right_y, out);
    out << "\n";
  }

  // member: eyeball_center_right_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "eyeball_center_right_z: ";
    rosidl_generator_traits::value_to_yaml(msg.eyeball_center_right_z, out);
    out << "\n";
  }

  // member: optical_axis_right_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "optical_axis_right_x: ";
    rosidl_generator_traits::value_to_yaml(msg.optical_axis_right_x, out);
    out << "\n";
  }

  // member: optical_axis_right_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "optical_axis_right_y: ";
    rosidl_generator_traits::value_to_yaml(msg.optical_axis_right_y, out);
    out << "\n";
  }

  // member: optical_axis_right_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "optical_axis_right_z: ";
    rosidl_generator_traits::value_to_yaml(msg.optical_axis_right_z, out);
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

inline std::string to_yaml(const GazeData & msg, bool use_flow_style = false)
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

}  // namespace egocentric_msg

namespace rosidl_generator_traits
{

[[deprecated("use egocentric_msg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const egocentric_msg::msg::GazeData & msg,
  std::ostream & out, size_t indentation = 0)
{
  egocentric_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use egocentric_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const egocentric_msg::msg::GazeData & msg)
{
  return egocentric_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<egocentric_msg::msg::GazeData>()
{
  return "egocentric_msg::msg::GazeData";
}

template<>
inline const char * name<egocentric_msg::msg::GazeData>()
{
  return "egocentric_msg/msg/GazeData";
}

template<>
struct has_fixed_size<egocentric_msg::msg::GazeData>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<egocentric_msg::msg::GazeData>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<egocentric_msg::msg::GazeData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // EGOCENTRIC_MSG__MSG__DETAIL__GAZE_DATA__TRAITS_HPP_
