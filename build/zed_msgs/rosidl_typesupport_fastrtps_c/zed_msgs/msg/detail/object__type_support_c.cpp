// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from zed_msgs:msg/Object.idl
// generated code does not contain a copyright notice
#include "zed_msgs/msg/detail/object__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "zed_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "zed_msgs/msg/detail/object__struct.h"
#include "zed_msgs/msg/detail/object__functions.h"
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

#include "rosidl_runtime_c/string.h"  // label, sublabel
#include "rosidl_runtime_c/string_functions.h"  // label, sublabel
#include "zed_msgs/msg/detail/bounding_box2_df__functions.h"  // head_bounding_box_2d
#include "zed_msgs/msg/detail/bounding_box2_di__functions.h"  // bounding_box_2d
#include "zed_msgs/msg/detail/bounding_box3_d__functions.h"  // bounding_box_3d, head_bounding_box_3d
#include "zed_msgs/msg/detail/skeleton2_d__functions.h"  // skeleton_2d
#include "zed_msgs/msg/detail/skeleton3_d__functions.h"  // skeleton_3d

// forward declare type support functions

bool cdr_serialize_zed_msgs__msg__BoundingBox2Df(
  const zed_msgs__msg__BoundingBox2Df * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_zed_msgs__msg__BoundingBox2Df(
  eprosima::fastcdr::Cdr & cdr,
  zed_msgs__msg__BoundingBox2Df * ros_message);

size_t get_serialized_size_zed_msgs__msg__BoundingBox2Df(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_zed_msgs__msg__BoundingBox2Df(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_zed_msgs__msg__BoundingBox2Df(
  const zed_msgs__msg__BoundingBox2Df * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_zed_msgs__msg__BoundingBox2Df(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_zed_msgs__msg__BoundingBox2Df(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, zed_msgs, msg, BoundingBox2Df)();

bool cdr_serialize_zed_msgs__msg__BoundingBox2Di(
  const zed_msgs__msg__BoundingBox2Di * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_zed_msgs__msg__BoundingBox2Di(
  eprosima::fastcdr::Cdr & cdr,
  zed_msgs__msg__BoundingBox2Di * ros_message);

size_t get_serialized_size_zed_msgs__msg__BoundingBox2Di(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_zed_msgs__msg__BoundingBox2Di(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_zed_msgs__msg__BoundingBox2Di(
  const zed_msgs__msg__BoundingBox2Di * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_zed_msgs__msg__BoundingBox2Di(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_zed_msgs__msg__BoundingBox2Di(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, zed_msgs, msg, BoundingBox2Di)();

bool cdr_serialize_zed_msgs__msg__BoundingBox3D(
  const zed_msgs__msg__BoundingBox3D * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_zed_msgs__msg__BoundingBox3D(
  eprosima::fastcdr::Cdr & cdr,
  zed_msgs__msg__BoundingBox3D * ros_message);

size_t get_serialized_size_zed_msgs__msg__BoundingBox3D(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_zed_msgs__msg__BoundingBox3D(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_zed_msgs__msg__BoundingBox3D(
  const zed_msgs__msg__BoundingBox3D * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_zed_msgs__msg__BoundingBox3D(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_zed_msgs__msg__BoundingBox3D(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, zed_msgs, msg, BoundingBox3D)();

bool cdr_serialize_zed_msgs__msg__Skeleton2D(
  const zed_msgs__msg__Skeleton2D * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_zed_msgs__msg__Skeleton2D(
  eprosima::fastcdr::Cdr & cdr,
  zed_msgs__msg__Skeleton2D * ros_message);

size_t get_serialized_size_zed_msgs__msg__Skeleton2D(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_zed_msgs__msg__Skeleton2D(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_zed_msgs__msg__Skeleton2D(
  const zed_msgs__msg__Skeleton2D * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_zed_msgs__msg__Skeleton2D(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_zed_msgs__msg__Skeleton2D(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, zed_msgs, msg, Skeleton2D)();

bool cdr_serialize_zed_msgs__msg__Skeleton3D(
  const zed_msgs__msg__Skeleton3D * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_zed_msgs__msg__Skeleton3D(
  eprosima::fastcdr::Cdr & cdr,
  zed_msgs__msg__Skeleton3D * ros_message);

size_t get_serialized_size_zed_msgs__msg__Skeleton3D(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_zed_msgs__msg__Skeleton3D(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_zed_msgs__msg__Skeleton3D(
  const zed_msgs__msg__Skeleton3D * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_zed_msgs__msg__Skeleton3D(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_zed_msgs__msg__Skeleton3D(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, zed_msgs, msg, Skeleton3D)();


using _Object__ros_msg_type = zed_msgs__msg__Object;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zed_msgs
bool cdr_serialize_zed_msgs__msg__Object(
  const zed_msgs__msg__Object * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: label
  {
    const rosidl_runtime_c__String * str = &ros_message->label;
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

  // Field name: label_id
  {
    cdr << ros_message->label_id;
  }

  // Field name: sublabel
  {
    const rosidl_runtime_c__String * str = &ros_message->sublabel;
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

  // Field name: confidence
  {
    cdr << ros_message->confidence;
  }

  // Field name: position
  {
    size_t size = 3;
    auto array_ptr = ros_message->position;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: position_covariance
  {
    size_t size = 6;
    auto array_ptr = ros_message->position_covariance;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: velocity
  {
    size_t size = 3;
    auto array_ptr = ros_message->velocity;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: tracking_available
  {
    cdr << (ros_message->tracking_available ? true : false);
  }

  // Field name: tracking_state
  {
    cdr << ros_message->tracking_state;
  }

  // Field name: action_state
  {
    cdr << ros_message->action_state;
  }

  // Field name: bounding_box_2d
  {
    cdr_serialize_zed_msgs__msg__BoundingBox2Di(
      &ros_message->bounding_box_2d, cdr);
  }

  // Field name: bounding_box_3d
  {
    cdr_serialize_zed_msgs__msg__BoundingBox3D(
      &ros_message->bounding_box_3d, cdr);
  }

  // Field name: dimensions_3d
  {
    size_t size = 3;
    auto array_ptr = ros_message->dimensions_3d;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: skeleton_available
  {
    cdr << (ros_message->skeleton_available ? true : false);
  }

  // Field name: body_format
  {
    cdr << ros_message->body_format;
  }

  // Field name: head_bounding_box_2d
  {
    cdr_serialize_zed_msgs__msg__BoundingBox2Df(
      &ros_message->head_bounding_box_2d, cdr);
  }

  // Field name: head_bounding_box_3d
  {
    cdr_serialize_zed_msgs__msg__BoundingBox3D(
      &ros_message->head_bounding_box_3d, cdr);
  }

  // Field name: head_position
  {
    size_t size = 3;
    auto array_ptr = ros_message->head_position;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: skeleton_2d
  {
    cdr_serialize_zed_msgs__msg__Skeleton2D(
      &ros_message->skeleton_2d, cdr);
  }

  // Field name: skeleton_3d
  {
    cdr_serialize_zed_msgs__msg__Skeleton3D(
      &ros_message->skeleton_3d, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zed_msgs
bool cdr_deserialize_zed_msgs__msg__Object(
  eprosima::fastcdr::Cdr & cdr,
  zed_msgs__msg__Object * ros_message)
{
  // Field name: label
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->label.data) {
      rosidl_runtime_c__String__init(&ros_message->label);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->label,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'label'\n");
      return false;
    }
  }

  // Field name: label_id
  {
    cdr >> ros_message->label_id;
  }

  // Field name: sublabel
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->sublabel.data) {
      rosidl_runtime_c__String__init(&ros_message->sublabel);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->sublabel,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'sublabel'\n");
      return false;
    }
  }

  // Field name: confidence
  {
    cdr >> ros_message->confidence;
  }

  // Field name: position
  {
    size_t size = 3;
    auto array_ptr = ros_message->position;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: position_covariance
  {
    size_t size = 6;
    auto array_ptr = ros_message->position_covariance;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: velocity
  {
    size_t size = 3;
    auto array_ptr = ros_message->velocity;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: tracking_available
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->tracking_available = tmp ? true : false;
  }

  // Field name: tracking_state
  {
    cdr >> ros_message->tracking_state;
  }

  // Field name: action_state
  {
    cdr >> ros_message->action_state;
  }

  // Field name: bounding_box_2d
  {
    cdr_deserialize_zed_msgs__msg__BoundingBox2Di(cdr, &ros_message->bounding_box_2d);
  }

  // Field name: bounding_box_3d
  {
    cdr_deserialize_zed_msgs__msg__BoundingBox3D(cdr, &ros_message->bounding_box_3d);
  }

  // Field name: dimensions_3d
  {
    size_t size = 3;
    auto array_ptr = ros_message->dimensions_3d;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: skeleton_available
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->skeleton_available = tmp ? true : false;
  }

  // Field name: body_format
  {
    cdr >> ros_message->body_format;
  }

  // Field name: head_bounding_box_2d
  {
    cdr_deserialize_zed_msgs__msg__BoundingBox2Df(cdr, &ros_message->head_bounding_box_2d);
  }

  // Field name: head_bounding_box_3d
  {
    cdr_deserialize_zed_msgs__msg__BoundingBox3D(cdr, &ros_message->head_bounding_box_3d);
  }

  // Field name: head_position
  {
    size_t size = 3;
    auto array_ptr = ros_message->head_position;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: skeleton_2d
  {
    cdr_deserialize_zed_msgs__msg__Skeleton2D(cdr, &ros_message->skeleton_2d);
  }

  // Field name: skeleton_3d
  {
    cdr_deserialize_zed_msgs__msg__Skeleton3D(cdr, &ros_message->skeleton_3d);
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zed_msgs
size_t get_serialized_size_zed_msgs__msg__Object(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Object__ros_msg_type * ros_message = static_cast<const _Object__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: label
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->label.size + 1);

  // Field name: label_id
  {
    size_t item_size = sizeof(ros_message->label_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: sublabel
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->sublabel.size + 1);

  // Field name: confidence
  {
    size_t item_size = sizeof(ros_message->confidence);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: position
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->position;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: position_covariance
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->position_covariance;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: velocity
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->velocity;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: tracking_available
  {
    size_t item_size = sizeof(ros_message->tracking_available);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: tracking_state
  {
    size_t item_size = sizeof(ros_message->tracking_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: action_state
  {
    size_t item_size = sizeof(ros_message->action_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: bounding_box_2d
  current_alignment += get_serialized_size_zed_msgs__msg__BoundingBox2Di(
    &(ros_message->bounding_box_2d), current_alignment);

  // Field name: bounding_box_3d
  current_alignment += get_serialized_size_zed_msgs__msg__BoundingBox3D(
    &(ros_message->bounding_box_3d), current_alignment);

  // Field name: dimensions_3d
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->dimensions_3d;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: skeleton_available
  {
    size_t item_size = sizeof(ros_message->skeleton_available);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: body_format
  {
    size_t item_size = sizeof(ros_message->body_format);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: head_bounding_box_2d
  current_alignment += get_serialized_size_zed_msgs__msg__BoundingBox2Df(
    &(ros_message->head_bounding_box_2d), current_alignment);

  // Field name: head_bounding_box_3d
  current_alignment += get_serialized_size_zed_msgs__msg__BoundingBox3D(
    &(ros_message->head_bounding_box_3d), current_alignment);

  // Field name: head_position
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->head_position;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: skeleton_2d
  current_alignment += get_serialized_size_zed_msgs__msg__Skeleton2D(
    &(ros_message->skeleton_2d), current_alignment);

  // Field name: skeleton_3d
  current_alignment += get_serialized_size_zed_msgs__msg__Skeleton3D(
    &(ros_message->skeleton_3d), current_alignment);

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zed_msgs
size_t max_serialized_size_zed_msgs__msg__Object(
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

  // Field name: label
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

  // Field name: label_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: sublabel
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

  // Field name: confidence
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: position
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: position_covariance
  {
    size_t array_size = 6;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: velocity
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: tracking_available
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: tracking_state
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: action_state
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: bounding_box_2d
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_zed_msgs__msg__BoundingBox2Di(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: bounding_box_3d
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_zed_msgs__msg__BoundingBox3D(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: dimensions_3d
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: skeleton_available
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: body_format
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: head_bounding_box_2d
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_zed_msgs__msg__BoundingBox2Df(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: head_bounding_box_3d
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_zed_msgs__msg__BoundingBox3D(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: head_position
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: skeleton_2d
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_zed_msgs__msg__Skeleton2D(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: skeleton_3d
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_zed_msgs__msg__Skeleton3D(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = zed_msgs__msg__Object;
    is_plain =
      (
      offsetof(DataType, skeleton_3d) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zed_msgs
bool cdr_serialize_key_zed_msgs__msg__Object(
  const zed_msgs__msg__Object * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: label
  {
    const rosidl_runtime_c__String * str = &ros_message->label;
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

  // Field name: label_id
  {
    cdr << ros_message->label_id;
  }

  // Field name: sublabel
  {
    const rosidl_runtime_c__String * str = &ros_message->sublabel;
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

  // Field name: confidence
  {
    cdr << ros_message->confidence;
  }

  // Field name: position
  {
    size_t size = 3;
    auto array_ptr = ros_message->position;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: position_covariance
  {
    size_t size = 6;
    auto array_ptr = ros_message->position_covariance;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: velocity
  {
    size_t size = 3;
    auto array_ptr = ros_message->velocity;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: tracking_available
  {
    cdr << (ros_message->tracking_available ? true : false);
  }

  // Field name: tracking_state
  {
    cdr << ros_message->tracking_state;
  }

  // Field name: action_state
  {
    cdr << ros_message->action_state;
  }

  // Field name: bounding_box_2d
  {
    cdr_serialize_key_zed_msgs__msg__BoundingBox2Di(
      &ros_message->bounding_box_2d, cdr);
  }

  // Field name: bounding_box_3d
  {
    cdr_serialize_key_zed_msgs__msg__BoundingBox3D(
      &ros_message->bounding_box_3d, cdr);
  }

  // Field name: dimensions_3d
  {
    size_t size = 3;
    auto array_ptr = ros_message->dimensions_3d;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: skeleton_available
  {
    cdr << (ros_message->skeleton_available ? true : false);
  }

  // Field name: body_format
  {
    cdr << ros_message->body_format;
  }

  // Field name: head_bounding_box_2d
  {
    cdr_serialize_key_zed_msgs__msg__BoundingBox2Df(
      &ros_message->head_bounding_box_2d, cdr);
  }

  // Field name: head_bounding_box_3d
  {
    cdr_serialize_key_zed_msgs__msg__BoundingBox3D(
      &ros_message->head_bounding_box_3d, cdr);
  }

  // Field name: head_position
  {
    size_t size = 3;
    auto array_ptr = ros_message->head_position;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: skeleton_2d
  {
    cdr_serialize_key_zed_msgs__msg__Skeleton2D(
      &ros_message->skeleton_2d, cdr);
  }

  // Field name: skeleton_3d
  {
    cdr_serialize_key_zed_msgs__msg__Skeleton3D(
      &ros_message->skeleton_3d, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zed_msgs
size_t get_serialized_size_key_zed_msgs__msg__Object(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Object__ros_msg_type * ros_message = static_cast<const _Object__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: label
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->label.size + 1);

  // Field name: label_id
  {
    size_t item_size = sizeof(ros_message->label_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: sublabel
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->sublabel.size + 1);

  // Field name: confidence
  {
    size_t item_size = sizeof(ros_message->confidence);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: position
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->position;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: position_covariance
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->position_covariance;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: velocity
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->velocity;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: tracking_available
  {
    size_t item_size = sizeof(ros_message->tracking_available);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: tracking_state
  {
    size_t item_size = sizeof(ros_message->tracking_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: action_state
  {
    size_t item_size = sizeof(ros_message->action_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: bounding_box_2d
  current_alignment += get_serialized_size_key_zed_msgs__msg__BoundingBox2Di(
    &(ros_message->bounding_box_2d), current_alignment);

  // Field name: bounding_box_3d
  current_alignment += get_serialized_size_key_zed_msgs__msg__BoundingBox3D(
    &(ros_message->bounding_box_3d), current_alignment);

  // Field name: dimensions_3d
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->dimensions_3d;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: skeleton_available
  {
    size_t item_size = sizeof(ros_message->skeleton_available);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: body_format
  {
    size_t item_size = sizeof(ros_message->body_format);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: head_bounding_box_2d
  current_alignment += get_serialized_size_key_zed_msgs__msg__BoundingBox2Df(
    &(ros_message->head_bounding_box_2d), current_alignment);

  // Field name: head_bounding_box_3d
  current_alignment += get_serialized_size_key_zed_msgs__msg__BoundingBox3D(
    &(ros_message->head_bounding_box_3d), current_alignment);

  // Field name: head_position
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->head_position;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: skeleton_2d
  current_alignment += get_serialized_size_key_zed_msgs__msg__Skeleton2D(
    &(ros_message->skeleton_2d), current_alignment);

  // Field name: skeleton_3d
  current_alignment += get_serialized_size_key_zed_msgs__msg__Skeleton3D(
    &(ros_message->skeleton_3d), current_alignment);

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zed_msgs
size_t max_serialized_size_key_zed_msgs__msg__Object(
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
  // Field name: label
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

  // Field name: label_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: sublabel
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

  // Field name: confidence
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: position
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: position_covariance
  {
    size_t array_size = 6;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: velocity
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: tracking_available
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: tracking_state
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: action_state
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: bounding_box_2d
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_zed_msgs__msg__BoundingBox2Di(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: bounding_box_3d
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_zed_msgs__msg__BoundingBox3D(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: dimensions_3d
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: skeleton_available
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: body_format
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: head_bounding_box_2d
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_zed_msgs__msg__BoundingBox2Df(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: head_bounding_box_3d
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_zed_msgs__msg__BoundingBox3D(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: head_position
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: skeleton_2d
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_zed_msgs__msg__Skeleton2D(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: skeleton_3d
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_zed_msgs__msg__Skeleton3D(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = zed_msgs__msg__Object;
    is_plain =
      (
      offsetof(DataType, skeleton_3d) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _Object__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const zed_msgs__msg__Object * ros_message = static_cast<const zed_msgs__msg__Object *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_zed_msgs__msg__Object(ros_message, cdr);
}

static bool _Object__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  zed_msgs__msg__Object * ros_message = static_cast<zed_msgs__msg__Object *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_zed_msgs__msg__Object(cdr, ros_message);
}

static uint32_t _Object__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_zed_msgs__msg__Object(
      untyped_ros_message, 0));
}

static size_t _Object__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_zed_msgs__msg__Object(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Object = {
  "zed_msgs::msg",
  "Object",
  _Object__cdr_serialize,
  _Object__cdr_deserialize,
  _Object__get_serialized_size,
  _Object__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _Object__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Object,
  get_message_typesupport_handle_function,
  &zed_msgs__msg__Object__get_type_hash,
  &zed_msgs__msg__Object__get_type_description,
  &zed_msgs__msg__Object__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, zed_msgs, msg, Object)() {
  return &_Object__type_support;
}

#if defined(__cplusplus)
}
#endif
