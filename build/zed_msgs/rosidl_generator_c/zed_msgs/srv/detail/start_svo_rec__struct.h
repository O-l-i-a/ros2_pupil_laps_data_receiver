// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from zed_msgs:srv/StartSvoRec.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "zed_msgs/srv/start_svo_rec.h"


#ifndef ZED_MSGS__SRV__DETAIL__START_SVO_REC__STRUCT_H_
#define ZED_MSGS__SRV__DETAIL__START_SVO_REC__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'svo_filename'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/StartSvoRec in the package zed_msgs.
typedef struct zed_msgs__srv__StartSvoRec_Request
{
  /// Bitrate - 0 or [1000,60000]
  uint32_t bitrate;
  /// Compression Mode - [0,2]
  uint8_t compression_mode;
  /// Target Framerate
  /// Allowed framerates are 0,15,30, 60 or 100.
  /// Any other values will be discarded and camera FPS will be taken.
  uint32_t target_framerate;
  /// Input Transcode
  bool input_transcode;
  /// Filename
  rosidl_runtime_c__String svo_filename;
} zed_msgs__srv__StartSvoRec_Request;

// Struct for a sequence of zed_msgs__srv__StartSvoRec_Request.
typedef struct zed_msgs__srv__StartSvoRec_Request__Sequence
{
  zed_msgs__srv__StartSvoRec_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zed_msgs__srv__StartSvoRec_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/StartSvoRec in the package zed_msgs.
typedef struct zed_msgs__srv__StartSvoRec_Response
{
  /// indicate successful run of service
  bool success;
  /// informational, e.g. for error messages
  rosidl_runtime_c__String message;
} zed_msgs__srv__StartSvoRec_Response;

// Struct for a sequence of zed_msgs__srv__StartSvoRec_Response.
typedef struct zed_msgs__srv__StartSvoRec_Response__Sequence
{
  zed_msgs__srv__StartSvoRec_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zed_msgs__srv__StartSvoRec_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  zed_msgs__srv__StartSvoRec_Event__request__MAX_SIZE = 1
};
// response
enum
{
  zed_msgs__srv__StartSvoRec_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/StartSvoRec in the package zed_msgs.
typedef struct zed_msgs__srv__StartSvoRec_Event
{
  service_msgs__msg__ServiceEventInfo info;
  zed_msgs__srv__StartSvoRec_Request__Sequence request;
  zed_msgs__srv__StartSvoRec_Response__Sequence response;
} zed_msgs__srv__StartSvoRec_Event;

// Struct for a sequence of zed_msgs__srv__StartSvoRec_Event.
typedef struct zed_msgs__srv__StartSvoRec_Event__Sequence
{
  zed_msgs__srv__StartSvoRec_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zed_msgs__srv__StartSvoRec_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ZED_MSGS__SRV__DETAIL__START_SVO_REC__STRUCT_H_
