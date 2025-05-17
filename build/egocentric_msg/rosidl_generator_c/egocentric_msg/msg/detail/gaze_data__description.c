// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from egocentric_msg:msg/GazeData.idl
// generated code does not contain a copyright notice

#include "egocentric_msg/msg/detail/gaze_data__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_egocentric_msg
const rosidl_type_hash_t *
egocentric_msg__msg__GazeData__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x53, 0x8c, 0xa5, 0x1c, 0xf9, 0x3e, 0xad, 0x1b,
      0x1c, 0xc3, 0x67, 0x7b, 0xf2, 0x2f, 0x44, 0x99,
      0x2c, 0xc4, 0x4a, 0x3f, 0x4d, 0x8f, 0x6c, 0x5e,
      0x27, 0x60, 0x2f, 0x39, 0xe0, 0xf8, 0xbe, 0xef,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char egocentric_msg__msg__GazeData__TYPE_NAME[] = "egocentric_msg/msg/GazeData";

// Define type names, field names, and default values
static char egocentric_msg__msg__GazeData__FIELD_NAME__x[] = "x";
static char egocentric_msg__msg__GazeData__FIELD_NAME__y[] = "y";
static char egocentric_msg__msg__GazeData__FIELD_NAME__worn[] = "worn";
static char egocentric_msg__msg__GazeData__FIELD_NAME__pupil_diameter_left[] = "pupil_diameter_left";
static char egocentric_msg__msg__GazeData__FIELD_NAME__eyeball_center_left_x[] = "eyeball_center_left_x";
static char egocentric_msg__msg__GazeData__FIELD_NAME__eyeball_center_left_y[] = "eyeball_center_left_y";
static char egocentric_msg__msg__GazeData__FIELD_NAME__eyeball_center_left_z[] = "eyeball_center_left_z";
static char egocentric_msg__msg__GazeData__FIELD_NAME__optical_axis_left_x[] = "optical_axis_left_x";
static char egocentric_msg__msg__GazeData__FIELD_NAME__optical_axis_left_y[] = "optical_axis_left_y";
static char egocentric_msg__msg__GazeData__FIELD_NAME__optical_axis_left_z[] = "optical_axis_left_z";
static char egocentric_msg__msg__GazeData__FIELD_NAME__pupil_diameter_right[] = "pupil_diameter_right";
static char egocentric_msg__msg__GazeData__FIELD_NAME__eyeball_center_right_x[] = "eyeball_center_right_x";
static char egocentric_msg__msg__GazeData__FIELD_NAME__eyeball_center_right_y[] = "eyeball_center_right_y";
static char egocentric_msg__msg__GazeData__FIELD_NAME__eyeball_center_right_z[] = "eyeball_center_right_z";
static char egocentric_msg__msg__GazeData__FIELD_NAME__optical_axis_right_x[] = "optical_axis_right_x";
static char egocentric_msg__msg__GazeData__FIELD_NAME__optical_axis_right_y[] = "optical_axis_right_y";
static char egocentric_msg__msg__GazeData__FIELD_NAME__optical_axis_right_z[] = "optical_axis_right_z";
static char egocentric_msg__msg__GazeData__FIELD_NAME__timestamp_unix_seconds[] = "timestamp_unix_seconds";

static rosidl_runtime_c__type_description__Field egocentric_msg__msg__GazeData__FIELDS[] = {
  {
    {egocentric_msg__msg__GazeData__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {egocentric_msg__msg__GazeData__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {egocentric_msg__msg__GazeData__FIELD_NAME__worn, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {egocentric_msg__msg__GazeData__FIELD_NAME__pupil_diameter_left, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {egocentric_msg__msg__GazeData__FIELD_NAME__eyeball_center_left_x, 21, 21},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {egocentric_msg__msg__GazeData__FIELD_NAME__eyeball_center_left_y, 21, 21},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {egocentric_msg__msg__GazeData__FIELD_NAME__eyeball_center_left_z, 21, 21},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {egocentric_msg__msg__GazeData__FIELD_NAME__optical_axis_left_x, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {egocentric_msg__msg__GazeData__FIELD_NAME__optical_axis_left_y, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {egocentric_msg__msg__GazeData__FIELD_NAME__optical_axis_left_z, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {egocentric_msg__msg__GazeData__FIELD_NAME__pupil_diameter_right, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {egocentric_msg__msg__GazeData__FIELD_NAME__eyeball_center_right_x, 22, 22},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {egocentric_msg__msg__GazeData__FIELD_NAME__eyeball_center_right_y, 22, 22},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {egocentric_msg__msg__GazeData__FIELD_NAME__eyeball_center_right_z, 22, 22},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {egocentric_msg__msg__GazeData__FIELD_NAME__optical_axis_right_x, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {egocentric_msg__msg__GazeData__FIELD_NAME__optical_axis_right_y, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {egocentric_msg__msg__GazeData__FIELD_NAME__optical_axis_right_z, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {egocentric_msg__msg__GazeData__FIELD_NAME__timestamp_unix_seconds, 22, 22},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
egocentric_msg__msg__GazeData__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {egocentric_msg__msg__GazeData__TYPE_NAME, 27, 27},
      {egocentric_msg__msg__GazeData__FIELDS, 18, 18},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 x\n"
  "float32 y\n"
  "bool worn\n"
  "float32 pupil_diameter_left\n"
  "float32 eyeball_center_left_x\n"
  "float32 eyeball_center_left_y\n"
  "float32 eyeball_center_left_z\n"
  "float32 optical_axis_left_x\n"
  "float32 optical_axis_left_y\n"
  "float32 optical_axis_left_z\n"
  "float32 pupil_diameter_right\n"
  "float32 eyeball_center_right_x\n"
  "float32 eyeball_center_right_y\n"
  "float32 eyeball_center_right_z\n"
  "float32 optical_axis_right_x\n"
  "float32 optical_axis_right_y\n"
  "float32 optical_axis_right_z\n"
  "float32 timestamp_unix_seconds\n"
  "";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
egocentric_msg__msg__GazeData__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {egocentric_msg__msg__GazeData__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 473, 473},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
egocentric_msg__msg__GazeData__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *egocentric_msg__msg__GazeData__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
