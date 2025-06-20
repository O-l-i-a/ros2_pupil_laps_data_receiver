// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from gaze_interface:msg/GazeDataAsync.idl
// generated code does not contain a copyright notice
#ifndef GAZE_INTERFACE__MSG__DETAIL__GAZE_DATA_ASYNC__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define GAZE_INTERFACE__MSG__DETAIL__GAZE_DATA_ASYNC__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "gaze_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "gaze_interface/msg/detail/gaze_data_async__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gaze_interface
bool cdr_serialize_gaze_interface__msg__GazeDataAsync(
  const gaze_interface__msg__GazeDataAsync * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gaze_interface
bool cdr_deserialize_gaze_interface__msg__GazeDataAsync(
  eprosima::fastcdr::Cdr &,
  gaze_interface__msg__GazeDataAsync * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gaze_interface
size_t get_serialized_size_gaze_interface__msg__GazeDataAsync(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gaze_interface
size_t max_serialized_size_gaze_interface__msg__GazeDataAsync(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gaze_interface
bool cdr_serialize_key_gaze_interface__msg__GazeDataAsync(
  const gaze_interface__msg__GazeDataAsync * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gaze_interface
size_t get_serialized_size_key_gaze_interface__msg__GazeDataAsync(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gaze_interface
size_t max_serialized_size_key_gaze_interface__msg__GazeDataAsync(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gaze_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gaze_interface, msg, GazeDataAsync)();

#ifdef __cplusplus
}
#endif

#endif  // GAZE_INTERFACE__MSG__DETAIL__GAZE_DATA_ASYNC__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
