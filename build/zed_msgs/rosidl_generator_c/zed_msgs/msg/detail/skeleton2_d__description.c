// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from zed_msgs:msg/Skeleton2D.idl
// generated code does not contain a copyright notice

#include "zed_msgs/msg/detail/skeleton2_d__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_zed_msgs
const rosidl_type_hash_t *
zed_msgs__msg__Skeleton2D__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x82, 0x31, 0xda, 0x5f, 0x0a, 0x74, 0xd2, 0x69,
      0x0c, 0x50, 0x95, 0xed, 0x5b, 0x91, 0x3e, 0x3a,
      0x57, 0x79, 0xe3, 0x28, 0x56, 0xd5, 0x73, 0x7e,
      0xd8, 0xe3, 0xd0, 0x27, 0xc3, 0x2c, 0xb3, 0x6a,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "zed_msgs/msg/detail/keypoint2_df__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t zed_msgs__msg__Keypoint2Df__EXPECTED_HASH = {1, {
    0xf3, 0xcd, 0xe2, 0xac, 0xac, 0x57, 0x5a, 0x10,
    0xc3, 0x84, 0x1e, 0x2d, 0x98, 0xba, 0x51, 0xcd,
    0x09, 0x60, 0x48, 0xd0, 0x9b, 0xf7, 0x24, 0x0f,
    0x71, 0x35, 0x6a, 0x72, 0x0e, 0xcf, 0xc0, 0x37,
  }};
#endif

static char zed_msgs__msg__Skeleton2D__TYPE_NAME[] = "zed_msgs/msg/Skeleton2D";
static char zed_msgs__msg__Keypoint2Df__TYPE_NAME[] = "zed_msgs/msg/Keypoint2Df";

// Define type names, field names, and default values
static char zed_msgs__msg__Skeleton2D__FIELD_NAME__keypoints[] = "keypoints";

static rosidl_runtime_c__type_description__Field zed_msgs__msg__Skeleton2D__FIELDS[] = {
  {
    {zed_msgs__msg__Skeleton2D__FIELD_NAME__keypoints, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_ARRAY,
      70,
      0,
      {zed_msgs__msg__Keypoint2Df__TYPE_NAME, 24, 24},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription zed_msgs__msg__Skeleton2D__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {zed_msgs__msg__Keypoint2Df__TYPE_NAME, 24, 24},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
zed_msgs__msg__Skeleton2D__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {zed_msgs__msg__Skeleton2D__TYPE_NAME, 23, 23},
      {zed_msgs__msg__Skeleton2D__FIELDS, 1, 1},
    },
    {zed_msgs__msg__Skeleton2D__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&zed_msgs__msg__Keypoint2Df__EXPECTED_HASH, zed_msgs__msg__Keypoint2Df__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = zed_msgs__msg__Keypoint2Df__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Skeleton joints\n"
  "zed_msgs/Keypoint2Df[70] keypoints";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
zed_msgs__msg__Skeleton2D__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {zed_msgs__msg__Skeleton2D__TYPE_NAME, 23, 23},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 53, 53},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
zed_msgs__msg__Skeleton2D__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *zed_msgs__msg__Skeleton2D__get_individual_type_description_source(NULL),
    sources[1] = *zed_msgs__msg__Keypoint2Df__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
