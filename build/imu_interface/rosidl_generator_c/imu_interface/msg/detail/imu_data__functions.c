// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from imu_interface:msg/ImuData.idl
// generated code does not contain a copyright notice
#include "imu_interface/msg/detail/imu_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `acceleration`
// Member `gyroscope`
#include "geometry_msgs/msg/detail/vector3__functions.h"
// Member `quaternion`
#include "geometry_msgs/msg/detail/quaternion__functions.h"

bool
imu_interface__msg__ImuData__init(imu_interface__msg__ImuData * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    imu_interface__msg__ImuData__fini(msg);
    return false;
  }
  // timestamp_unix_ns
  // timestamp_unix_seconds
  // acceleration
  if (!geometry_msgs__msg__Vector3__init(&msg->acceleration)) {
    imu_interface__msg__ImuData__fini(msg);
    return false;
  }
  // gyroscope
  if (!geometry_msgs__msg__Vector3__init(&msg->gyroscope)) {
    imu_interface__msg__ImuData__fini(msg);
    return false;
  }
  // quaternion
  if (!geometry_msgs__msg__Quaternion__init(&msg->quaternion)) {
    imu_interface__msg__ImuData__fini(msg);
    return false;
  }
  return true;
}

void
imu_interface__msg__ImuData__fini(imu_interface__msg__ImuData * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // timestamp_unix_ns
  // timestamp_unix_seconds
  // acceleration
  geometry_msgs__msg__Vector3__fini(&msg->acceleration);
  // gyroscope
  geometry_msgs__msg__Vector3__fini(&msg->gyroscope);
  // quaternion
  geometry_msgs__msg__Quaternion__fini(&msg->quaternion);
}

bool
imu_interface__msg__ImuData__are_equal(const imu_interface__msg__ImuData * lhs, const imu_interface__msg__ImuData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // timestamp_unix_ns
  if (lhs->timestamp_unix_ns != rhs->timestamp_unix_ns) {
    return false;
  }
  // timestamp_unix_seconds
  if (lhs->timestamp_unix_seconds != rhs->timestamp_unix_seconds) {
    return false;
  }
  // acceleration
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->acceleration), &(rhs->acceleration)))
  {
    return false;
  }
  // gyroscope
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->gyroscope), &(rhs->gyroscope)))
  {
    return false;
  }
  // quaternion
  if (!geometry_msgs__msg__Quaternion__are_equal(
      &(lhs->quaternion), &(rhs->quaternion)))
  {
    return false;
  }
  return true;
}

bool
imu_interface__msg__ImuData__copy(
  const imu_interface__msg__ImuData * input,
  imu_interface__msg__ImuData * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // timestamp_unix_ns
  output->timestamp_unix_ns = input->timestamp_unix_ns;
  // timestamp_unix_seconds
  output->timestamp_unix_seconds = input->timestamp_unix_seconds;
  // acceleration
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->acceleration), &(output->acceleration)))
  {
    return false;
  }
  // gyroscope
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->gyroscope), &(output->gyroscope)))
  {
    return false;
  }
  // quaternion
  if (!geometry_msgs__msg__Quaternion__copy(
      &(input->quaternion), &(output->quaternion)))
  {
    return false;
  }
  return true;
}

imu_interface__msg__ImuData *
imu_interface__msg__ImuData__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  imu_interface__msg__ImuData * msg = (imu_interface__msg__ImuData *)allocator.allocate(sizeof(imu_interface__msg__ImuData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(imu_interface__msg__ImuData));
  bool success = imu_interface__msg__ImuData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
imu_interface__msg__ImuData__destroy(imu_interface__msg__ImuData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    imu_interface__msg__ImuData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
imu_interface__msg__ImuData__Sequence__init(imu_interface__msg__ImuData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  imu_interface__msg__ImuData * data = NULL;

  if (size) {
    data = (imu_interface__msg__ImuData *)allocator.zero_allocate(size, sizeof(imu_interface__msg__ImuData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = imu_interface__msg__ImuData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        imu_interface__msg__ImuData__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
imu_interface__msg__ImuData__Sequence__fini(imu_interface__msg__ImuData__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      imu_interface__msg__ImuData__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

imu_interface__msg__ImuData__Sequence *
imu_interface__msg__ImuData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  imu_interface__msg__ImuData__Sequence * array = (imu_interface__msg__ImuData__Sequence *)allocator.allocate(sizeof(imu_interface__msg__ImuData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = imu_interface__msg__ImuData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
imu_interface__msg__ImuData__Sequence__destroy(imu_interface__msg__ImuData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    imu_interface__msg__ImuData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
imu_interface__msg__ImuData__Sequence__are_equal(const imu_interface__msg__ImuData__Sequence * lhs, const imu_interface__msg__ImuData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!imu_interface__msg__ImuData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
imu_interface__msg__ImuData__Sequence__copy(
  const imu_interface__msg__ImuData__Sequence * input,
  imu_interface__msg__ImuData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(imu_interface__msg__ImuData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    imu_interface__msg__ImuData * data =
      (imu_interface__msg__ImuData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!imu_interface__msg__ImuData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          imu_interface__msg__ImuData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!imu_interface__msg__ImuData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
