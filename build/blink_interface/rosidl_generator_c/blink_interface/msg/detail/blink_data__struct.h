// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from blink_interface:msg/BlinkData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "blink_interface/msg/blink_data.h"


#ifndef BLINK_INTERFACE__MSG__DETAIL__BLINK_DATA__STRUCT_H_
#define BLINK_INTERFACE__MSG__DETAIL__BLINK_DATA__STRUCT_H_

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

/// Struct defined in msg/BlinkData in the package blink_interface.
typedef struct blink_interface__msg__BlinkData
{
  std_msgs__msg__Header header;
  float end_time_ns;
  float start_time_ns;
} blink_interface__msg__BlinkData;

// Struct for a sequence of blink_interface__msg__BlinkData.
typedef struct blink_interface__msg__BlinkData__Sequence
{
  blink_interface__msg__BlinkData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} blink_interface__msg__BlinkData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BLINK_INTERFACE__MSG__DETAIL__BLINK_DATA__STRUCT_H_
