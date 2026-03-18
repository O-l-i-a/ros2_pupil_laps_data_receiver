// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from blink_interface:msg/EyeStateData.idl
// generated code does not contain a copyright notice
#include "blink_interface/msg/detail/eye_state_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `event_name`
#include "rosidl_runtime_c/string_functions.h"

bool
blink_interface__msg__EyeStateData__init(blink_interface__msg__EyeStateData * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    blink_interface__msg__EyeStateData__fini(msg);
    return false;
  }
  // event_name
  if (!rosidl_runtime_c__String__init(&msg->event_name)) {
    blink_interface__msg__EyeStateData__fini(msg);
    return false;
  }
  // event_type
  // start_time_ns
  // end_time_ns
  // rtp_ts_unix_seconds
  // has_end_time
  // start_gaze_x
  // start_gaze_y
  // end_gaze_x
  // end_gaze_y
  // mean_gaze_x
  // mean_gaze_y
  // amplitude_pixels
  // amplitude_angle_deg
  // mean_velocity
  // max_velocity
  return true;
}

void
blink_interface__msg__EyeStateData__fini(blink_interface__msg__EyeStateData * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // event_name
  rosidl_runtime_c__String__fini(&msg->event_name);
  // event_type
  // start_time_ns
  // end_time_ns
  // rtp_ts_unix_seconds
  // has_end_time
  // start_gaze_x
  // start_gaze_y
  // end_gaze_x
  // end_gaze_y
  // mean_gaze_x
  // mean_gaze_y
  // amplitude_pixels
  // amplitude_angle_deg
  // mean_velocity
  // max_velocity
}

bool
blink_interface__msg__EyeStateData__are_equal(const blink_interface__msg__EyeStateData * lhs, const blink_interface__msg__EyeStateData * rhs)
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
  // event_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->event_name), &(rhs->event_name)))
  {
    return false;
  }
  // event_type
  if (lhs->event_type != rhs->event_type) {
    return false;
  }
  // start_time_ns
  if (lhs->start_time_ns != rhs->start_time_ns) {
    return false;
  }
  // end_time_ns
  if (lhs->end_time_ns != rhs->end_time_ns) {
    return false;
  }
  // rtp_ts_unix_seconds
  if (lhs->rtp_ts_unix_seconds != rhs->rtp_ts_unix_seconds) {
    return false;
  }
  // has_end_time
  if (lhs->has_end_time != rhs->has_end_time) {
    return false;
  }
  // start_gaze_x
  if (lhs->start_gaze_x != rhs->start_gaze_x) {
    return false;
  }
  // start_gaze_y
  if (lhs->start_gaze_y != rhs->start_gaze_y) {
    return false;
  }
  // end_gaze_x
  if (lhs->end_gaze_x != rhs->end_gaze_x) {
    return false;
  }
  // end_gaze_y
  if (lhs->end_gaze_y != rhs->end_gaze_y) {
    return false;
  }
  // mean_gaze_x
  if (lhs->mean_gaze_x != rhs->mean_gaze_x) {
    return false;
  }
  // mean_gaze_y
  if (lhs->mean_gaze_y != rhs->mean_gaze_y) {
    return false;
  }
  // amplitude_pixels
  if (lhs->amplitude_pixels != rhs->amplitude_pixels) {
    return false;
  }
  // amplitude_angle_deg
  if (lhs->amplitude_angle_deg != rhs->amplitude_angle_deg) {
    return false;
  }
  // mean_velocity
  if (lhs->mean_velocity != rhs->mean_velocity) {
    return false;
  }
  // max_velocity
  if (lhs->max_velocity != rhs->max_velocity) {
    return false;
  }
  return true;
}

bool
blink_interface__msg__EyeStateData__copy(
  const blink_interface__msg__EyeStateData * input,
  blink_interface__msg__EyeStateData * output)
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
  // event_name
  if (!rosidl_runtime_c__String__copy(
      &(input->event_name), &(output->event_name)))
  {
    return false;
  }
  // event_type
  output->event_type = input->event_type;
  // start_time_ns
  output->start_time_ns = input->start_time_ns;
  // end_time_ns
  output->end_time_ns = input->end_time_ns;
  // rtp_ts_unix_seconds
  output->rtp_ts_unix_seconds = input->rtp_ts_unix_seconds;
  // has_end_time
  output->has_end_time = input->has_end_time;
  // start_gaze_x
  output->start_gaze_x = input->start_gaze_x;
  // start_gaze_y
  output->start_gaze_y = input->start_gaze_y;
  // end_gaze_x
  output->end_gaze_x = input->end_gaze_x;
  // end_gaze_y
  output->end_gaze_y = input->end_gaze_y;
  // mean_gaze_x
  output->mean_gaze_x = input->mean_gaze_x;
  // mean_gaze_y
  output->mean_gaze_y = input->mean_gaze_y;
  // amplitude_pixels
  output->amplitude_pixels = input->amplitude_pixels;
  // amplitude_angle_deg
  output->amplitude_angle_deg = input->amplitude_angle_deg;
  // mean_velocity
  output->mean_velocity = input->mean_velocity;
  // max_velocity
  output->max_velocity = input->max_velocity;
  return true;
}

blink_interface__msg__EyeStateData *
blink_interface__msg__EyeStateData__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  blink_interface__msg__EyeStateData * msg = (blink_interface__msg__EyeStateData *)allocator.allocate(sizeof(blink_interface__msg__EyeStateData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(blink_interface__msg__EyeStateData));
  bool success = blink_interface__msg__EyeStateData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
blink_interface__msg__EyeStateData__destroy(blink_interface__msg__EyeStateData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    blink_interface__msg__EyeStateData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
blink_interface__msg__EyeStateData__Sequence__init(blink_interface__msg__EyeStateData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  blink_interface__msg__EyeStateData * data = NULL;

  if (size) {
    data = (blink_interface__msg__EyeStateData *)allocator.zero_allocate(size, sizeof(blink_interface__msg__EyeStateData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = blink_interface__msg__EyeStateData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        blink_interface__msg__EyeStateData__fini(&data[i - 1]);
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
blink_interface__msg__EyeStateData__Sequence__fini(blink_interface__msg__EyeStateData__Sequence * array)
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
      blink_interface__msg__EyeStateData__fini(&array->data[i]);
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

blink_interface__msg__EyeStateData__Sequence *
blink_interface__msg__EyeStateData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  blink_interface__msg__EyeStateData__Sequence * array = (blink_interface__msg__EyeStateData__Sequence *)allocator.allocate(sizeof(blink_interface__msg__EyeStateData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = blink_interface__msg__EyeStateData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
blink_interface__msg__EyeStateData__Sequence__destroy(blink_interface__msg__EyeStateData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    blink_interface__msg__EyeStateData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
blink_interface__msg__EyeStateData__Sequence__are_equal(const blink_interface__msg__EyeStateData__Sequence * lhs, const blink_interface__msg__EyeStateData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!blink_interface__msg__EyeStateData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
blink_interface__msg__EyeStateData__Sequence__copy(
  const blink_interface__msg__EyeStateData__Sequence * input,
  blink_interface__msg__EyeStateData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(blink_interface__msg__EyeStateData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    blink_interface__msg__EyeStateData * data =
      (blink_interface__msg__EyeStateData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!blink_interface__msg__EyeStateData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          blink_interface__msg__EyeStateData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!blink_interface__msg__EyeStateData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
