// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from gaze_interface:msg/GazeDataAsync.idl
// generated code does not contain a copyright notice
#include "gaze_interface/msg/detail/gaze_data_async__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
gaze_interface__msg__GazeDataAsync__init(gaze_interface__msg__GazeDataAsync * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    gaze_interface__msg__GazeDataAsync__fini(msg);
    return false;
  }
  // norm_pos_x
  // norm_pos_y
  // timestamp_unix_seconds
  return true;
}

void
gaze_interface__msg__GazeDataAsync__fini(gaze_interface__msg__GazeDataAsync * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // norm_pos_x
  // norm_pos_y
  // timestamp_unix_seconds
}

bool
gaze_interface__msg__GazeDataAsync__are_equal(const gaze_interface__msg__GazeDataAsync * lhs, const gaze_interface__msg__GazeDataAsync * rhs)
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
  // norm_pos_x
  if (lhs->norm_pos_x != rhs->norm_pos_x) {
    return false;
  }
  // norm_pos_y
  if (lhs->norm_pos_y != rhs->norm_pos_y) {
    return false;
  }
  // timestamp_unix_seconds
  if (lhs->timestamp_unix_seconds != rhs->timestamp_unix_seconds) {
    return false;
  }
  return true;
}

bool
gaze_interface__msg__GazeDataAsync__copy(
  const gaze_interface__msg__GazeDataAsync * input,
  gaze_interface__msg__GazeDataAsync * output)
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
  // norm_pos_x
  output->norm_pos_x = input->norm_pos_x;
  // norm_pos_y
  output->norm_pos_y = input->norm_pos_y;
  // timestamp_unix_seconds
  output->timestamp_unix_seconds = input->timestamp_unix_seconds;
  return true;
}

gaze_interface__msg__GazeDataAsync *
gaze_interface__msg__GazeDataAsync__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gaze_interface__msg__GazeDataAsync * msg = (gaze_interface__msg__GazeDataAsync *)allocator.allocate(sizeof(gaze_interface__msg__GazeDataAsync), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gaze_interface__msg__GazeDataAsync));
  bool success = gaze_interface__msg__GazeDataAsync__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gaze_interface__msg__GazeDataAsync__destroy(gaze_interface__msg__GazeDataAsync * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gaze_interface__msg__GazeDataAsync__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gaze_interface__msg__GazeDataAsync__Sequence__init(gaze_interface__msg__GazeDataAsync__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gaze_interface__msg__GazeDataAsync * data = NULL;

  if (size) {
    data = (gaze_interface__msg__GazeDataAsync *)allocator.zero_allocate(size, sizeof(gaze_interface__msg__GazeDataAsync), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gaze_interface__msg__GazeDataAsync__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gaze_interface__msg__GazeDataAsync__fini(&data[i - 1]);
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
gaze_interface__msg__GazeDataAsync__Sequence__fini(gaze_interface__msg__GazeDataAsync__Sequence * array)
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
      gaze_interface__msg__GazeDataAsync__fini(&array->data[i]);
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

gaze_interface__msg__GazeDataAsync__Sequence *
gaze_interface__msg__GazeDataAsync__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gaze_interface__msg__GazeDataAsync__Sequence * array = (gaze_interface__msg__GazeDataAsync__Sequence *)allocator.allocate(sizeof(gaze_interface__msg__GazeDataAsync__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gaze_interface__msg__GazeDataAsync__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gaze_interface__msg__GazeDataAsync__Sequence__destroy(gaze_interface__msg__GazeDataAsync__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gaze_interface__msg__GazeDataAsync__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gaze_interface__msg__GazeDataAsync__Sequence__are_equal(const gaze_interface__msg__GazeDataAsync__Sequence * lhs, const gaze_interface__msg__GazeDataAsync__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gaze_interface__msg__GazeDataAsync__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gaze_interface__msg__GazeDataAsync__Sequence__copy(
  const gaze_interface__msg__GazeDataAsync__Sequence * input,
  gaze_interface__msg__GazeDataAsync__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gaze_interface__msg__GazeDataAsync);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    gaze_interface__msg__GazeDataAsync * data =
      (gaze_interface__msg__GazeDataAsync *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gaze_interface__msg__GazeDataAsync__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          gaze_interface__msg__GazeDataAsync__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gaze_interface__msg__GazeDataAsync__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
