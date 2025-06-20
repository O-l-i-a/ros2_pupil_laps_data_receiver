// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from zed_msgs:msg/Heartbeat.idl
// generated code does not contain a copyright notice

#include "zed_msgs/msg/detail/heartbeat__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_zed_msgs
const rosidl_type_hash_t *
zed_msgs__msg__Heartbeat__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x0f, 0x8f, 0x28, 0xff, 0xd3, 0xe8, 0x91, 0x19,
      0xa5, 0x8c, 0x5a, 0xe1, 0x12, 0xce, 0xdf, 0xc6,
      0x56, 0x9d, 0xfa, 0xde, 0xd9, 0x31, 0xff, 0x4a,
      0x04, 0xd2, 0x89, 0xa7, 0x53, 0xa4, 0x9b, 0x0b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char zed_msgs__msg__Heartbeat__TYPE_NAME[] = "zed_msgs/msg/Heartbeat";

// Define type names, field names, and default values
static char zed_msgs__msg__Heartbeat__FIELD_NAME__beat_count[] = "beat_count";
static char zed_msgs__msg__Heartbeat__FIELD_NAME__node_ns[] = "node_ns";
static char zed_msgs__msg__Heartbeat__FIELD_NAME__node_name[] = "node_name";
static char zed_msgs__msg__Heartbeat__FIELD_NAME__full_name[] = "full_name";
static char zed_msgs__msg__Heartbeat__FIELD_NAME__camera_sn[] = "camera_sn";
static char zed_msgs__msg__Heartbeat__FIELD_NAME__svo_mode[] = "svo_mode";
static char zed_msgs__msg__Heartbeat__FIELD_NAME__simul_mode[] = "simul_mode";

static rosidl_runtime_c__type_description__Field zed_msgs__msg__Heartbeat__FIELDS[] = {
  {
    {zed_msgs__msg__Heartbeat__FIELD_NAME__beat_count, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Heartbeat__FIELD_NAME__node_ns, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Heartbeat__FIELD_NAME__node_name, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Heartbeat__FIELD_NAME__full_name, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Heartbeat__FIELD_NAME__camera_sn, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Heartbeat__FIELD_NAME__svo_mode, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__msg__Heartbeat__FIELD_NAME__simul_mode, 10, 10},
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
zed_msgs__msg__Heartbeat__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {zed_msgs__msg__Heartbeat__TYPE_NAME, 22, 22},
      {zed_msgs__msg__Heartbeat__FIELDS, 7, 7},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Message to notify that the node is alive to other nodes\n"
  "\n"
  "# idx of the message\n"
  "uint64 beat_count\n"
  "\n"
  "# namespace of the node\n"
  "string node_ns\n"
  "# name of the node\n"
  "string node_name\n"
  "# full node name\n"
  "string full_name\n"
  "\n"
  "# serial number of the input camera\n"
  "uint32 camera_sn\n"
  "\n"
  "# data from an svo?\n"
  "bool svo_mode\n"
  "\n"
  "#data from simulation?\n"
  "bool simul_mode";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
zed_msgs__msg__Heartbeat__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {zed_msgs__msg__Heartbeat__TYPE_NAME, 22, 22},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 337, 337},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
zed_msgs__msg__Heartbeat__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *zed_msgs__msg__Heartbeat__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
