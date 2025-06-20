// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from zed_msgs:msg/MagHeadingStatus.idl
// generated code does not contain a copyright notice

#include "zed_msgs/msg/detail/mag_heading_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_zed_msgs
const rosidl_type_hash_t *
zed_msgs__msg__MagHeadingStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x6d, 0x1f, 0x4e, 0x83, 0x94, 0x97, 0x36, 0xd2,
      0x33, 0x14, 0x92, 0x5f, 0x22, 0xb8, 0x9b, 0xfe,
      0x2e, 0x67, 0x39, 0xdd, 0x89, 0x11, 0xfd, 0x20,
      0xc4, 0x5b, 0x49, 0x03, 0x61, 0xb9, 0x89, 0x0f,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char zed_msgs__msg__MagHeadingStatus__TYPE_NAME[] = "zed_msgs/msg/MagHeadingStatus";

// Define type names, field names, and default values
static char zed_msgs__msg__MagHeadingStatus__FIELD_NAME__status[] = "status";

static rosidl_runtime_c__type_description__Field zed_msgs__msg__MagHeadingStatus__FIELDS[] = {
  {
    {zed_msgs__msg__MagHeadingStatus__FIELD_NAME__status, 6, 6},
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
zed_msgs__msg__MagHeadingStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {zed_msgs__msg__MagHeadingStatus__TYPE_NAME, 29, 29},
      {zed_msgs__msg__MagHeadingStatus__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Status constants\n"
  "#  GOOD               The heading is reliable and not affected by iron interferences.\n"
  "#  OK                 The heading is reliable, but affected by slight iron interferences.\n"
  "#  NOT_GOOD           The heading is not reliable because affected by strong iron interferences.\n"
  "#  NOT_CALIBRATED     The magnetometer has not been calibrated.\n"
  "#  MAG_NOT_AVAILABLE  The magnetometer sensor is not available.\n"
  "\n"
  "uint8 GOOD=0 \n"
  "uint8 OK = 1\n"
  "uint8 NOT_GOOD = 2\n"
  "uint8 NOT_CALIBRATED = 3\n"
  "uint8 MAG_NOT_AVAILABLE = 4\n"
  "\n"
  "# Status\n"
  "uint8 status";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
zed_msgs__msg__MagHeadingStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {zed_msgs__msg__MagHeadingStatus__TYPE_NAME, 29, 29},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 543, 543},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
zed_msgs__msg__MagHeadingStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *zed_msgs__msg__MagHeadingStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
