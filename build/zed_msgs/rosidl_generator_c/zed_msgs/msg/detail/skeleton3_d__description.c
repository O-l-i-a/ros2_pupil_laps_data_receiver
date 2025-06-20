// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from zed_msgs:msg/Skeleton3D.idl
// generated code does not contain a copyright notice

#include "zed_msgs/msg/detail/skeleton3_d__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_zed_msgs
const rosidl_type_hash_t *
zed_msgs__msg__Skeleton3D__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe7, 0x62, 0x79, 0x8d, 0x06, 0x7f, 0x7d, 0x68,
      0x1f, 0xde, 0xe2, 0x59, 0xaa, 0x75, 0xe2, 0x8f,
      0x0f, 0xc6, 0xeb, 0x36, 0xda, 0xd1, 0x3e, 0x4e,
      0xdd, 0xec, 0x89, 0xc7, 0xd8, 0xbd, 0x6b, 0x54,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "zed_msgs/msg/detail/keypoint3_d__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t zed_msgs__msg__Keypoint3D__EXPECTED_HASH = {1, {
    0x83, 0x8f, 0x35, 0xf5, 0xca, 0x29, 0x6b, 0xa0,
    0xbe, 0x86, 0x86, 0x7a, 0x75, 0x9b, 0x9d, 0x64,
    0x49, 0xe5, 0x5e, 0xd6, 0xec, 0x3e, 0xaa, 0x7d,
    0x2f, 0x7a, 0x26, 0x11, 0x03, 0xc2, 0x3f, 0xd1,
  }};
#endif

static char zed_msgs__msg__Skeleton3D__TYPE_NAME[] = "zed_msgs/msg/Skeleton3D";
static char zed_msgs__msg__Keypoint3D__TYPE_NAME[] = "zed_msgs/msg/Keypoint3D";

// Define type names, field names, and default values
static char zed_msgs__msg__Skeleton3D__FIELD_NAME__keypoints[] = "keypoints";

static rosidl_runtime_c__type_description__Field zed_msgs__msg__Skeleton3D__FIELDS[] = {
  {
    {zed_msgs__msg__Skeleton3D__FIELD_NAME__keypoints, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_ARRAY,
      70,
      0,
      {zed_msgs__msg__Keypoint3D__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription zed_msgs__msg__Skeleton3D__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {zed_msgs__msg__Keypoint3D__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
zed_msgs__msg__Skeleton3D__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {zed_msgs__msg__Skeleton3D__TYPE_NAME, 23, 23},
      {zed_msgs__msg__Skeleton3D__FIELDS, 1, 1},
    },
    {zed_msgs__msg__Skeleton3D__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&zed_msgs__msg__Keypoint3D__EXPECTED_HASH, zed_msgs__msg__Keypoint3D__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = zed_msgs__msg__Keypoint3D__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Skeleton joints\n"
  "zed_msgs/Keypoint3D[70] keypoints";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
zed_msgs__msg__Skeleton3D__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {zed_msgs__msg__Skeleton3D__TYPE_NAME, 23, 23},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 52, 52},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
zed_msgs__msg__Skeleton3D__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *zed_msgs__msg__Skeleton3D__get_individual_type_description_source(NULL),
    sources[1] = *zed_msgs__msg__Keypoint3D__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
