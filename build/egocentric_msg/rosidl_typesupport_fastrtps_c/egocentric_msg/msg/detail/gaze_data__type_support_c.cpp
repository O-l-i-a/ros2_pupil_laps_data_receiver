// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from egocentric_msg:msg/GazeData.idl
// generated code does not contain a copyright notice
#include "egocentric_msg/msg/detail/gaze_data__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "egocentric_msg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "egocentric_msg/msg/detail/gaze_data__struct.h"
#include "egocentric_msg/msg/detail/gaze_data__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _GazeData__ros_msg_type = egocentric_msg__msg__GazeData;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_egocentric_msg
bool cdr_serialize_egocentric_msg__msg__GazeData(
  const egocentric_msg__msg__GazeData * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: x
  {
    cdr << ros_message->x;
  }

  // Field name: y
  {
    cdr << ros_message->y;
  }

  // Field name: worn
  {
    cdr << (ros_message->worn ? true : false);
  }

  // Field name: pupil_diameter_left
  {
    cdr << ros_message->pupil_diameter_left;
  }

  // Field name: eyeball_center_left_x
  {
    cdr << ros_message->eyeball_center_left_x;
  }

  // Field name: eyeball_center_left_y
  {
    cdr << ros_message->eyeball_center_left_y;
  }

  // Field name: eyeball_center_left_z
  {
    cdr << ros_message->eyeball_center_left_z;
  }

  // Field name: optical_axis_left_x
  {
    cdr << ros_message->optical_axis_left_x;
  }

  // Field name: optical_axis_left_y
  {
    cdr << ros_message->optical_axis_left_y;
  }

  // Field name: optical_axis_left_z
  {
    cdr << ros_message->optical_axis_left_z;
  }

  // Field name: pupil_diameter_right
  {
    cdr << ros_message->pupil_diameter_right;
  }

  // Field name: eyeball_center_right_x
  {
    cdr << ros_message->eyeball_center_right_x;
  }

  // Field name: eyeball_center_right_y
  {
    cdr << ros_message->eyeball_center_right_y;
  }

  // Field name: eyeball_center_right_z
  {
    cdr << ros_message->eyeball_center_right_z;
  }

  // Field name: optical_axis_right_x
  {
    cdr << ros_message->optical_axis_right_x;
  }

  // Field name: optical_axis_right_y
  {
    cdr << ros_message->optical_axis_right_y;
  }

  // Field name: optical_axis_right_z
  {
    cdr << ros_message->optical_axis_right_z;
  }

  // Field name: timestamp_unix_seconds
  {
    cdr << ros_message->timestamp_unix_seconds;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_egocentric_msg
bool cdr_deserialize_egocentric_msg__msg__GazeData(
  eprosima::fastcdr::Cdr & cdr,
  egocentric_msg__msg__GazeData * ros_message)
{
  // Field name: x
  {
    cdr >> ros_message->x;
  }

  // Field name: y
  {
    cdr >> ros_message->y;
  }

  // Field name: worn
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->worn = tmp ? true : false;
  }

  // Field name: pupil_diameter_left
  {
    cdr >> ros_message->pupil_diameter_left;
  }

  // Field name: eyeball_center_left_x
  {
    cdr >> ros_message->eyeball_center_left_x;
  }

  // Field name: eyeball_center_left_y
  {
    cdr >> ros_message->eyeball_center_left_y;
  }

  // Field name: eyeball_center_left_z
  {
    cdr >> ros_message->eyeball_center_left_z;
  }

  // Field name: optical_axis_left_x
  {
    cdr >> ros_message->optical_axis_left_x;
  }

  // Field name: optical_axis_left_y
  {
    cdr >> ros_message->optical_axis_left_y;
  }

  // Field name: optical_axis_left_z
  {
    cdr >> ros_message->optical_axis_left_z;
  }

  // Field name: pupil_diameter_right
  {
    cdr >> ros_message->pupil_diameter_right;
  }

  // Field name: eyeball_center_right_x
  {
    cdr >> ros_message->eyeball_center_right_x;
  }

  // Field name: eyeball_center_right_y
  {
    cdr >> ros_message->eyeball_center_right_y;
  }

  // Field name: eyeball_center_right_z
  {
    cdr >> ros_message->eyeball_center_right_z;
  }

  // Field name: optical_axis_right_x
  {
    cdr >> ros_message->optical_axis_right_x;
  }

  // Field name: optical_axis_right_y
  {
    cdr >> ros_message->optical_axis_right_y;
  }

  // Field name: optical_axis_right_z
  {
    cdr >> ros_message->optical_axis_right_z;
  }

  // Field name: timestamp_unix_seconds
  {
    cdr >> ros_message->timestamp_unix_seconds;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_egocentric_msg
size_t get_serialized_size_egocentric_msg__msg__GazeData(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GazeData__ros_msg_type * ros_message = static_cast<const _GazeData__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: x
  {
    size_t item_size = sizeof(ros_message->x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: y
  {
    size_t item_size = sizeof(ros_message->y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: worn
  {
    size_t item_size = sizeof(ros_message->worn);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pupil_diameter_left
  {
    size_t item_size = sizeof(ros_message->pupil_diameter_left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: eyeball_center_left_x
  {
    size_t item_size = sizeof(ros_message->eyeball_center_left_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: eyeball_center_left_y
  {
    size_t item_size = sizeof(ros_message->eyeball_center_left_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: eyeball_center_left_z
  {
    size_t item_size = sizeof(ros_message->eyeball_center_left_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: optical_axis_left_x
  {
    size_t item_size = sizeof(ros_message->optical_axis_left_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: optical_axis_left_y
  {
    size_t item_size = sizeof(ros_message->optical_axis_left_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: optical_axis_left_z
  {
    size_t item_size = sizeof(ros_message->optical_axis_left_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pupil_diameter_right
  {
    size_t item_size = sizeof(ros_message->pupil_diameter_right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: eyeball_center_right_x
  {
    size_t item_size = sizeof(ros_message->eyeball_center_right_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: eyeball_center_right_y
  {
    size_t item_size = sizeof(ros_message->eyeball_center_right_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: eyeball_center_right_z
  {
    size_t item_size = sizeof(ros_message->eyeball_center_right_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: optical_axis_right_x
  {
    size_t item_size = sizeof(ros_message->optical_axis_right_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: optical_axis_right_y
  {
    size_t item_size = sizeof(ros_message->optical_axis_right_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: optical_axis_right_z
  {
    size_t item_size = sizeof(ros_message->optical_axis_right_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: timestamp_unix_seconds
  {
    size_t item_size = sizeof(ros_message->timestamp_unix_seconds);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_egocentric_msg
size_t max_serialized_size_egocentric_msg__msg__GazeData(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: worn
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: pupil_diameter_left
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: eyeball_center_left_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: eyeball_center_left_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: eyeball_center_left_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: optical_axis_left_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: optical_axis_left_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: optical_axis_left_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: pupil_diameter_right
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: eyeball_center_right_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: eyeball_center_right_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: eyeball_center_right_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: optical_axis_right_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: optical_axis_right_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: optical_axis_right_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: timestamp_unix_seconds
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = egocentric_msg__msg__GazeData;
    is_plain =
      (
      offsetof(DataType, timestamp_unix_seconds) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_egocentric_msg
bool cdr_serialize_key_egocentric_msg__msg__GazeData(
  const egocentric_msg__msg__GazeData * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: x
  {
    cdr << ros_message->x;
  }

  // Field name: y
  {
    cdr << ros_message->y;
  }

  // Field name: worn
  {
    cdr << (ros_message->worn ? true : false);
  }

  // Field name: pupil_diameter_left
  {
    cdr << ros_message->pupil_diameter_left;
  }

  // Field name: eyeball_center_left_x
  {
    cdr << ros_message->eyeball_center_left_x;
  }

  // Field name: eyeball_center_left_y
  {
    cdr << ros_message->eyeball_center_left_y;
  }

  // Field name: eyeball_center_left_z
  {
    cdr << ros_message->eyeball_center_left_z;
  }

  // Field name: optical_axis_left_x
  {
    cdr << ros_message->optical_axis_left_x;
  }

  // Field name: optical_axis_left_y
  {
    cdr << ros_message->optical_axis_left_y;
  }

  // Field name: optical_axis_left_z
  {
    cdr << ros_message->optical_axis_left_z;
  }

  // Field name: pupil_diameter_right
  {
    cdr << ros_message->pupil_diameter_right;
  }

  // Field name: eyeball_center_right_x
  {
    cdr << ros_message->eyeball_center_right_x;
  }

  // Field name: eyeball_center_right_y
  {
    cdr << ros_message->eyeball_center_right_y;
  }

  // Field name: eyeball_center_right_z
  {
    cdr << ros_message->eyeball_center_right_z;
  }

  // Field name: optical_axis_right_x
  {
    cdr << ros_message->optical_axis_right_x;
  }

  // Field name: optical_axis_right_y
  {
    cdr << ros_message->optical_axis_right_y;
  }

  // Field name: optical_axis_right_z
  {
    cdr << ros_message->optical_axis_right_z;
  }

  // Field name: timestamp_unix_seconds
  {
    cdr << ros_message->timestamp_unix_seconds;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_egocentric_msg
size_t get_serialized_size_key_egocentric_msg__msg__GazeData(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GazeData__ros_msg_type * ros_message = static_cast<const _GazeData__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: x
  {
    size_t item_size = sizeof(ros_message->x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: y
  {
    size_t item_size = sizeof(ros_message->y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: worn
  {
    size_t item_size = sizeof(ros_message->worn);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pupil_diameter_left
  {
    size_t item_size = sizeof(ros_message->pupil_diameter_left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: eyeball_center_left_x
  {
    size_t item_size = sizeof(ros_message->eyeball_center_left_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: eyeball_center_left_y
  {
    size_t item_size = sizeof(ros_message->eyeball_center_left_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: eyeball_center_left_z
  {
    size_t item_size = sizeof(ros_message->eyeball_center_left_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: optical_axis_left_x
  {
    size_t item_size = sizeof(ros_message->optical_axis_left_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: optical_axis_left_y
  {
    size_t item_size = sizeof(ros_message->optical_axis_left_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: optical_axis_left_z
  {
    size_t item_size = sizeof(ros_message->optical_axis_left_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pupil_diameter_right
  {
    size_t item_size = sizeof(ros_message->pupil_diameter_right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: eyeball_center_right_x
  {
    size_t item_size = sizeof(ros_message->eyeball_center_right_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: eyeball_center_right_y
  {
    size_t item_size = sizeof(ros_message->eyeball_center_right_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: eyeball_center_right_z
  {
    size_t item_size = sizeof(ros_message->eyeball_center_right_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: optical_axis_right_x
  {
    size_t item_size = sizeof(ros_message->optical_axis_right_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: optical_axis_right_y
  {
    size_t item_size = sizeof(ros_message->optical_axis_right_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: optical_axis_right_z
  {
    size_t item_size = sizeof(ros_message->optical_axis_right_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: timestamp_unix_seconds
  {
    size_t item_size = sizeof(ros_message->timestamp_unix_seconds);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_egocentric_msg
size_t max_serialized_size_key_egocentric_msg__msg__GazeData(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: worn
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: pupil_diameter_left
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: eyeball_center_left_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: eyeball_center_left_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: eyeball_center_left_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: optical_axis_left_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: optical_axis_left_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: optical_axis_left_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: pupil_diameter_right
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: eyeball_center_right_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: eyeball_center_right_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: eyeball_center_right_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: optical_axis_right_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: optical_axis_right_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: optical_axis_right_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: timestamp_unix_seconds
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = egocentric_msg__msg__GazeData;
    is_plain =
      (
      offsetof(DataType, timestamp_unix_seconds) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _GazeData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const egocentric_msg__msg__GazeData * ros_message = static_cast<const egocentric_msg__msg__GazeData *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_egocentric_msg__msg__GazeData(ros_message, cdr);
}

static bool _GazeData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  egocentric_msg__msg__GazeData * ros_message = static_cast<egocentric_msg__msg__GazeData *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_egocentric_msg__msg__GazeData(cdr, ros_message);
}

static uint32_t _GazeData__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_egocentric_msg__msg__GazeData(
      untyped_ros_message, 0));
}

static size_t _GazeData__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_egocentric_msg__msg__GazeData(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_GazeData = {
  "egocentric_msg::msg",
  "GazeData",
  _GazeData__cdr_serialize,
  _GazeData__cdr_deserialize,
  _GazeData__get_serialized_size,
  _GazeData__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _GazeData__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GazeData,
  get_message_typesupport_handle_function,
  &egocentric_msg__msg__GazeData__get_type_hash,
  &egocentric_msg__msg__GazeData__get_type_description,
  &egocentric_msg__msg__GazeData__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, egocentric_msg, msg, GazeData)() {
  return &_GazeData__type_support;
}

#if defined(__cplusplus)
}
#endif
