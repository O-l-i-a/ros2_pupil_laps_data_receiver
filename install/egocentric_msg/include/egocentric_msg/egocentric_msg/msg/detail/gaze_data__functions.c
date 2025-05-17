// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from egocentric_msg:msg/GazeData.idl
// generated code does not contain a copyright notice
#include "egocentric_msg/msg/detail/gaze_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
egocentric_msg__msg__GazeData__init(egocentric_msg__msg__GazeData * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // worn
  // pupil_diameter_left
  // eyeball_center_left_x
  // eyeball_center_left_y
  // eyeball_center_left_z
  // optical_axis_left_x
  // optical_axis_left_y
  // optical_axis_left_z
  // pupil_diameter_right
  // eyeball_center_right_x
  // eyeball_center_right_y
  // eyeball_center_right_z
  // optical_axis_right_x
  // optical_axis_right_y
  // optical_axis_right_z
  // timestamp_unix_seconds
  return true;
}

void
egocentric_msg__msg__GazeData__fini(egocentric_msg__msg__GazeData * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // worn
  // pupil_diameter_left
  // eyeball_center_left_x
  // eyeball_center_left_y
  // eyeball_center_left_z
  // optical_axis_left_x
  // optical_axis_left_y
  // optical_axis_left_z
  // pupil_diameter_right
  // eyeball_center_right_x
  // eyeball_center_right_y
  // eyeball_center_right_z
  // optical_axis_right_x
  // optical_axis_right_y
  // optical_axis_right_z
  // timestamp_unix_seconds
}

bool
egocentric_msg__msg__GazeData__are_equal(const egocentric_msg__msg__GazeData * lhs, const egocentric_msg__msg__GazeData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // worn
  if (lhs->worn != rhs->worn) {
    return false;
  }
  // pupil_diameter_left
  if (lhs->pupil_diameter_left != rhs->pupil_diameter_left) {
    return false;
  }
  // eyeball_center_left_x
  if (lhs->eyeball_center_left_x != rhs->eyeball_center_left_x) {
    return false;
  }
  // eyeball_center_left_y
  if (lhs->eyeball_center_left_y != rhs->eyeball_center_left_y) {
    return false;
  }
  // eyeball_center_left_z
  if (lhs->eyeball_center_left_z != rhs->eyeball_center_left_z) {
    return false;
  }
  // optical_axis_left_x
  if (lhs->optical_axis_left_x != rhs->optical_axis_left_x) {
    return false;
  }
  // optical_axis_left_y
  if (lhs->optical_axis_left_y != rhs->optical_axis_left_y) {
    return false;
  }
  // optical_axis_left_z
  if (lhs->optical_axis_left_z != rhs->optical_axis_left_z) {
    return false;
  }
  // pupil_diameter_right
  if (lhs->pupil_diameter_right != rhs->pupil_diameter_right) {
    return false;
  }
  // eyeball_center_right_x
  if (lhs->eyeball_center_right_x != rhs->eyeball_center_right_x) {
    return false;
  }
  // eyeball_center_right_y
  if (lhs->eyeball_center_right_y != rhs->eyeball_center_right_y) {
    return false;
  }
  // eyeball_center_right_z
  if (lhs->eyeball_center_right_z != rhs->eyeball_center_right_z) {
    return false;
  }
  // optical_axis_right_x
  if (lhs->optical_axis_right_x != rhs->optical_axis_right_x) {
    return false;
  }
  // optical_axis_right_y
  if (lhs->optical_axis_right_y != rhs->optical_axis_right_y) {
    return false;
  }
  // optical_axis_right_z
  if (lhs->optical_axis_right_z != rhs->optical_axis_right_z) {
    return false;
  }
  // timestamp_unix_seconds
  if (lhs->timestamp_unix_seconds != rhs->timestamp_unix_seconds) {
    return false;
  }
  return true;
}

bool
egocentric_msg__msg__GazeData__copy(
  const egocentric_msg__msg__GazeData * input,
  egocentric_msg__msg__GazeData * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // worn
  output->worn = input->worn;
  // pupil_diameter_left
  output->pupil_diameter_left = input->pupil_diameter_left;
  // eyeball_center_left_x
  output->eyeball_center_left_x = input->eyeball_center_left_x;
  // eyeball_center_left_y
  output->eyeball_center_left_y = input->eyeball_center_left_y;
  // eyeball_center_left_z
  output->eyeball_center_left_z = input->eyeball_center_left_z;
  // optical_axis_left_x
  output->optical_axis_left_x = input->optical_axis_left_x;
  // optical_axis_left_y
  output->optical_axis_left_y = input->optical_axis_left_y;
  // optical_axis_left_z
  output->optical_axis_left_z = input->optical_axis_left_z;
  // pupil_diameter_right
  output->pupil_diameter_right = input->pupil_diameter_right;
  // eyeball_center_right_x
  output->eyeball_center_right_x = input->eyeball_center_right_x;
  // eyeball_center_right_y
  output->eyeball_center_right_y = input->eyeball_center_right_y;
  // eyeball_center_right_z
  output->eyeball_center_right_z = input->eyeball_center_right_z;
  // optical_axis_right_x
  output->optical_axis_right_x = input->optical_axis_right_x;
  // optical_axis_right_y
  output->optical_axis_right_y = input->optical_axis_right_y;
  // optical_axis_right_z
  output->optical_axis_right_z = input->optical_axis_right_z;
  // timestamp_unix_seconds
  output->timestamp_unix_seconds = input->timestamp_unix_seconds;
  return true;
}

egocentric_msg__msg__GazeData *
egocentric_msg__msg__GazeData__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  egocentric_msg__msg__GazeData * msg = (egocentric_msg__msg__GazeData *)allocator.allocate(sizeof(egocentric_msg__msg__GazeData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(egocentric_msg__msg__GazeData));
  bool success = egocentric_msg__msg__GazeData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
egocentric_msg__msg__GazeData__destroy(egocentric_msg__msg__GazeData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    egocentric_msg__msg__GazeData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
egocentric_msg__msg__GazeData__Sequence__init(egocentric_msg__msg__GazeData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  egocentric_msg__msg__GazeData * data = NULL;

  if (size) {
    data = (egocentric_msg__msg__GazeData *)allocator.zero_allocate(size, sizeof(egocentric_msg__msg__GazeData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = egocentric_msg__msg__GazeData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        egocentric_msg__msg__GazeData__fini(&data[i - 1]);
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
egocentric_msg__msg__GazeData__Sequence__fini(egocentric_msg__msg__GazeData__Sequence * array)
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
      egocentric_msg__msg__GazeData__fini(&array->data[i]);
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

egocentric_msg__msg__GazeData__Sequence *
egocentric_msg__msg__GazeData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  egocentric_msg__msg__GazeData__Sequence * array = (egocentric_msg__msg__GazeData__Sequence *)allocator.allocate(sizeof(egocentric_msg__msg__GazeData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = egocentric_msg__msg__GazeData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
egocentric_msg__msg__GazeData__Sequence__destroy(egocentric_msg__msg__GazeData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    egocentric_msg__msg__GazeData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
egocentric_msg__msg__GazeData__Sequence__are_equal(const egocentric_msg__msg__GazeData__Sequence * lhs, const egocentric_msg__msg__GazeData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!egocentric_msg__msg__GazeData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
egocentric_msg__msg__GazeData__Sequence__copy(
  const egocentric_msg__msg__GazeData__Sequence * input,
  egocentric_msg__msg__GazeData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(egocentric_msg__msg__GazeData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    egocentric_msg__msg__GazeData * data =
      (egocentric_msg__msg__GazeData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!egocentric_msg__msg__GazeData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          egocentric_msg__msg__GazeData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!egocentric_msg__msg__GazeData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
