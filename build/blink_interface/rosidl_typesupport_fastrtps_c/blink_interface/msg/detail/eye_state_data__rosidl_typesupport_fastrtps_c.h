// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from blink_interface:msg/EyeStateData.idl
// generated code does not contain a copyright notice
#ifndef BLINK_INTERFACE__MSG__DETAIL__EYE_STATE_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define BLINK_INTERFACE__MSG__DETAIL__EYE_STATE_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "blink_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "blink_interface/msg/detail/eye_state_data__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_blink_interface
bool cdr_serialize_blink_interface__msg__EyeStateData(
  const blink_interface__msg__EyeStateData * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_blink_interface
bool cdr_deserialize_blink_interface__msg__EyeStateData(
  eprosima::fastcdr::Cdr &,
  blink_interface__msg__EyeStateData * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_blink_interface
size_t get_serialized_size_blink_interface__msg__EyeStateData(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_blink_interface
size_t max_serialized_size_blink_interface__msg__EyeStateData(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_blink_interface
bool cdr_serialize_key_blink_interface__msg__EyeStateData(
  const blink_interface__msg__EyeStateData * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_blink_interface
size_t get_serialized_size_key_blink_interface__msg__EyeStateData(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_blink_interface
size_t max_serialized_size_key_blink_interface__msg__EyeStateData(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_blink_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, blink_interface, msg, EyeStateData)();

#ifdef __cplusplus
}
#endif

#endif  // BLINK_INTERFACE__MSG__DETAIL__EYE_STATE_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
