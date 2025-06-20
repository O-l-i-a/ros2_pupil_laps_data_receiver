// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from zed_msgs:msg/Keypoint3D.idl
// generated code does not contain a copyright notice

#include "zed_msgs/msg/detail/keypoint3_d__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_zed_msgs
const rosidl_type_hash_t *
zed_msgs__msg__Keypoint3D__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x83, 0x8f, 0x35, 0xf5, 0xca, 0x29, 0x6b, 0xa0,
      0xbe, 0x86, 0x86, 0x7a, 0x75, 0x9b, 0x9d, 0x64,
      0x49, 0xe5, 0x5e, 0xd6, 0xec, 0x3e, 0xaa, 0x7d,
      0x2f, 0x7a, 0x26, 0x11, 0x03, 0xc2, 0x3f, 0xd1,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char zed_msgs__msg__Keypoint3D__TYPE_NAME[] = "zed_msgs/msg/Keypoint3D";

// Define type names, field names, and default values
static char zed_msgs__msg__Keypoint3D__FIELD_NAME__kp[] = "kp";

static rosidl_runtime_c__type_description__Field zed_msgs__msg__Keypoint3D__FIELDS[] = {
  {
    {zed_msgs__msg__Keypoint3D__FIELD_NAME__kp, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
zed_msgs__msg__Keypoint3D__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {zed_msgs__msg__Keypoint3D__TYPE_NAME, 23, 23},
      {zed_msgs__msg__Keypoint3D__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32[3] kp";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
zed_msgs__msg__Keypoint3D__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {zed_msgs__msg__Keypoint3D__TYPE_NAME, 23, 23},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 14, 14},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
zed_msgs__msg__Keypoint3D__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *zed_msgs__msg__Keypoint3D__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
