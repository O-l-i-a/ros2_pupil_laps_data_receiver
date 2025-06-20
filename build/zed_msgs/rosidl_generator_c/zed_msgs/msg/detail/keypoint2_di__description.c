// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from zed_msgs:msg/Keypoint2Di.idl
// generated code does not contain a copyright notice

#include "zed_msgs/msg/detail/keypoint2_di__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_zed_msgs
const rosidl_type_hash_t *
zed_msgs__msg__Keypoint2Di__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x96, 0x40, 0xce, 0x7b, 0x25, 0x47, 0xa1, 0x38,
      0x2a, 0x21, 0xb8, 0xcc, 0x0c, 0xda, 0x86, 0x00,
      0xe1, 0x9b, 0x04, 0x1f, 0xca, 0x43, 0xd8, 0x12,
      0x8c, 0xbc, 0x24, 0xe3, 0x2c, 0xc8, 0x09, 0x82,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char zed_msgs__msg__Keypoint2Di__TYPE_NAME[] = "zed_msgs/msg/Keypoint2Di";

// Define type names, field names, and default values
static char zed_msgs__msg__Keypoint2Di__FIELD_NAME__kp[] = "kp";

static rosidl_runtime_c__type_description__Field zed_msgs__msg__Keypoint2Di__FIELDS[] = {
  {
    {zed_msgs__msg__Keypoint2Di__FIELD_NAME__kp, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32_ARRAY,
      2,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
zed_msgs__msg__Keypoint2Di__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {zed_msgs__msg__Keypoint2Di__TYPE_NAME, 24, 24},
      {zed_msgs__msg__Keypoint2Di__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint32[2] kp";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
zed_msgs__msg__Keypoint2Di__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {zed_msgs__msg__Keypoint2Di__TYPE_NAME, 24, 24},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 13, 13},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
zed_msgs__msg__Keypoint2Di__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *zed_msgs__msg__Keypoint2Di__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
