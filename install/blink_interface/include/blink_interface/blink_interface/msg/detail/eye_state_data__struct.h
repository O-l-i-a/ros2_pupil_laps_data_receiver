// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from blink_interface:msg/EyeStateData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "blink_interface/msg/eye_state_data.h"


#ifndef BLINK_INTERFACE__MSG__DETAIL__EYE_STATE_DATA__STRUCT_H_
#define BLINK_INTERFACE__MSG__DETAIL__EYE_STATE_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'event_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/EyeStateData in the package blink_interface.
typedef struct blink_interface__msg__EyeStateData
{
  std_msgs__msg__Header header;
  /// "blink", "fixation", "saccade", "fixation_onset", "saccade_onset"
  rosidl_runtime_c__String event_name;
  int32_t event_type;
  double start_time_ns;
  double end_time_ns;
  double rtp_ts_unix_seconds;
  bool has_end_time;
  float start_gaze_x;
  float start_gaze_y;
  float end_gaze_x;
  float end_gaze_y;
  float mean_gaze_x;
  float mean_gaze_y;
  float amplitude_pixels;
  float amplitude_angle_deg;
  float mean_velocity;
  float max_velocity;
} blink_interface__msg__EyeStateData;

// Struct for a sequence of blink_interface__msg__EyeStateData.
typedef struct blink_interface__msg__EyeStateData__Sequence
{
  blink_interface__msg__EyeStateData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} blink_interface__msg__EyeStateData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BLINK_INTERFACE__MSG__DETAIL__EYE_STATE_DATA__STRUCT_H_
