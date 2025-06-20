// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from gaze_interface:msg/GazeDataAsync.idl
// generated code does not contain a copyright notice

#ifndef GAZE_INTERFACE__MSG__DETAIL__GAZE_DATA_ASYNC__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define GAZE_INTERFACE__MSG__DETAIL__GAZE_DATA_ASYNC__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "gaze_interface/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "gaze_interface/msg/detail/gaze_data_async__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace gaze_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gaze_interface
cdr_serialize(
  const gaze_interface::msg::GazeDataAsync & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gaze_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  gaze_interface::msg::GazeDataAsync & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gaze_interface
get_serialized_size(
  const gaze_interface::msg::GazeDataAsync & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gaze_interface
max_serialized_size_GazeDataAsync(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gaze_interface
cdr_serialize_key(
  const gaze_interface::msg::GazeDataAsync & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gaze_interface
get_serialized_size_key(
  const gaze_interface::msg::GazeDataAsync & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gaze_interface
max_serialized_size_key_GazeDataAsync(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace gaze_interface

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gaze_interface
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, gaze_interface, msg, GazeDataAsync)();

#ifdef __cplusplus
}
#endif

#endif  // GAZE_INTERFACE__MSG__DETAIL__GAZE_DATA_ASYNC__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
