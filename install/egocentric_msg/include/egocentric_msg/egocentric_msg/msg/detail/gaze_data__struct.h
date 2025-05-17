// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from egocentric_msg:msg/GazeData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "egocentric_msg/msg/gaze_data.h"


#ifndef EGOCENTRIC_MSG__MSG__DETAIL__GAZE_DATA__STRUCT_H_
#define EGOCENTRIC_MSG__MSG__DETAIL__GAZE_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/GazeData in the package egocentric_msg.
typedef struct egocentric_msg__msg__GazeData
{
  float x;
  float y;
  bool worn;
  float pupil_diameter_left;
  float eyeball_center_left_x;
  float eyeball_center_left_y;
  float eyeball_center_left_z;
  float optical_axis_left_x;
  float optical_axis_left_y;
  float optical_axis_left_z;
  float pupil_diameter_right;
  float eyeball_center_right_x;
  float eyeball_center_right_y;
  float eyeball_center_right_z;
  float optical_axis_right_x;
  float optical_axis_right_y;
  float optical_axis_right_z;
  float timestamp_unix_seconds;
} egocentric_msg__msg__GazeData;

// Struct for a sequence of egocentric_msg__msg__GazeData.
typedef struct egocentric_msg__msg__GazeData__Sequence
{
  egocentric_msg__msg__GazeData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} egocentric_msg__msg__GazeData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EGOCENTRIC_MSG__MSG__DETAIL__GAZE_DATA__STRUCT_H_
