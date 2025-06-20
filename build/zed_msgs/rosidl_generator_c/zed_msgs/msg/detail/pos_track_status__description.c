// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from zed_msgs:msg/PosTrackStatus.idl
// generated code does not contain a copyright notice

#include "zed_msgs/msg/detail/pos_track_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_zed_msgs
const rosidl_type_hash_t *
zed_msgs__msg__PosTrackStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xfa, 0x5b, 0x99, 0x0d, 0xea, 0x86, 0xae, 0xea,
      0x12, 0xa6, 0x45, 0xcd, 0xb4, 0x80, 0x74, 0x30,
      0x2d, 0x9d, 0x55, 0x25, 0xf5, 0x5e, 0x07, 0xf4,
      0x85, 0x11, 0xfb, 0x62, 0xb6, 0x9d, 0x8e, 0x17,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char zed_msgs__msg__PosTrackStatus__TYPE_NAME[] = "zed_msgs/msg/PosTrackStatus";

// Define type names, field names, and default values
static char zed_msgs__msg__PosTrackStatus__FIELD_NAME__odometry_status[] = "odometry_status";
static char zed_msgs__msg__PosTrackStatus__FIELD_NAME__spatial_memory_status[] = "spatial_memory_status";
static char zed_msgs__msg__PosTrackStatus__FIELD_NAME__status[] = "status";

static rosidl_runtime_c__type_description__Field zed_msgs__msg__PosTrackStatus__FIELDS[] = {
  {
    {zed_msgs__msg__PosTrackStatus__FIELD_NAME__odometry_status, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__PosTrackStatus__FIELD_NAME__spatial_memory_status, 21, 21},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__PosTrackStatus__FIELD_NAME__status, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
zed_msgs__msg__PosTrackStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {zed_msgs__msg__PosTrackStatus__TYPE_NAME, 27, 27},
      {zed_msgs__msg__PosTrackStatus__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# CONSTANTS\n"
  "uint8 OK = 0\n"
  "uint8 UNAVAILABLE = 1\n"
  "uint8 LOOP_CLOSED = 1\n"
  "uint8 SEARCHING = 2\n"
  "uint8 OFF = 3\n"
  "\n"
  "# VISUAL_STATUS\n"
  "# Represents the current state of Visual-Inertial Odometry (VIO) tracking between the previous frame and the current frame.\n"
  "# OK  - The positional tracking module successfully tracked from the previous frame to the current frame.\n"
  "# NOT_OK - The positional tracking module failed to track from the previous frame to the current frame.\n"
  "uint8 odometry_status\n"
  "\n"
  "# SPATIAL_MEMORY_STATUS\n"
  "# Represents the current state of camera tracking in the global map.\n"
  "# OK - The positional tracking module is operating normally.\n"
  "# LOOP_CLOSED - The positional tracking module detected a loop and corrected its position.\n"
  "# SEARCHING - The positional tracking module is searching for recognizable areas in the global map to relocate.\n"
  "# OFF - Spatial memory is disabled\n"
  "uint8 spatial_memory_status\n"
  "\n"
  "# Deprecated\n"
  "uint8 status";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
zed_msgs__msg__PosTrackStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {zed_msgs__msg__PosTrackStatus__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 924, 924},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
zed_msgs__msg__PosTrackStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *zed_msgs__msg__PosTrackStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
