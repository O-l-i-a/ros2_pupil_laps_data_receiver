// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from zed_msgs:srv/StartSvoRec.idl
// generated code does not contain a copyright notice

#include "zed_msgs/srv/detail/start_svo_rec__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_zed_msgs
const rosidl_type_hash_t *
zed_msgs__srv__StartSvoRec__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x25, 0xf7, 0xc6, 0x2d, 0xc4, 0x7e, 0x31, 0x0b,
      0xaf, 0x66, 0x7e, 0xde, 0xa9, 0x77, 0x22, 0xa2,
      0x2d, 0x6d, 0x1c, 0xd8, 0x6a, 0x2a, 0x0b, 0xba,
      0x91, 0x2b, 0xa6, 0x7f, 0x54, 0xaa, 0x30, 0x3e,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_zed_msgs
const rosidl_type_hash_t *
zed_msgs__srv__StartSvoRec_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x2c, 0x42, 0x37, 0xda, 0x7c, 0xd6, 0x24, 0x3c,
      0x42, 0xa7, 0x19, 0x9a, 0x16, 0xd7, 0x77, 0xc2,
      0xea, 0x03, 0xfb, 0x09, 0x4c, 0x63, 0xf7, 0xa5,
      0x9f, 0x08, 0x00, 0x79, 0x70, 0x85, 0x87, 0x83,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_zed_msgs
const rosidl_type_hash_t *
zed_msgs__srv__StartSvoRec_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xfd, 0x4b, 0xed, 0xe4, 0x46, 0x2e, 0x02, 0xd6,
      0xea, 0xc8, 0xc0, 0x8f, 0x33, 0x3a, 0x7e, 0xe9,
      0xb9, 0x88, 0xf0, 0x36, 0x34, 0x3e, 0xcf, 0xd3,
      0xb8, 0x60, 0xa7, 0x29, 0xf5, 0xd4, 0x6e, 0x4b,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_zed_msgs
const rosidl_type_hash_t *
zed_msgs__srv__StartSvoRec_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9a, 0x62, 0xca, 0xf3, 0x69, 0x27, 0xdf, 0x9d,
      0xcb, 0x8f, 0x89, 0x64, 0xbe, 0x0e, 0xe4, 0x13,
      0x2e, 0x9b, 0x6d, 0xcc, 0x8f, 0x79, 0x56, 0xe0,
      0x70, 0x2e, 0xf3, 0xc6, 0x67, 0xa1, 0xb2, 0xee,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char zed_msgs__srv__StartSvoRec__TYPE_NAME[] = "zed_msgs/srv/StartSvoRec";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char zed_msgs__srv__StartSvoRec_Event__TYPE_NAME[] = "zed_msgs/srv/StartSvoRec_Event";
static char zed_msgs__srv__StartSvoRec_Request__TYPE_NAME[] = "zed_msgs/srv/StartSvoRec_Request";
static char zed_msgs__srv__StartSvoRec_Response__TYPE_NAME[] = "zed_msgs/srv/StartSvoRec_Response";

// Define type names, field names, and default values
static char zed_msgs__srv__StartSvoRec__FIELD_NAME__request_message[] = "request_message";
static char zed_msgs__srv__StartSvoRec__FIELD_NAME__response_message[] = "response_message";
static char zed_msgs__srv__StartSvoRec__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field zed_msgs__srv__StartSvoRec__FIELDS[] = {
  {
    {zed_msgs__srv__StartSvoRec__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {zed_msgs__srv__StartSvoRec_Request__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__srv__StartSvoRec__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {zed_msgs__srv__StartSvoRec_Response__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__srv__StartSvoRec__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {zed_msgs__srv__StartSvoRec_Event__TYPE_NAME, 30, 30},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription zed_msgs__srv__StartSvoRec__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {zed_msgs__srv__StartSvoRec_Event__TYPE_NAME, 30, 30},
    {NULL, 0, 0},
  },
  {
    {zed_msgs__srv__StartSvoRec_Request__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {zed_msgs__srv__StartSvoRec_Response__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
zed_msgs__srv__StartSvoRec__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {zed_msgs__srv__StartSvoRec__TYPE_NAME, 24, 24},
      {zed_msgs__srv__StartSvoRec__FIELDS, 3, 3},
    },
    {zed_msgs__srv__StartSvoRec__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = zed_msgs__srv__StartSvoRec_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = zed_msgs__srv__StartSvoRec_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = zed_msgs__srv__StartSvoRec_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char zed_msgs__srv__StartSvoRec_Request__FIELD_NAME__bitrate[] = "bitrate";
static char zed_msgs__srv__StartSvoRec_Request__FIELD_NAME__compression_mode[] = "compression_mode";
static char zed_msgs__srv__StartSvoRec_Request__FIELD_NAME__target_framerate[] = "target_framerate";
static char zed_msgs__srv__StartSvoRec_Request__FIELD_NAME__input_transcode[] = "input_transcode";
static char zed_msgs__srv__StartSvoRec_Request__FIELD_NAME__svo_filename[] = "svo_filename";

static rosidl_runtime_c__type_description__Field zed_msgs__srv__StartSvoRec_Request__FIELDS[] = {
  {
    {zed_msgs__srv__StartSvoRec_Request__FIELD_NAME__bitrate, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__srv__StartSvoRec_Request__FIELD_NAME__compression_mode, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__srv__StartSvoRec_Request__FIELD_NAME__target_framerate, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__srv__StartSvoRec_Request__FIELD_NAME__input_transcode, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__srv__StartSvoRec_Request__FIELD_NAME__svo_filename, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
zed_msgs__srv__StartSvoRec_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {zed_msgs__srv__StartSvoRec_Request__TYPE_NAME, 32, 32},
      {zed_msgs__srv__StartSvoRec_Request__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char zed_msgs__srv__StartSvoRec_Response__FIELD_NAME__success[] = "success";
static char zed_msgs__srv__StartSvoRec_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field zed_msgs__srv__StartSvoRec_Response__FIELDS[] = {
  {
    {zed_msgs__srv__StartSvoRec_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__srv__StartSvoRec_Response__FIELD_NAME__message, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
zed_msgs__srv__StartSvoRec_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {zed_msgs__srv__StartSvoRec_Response__TYPE_NAME, 33, 33},
      {zed_msgs__srv__StartSvoRec_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char zed_msgs__srv__StartSvoRec_Event__FIELD_NAME__info[] = "info";
static char zed_msgs__srv__StartSvoRec_Event__FIELD_NAME__request[] = "request";
static char zed_msgs__srv__StartSvoRec_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field zed_msgs__srv__StartSvoRec_Event__FIELDS[] = {
  {
    {zed_msgs__srv__StartSvoRec_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__srv__StartSvoRec_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {zed_msgs__srv__StartSvoRec_Request__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
  {
    {zed_msgs__srv__StartSvoRec_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {zed_msgs__srv__StartSvoRec_Response__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription zed_msgs__srv__StartSvoRec_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {zed_msgs__srv__StartSvoRec_Request__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {zed_msgs__srv__StartSvoRec_Response__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
zed_msgs__srv__StartSvoRec_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {zed_msgs__srv__StartSvoRec_Event__TYPE_NAME, 30, 30},
      {zed_msgs__srv__StartSvoRec_Event__FIELDS, 3, 3},
    },
    {zed_msgs__srv__StartSvoRec_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = zed_msgs__srv__StartSvoRec_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = zed_msgs__srv__StartSvoRec_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Start SVO Recording\n"
  "\n"
  "# Bitrate - 0 or [1000,60000]\n"
  "uint32 bitrate\n"
  "\n"
  "# Compression Mode - [0,2]\n"
  "uint8 compression_mode\n"
  "\n"
  "# Target Framerate\n"
  "# Allowed framerates are 0,15,30, 60 or 100. \n"
  "# Any other values will be discarded and camera FPS will be taken.\n"
  "uint32 target_framerate\n"
  "\n"
  "# Input Transcode\n"
  "bool input_transcode\n"
  "\n"
  "# Filename\n"
  "string svo_filename \n"
  "---\n"
  "bool success   # indicate successful run of service\n"
  "string message # informational, e.g. for error messages";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
zed_msgs__srv__StartSvoRec__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {zed_msgs__srv__StartSvoRec__TYPE_NAME, 24, 24},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 461, 461},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
zed_msgs__srv__StartSvoRec_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {zed_msgs__srv__StartSvoRec_Request__TYPE_NAME, 32, 32},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
zed_msgs__srv__StartSvoRec_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {zed_msgs__srv__StartSvoRec_Response__TYPE_NAME, 33, 33},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
zed_msgs__srv__StartSvoRec_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {zed_msgs__srv__StartSvoRec_Event__TYPE_NAME, 30, 30},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
zed_msgs__srv__StartSvoRec__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *zed_msgs__srv__StartSvoRec__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *zed_msgs__srv__StartSvoRec_Event__get_individual_type_description_source(NULL);
    sources[4] = *zed_msgs__srv__StartSvoRec_Request__get_individual_type_description_source(NULL);
    sources[5] = *zed_msgs__srv__StartSvoRec_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
zed_msgs__srv__StartSvoRec_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *zed_msgs__srv__StartSvoRec_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
zed_msgs__srv__StartSvoRec_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *zed_msgs__srv__StartSvoRec_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
zed_msgs__srv__StartSvoRec_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *zed_msgs__srv__StartSvoRec_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *zed_msgs__srv__StartSvoRec_Request__get_individual_type_description_source(NULL);
    sources[4] = *zed_msgs__srv__StartSvoRec_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
