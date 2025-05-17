// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from egocentric_msg:msg/GazeData.idl
// generated code does not contain a copyright notice

#ifndef EGOCENTRIC_MSG__MSG__DETAIL__GAZE_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define EGOCENTRIC_MSG__MSG__DETAIL__GAZE_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "egocentric_msg/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "egocentric_msg/msg/detail/gaze_data__struct.hpp"

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

namespace egocentric_msg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_egocentric_msg
cdr_serialize(
  const egocentric_msg::msg::GazeData & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_egocentric_msg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  egocentric_msg::msg::GazeData & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_egocentric_msg
get_serialized_size(
  const egocentric_msg::msg::GazeData & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_egocentric_msg
max_serialized_size_GazeData(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_egocentric_msg
cdr_serialize_key(
  const egocentric_msg::msg::GazeData & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_egocentric_msg
get_serialized_size_key(
  const egocentric_msg::msg::GazeData & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_egocentric_msg
max_serialized_size_key_GazeData(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace egocentric_msg

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_egocentric_msg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, egocentric_msg, msg, GazeData)();

#ifdef __cplusplus
}
#endif

#endif  // EGOCENTRIC_MSG__MSG__DETAIL__GAZE_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
