// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from zed_msgs:msg/GnssFusionStatus.idl
// generated code does not contain a copyright notice

#include "zed_msgs/msg/detail/gnss_fusion_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_zed_msgs
const rosidl_type_hash_t *
zed_msgs__msg__GnssFusionStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x74, 0xe5, 0xd7, 0x1e, 0x46, 0x95, 0xa5, 0x9f,
      0x06, 0x8b, 0xb9, 0x21, 0xa4, 0x52, 0x41, 0x66,
      0xf9, 0x31, 0x78, 0x76, 0xf6, 0x18, 0xfd, 0x88,
      0xdd, 0xd2, 0xfc, 0x53, 0xf6, 0x16, 0x31, 0x46,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char zed_msgs__msg__GnssFusionStatus__TYPE_NAME[] = "zed_msgs/msg/GnssFusionStatus";

// Define type names, field names, and default values
static char zed_msgs__msg__GnssFusionStatus__FIELD_NAME__gnss_fusion_status[] = "gnss_fusion_status";

static rosidl_runtime_c__type_description__Field zed_msgs__msg__GnssFusionStatus__FIELDS[] = {
  {
    {zed_msgs__msg__GnssFusionStatus__FIELD_NAME__gnss_fusion_status, 18, 18},
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
zed_msgs__msg__GnssFusionStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {zed_msgs__msg__GnssFusionStatus__TYPE_NAME, 29, 29},
      {zed_msgs__msg__GnssFusionStatus__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# GNSS_FUSION_STATUS\n"
  "# Represents the current state of GNSS fusion for global localization.\n"
  "# OK - The GNSS fusion module is calibrated and working successfully.\n"
  "# OFF - The GNSS fusion module is not enabled.\n"
  "# CALIBRATION_IN_PROGRESS - Calibration of the GNSS/VIO fusion module is in progress.\n"
  "# RECALIBRATION_IN_PROGRESS- Re-alignment of GNSS/VIO data is in progress, leading to potentially inaccurate global position.\n"
  "uint8 OK = 0\n"
  "uint8 OFF = 1\n"
  "uint8 CALIBRATION_IN_PROGRESS = 2\n"
  "uint8 RECALIBRATION_IN_PROGRESS = 3\n"
  "\n"
  "uint8 gnss_fusion_status";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
zed_msgs__msg__GnssFusionStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {zed_msgs__msg__GnssFusionStatus__TYPE_NAME, 29, 29},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 543, 543},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
zed_msgs__msg__GnssFusionStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *zed_msgs__msg__GnssFusionStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
