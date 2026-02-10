// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from imu_interface:msg/ImuData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "imu_interface/msg/imu_data.h"


#ifndef IMU_INTERFACE__MSG__DETAIL__IMU_DATA__STRUCT_H_
#define IMU_INTERFACE__MSG__DETAIL__IMU_DATA__STRUCT_H_

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
// Member 'acceleration'
// Member 'gyroscope'
#include "geometry_msgs/msg/detail/vector3__struct.h"
// Member 'quaternion'
#include "geometry_msgs/msg/detail/quaternion__struct.h"

/// Struct defined in msg/ImuData in the package imu_interface.
typedef struct imu_interface__msg__ImuData
{
  std_msgs__msg__Header header;
  uint64_t timestamp_unix_ns;
  double timestamp_unix_seconds;
  geometry_msgs__msg__Vector3 acceleration;
  geometry_msgs__msg__Vector3 gyroscope;
  geometry_msgs__msg__Quaternion quaternion;
} imu_interface__msg__ImuData;

// Struct for a sequence of imu_interface__msg__ImuData.
typedef struct imu_interface__msg__ImuData__Sequence
{
  imu_interface__msg__ImuData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} imu_interface__msg__ImuData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // IMU_INTERFACE__MSG__DETAIL__IMU_DATA__STRUCT_H_
