// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from zed_msgs:msg/ObjectsStamped.idl
// generated code does not contain a copyright notice

#include "zed_msgs/msg/detail/objects_stamped__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_zed_msgs
const rosidl_type_hash_t *
zed_msgs__msg__ObjectsStamped__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x09, 0x45, 0x16, 0x0e, 0xf0, 0x44, 0xaa, 0x44,
      0xb8, 0x6c, 0x8b, 0x0e, 0x5a, 0xe4, 0xed, 0x5a,
      0x88, 0x23, 0x25, 0x9e, 0xaf, 0xb3, 0x7d, 0x67,
      0xe9, 0x80, 0x9e, 0xfd, 0x58, 0x9d, 0x39, 0x52,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "zed_msgs/msg/detail/bounding_box3_d__functions.h"
#include "zed_msgs/msg/detail/skeleton3_d__functions.h"
#include "zed_msgs/msg/detail/keypoint2_di__functions.h"
#include "zed_msgs/msg/detail/bounding_box2_di__functions.h"
#include "std_msgs/msg/detail/header__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "zed_msgs/msg/detail/object__functions.h"
#include "zed_msgs/msg/detail/skeleton2_d__functions.h"
#include "zed_msgs/msg/detail/bounding_box2_df__functions.h"
#include "zed_msgs/msg/detail/keypoint2_df__functions.h"
#include "zed_msgs/msg/detail/keypoint3_d__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
static const rosidl_type_hash_t zed_msgs__msg__BoundingBox2Df__EXPECTED_HASH = {1, {
    0x56, 0x34, 0x8c, 0xd4, 0x1a, 0x63, 0xa6, 0x81,
    0x52, 0x33, 0x19, 0x51, 0x9a, 0x2d, 0x7a, 0x02,
    0x41, 0xc3, 0x96, 0xe1, 0xef, 0x8f, 0xec, 0x82,
    0x41, 0xfb, 0x17, 0xa4, 0xc2, 0x12, 0x93, 0xd9,
  }};
static const rosidl_type_hash_t zed_msgs__msg__BoundingBox2Di__EXPECTED_HASH = {1, {
    0x14, 0xd9, 0xbb, 0x2e, 0xf4, 0x2e, 0xdf, 0xe4,
    0x53, 0x29, 0xd1, 0x60, 0xbf, 0x82, 0x90, 0x9d,
    0x2d, 0xb8, 0x12, 0xf2, 0x0e, 0x71, 0xe1, 0x14,
    0xb4, 0x08, 0xa3, 0x64, 0x7b, 0x2c, 0x9d, 0x70,
  }};
static const rosidl_type_hash_t zed_msgs__msg__BoundingBox3D__EXPECTED_HASH = {1, {
    0xe1, 0xd7, 0xaa, 0xd1, 0xe5, 0xf1, 0x1b, 0xc9,
    0x85, 0xb8, 0xe5, 0x3d, 0x90, 0x6e, 0xe4, 0x2e,
    0x83, 0x14, 0x65, 0xcf, 0x09, 0x3f, 0x5f, 0x1d,
    0x3e, 0xd6, 0x44, 0x19, 0xa4, 0xeb, 0x03, 0xed,
  }};
static const rosidl_type_hash_t zed_msgs__msg__Keypoint2Df__EXPECTED_HASH = {1, {
    0xf3, 0xcd, 0xe2, 0xac, 0xac, 0x57, 0x5a, 0x10,
    0xc3, 0x84, 0x1e, 0x2d, 0x98, 0xba, 0x51, 0xcd,
    0x09, 0x60, 0x48, 0xd0, 0x9b, 0xf7, 0x24, 0x0f,
    0x71, 0x35, 0x6a, 0x72, 0x0e, 0xcf, 0xc0, 0x37,
  }};
static const rosidl_type_hash_t zed_msgs__msg__Keypoint2Di__EXPECTED_HASH = {1, {
    0x96, 0x40, 0xce, 0x7b, 0x25, 0x47, 0xa1, 0x38,
    0x2a, 0x21, 0xb8, 0xcc, 0x0c, 0xda, 0x86, 0x00,
    0xe1, 0x9b, 0x04, 0x1f, 0xca, 0x43, 0xd8, 0x12,
    0x8c, 0xbc, 0x24, 0xe3, 0x2c, 0xc8, 0x09, 0x82,
  }};
static const rosidl_type_hash_t zed_msgs__msg__Keypoint3D__EXPECTED_HASH = {1, {
    0x83, 0x8f, 0x35, 0xf5, 0xca, 0x29, 0x6b, 0xa0,
    0xbe, 0x86, 0x86, 0x7a, 0x75, 0x9b, 0x9d, 0x64,
    0x49, 0xe5, 0x5e, 0xd6, 0xec, 0x3e, 0xaa, 0x7d,
    0x2f, 0x7a, 0x26, 0x11, 0x03, 0xc2, 0x3f, 0xd1,
  }};
static const rosidl_type_hash_t zed_msgs__msg__Object__EXPECTED_HASH = {1, {
    0xa1, 0x5a, 0xf0, 0x06, 0x6d, 0xad, 0xda, 0x82,
    0x48, 0x44, 0xd9, 0x89, 0x6e, 0xbb, 0x9d, 0x33,
    0xc8, 0x7a, 0x07, 0x26, 0xca, 0x17, 0x4a, 0xcd,
    0xba, 0xe4, 0xbc, 0xec, 0x57, 0xa1, 0xab, 0x03,
  }};
static const rosidl_type_hash_t zed_msgs__msg__Skeleton2D__EXPECTED_HASH = {1, {
    0x82, 0x31, 0xda, 0x5f, 0x0a, 0x74, 0xd2, 0x69,
    0x0c, 0x50, 0x95, 0xed, 0x5b, 0x91, 0x3e, 0x3a,
    0x57, 0x79, 0xe3, 0x28, 0x56, 0xd5, 0x73, 0x7e,
    0xd8, 0xe3, 0xd0, 0x27, 0xc3, 0x2c, 0xb3, 0x6a,
  }};
static const rosidl_type_hash_t zed_msgs__msg__Skeleton3D__EXPECTED_HASH = {1, {
    0xe7, 0x62, 0x79, 0x8d, 0x06, 0x7f, 0x7d, 0x68,
    0x1f, 0xde, 0xe2, 0x59, 0xaa, 0x75, 0xe2, 0x8f,
    0x0f, 0xc6, 0xeb, 0x36, 0xda, 0xd1, 0x3e, 0x4e,
    0xdd, 0xec, 0x89, 0xc7, 0xd8, 0xbd, 0x6b, 0x54,
  }};
#endif

static char zed_msgs__msg__ObjectsStamped__TYPE_NAME[] = "zed_msgs/msg/ObjectsStamped";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";
static char zed_msgs__msg__BoundingBox2Df__TYPE_NAME[] = "zed_msgs/msg/BoundingBox2Df";
static char zed_msgs__msg__BoundingBox2Di__TYPE_NAME[] = "zed_msgs/msg/BoundingBox2Di";
static char zed_msgs__msg__BoundingBox3D__TYPE_NAME[] = "zed_msgs/msg/BoundingBox3D";
static char zed_msgs__msg__Keypoint2Df__TYPE_NAME[] = "zed_msgs/msg/Keypoint2Df";
static char zed_msgs__msg__Keypoint2Di__TYPE_NAME[] = "zed_msgs/msg/Keypoint2Di";
static char zed_msgs__msg__Keypoint3D__TYPE_NAME[] = "zed_msgs/msg/Keypoint3D";
static char zed_msgs__msg__Object__TYPE_NAME[] = "zed_msgs/msg/Object";
static char zed_msgs__msg__Skeleton2D__TYPE_NAME[] = "zed_msgs/msg/Skeleton2D";
static char zed_msgs__msg__Skeleton3D__TYPE_NAME[] = "zed_msgs/msg/Skeleton3D";

// Define type names, field names, and default values
static char zed_msgs__msg__ObjectsStamped__FIELD_NAME__header[] = "header";
static char zed_msgs__msg__ObjectsStamped__FIELD_NAME__objects[] = "objects";

static rosidl_runtime_c__type_description__Field zed_msgs__msg__ObjectsStamped__FIELDS[] = {
  {
    {zed_msgs__msg__ObjectsStamped__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__ObjectsStamped__FIELD_NAME__objects, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {zed_msgs__msg__Object__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription zed_msgs__msg__ObjectsStamped__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__BoundingBox2Df__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__BoundingBox2Di__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__BoundingBox3D__TYPE_NAME, 26, 26},
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Keypoint2Df__TYPE_NAME, 24, 24},
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Keypoint2Di__TYPE_NAME, 24, 24},
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Keypoint3D__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Object__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Skeleton2D__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Skeleton3D__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
zed_msgs__msg__ObjectsStamped__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {zed_msgs__msg__ObjectsStamped__TYPE_NAME, 27, 27},
      {zed_msgs__msg__ObjectsStamped__FIELDS, 2, 2},
    },
    {zed_msgs__msg__ObjectsStamped__REFERENCED_TYPE_DESCRIPTIONS, 11, 11},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&zed_msgs__msg__BoundingBox2Df__EXPECTED_HASH, zed_msgs__msg__BoundingBox2Df__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = zed_msgs__msg__BoundingBox2Df__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&zed_msgs__msg__BoundingBox2Di__EXPECTED_HASH, zed_msgs__msg__BoundingBox2Di__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = zed_msgs__msg__BoundingBox2Di__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&zed_msgs__msg__BoundingBox3D__EXPECTED_HASH, zed_msgs__msg__BoundingBox3D__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = zed_msgs__msg__BoundingBox3D__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&zed_msgs__msg__Keypoint2Df__EXPECTED_HASH, zed_msgs__msg__Keypoint2Df__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = zed_msgs__msg__Keypoint2Df__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&zed_msgs__msg__Keypoint2Di__EXPECTED_HASH, zed_msgs__msg__Keypoint2Di__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[6].fields = zed_msgs__msg__Keypoint2Di__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&zed_msgs__msg__Keypoint3D__EXPECTED_HASH, zed_msgs__msg__Keypoint3D__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[7].fields = zed_msgs__msg__Keypoint3D__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&zed_msgs__msg__Object__EXPECTED_HASH, zed_msgs__msg__Object__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[8].fields = zed_msgs__msg__Object__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&zed_msgs__msg__Skeleton2D__EXPECTED_HASH, zed_msgs__msg__Skeleton2D__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[9].fields = zed_msgs__msg__Skeleton2D__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&zed_msgs__msg__Skeleton3D__EXPECTED_HASH, zed_msgs__msg__Skeleton3D__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[10].fields = zed_msgs__msg__Skeleton3D__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Standard Header\n"
  "std_msgs/Header header\n"
  "\n"
  "# Array of `object_stamped` topics\n"
  "zed_msgs/Object[] objects";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
zed_msgs__msg__ObjectsStamped__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {zed_msgs__msg__ObjectsStamped__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 103, 103},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
zed_msgs__msg__ObjectsStamped__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[12];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 12, 12};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *zed_msgs__msg__ObjectsStamped__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    sources[3] = *zed_msgs__msg__BoundingBox2Df__get_individual_type_description_source(NULL);
    sources[4] = *zed_msgs__msg__BoundingBox2Di__get_individual_type_description_source(NULL);
    sources[5] = *zed_msgs__msg__BoundingBox3D__get_individual_type_description_source(NULL);
    sources[6] = *zed_msgs__msg__Keypoint2Df__get_individual_type_description_source(NULL);
    sources[7] = *zed_msgs__msg__Keypoint2Di__get_individual_type_description_source(NULL);
    sources[8] = *zed_msgs__msg__Keypoint3D__get_individual_type_description_source(NULL);
    sources[9] = *zed_msgs__msg__Object__get_individual_type_description_source(NULL);
    sources[10] = *zed_msgs__msg__Skeleton2D__get_individual_type_description_source(NULL);
    sources[11] = *zed_msgs__msg__Skeleton3D__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
