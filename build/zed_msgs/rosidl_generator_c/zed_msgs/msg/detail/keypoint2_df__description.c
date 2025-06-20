// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from zed_msgs:msg/Keypoint2Df.idl
// generated code does not contain a copyright notice

#include "zed_msgs/msg/detail/keypoint2_df__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_zed_msgs
const rosidl_type_hash_t *
zed_msgs__msg__Keypoint2Df__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf3, 0xcd, 0xe2, 0xac, 0xac, 0x57, 0x5a, 0x10,
      0xc3, 0x84, 0x1e, 0x2d, 0x98, 0xba, 0x51, 0xcd,
      0x09, 0x60, 0x48, 0xd0, 0x9b, 0xf7, 0x24, 0x0f,
      0x71, 0x35, 0x6a, 0x72, 0x0e, 0xcf, 0xc0, 0x37,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char zed_msgs__msg__Keypoint2Df__TYPE_NAME[] = "zed_msgs/msg/Keypoint2Df";

// Define type names, field names, and default values
static char zed_msgs__msg__Keypoint2Df__FIELD_NAME__kp[] = "kp";

static rosidl_runtime_c__type_description__Field zed_msgs__msg__Keypoint2Df__FIELDS[] = {
  {
    {zed_msgs__msg__Keypoint2Df__FIELD_NAME__kp, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      2,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
zed_msgs__msg__Keypoint2Df__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {zed_msgs__msg__Keypoint2Df__TYPE_NAME, 24, 24},
      {zed_msgs__msg__Keypoint2Df__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32[2] kp";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
zed_msgs__msg__Keypoint2Df__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {zed_msgs__msg__Keypoint2Df__TYPE_NAME, 24, 24},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 14, 14},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
zed_msgs__msg__Keypoint2Df__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *zed_msgs__msg__Keypoint2Df__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
