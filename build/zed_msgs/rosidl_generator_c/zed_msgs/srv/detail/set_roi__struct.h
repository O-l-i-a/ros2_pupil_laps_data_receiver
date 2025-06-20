// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from zed_msgs:srv/SetROI.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "zed_msgs/srv/set_roi.h"


#ifndef ZED_MSGS__SRV__DETAIL__SET_ROI__STRUCT_H_
#define ZED_MSGS__SRV__DETAIL__SET_ROI__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'roi'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetROI in the package zed_msgs.
typedef struct zed_msgs__srv__SetROI_Request
{
  /// Region of interest polygon as an array of normalized vertices. e.g. "[[0.5,0.25],[0.75,0.5],[0.5,0.75],[0.25,0.5]]"
  /// You can use
  rosidl_runtime_c__String roi;
} zed_msgs__srv__SetROI_Request;

// Struct for a sequence of zed_msgs__srv__SetROI_Request.
typedef struct zed_msgs__srv__SetROI_Request__Sequence
{
  zed_msgs__srv__SetROI_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zed_msgs__srv__SetROI_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetROI in the package zed_msgs.
typedef struct zed_msgs__srv__SetROI_Response
{
  /// indicate successful run of service
  bool success;
  /// informational, e.g. for error messages
  rosidl_runtime_c__String message;
} zed_msgs__srv__SetROI_Response;

// Struct for a sequence of zed_msgs__srv__SetROI_Response.
typedef struct zed_msgs__srv__SetROI_Response__Sequence
{
  zed_msgs__srv__SetROI_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zed_msgs__srv__SetROI_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  zed_msgs__srv__SetROI_Event__request__MAX_SIZE = 1
};
// response
enum
{
  zed_msgs__srv__SetROI_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/SetROI in the package zed_msgs.
typedef struct zed_msgs__srv__SetROI_Event
{
  service_msgs__msg__ServiceEventInfo info;
  zed_msgs__srv__SetROI_Request__Sequence request;
  zed_msgs__srv__SetROI_Response__Sequence response;
} zed_msgs__srv__SetROI_Event;

// Struct for a sequence of zed_msgs__srv__SetROI_Event.
typedef struct zed_msgs__srv__SetROI_Event__Sequence
{
  zed_msgs__srv__SetROI_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zed_msgs__srv__SetROI_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ZED_MSGS__SRV__DETAIL__SET_ROI__STRUCT_H_
