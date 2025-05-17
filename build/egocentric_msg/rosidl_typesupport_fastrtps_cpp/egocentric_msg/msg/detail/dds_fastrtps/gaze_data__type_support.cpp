// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from egocentric_msg:msg/GazeData.idl
// generated code does not contain a copyright notice
#include "egocentric_msg/msg/detail/gaze_data__rosidl_typesupport_fastrtps_cpp.hpp"
#include "egocentric_msg/msg/detail/gaze_data__functions.h"
#include "egocentric_msg/msg/detail/gaze_data__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: x
  cdr << ros_message.x;

  // Member: y
  cdr << ros_message.y;

  // Member: worn
  cdr << (ros_message.worn ? true : false);

  // Member: pupil_diameter_left
  cdr << ros_message.pupil_diameter_left;

  // Member: eyeball_center_left_x
  cdr << ros_message.eyeball_center_left_x;

  // Member: eyeball_center_left_y
  cdr << ros_message.eyeball_center_left_y;

  // Member: eyeball_center_left_z
  cdr << ros_message.eyeball_center_left_z;

  // Member: optical_axis_left_x
  cdr << ros_message.optical_axis_left_x;

  // Member: optical_axis_left_y
  cdr << ros_message.optical_axis_left_y;

  // Member: optical_axis_left_z
  cdr << ros_message.optical_axis_left_z;

  // Member: pupil_diameter_right
  cdr << ros_message.pupil_diameter_right;

  // Member: eyeball_center_right_x
  cdr << ros_message.eyeball_center_right_x;

  // Member: eyeball_center_right_y
  cdr << ros_message.eyeball_center_right_y;

  // Member: eyeball_center_right_z
  cdr << ros_message.eyeball_center_right_z;

  // Member: optical_axis_right_x
  cdr << ros_message.optical_axis_right_x;

  // Member: optical_axis_right_y
  cdr << ros_message.optical_axis_right_y;

  // Member: optical_axis_right_z
  cdr << ros_message.optical_axis_right_z;

  // Member: timestamp_unix_seconds
  cdr << ros_message.timestamp_unix_seconds;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_egocentric_msg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  egocentric_msg::msg::GazeData & ros_message)
{
  // Member: x
  cdr >> ros_message.x;

  // Member: y
  cdr >> ros_message.y;

  // Member: worn
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.worn = tmp ? true : false;
  }

  // Member: pupil_diameter_left
  cdr >> ros_message.pupil_diameter_left;

  // Member: eyeball_center_left_x
  cdr >> ros_message.eyeball_center_left_x;

  // Member: eyeball_center_left_y
  cdr >> ros_message.eyeball_center_left_y;

  // Member: eyeball_center_left_z
  cdr >> ros_message.eyeball_center_left_z;

  // Member: optical_axis_left_x
  cdr >> ros_message.optical_axis_left_x;

  // Member: optical_axis_left_y
  cdr >> ros_message.optical_axis_left_y;

  // Member: optical_axis_left_z
  cdr >> ros_message.optical_axis_left_z;

  // Member: pupil_diameter_right
  cdr >> ros_message.pupil_diameter_right;

  // Member: eyeball_center_right_x
  cdr >> ros_message.eyeball_center_right_x;

  // Member: eyeball_center_right_y
  cdr >> ros_message.eyeball_center_right_y;

  // Member: eyeball_center_right_z
  cdr >> ros_message.eyeball_center_right_z;

  // Member: optical_axis_right_x
  cdr >> ros_message.optical_axis_right_x;

  // Member: optical_axis_right_y
  cdr >> ros_message.optical_axis_right_y;

  // Member: optical_axis_right_z
  cdr >> ros_message.optical_axis_right_z;

  // Member: timestamp_unix_seconds
  cdr >> ros_message.timestamp_unix_seconds;

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_egocentric_msg
get_serialized_size(
  const egocentric_msg::msg::GazeData & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: x
  {
    size_t item_size = sizeof(ros_message.x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: y
  {
    size_t item_size = sizeof(ros_message.y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: worn
  {
    size_t item_size = sizeof(ros_message.worn);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: pupil_diameter_left
  {
    size_t item_size = sizeof(ros_message.pupil_diameter_left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: eyeball_center_left_x
  {
    size_t item_size = sizeof(ros_message.eyeball_center_left_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: eyeball_center_left_y
  {
    size_t item_size = sizeof(ros_message.eyeball_center_left_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: eyeball_center_left_z
  {
    size_t item_size = sizeof(ros_message.eyeball_center_left_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: optical_axis_left_x
  {
    size_t item_size = sizeof(ros_message.optical_axis_left_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: optical_axis_left_y
  {
    size_t item_size = sizeof(ros_message.optical_axis_left_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: optical_axis_left_z
  {
    size_t item_size = sizeof(ros_message.optical_axis_left_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: pupil_diameter_right
  {
    size_t item_size = sizeof(ros_message.pupil_diameter_right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: eyeball_center_right_x
  {
    size_t item_size = sizeof(ros_message.eyeball_center_right_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: eyeball_center_right_y
  {
    size_t item_size = sizeof(ros_message.eyeball_center_right_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: eyeball_center_right_z
  {
    size_t item_size = sizeof(ros_message.eyeball_center_right_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: optical_axis_right_x
  {
    size_t item_size = sizeof(ros_message.optical_axis_right_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: optical_axis_right_y
  {
    size_t item_size = sizeof(ros_message.optical_axis_right_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: optical_axis_right_z
  {
    size_t item_size = sizeof(ros_message.optical_axis_right_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: timestamp_unix_seconds
  {
    size_t item_size = sizeof(ros_message.timestamp_unix_seconds);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_egocentric_msg
max_serialized_size_GazeData(
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

  // Member: x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: worn
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: pupil_diameter_left
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: eyeball_center_left_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: eyeball_center_left_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: eyeball_center_left_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: optical_axis_left_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: optical_axis_left_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: optical_axis_left_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: pupil_diameter_right
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: eyeball_center_right_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: eyeball_center_right_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: eyeball_center_right_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: optical_axis_right_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: optical_axis_right_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: optical_axis_right_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: timestamp_unix_seconds
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
    using DataType = egocentric_msg::msg::GazeData;
    is_plain =
      (
      offsetof(DataType, timestamp_unix_seconds) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_egocentric_msg
cdr_serialize_key(
  const egocentric_msg::msg::GazeData & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: x
  cdr << ros_message.x;

  // Member: y
  cdr << ros_message.y;

  // Member: worn
  cdr << (ros_message.worn ? true : false);

  // Member: pupil_diameter_left
  cdr << ros_message.pupil_diameter_left;

  // Member: eyeball_center_left_x
  cdr << ros_message.eyeball_center_left_x;

  // Member: eyeball_center_left_y
  cdr << ros_message.eyeball_center_left_y;

  // Member: eyeball_center_left_z
  cdr << ros_message.eyeball_center_left_z;

  // Member: optical_axis_left_x
  cdr << ros_message.optical_axis_left_x;

  // Member: optical_axis_left_y
  cdr << ros_message.optical_axis_left_y;

  // Member: optical_axis_left_z
  cdr << ros_message.optical_axis_left_z;

  // Member: pupil_diameter_right
  cdr << ros_message.pupil_diameter_right;

  // Member: eyeball_center_right_x
  cdr << ros_message.eyeball_center_right_x;

  // Member: eyeball_center_right_y
  cdr << ros_message.eyeball_center_right_y;

  // Member: eyeball_center_right_z
  cdr << ros_message.eyeball_center_right_z;

  // Member: optical_axis_right_x
  cdr << ros_message.optical_axis_right_x;

  // Member: optical_axis_right_y
  cdr << ros_message.optical_axis_right_y;

  // Member: optical_axis_right_z
  cdr << ros_message.optical_axis_right_z;

  // Member: timestamp_unix_seconds
  cdr << ros_message.timestamp_unix_seconds;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_egocentric_msg
get_serialized_size_key(
  const egocentric_msg::msg::GazeData & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: x
  {
    size_t item_size = sizeof(ros_message.x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: y
  {
    size_t item_size = sizeof(ros_message.y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: worn
  {
    size_t item_size = sizeof(ros_message.worn);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: pupil_diameter_left
  {
    size_t item_size = sizeof(ros_message.pupil_diameter_left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: eyeball_center_left_x
  {
    size_t item_size = sizeof(ros_message.eyeball_center_left_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: eyeball_center_left_y
  {
    size_t item_size = sizeof(ros_message.eyeball_center_left_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: eyeball_center_left_z
  {
    size_t item_size = sizeof(ros_message.eyeball_center_left_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: optical_axis_left_x
  {
    size_t item_size = sizeof(ros_message.optical_axis_left_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: optical_axis_left_y
  {
    size_t item_size = sizeof(ros_message.optical_axis_left_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: optical_axis_left_z
  {
    size_t item_size = sizeof(ros_message.optical_axis_left_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: pupil_diameter_right
  {
    size_t item_size = sizeof(ros_message.pupil_diameter_right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: eyeball_center_right_x
  {
    size_t item_size = sizeof(ros_message.eyeball_center_right_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: eyeball_center_right_y
  {
    size_t item_size = sizeof(ros_message.eyeball_center_right_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: eyeball_center_right_z
  {
    size_t item_size = sizeof(ros_message.eyeball_center_right_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: optical_axis_right_x
  {
    size_t item_size = sizeof(ros_message.optical_axis_right_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: optical_axis_right_y
  {
    size_t item_size = sizeof(ros_message.optical_axis_right_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: optical_axis_right_z
  {
    size_t item_size = sizeof(ros_message.optical_axis_right_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: timestamp_unix_seconds
  {
    size_t item_size = sizeof(ros_message.timestamp_unix_seconds);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_egocentric_msg
max_serialized_size_key_GazeData(
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

  // Member: x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: worn
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: pupil_diameter_left
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: eyeball_center_left_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: eyeball_center_left_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: eyeball_center_left_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: optical_axis_left_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: optical_axis_left_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: optical_axis_left_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: pupil_diameter_right
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: eyeball_center_right_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: eyeball_center_right_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: eyeball_center_right_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: optical_axis_right_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: optical_axis_right_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: optical_axis_right_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: timestamp_unix_seconds
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
    using DataType = egocentric_msg::msg::GazeData;
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
  auto typed_message =
    static_cast<const egocentric_msg::msg::GazeData *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GazeData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<egocentric_msg::msg::GazeData *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GazeData__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const egocentric_msg::msg::GazeData *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GazeData__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_GazeData(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _GazeData__callbacks = {
  "egocentric_msg::msg",
  "GazeData",
  _GazeData__cdr_serialize,
  _GazeData__cdr_deserialize,
  _GazeData__get_serialized_size,
  _GazeData__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _GazeData__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GazeData__callbacks,
  get_message_typesupport_handle_function,
  &egocentric_msg__msg__GazeData__get_type_hash,
  &egocentric_msg__msg__GazeData__get_type_description,
  &egocentric_msg__msg__GazeData__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace egocentric_msg

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_egocentric_msg
const rosidl_message_type_support_t *
get_message_type_support_handle<egocentric_msg::msg::GazeData>()
{
  return &egocentric_msg::msg::typesupport_fastrtps_cpp::_GazeData__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, egocentric_msg, msg, GazeData)() {
  return &egocentric_msg::msg::typesupport_fastrtps_cpp::_GazeData__handle;
}

#ifdef __cplusplus
}
#endif
