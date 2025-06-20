// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from zed_msgs:msg/BoundingBox2Di.idl
// generated code does not contain a copyright notice

#include "zed_msgs/msg/detail/bounding_box2_di__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_zed_msgs
const rosidl_type_hash_t *
zed_msgs__msg__BoundingBox2Di__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x14, 0xd9, 0xbb, 0x2e, 0xf4, 0x2e, 0xdf, 0xe4,
      0x53, 0x29, 0xd1, 0x60, 0xbf, 0x82, 0x90, 0x9d,
      0x2d, 0xb8, 0x12, 0xf2, 0x0e, 0x71, 0xe1, 0x14,
      0xb4, 0x08, 0xa3, 0x64, 0x7b, 0x2c, 0x9d, 0x70,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "zed_msgs/msg/detail/keypoint2_di__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t zed_msgs__msg__Keypoint2Di__EXPECTED_HASH = {1, {
    0x96, 0x40, 0xce, 0x7b, 0x25, 0x47, 0xa1, 0x38,
    0x2a, 0x21, 0xb8, 0xcc, 0x0c, 0xda, 0x86, 0x00,
    0xe1, 0x9b, 0x04, 0x1f, 0xca, 0x43, 0xd8, 0x12,
    0x8c, 0xbc, 0x24, 0xe3, 0x2c, 0xc8, 0x09, 0x82,
  }};
#endif

static char zed_msgs__msg__BoundingBox2Di__TYPE_NAME[] = "zed_msgs/msg/BoundingBox2Di";
static char zed_msgs__msg__Keypoint2Di__TYPE_NAME[] = "zed_msgs/msg/Keypoint2Di";

// Define type names, field names, and default values
static char zed_msgs__msg__BoundingBox2Di__FIELD_NAME__corners[] = "corners";

static rosidl_runtime_c__type_description__Field zed_msgs__msg__BoundingBox2Di__FIELDS[] = {
  {
    {zed_msgs__msg__BoundingBox2Di__FIELD_NAME__corners, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_ARRAY,
      4,
      0,
      {zed_msgs__msg__Keypoint2Di__TYPE_NAME, 24, 24},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription zed_msgs__msg__BoundingBox2Di__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {zed_msgs__msg__Keypoint2Di__TYPE_NAME, 24, 24},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
zed_msgs__msg__BoundingBox2Di__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {zed_msgs__msg__BoundingBox2Di__TYPE_NAME, 27, 27},
      {zed_msgs__msg__BoundingBox2Di__FIELDS, 1, 1},
    },
    {zed_msgs__msg__BoundingBox2Di__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&zed_msgs__msg__Keypoint2Di__EXPECTED_HASH, zed_msgs__msg__Keypoint2Di__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = zed_msgs__msg__Keypoint2Di__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "#      0 ------- 1\n"
  "#      |         |\n"
  "#      |         |\n"
  "#      |         |\n"
  "#      3 ------- 2\n"
  "zed_msgs/Keypoint2Di[4] corners";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
zed_msgs__msg__BoundingBox2Di__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {zed_msgs__msg__BoundingBox2Di__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 127, 127},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
zed_msgs__msg__BoundingBox2Di__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *zed_msgs__msg__BoundingBox2Di__get_individual_type_description_source(NULL),
    sources[1] = *zed_msgs__msg__Keypoint2Di__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
