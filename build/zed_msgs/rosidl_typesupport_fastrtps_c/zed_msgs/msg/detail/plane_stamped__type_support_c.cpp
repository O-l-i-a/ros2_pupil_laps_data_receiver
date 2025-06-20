// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from zed_msgs:msg/PlaneStamped.idl
// generated code does not contain a copyright notice
#include "zed_msgs/msg/detail/plane_stamped__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "zed_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "zed_msgs/msg/detail/plane_stamped__struct.h"
#include "zed_msgs/msg/detail/plane_stamped__functions.h"
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

#include "geometry_msgs/msg/detail/point32__functions.h"  // center, normal
#include "geometry_msgs/msg/detail/polygon__functions.h"  // bounds
#include "geometry_msgs/msg/detail/transform__functions.h"  // pose
#include "shape_msgs/msg/detail/mesh__functions.h"  // mesh
#include "shape_msgs/msg/detail/plane__functions.h"  // coefficients
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
bool cdr_serialize_geometry_msgs__msg__Point32(
  const geometry_msgs__msg__Point32 * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
bool cdr_deserialize_geometry_msgs__msg__Point32(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__Point32 * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t get_serialized_size_geometry_msgs__msg__Point32(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t max_serialized_size_geometry_msgs__msg__Point32(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
bool cdr_serialize_key_geometry_msgs__msg__Point32(
  const geometry_msgs__msg__Point32 * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t get_serialized_size_key_geometry_msgs__msg__Point32(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t max_serialized_size_key_geometry_msgs__msg__Point32(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
bool cdr_serialize_geometry_msgs__msg__Polygon(
  const geometry_msgs__msg__Polygon * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
bool cdr_deserialize_geometry_msgs__msg__Polygon(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__Polygon * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t get_serialized_size_geometry_msgs__msg__Polygon(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t max_serialized_size_geometry_msgs__msg__Polygon(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
bool cdr_serialize_key_geometry_msgs__msg__Polygon(
  const geometry_msgs__msg__Polygon * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t get_serialized_size_key_geometry_msgs__msg__Polygon(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t max_serialized_size_key_geometry_msgs__msg__Polygon(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Polygon)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
bool cdr_serialize_geometry_msgs__msg__Transform(
  const geometry_msgs__msg__Transform * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
bool cdr_deserialize_geometry_msgs__msg__Transform(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__Transform * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t get_serialized_size_geometry_msgs__msg__Transform(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t max_serialized_size_geometry_msgs__msg__Transform(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
bool cdr_serialize_key_geometry_msgs__msg__Transform(
  const geometry_msgs__msg__Transform * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t get_serialized_size_key_geometry_msgs__msg__Transform(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t max_serialized_size_key_geometry_msgs__msg__Transform(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Transform)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
bool cdr_serialize_shape_msgs__msg__Mesh(
  const shape_msgs__msg__Mesh * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
bool cdr_deserialize_shape_msgs__msg__Mesh(
  eprosima::fastcdr::Cdr & cdr,
  shape_msgs__msg__Mesh * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t get_serialized_size_shape_msgs__msg__Mesh(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t max_serialized_size_shape_msgs__msg__Mesh(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
bool cdr_serialize_key_shape_msgs__msg__Mesh(
  const shape_msgs__msg__Mesh * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t get_serialized_size_key_shape_msgs__msg__Mesh(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t max_serialized_size_key_shape_msgs__msg__Mesh(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, shape_msgs, msg, Mesh)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
bool cdr_serialize_shape_msgs__msg__Plane(
  const shape_msgs__msg__Plane * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
bool cdr_deserialize_shape_msgs__msg__Plane(
  eprosima::fastcdr::Cdr & cdr,
  shape_msgs__msg__Plane * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t get_serialized_size_shape_msgs__msg__Plane(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t max_serialized_size_shape_msgs__msg__Plane(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
bool cdr_serialize_key_shape_msgs__msg__Plane(
  const shape_msgs__msg__Plane * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t get_serialized_size_key_shape_msgs__msg__Plane(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t max_serialized_size_key_shape_msgs__msg__Plane(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, shape_msgs, msg, Plane)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
bool cdr_serialize_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
bool cdr_deserialize_std_msgs__msg__Header(
  eprosima::fastcdr::Cdr & cdr,
  std_msgs__msg__Header * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
bool cdr_serialize_key_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t get_serialized_size_key_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
size_t max_serialized_size_key_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _PlaneStamped__ros_msg_type = zed_msgs__msg__PlaneStamped;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zed_msgs
bool cdr_serialize_zed_msgs__msg__PlaneStamped(
  const zed_msgs__msg__PlaneStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: mesh
  {
    cdr_serialize_shape_msgs__msg__Mesh(
      &ros_message->mesh, cdr);
  }

  // Field name: coefficients
  {
    cdr_serialize_shape_msgs__msg__Plane(
      &ros_message->coefficients, cdr);
  }

  // Field name: normal
  {
    cdr_serialize_geometry_msgs__msg__Point32(
      &ros_message->normal, cdr);
  }

  // Field name: center
  {
    cdr_serialize_geometry_msgs__msg__Point32(
      &ros_message->center, cdr);
  }

  // Field name: pose
  {
    cdr_serialize_geometry_msgs__msg__Transform(
      &ros_message->pose, cdr);
  }

  // Field name: extents
  {
    size_t size = 2;
    auto array_ptr = ros_message->extents;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: bounds
  {
    cdr_serialize_geometry_msgs__msg__Polygon(
      &ros_message->bounds, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zed_msgs
bool cdr_deserialize_zed_msgs__msg__PlaneStamped(
  eprosima::fastcdr::Cdr & cdr,
  zed_msgs__msg__PlaneStamped * ros_message)
{
  // Field name: header
  {
    cdr_deserialize_std_msgs__msg__Header(cdr, &ros_message->header);
  }

  // Field name: mesh
  {
    cdr_deserialize_shape_msgs__msg__Mesh(cdr, &ros_message->mesh);
  }

  // Field name: coefficients
  {
    cdr_deserialize_shape_msgs__msg__Plane(cdr, &ros_message->coefficients);
  }

  // Field name: normal
  {
    cdr_deserialize_geometry_msgs__msg__Point32(cdr, &ros_message->normal);
  }

  // Field name: center
  {
    cdr_deserialize_geometry_msgs__msg__Point32(cdr, &ros_message->center);
  }

  // Field name: pose
  {
    cdr_deserialize_geometry_msgs__msg__Transform(cdr, &ros_message->pose);
  }

  // Field name: extents
  {
    size_t size = 2;
    auto array_ptr = ros_message->extents;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: bounds
  {
    cdr_deserialize_geometry_msgs__msg__Polygon(cdr, &ros_message->bounds);
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zed_msgs
size_t get_serialized_size_zed_msgs__msg__PlaneStamped(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PlaneStamped__ros_msg_type * ros_message = static_cast<const _PlaneStamped__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: mesh
  current_alignment += get_serialized_size_shape_msgs__msg__Mesh(
    &(ros_message->mesh), current_alignment);

  // Field name: coefficients
  current_alignment += get_serialized_size_shape_msgs__msg__Plane(
    &(ros_message->coefficients), current_alignment);

  // Field name: normal
  current_alignment += get_serialized_size_geometry_msgs__msg__Point32(
    &(ros_message->normal), current_alignment);

  // Field name: center
  current_alignment += get_serialized_size_geometry_msgs__msg__Point32(
    &(ros_message->center), current_alignment);

  // Field name: pose
  current_alignment += get_serialized_size_geometry_msgs__msg__Transform(
    &(ros_message->pose), current_alignment);

  // Field name: extents
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->extents;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: bounds
  current_alignment += get_serialized_size_geometry_msgs__msg__Polygon(
    &(ros_message->bounds), current_alignment);

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zed_msgs
size_t max_serialized_size_zed_msgs__msg__PlaneStamped(
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

  // Field name: mesh
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_shape_msgs__msg__Mesh(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: coefficients
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_shape_msgs__msg__Plane(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: normal
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Point32(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: center
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Point32(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: pose
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Transform(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: extents
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: bounds
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Polygon(
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
    using DataType = zed_msgs__msg__PlaneStamped;
    is_plain =
      (
      offsetof(DataType, bounds) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zed_msgs
bool cdr_serialize_key_zed_msgs__msg__PlaneStamped(
  const zed_msgs__msg__PlaneStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_key_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: mesh
  {
    cdr_serialize_key_shape_msgs__msg__Mesh(
      &ros_message->mesh, cdr);
  }

  // Field name: coefficients
  {
    cdr_serialize_key_shape_msgs__msg__Plane(
      &ros_message->coefficients, cdr);
  }

  // Field name: normal
  {
    cdr_serialize_key_geometry_msgs__msg__Point32(
      &ros_message->normal, cdr);
  }

  // Field name: center
  {
    cdr_serialize_key_geometry_msgs__msg__Point32(
      &ros_message->center, cdr);
  }

  // Field name: pose
  {
    cdr_serialize_key_geometry_msgs__msg__Transform(
      &ros_message->pose, cdr);
  }

  // Field name: extents
  {
    size_t size = 2;
    auto array_ptr = ros_message->extents;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: bounds
  {
    cdr_serialize_key_geometry_msgs__msg__Polygon(
      &ros_message->bounds, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zed_msgs
size_t get_serialized_size_key_zed_msgs__msg__PlaneStamped(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PlaneStamped__ros_msg_type * ros_message = static_cast<const _PlaneStamped__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_key_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: mesh
  current_alignment += get_serialized_size_key_shape_msgs__msg__Mesh(
    &(ros_message->mesh), current_alignment);

  // Field name: coefficients
  current_alignment += get_serialized_size_key_shape_msgs__msg__Plane(
    &(ros_message->coefficients), current_alignment);

  // Field name: normal
  current_alignment += get_serialized_size_key_geometry_msgs__msg__Point32(
    &(ros_message->normal), current_alignment);

  // Field name: center
  current_alignment += get_serialized_size_key_geometry_msgs__msg__Point32(
    &(ros_message->center), current_alignment);

  // Field name: pose
  current_alignment += get_serialized_size_key_geometry_msgs__msg__Transform(
    &(ros_message->pose), current_alignment);

  // Field name: extents
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->extents;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: bounds
  current_alignment += get_serialized_size_key_geometry_msgs__msg__Polygon(
    &(ros_message->bounds), current_alignment);

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zed_msgs
size_t max_serialized_size_key_zed_msgs__msg__PlaneStamped(
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

  // Field name: mesh
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_shape_msgs__msg__Mesh(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: coefficients
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_shape_msgs__msg__Plane(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: normal
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__Point32(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: center
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__Point32(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: pose
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__Transform(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: extents
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: bounds
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__Polygon(
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
    using DataType = zed_msgs__msg__PlaneStamped;
    is_plain =
      (
      offsetof(DataType, bounds) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _PlaneStamped__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const zed_msgs__msg__PlaneStamped * ros_message = static_cast<const zed_msgs__msg__PlaneStamped *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_zed_msgs__msg__PlaneStamped(ros_message, cdr);
}

static bool _PlaneStamped__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  zed_msgs__msg__PlaneStamped * ros_message = static_cast<zed_msgs__msg__PlaneStamped *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_zed_msgs__msg__PlaneStamped(cdr, ros_message);
}

static uint32_t _PlaneStamped__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_zed_msgs__msg__PlaneStamped(
      untyped_ros_message, 0));
}

static size_t _PlaneStamped__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_zed_msgs__msg__PlaneStamped(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PlaneStamped = {
  "zed_msgs::msg",
  "PlaneStamped",
  _PlaneStamped__cdr_serialize,
  _PlaneStamped__cdr_deserialize,
  _PlaneStamped__get_serialized_size,
  _PlaneStamped__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _PlaneStamped__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PlaneStamped,
  get_message_typesupport_handle_function,
  &zed_msgs__msg__PlaneStamped__get_type_hash,
  &zed_msgs__msg__PlaneStamped__get_type_description,
  &zed_msgs__msg__PlaneStamped__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, zed_msgs, msg, PlaneStamped)() {
  return &_PlaneStamped__type_support;
}

#if defined(__cplusplus)
}
#endif
