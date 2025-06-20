// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from zed_msgs:msg/Object.idl
// generated code does not contain a copyright notice

#include "zed_msgs/msg/detail/object__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_zed_msgs
const rosidl_type_hash_t *
zed_msgs__msg__Object__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa1, 0x5a, 0xf0, 0x06, 0x6d, 0xad, 0xda, 0x82,
      0x48, 0x44, 0xd9, 0x89, 0x6e, 0xbb, 0x9d, 0x33,
      0xc8, 0x7a, 0x07, 0x26, 0xca, 0x17, 0x4a, 0xcd,
      0xba, 0xe4, 0xbc, 0xec, 0x57, 0xa1, 0xab, 0x03,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "zed_msgs/msg/detail/bounding_box3_d__functions.h"
#include "zed_msgs/msg/detail/skeleton3_d__functions.h"
#include "zed_msgs/msg/detail/bounding_box2_df__functions.h"
#include "zed_msgs/msg/detail/bounding_box2_di__functions.h"
#include "zed_msgs/msg/detail/skeleton2_d__functions.h"
#include "zed_msgs/msg/detail/keypoint2_di__functions.h"
#include "zed_msgs/msg/detail/keypoint2_df__functions.h"
#include "zed_msgs/msg/detail/keypoint3_d__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
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

static char zed_msgs__msg__Object__TYPE_NAME[] = "zed_msgs/msg/Object";
static char zed_msgs__msg__BoundingBox2Df__TYPE_NAME[] = "zed_msgs/msg/BoundingBox2Df";
static char zed_msgs__msg__BoundingBox2Di__TYPE_NAME[] = "zed_msgs/msg/BoundingBox2Di";
static char zed_msgs__msg__BoundingBox3D__TYPE_NAME[] = "zed_msgs/msg/BoundingBox3D";
static char zed_msgs__msg__Keypoint2Df__TYPE_NAME[] = "zed_msgs/msg/Keypoint2Df";
static char zed_msgs__msg__Keypoint2Di__TYPE_NAME[] = "zed_msgs/msg/Keypoint2Di";
static char zed_msgs__msg__Keypoint3D__TYPE_NAME[] = "zed_msgs/msg/Keypoint3D";
static char zed_msgs__msg__Skeleton2D__TYPE_NAME[] = "zed_msgs/msg/Skeleton2D";
static char zed_msgs__msg__Skeleton3D__TYPE_NAME[] = "zed_msgs/msg/Skeleton3D";

// Define type names, field names, and default values
static char zed_msgs__msg__Object__FIELD_NAME__label[] = "label";
static char zed_msgs__msg__Object__FIELD_NAME__label_id[] = "label_id";
static char zed_msgs__msg__Object__FIELD_NAME__sublabel[] = "sublabel";
static char zed_msgs__msg__Object__FIELD_NAME__confidence[] = "confidence";
static char zed_msgs__msg__Object__FIELD_NAME__position[] = "position";
static char zed_msgs__msg__Object__FIELD_NAME__position_covariance[] = "position_covariance";
static char zed_msgs__msg__Object__FIELD_NAME__velocity[] = "velocity";
static char zed_msgs__msg__Object__FIELD_NAME__tracking_available[] = "tracking_available";
static char zed_msgs__msg__Object__FIELD_NAME__tracking_state[] = "tracking_state";
static char zed_msgs__msg__Object__FIELD_NAME__action_state[] = "action_state";
static char zed_msgs__msg__Object__FIELD_NAME__bounding_box_2d[] = "bounding_box_2d";
static char zed_msgs__msg__Object__FIELD_NAME__bounding_box_3d[] = "bounding_box_3d";
static char zed_msgs__msg__Object__FIELD_NAME__dimensions_3d[] = "dimensions_3d";
static char zed_msgs__msg__Object__FIELD_NAME__skeleton_available[] = "skeleton_available";
static char zed_msgs__msg__Object__FIELD_NAME__body_format[] = "body_format";
static char zed_msgs__msg__Object__FIELD_NAME__head_bounding_box_2d[] = "head_bounding_box_2d";
static char zed_msgs__msg__Object__FIELD_NAME__head_bounding_box_3d[] = "head_bounding_box_3d";
static char zed_msgs__msg__Object__FIELD_NAME__head_position[] = "head_position";
static char zed_msgs__msg__Object__FIELD_NAME__skeleton_2d[] = "skeleton_2d";
static char zed_msgs__msg__Object__FIELD_NAME__skeleton_3d[] = "skeleton_3d";

static rosidl_runtime_c__type_description__Field zed_msgs__msg__Object__FIELDS[] = {
  {
    {zed_msgs__msg__Object__FIELD_NAME__label, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Object__FIELD_NAME__label_id, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Object__FIELD_NAME__sublabel, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Object__FIELD_NAME__confidence, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Object__FIELD_NAME__position, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Object__FIELD_NAME__position_covariance, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      6,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Object__FIELD_NAME__velocity, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Object__FIELD_NAME__tracking_available, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Object__FIELD_NAME__tracking_state, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Object__FIELD_NAME__action_state, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Object__FIELD_NAME__bounding_box_2d, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {zed_msgs__msg__BoundingBox2Di__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Object__FIELD_NAME__bounding_box_3d, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {zed_msgs__msg__BoundingBox3D__TYPE_NAME, 26, 26},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Object__FIELD_NAME__dimensions_3d, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Object__FIELD_NAME__skeleton_available, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Object__FIELD_NAME__body_format, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Object__FIELD_NAME__head_bounding_box_2d, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {zed_msgs__msg__BoundingBox2Df__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Object__FIELD_NAME__head_bounding_box_3d, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {zed_msgs__msg__BoundingBox3D__TYPE_NAME, 26, 26},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Object__FIELD_NAME__head_position, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Object__FIELD_NAME__skeleton_2d, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {zed_msgs__msg__Skeleton2D__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Object__FIELD_NAME__skeleton_3d, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {zed_msgs__msg__Skeleton3D__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription zed_msgs__msg__Object__REFERENCED_TYPE_DESCRIPTIONS[] = {
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
    {zed_msgs__msg__Skeleton2D__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Skeleton3D__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
zed_msgs__msg__Object__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {zed_msgs__msg__Object__TYPE_NAME, 19, 19},
      {zed_msgs__msg__Object__FIELDS, 20, 20},
    },
    {zed_msgs__msg__Object__REFERENCED_TYPE_DESCRIPTIONS, 8, 8},
  };
  if (!constructed) {
    assert(0 == memcmp(&zed_msgs__msg__BoundingBox2Df__EXPECTED_HASH, zed_msgs__msg__BoundingBox2Df__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = zed_msgs__msg__BoundingBox2Df__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&zed_msgs__msg__BoundingBox2Di__EXPECTED_HASH, zed_msgs__msg__BoundingBox2Di__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = zed_msgs__msg__BoundingBox2Di__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&zed_msgs__msg__BoundingBox3D__EXPECTED_HASH, zed_msgs__msg__BoundingBox3D__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = zed_msgs__msg__BoundingBox3D__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&zed_msgs__msg__Keypoint2Df__EXPECTED_HASH, zed_msgs__msg__Keypoint2Df__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = zed_msgs__msg__Keypoint2Df__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&zed_msgs__msg__Keypoint2Di__EXPECTED_HASH, zed_msgs__msg__Keypoint2Di__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = zed_msgs__msg__Keypoint2Di__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&zed_msgs__msg__Keypoint3D__EXPECTED_HASH, zed_msgs__msg__Keypoint3D__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = zed_msgs__msg__Keypoint3D__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&zed_msgs__msg__Skeleton2D__EXPECTED_HASH, zed_msgs__msg__Skeleton2D__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[6].fields = zed_msgs__msg__Skeleton2D__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&zed_msgs__msg__Skeleton3D__EXPECTED_HASH, zed_msgs__msg__Skeleton3D__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[7].fields = zed_msgs__msg__Skeleton3D__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Object label\n"
  "string label\n"
  "\n"
  "# Object label ID\n"
  "int16 label_id\n"
  "\n"
  "# Object sub\n"
  "string sublabel\n"
  "\n"
  "# Object confidence level (1-99)\n"
  "float32 confidence\n"
  "\n"
  "# Object centroid position\n"
  "float32[3] position\n"
  "\n"
  "# Position covariance\n"
  "float32[6] position_covariance\n"
  "\n"
  "# Object velocity\n"
  "float32[3] velocity\n"
  "\n"
  "bool tracking_available\n"
  "\n"
  "# Tracking available\n"
  "# Tracking state\n"
  "# 0 -> OFF (object not valid)\n"
  "# 1 -> OK\n"
  "# 2 -> SEARCHING (occlusion occurred, trajectory is estimated)\n"
  "# 3 -> TERMINATE (This is the last searching state of the track. The track will be deleted in the next frame).\n"
  "int8 tracking_state\n"
  "\n"
  "# Action state\n"
  "# 0 -> IDLE\n"
  "# 2 -> MOVING\n"
  "int8 action_state\n"
  "\n"
  "# 2D Bounding box projected to the Camera image\n"
  "zed_msgs/BoundingBox2Di bounding_box_2d\n"
  "\n"
  "# 3D Bounding box in world frame\n"
  "zed_msgs/BoundingBox3D bounding_box_3d\n"
  "\n"
  "# 3D dimensions (width, height, lenght)\n"
  "float32[3] dimensions_3d\n"
  "\n"
  "# Is skeleton available?\n"
  "bool skeleton_available\n"
  "\n"
  "# Skeleton format\n"
  "# 0 -> POSE_18\n"
  "# 1 -> POSE_34\n"
  "# 2 -> POSE_38\n"
  "# 3 -> POSE_70\n"
  "int8 body_format\n"
  "\n"
  "# 2D Bounding box projected to Camera image of the person head\n"
  "zed_msgs/BoundingBox2Df head_bounding_box_2d\n"
  "\n"
  "# 3D Bounding box in world frame of the person head\n"
  "zed_msgs/BoundingBox3D head_bounding_box_3d\n"
  "\n"
  "# 3D position of the centroid of the person head\n"
  "float32[3] head_position\n"
  "\n"
  "# 2D Person skeleton projected to Camera image\n"
  "zed_msgs/Skeleton2D skeleton_2d\n"
  "\n"
  "# 3D Person skeleton in world frame\n"
  "zed_msgs/Skeleton3D skeleton_3d";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
zed_msgs__msg__Object__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {zed_msgs__msg__Object__TYPE_NAME, 19, 19},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 1448, 1448},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
zed_msgs__msg__Object__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[9];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 9, 9};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *zed_msgs__msg__Object__get_individual_type_description_source(NULL),
    sources[1] = *zed_msgs__msg__BoundingBox2Df__get_individual_type_description_source(NULL);
    sources[2] = *zed_msgs__msg__BoundingBox2Di__get_individual_type_description_source(NULL);
    sources[3] = *zed_msgs__msg__BoundingBox3D__get_individual_type_description_source(NULL);
    sources[4] = *zed_msgs__msg__Keypoint2Df__get_individual_type_description_source(NULL);
    sources[5] = *zed_msgs__msg__Keypoint2Di__get_individual_type_description_source(NULL);
    sources[6] = *zed_msgs__msg__Keypoint3D__get_individual_type_description_source(NULL);
    sources[7] = *zed_msgs__msg__Skeleton2D__get_individual_type_description_source(NULL);
    sources[8] = *zed_msgs__msg__Skeleton3D__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
