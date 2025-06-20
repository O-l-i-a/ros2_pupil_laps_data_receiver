// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from zed_msgs:msg/SvoStatus.idl
// generated code does not contain a copyright notice

#include "zed_msgs/msg/detail/svo_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_zed_msgs
const rosidl_type_hash_t *
zed_msgs__msg__SvoStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x07, 0x6e, 0x2e, 0xb1, 0x2b, 0xc4, 0xd1, 0x78,
      0xd2, 0xc8, 0xe6, 0x24, 0x05, 0xb8, 0x70, 0x73,
      0x63, 0xf4, 0xcb, 0x81, 0x49, 0x25, 0x56, 0x2e,
      0x2b, 0x17, 0xba, 0x87, 0x73, 0xd4, 0x33, 0xda,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char zed_msgs__msg__SvoStatus__TYPE_NAME[] = "zed_msgs/msg/SvoStatus";

// Define type names, field names, and default values
static char zed_msgs__msg__SvoStatus__FIELD_NAME__file_name[] = "file_name";
static char zed_msgs__msg__SvoStatus__FIELD_NAME__status[] = "status";
static char zed_msgs__msg__SvoStatus__FIELD_NAME__frame_ts[] = "frame_ts";
static char zed_msgs__msg__SvoStatus__FIELD_NAME__frame_id[] = "frame_id";
static char zed_msgs__msg__SvoStatus__FIELD_NAME__total_frames[] = "total_frames";
static char zed_msgs__msg__SvoStatus__FIELD_NAME__loop_active[] = "loop_active";
static char zed_msgs__msg__SvoStatus__FIELD_NAME__loop_count[] = "loop_count";
static char zed_msgs__msg__SvoStatus__FIELD_NAME__real_time_mode[] = "real_time_mode";

static rosidl_runtime_c__type_description__Field zed_msgs__msg__SvoStatus__FIELDS[] = {
  {
    {zed_msgs__msg__SvoStatus__FIELD_NAME__file_name, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__SvoStatus__FIELD_NAME__status, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__SvoStatus__FIELD_NAME__frame_ts, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__SvoStatus__FIELD_NAME__frame_id, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__SvoStatus__FIELD_NAME__total_frames, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__SvoStatus__FIELD_NAME__loop_active, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__SvoStatus__FIELD_NAME__loop_count, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__SvoStatus__FIELD_NAME__real_time_mode, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
zed_msgs__msg__SvoStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {zed_msgs__msg__SvoStatus__TYPE_NAME, 22, 22},
      {zed_msgs__msg__SvoStatus__FIELDS, 8, 8},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Message to provide information concerning the status of the SVO playback\n"
  "\n"
  "# SVO File name\n"
  "string file_name\n"
  "\n"
  "# SVO playback status\n"
  "uint8 status\n"
  "\n"
  "# SVO playback status constants\n"
  "uint8 STATUS_PLAYING=0\n"
  "uint8 STATUS_PAUSED=1\n"
  "uint8 STATUS_END=2\n"
  "\n"
  "# SVO frame timestamp\n"
  "uint64 frame_ts\n"
  "\n"
  "# SVO playback position\n"
  "uint32 frame_id\n"
  "\n"
  "# SVO total number of frames\n"
  "uint32 total_frames\n"
  "\n"
  "# SVO loop status\n"
  "bool loop_active\n"
  "\n"
  "# SVO loop count\n"
  "uint32 loop_count\n"
  "\n"
  "# SVO real-time mode status\n"
  "bool real_time_mode";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
zed_msgs__msg__SvoStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {zed_msgs__msg__SvoStatus__TYPE_NAME, 22, 22},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 493, 493},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
zed_msgs__msg__SvoStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *zed_msgs__msg__SvoStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
