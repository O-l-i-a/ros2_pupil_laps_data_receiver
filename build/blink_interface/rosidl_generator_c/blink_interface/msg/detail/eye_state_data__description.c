// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from blink_interface:msg/EyeStateData.idl
// generated code does not contain a copyright notice

#include "blink_interface/msg/detail/eye_state_data__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_blink_interface
const rosidl_type_hash_t *
blink_interface__msg__EyeStateData__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9c, 0x10, 0xd3, 0x45, 0x84, 0x3f, 0x22, 0x14,
      0x36, 0x31, 0xef, 0x12, 0x98, 0xc4, 0x24, 0x82,
      0xc2, 0x68, 0x84, 0xf5, 0xb6, 0x23, 0xb1, 0x15,
      0xfd, 0xaf, 0x01, 0xeb, 0x03, 0xde, 0xfc, 0xc6,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "std_msgs/msg/detail/header__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

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
#endif

static char blink_interface__msg__EyeStateData__TYPE_NAME[] = "blink_interface/msg/EyeStateData";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char blink_interface__msg__EyeStateData__FIELD_NAME__header[] = "header";
static char blink_interface__msg__EyeStateData__FIELD_NAME__event_name[] = "event_name";
static char blink_interface__msg__EyeStateData__FIELD_NAME__event_type[] = "event_type";
static char blink_interface__msg__EyeStateData__FIELD_NAME__start_time_ns[] = "start_time_ns";
static char blink_interface__msg__EyeStateData__FIELD_NAME__end_time_ns[] = "end_time_ns";
static char blink_interface__msg__EyeStateData__FIELD_NAME__rtp_ts_unix_seconds[] = "rtp_ts_unix_seconds";
static char blink_interface__msg__EyeStateData__FIELD_NAME__has_end_time[] = "has_end_time";
static char blink_interface__msg__EyeStateData__FIELD_NAME__start_gaze_x[] = "start_gaze_x";
static char blink_interface__msg__EyeStateData__FIELD_NAME__start_gaze_y[] = "start_gaze_y";
static char blink_interface__msg__EyeStateData__FIELD_NAME__end_gaze_x[] = "end_gaze_x";
static char blink_interface__msg__EyeStateData__FIELD_NAME__end_gaze_y[] = "end_gaze_y";
static char blink_interface__msg__EyeStateData__FIELD_NAME__mean_gaze_x[] = "mean_gaze_x";
static char blink_interface__msg__EyeStateData__FIELD_NAME__mean_gaze_y[] = "mean_gaze_y";
static char blink_interface__msg__EyeStateData__FIELD_NAME__amplitude_pixels[] = "amplitude_pixels";
static char blink_interface__msg__EyeStateData__FIELD_NAME__amplitude_angle_deg[] = "amplitude_angle_deg";
static char blink_interface__msg__EyeStateData__FIELD_NAME__mean_velocity[] = "mean_velocity";
static char blink_interface__msg__EyeStateData__FIELD_NAME__max_velocity[] = "max_velocity";

static rosidl_runtime_c__type_description__Field blink_interface__msg__EyeStateData__FIELDS[] = {
  {
    {blink_interface__msg__EyeStateData__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {blink_interface__msg__EyeStateData__FIELD_NAME__event_name, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {blink_interface__msg__EyeStateData__FIELD_NAME__event_type, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {blink_interface__msg__EyeStateData__FIELD_NAME__start_time_ns, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {blink_interface__msg__EyeStateData__FIELD_NAME__end_time_ns, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {blink_interface__msg__EyeStateData__FIELD_NAME__rtp_ts_unix_seconds, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {blink_interface__msg__EyeStateData__FIELD_NAME__has_end_time, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {blink_interface__msg__EyeStateData__FIELD_NAME__start_gaze_x, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {blink_interface__msg__EyeStateData__FIELD_NAME__start_gaze_y, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {blink_interface__msg__EyeStateData__FIELD_NAME__end_gaze_x, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {blink_interface__msg__EyeStateData__FIELD_NAME__end_gaze_y, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {blink_interface__msg__EyeStateData__FIELD_NAME__mean_gaze_x, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {blink_interface__msg__EyeStateData__FIELD_NAME__mean_gaze_y, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {blink_interface__msg__EyeStateData__FIELD_NAME__amplitude_pixels, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {blink_interface__msg__EyeStateData__FIELD_NAME__amplitude_angle_deg, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {blink_interface__msg__EyeStateData__FIELD_NAME__mean_velocity, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {blink_interface__msg__EyeStateData__FIELD_NAME__max_velocity, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription blink_interface__msg__EyeStateData__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
blink_interface__msg__EyeStateData__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {blink_interface__msg__EyeStateData__TYPE_NAME, 32, 32},
      {blink_interface__msg__EyeStateData__FIELDS, 17, 17},
    },
    {blink_interface__msg__EyeStateData__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "std_msgs/Header header\n"
  "\n"
  "# \"blink\", \"fixation\", \"saccade\", \"fixation_onset\", \"saccade_onset\"\n"
  "string event_name\n"
  "int32 event_type\n"
  "\n"
  "float64 start_time_ns\n"
  "float64 end_time_ns\n"
  "float64 rtp_ts_unix_seconds\n"
  "bool has_end_time\n"
  "\n"
  "float32 start_gaze_x\n"
  "float32 start_gaze_y\n"
  "float32 end_gaze_x\n"
  "float32 end_gaze_y\n"
  "float32 mean_gaze_x\n"
  "float32 mean_gaze_y\n"
  "float32 amplitude_pixels\n"
  "float32 amplitude_angle_deg\n"
  "float32 mean_velocity\n"
  "float32 max_velocity";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
blink_interface__msg__EyeStateData__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {blink_interface__msg__EyeStateData__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 433, 433},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
blink_interface__msg__EyeStateData__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *blink_interface__msg__EyeStateData__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
