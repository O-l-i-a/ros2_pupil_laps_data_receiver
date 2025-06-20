// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gaze_interface:msg/GazeDataAsync.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gaze_interface/msg/gaze_data_async.h"


#ifndef GAZE_INTERFACE__MSG__DETAIL__GAZE_DATA_ASYNC__STRUCT_H_
#define GAZE_INTERFACE__MSG__DETAIL__GAZE_DATA_ASYNC__STRUCT_H_

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

/// Struct defined in msg/GazeDataAsync in the package gaze_interface.
typedef struct gaze_interface__msg__GazeDataAsync
{
  std_msgs__msg__Header header;
  float norm_pos_x;
  float norm_pos_y;
  float timestamp_unix_seconds;
} gaze_interface__msg__GazeDataAsync;

// Struct for a sequence of gaze_interface__msg__GazeDataAsync.
typedef struct gaze_interface__msg__GazeDataAsync__Sequence
{
  gaze_interface__msg__GazeDataAsync * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gaze_interface__msg__GazeDataAsync__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GAZE_INTERFACE__MSG__DETAIL__GAZE_DATA_ASYNC__STRUCT_H_
