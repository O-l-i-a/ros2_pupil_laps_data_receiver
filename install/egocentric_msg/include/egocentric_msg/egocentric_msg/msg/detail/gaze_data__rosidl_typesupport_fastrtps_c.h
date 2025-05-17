// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from egocentric_msg:msg/GazeData.idl
// generated code does not contain a copyright notice
#ifndef EGOCENTRIC_MSG__MSG__DETAIL__GAZE_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define EGOCENTRIC_MSG__MSG__DETAIL__GAZE_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "egocentric_msg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "egocentric_msg/msg/detail/gaze_data__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_egocentric_msg
bool cdr_serialize_egocentric_msg__msg__GazeData(
  const egocentric_msg__msg__GazeData * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_egocentric_msg
bool cdr_deserialize_egocentric_msg__msg__GazeData(
  eprosima::fastcdr::Cdr &,
  egocentric_msg__msg__GazeData * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_egocentric_msg
size_t get_serialized_size_egocentric_msg__msg__GazeData(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_egocentric_msg
size_t max_serialized_size_egocentric_msg__msg__GazeData(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_egocentric_msg
bool cdr_serialize_key_egocentric_msg__msg__GazeData(
  const egocentric_msg__msg__GazeData * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_egocentric_msg
size_t get_serialized_size_key_egocentric_msg__msg__GazeData(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_egocentric_msg
size_t max_serialized_size_key_egocentric_msg__msg__GazeData(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_egocentric_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, egocentric_msg, msg, GazeData)();

#ifdef __cplusplus
}
#endif

#endif  // EGOCENTRIC_MSG__MSG__DETAIL__GAZE_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
