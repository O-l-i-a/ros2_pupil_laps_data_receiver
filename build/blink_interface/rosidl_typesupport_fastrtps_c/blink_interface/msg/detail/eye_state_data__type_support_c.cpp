// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from blink_interface:msg/EyeStateData.idl
// generated code does not contain a copyright notice
#include "blink_interface/msg/detail/eye_state_data__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "blink_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "blink_interface/msg/detail/eye_state_data__struct.h"
#include "blink_interface/msg/detail/eye_state_data__functions.h"
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

#include "rosidl_runtime_c/string.h"  // event_name
#include "rosidl_runtime_c/string_functions.h"  // event_name
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_blink_interface
bool cdr_serialize_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_blink_interface
bool cdr_deserialize_std_msgs__msg__Header(
  eprosima::fastcdr::Cdr & cdr,
  std_msgs__msg__Header * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_blink_interface
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_blink_interface
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_blink_interface
bool cdr_serialize_key_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_blink_interface
size_t get_serialized_size_key_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_blink_interface
size_t max_serialized_size_key_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_blink_interface
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _EyeStateData__ros_msg_type = blink_interface__msg__EyeStateData;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_blink_interface
bool cdr_serialize_blink_interface__msg__EyeStateData(
  const blink_interface__msg__EyeStateData * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: event_name
  {
    const rosidl_runtime_c__String * str = &ros_message->event_name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: event_type
  {
    cdr << ros_message->event_type;
  }

  // Field name: start_time_ns
  {
    cdr << ros_message->start_time_ns;
  }

  // Field name: end_time_ns
  {
    cdr << ros_message->end_time_ns;
  }

  // Field name: rtp_ts_unix_seconds
  {
    cdr << ros_message->rtp_ts_unix_seconds;
  }

  // Field name: has_end_time
  {
    cdr << (ros_message->has_end_time ? true : false);
  }

  // Field name: start_gaze_x
  {
    cdr << ros_message->start_gaze_x;
  }

  // Field name: start_gaze_y
  {
    cdr << ros_message->start_gaze_y;
  }

  // Field name: end_gaze_x
  {
    cdr << ros_message->end_gaze_x;
  }

  // Field name: end_gaze_y
  {
    cdr << ros_message->end_gaze_y;
  }

  // Field name: mean_gaze_x
  {
    cdr << ros_message->mean_gaze_x;
  }

  // Field name: mean_gaze_y
  {
    cdr << ros_message->mean_gaze_y;
  }

  // Field name: amplitude_pixels
  {
    cdr << ros_message->amplitude_pixels;
  }

  // Field name: amplitude_angle_deg
  {
    cdr << ros_message->amplitude_angle_deg;
  }

  // Field name: mean_velocity
  {
    cdr << ros_message->mean_velocity;
  }

  // Field name: max_velocity
  {
    cdr << ros_message->max_velocity;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_blink_interface
bool cdr_deserialize_blink_interface__msg__EyeStateData(
  eprosima::fastcdr::Cdr & cdr,
  blink_interface__msg__EyeStateData * ros_message)
{
  // Field name: header
  {
    cdr_deserialize_std_msgs__msg__Header(cdr, &ros_message->header);
  }

  // Field name: event_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->event_name.data) {
      rosidl_runtime_c__String__init(&ros_message->event_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->event_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'event_name'\n");
      return false;
    }
  }

  // Field name: event_type
  {
    cdr >> ros_message->event_type;
  }

  // Field name: start_time_ns
  {
    cdr >> ros_message->start_time_ns;
  }

  // Field name: end_time_ns
  {
    cdr >> ros_message->end_time_ns;
  }

  // Field name: rtp_ts_unix_seconds
  {
    cdr >> ros_message->rtp_ts_unix_seconds;
  }

  // Field name: has_end_time
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->has_end_time = tmp ? true : false;
  }

  // Field name: start_gaze_x
  {
    cdr >> ros_message->start_gaze_x;
  }

  // Field name: start_gaze_y
  {
    cdr >> ros_message->start_gaze_y;
  }

  // Field name: end_gaze_x
  {
    cdr >> ros_message->end_gaze_x;
  }

  // Field name: end_gaze_y
  {
    cdr >> ros_message->end_gaze_y;
  }

  // Field name: mean_gaze_x
  {
    cdr >> ros_message->mean_gaze_x;
  }

  // Field name: mean_gaze_y
  {
    cdr >> ros_message->mean_gaze_y;
  }

  // Field name: amplitude_pixels
  {
    cdr >> ros_message->amplitude_pixels;
  }

  // Field name: amplitude_angle_deg
  {
    cdr >> ros_message->amplitude_angle_deg;
  }

  // Field name: mean_velocity
  {
    cdr >> ros_message->mean_velocity;
  }

  // Field name: max_velocity
  {
    cdr >> ros_message->max_velocity;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_blink_interface
size_t get_serialized_size_blink_interface__msg__EyeStateData(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _EyeStateData__ros_msg_type * ros_message = static_cast<const _EyeStateData__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: event_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->event_name.size + 1);

  // Field name: event_type
  {
    size_t item_size = sizeof(ros_message->event_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: start_time_ns
  {
    size_t item_size = sizeof(ros_message->start_time_ns);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: end_time_ns
  {
    size_t item_size = sizeof(ros_message->end_time_ns);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rtp_ts_unix_seconds
  {
    size_t item_size = sizeof(ros_message->rtp_ts_unix_seconds);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: has_end_time
  {
    size_t item_size = sizeof(ros_message->has_end_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: start_gaze_x
  {
    size_t item_size = sizeof(ros_message->start_gaze_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: start_gaze_y
  {
    size_t item_size = sizeof(ros_message->start_gaze_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: end_gaze_x
  {
    size_t item_size = sizeof(ros_message->end_gaze_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: end_gaze_y
  {
    size_t item_size = sizeof(ros_message->end_gaze_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mean_gaze_x
  {
    size_t item_size = sizeof(ros_message->mean_gaze_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mean_gaze_y
  {
    size_t item_size = sizeof(ros_message->mean_gaze_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: amplitude_pixels
  {
    size_t item_size = sizeof(ros_message->amplitude_pixels);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: amplitude_angle_deg
  {
    size_t item_size = sizeof(ros_message->amplitude_angle_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mean_velocity
  {
    size_t item_size = sizeof(ros_message->mean_velocity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: max_velocity
  {
    size_t item_size = sizeof(ros_message->max_velocity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_blink_interface
size_t max_serialized_size_blink_interface__msg__EyeStateData(
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

  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: event_name
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: event_type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: start_time_ns
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: end_time_ns
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: rtp_ts_unix_seconds
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: has_end_time
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: start_gaze_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: start_gaze_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: end_gaze_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: end_gaze_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: mean_gaze_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: mean_gaze_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: amplitude_pixels
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: amplitude_angle_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: mean_velocity
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: max_velocity
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
    using DataType = blink_interface__msg__EyeStateData;
    is_plain =
      (
      offsetof(DataType, max_velocity) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_blink_interface
bool cdr_serialize_key_blink_interface__msg__EyeStateData(
  const blink_interface__msg__EyeStateData * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_key_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: event_name
  {
    const rosidl_runtime_c__String * str = &ros_message->event_name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: event_type
  {
    cdr << ros_message->event_type;
  }

  // Field name: start_time_ns
  {
    cdr << ros_message->start_time_ns;
  }

  // Field name: end_time_ns
  {
    cdr << ros_message->end_time_ns;
  }

  // Field name: rtp_ts_unix_seconds
  {
    cdr << ros_message->rtp_ts_unix_seconds;
  }

  // Field name: has_end_time
  {
    cdr << (ros_message->has_end_time ? true : false);
  }

  // Field name: start_gaze_x
  {
    cdr << ros_message->start_gaze_x;
  }

  // Field name: start_gaze_y
  {
    cdr << ros_message->start_gaze_y;
  }

  // Field name: end_gaze_x
  {
    cdr << ros_message->end_gaze_x;
  }

  // Field name: end_gaze_y
  {
    cdr << ros_message->end_gaze_y;
  }

  // Field name: mean_gaze_x
  {
    cdr << ros_message->mean_gaze_x;
  }

  // Field name: mean_gaze_y
  {
    cdr << ros_message->mean_gaze_y;
  }

  // Field name: amplitude_pixels
  {
    cdr << ros_message->amplitude_pixels;
  }

  // Field name: amplitude_angle_deg
  {
    cdr << ros_message->amplitude_angle_deg;
  }

  // Field name: mean_velocity
  {
    cdr << ros_message->mean_velocity;
  }

  // Field name: max_velocity
  {
    cdr << ros_message->max_velocity;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_blink_interface
size_t get_serialized_size_key_blink_interface__msg__EyeStateData(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _EyeStateData__ros_msg_type * ros_message = static_cast<const _EyeStateData__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_key_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: event_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->event_name.size + 1);

  // Field name: event_type
  {
    size_t item_size = sizeof(ros_message->event_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: start_time_ns
  {
    size_t item_size = sizeof(ros_message->start_time_ns);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: end_time_ns
  {
    size_t item_size = sizeof(ros_message->end_time_ns);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rtp_ts_unix_seconds
  {
    size_t item_size = sizeof(ros_message->rtp_ts_unix_seconds);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: has_end_time
  {
    size_t item_size = sizeof(ros_message->has_end_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: start_gaze_x
  {
    size_t item_size = sizeof(ros_message->start_gaze_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: start_gaze_y
  {
    size_t item_size = sizeof(ros_message->start_gaze_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: end_gaze_x
  {
    size_t item_size = sizeof(ros_message->end_gaze_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: end_gaze_y
  {
    size_t item_size = sizeof(ros_message->end_gaze_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mean_gaze_x
  {
    size_t item_size = sizeof(ros_message->mean_gaze_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mean_gaze_y
  {
    size_t item_size = sizeof(ros_message->mean_gaze_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: amplitude_pixels
  {
    size_t item_size = sizeof(ros_message->amplitude_pixels);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: amplitude_angle_deg
  {
    size_t item_size = sizeof(ros_message->amplitude_angle_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mean_velocity
  {
    size_t item_size = sizeof(ros_message->mean_velocity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: max_velocity
  {
    size_t item_size = sizeof(ros_message->max_velocity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_blink_interface
size_t max_serialized_size_key_blink_interface__msg__EyeStateData(
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
  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: event_name
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: event_type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: start_time_ns
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: end_time_ns
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: rtp_ts_unix_seconds
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: has_end_time
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: start_gaze_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: start_gaze_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: end_gaze_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: end_gaze_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: mean_gaze_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: mean_gaze_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: amplitude_pixels
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: amplitude_angle_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: mean_velocity
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: max_velocity
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
    using DataType = blink_interface__msg__EyeStateData;
    is_plain =
      (
      offsetof(DataType, max_velocity) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _EyeStateData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const blink_interface__msg__EyeStateData * ros_message = static_cast<const blink_interface__msg__EyeStateData *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_blink_interface__msg__EyeStateData(ros_message, cdr);
}

static bool _EyeStateData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  blink_interface__msg__EyeStateData * ros_message = static_cast<blink_interface__msg__EyeStateData *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_blink_interface__msg__EyeStateData(cdr, ros_message);
}

static uint32_t _EyeStateData__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_blink_interface__msg__EyeStateData(
      untyped_ros_message, 0));
}

static size_t _EyeStateData__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_blink_interface__msg__EyeStateData(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_EyeStateData = {
  "blink_interface::msg",
  "EyeStateData",
  _EyeStateData__cdr_serialize,
  _EyeStateData__cdr_deserialize,
  _EyeStateData__get_serialized_size,
  _EyeStateData__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _EyeStateData__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_EyeStateData,
  get_message_typesupport_handle_function,
  &blink_interface__msg__EyeStateData__get_type_hash,
  &blink_interface__msg__EyeStateData__get_type_description,
  &blink_interface__msg__EyeStateData__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, blink_interface, msg, EyeStateData)() {
  return &_EyeStateData__type_support;
}

#if defined(__cplusplus)
}
#endif
