// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from blink_interface:msg/BlinkData.idl
// generated code does not contain a copyright notice
#include "blink_interface/msg/detail/blink_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
blink_interface__msg__BlinkData__init(blink_interface__msg__BlinkData * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    blink_interface__msg__BlinkData__fini(msg);
    return false;
  }
  // end_time_ns
  // start_time_ns
  return true;
}

void
blink_interface__msg__BlinkData__fini(blink_interface__msg__BlinkData * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // end_time_ns
  // start_time_ns
}

bool
blink_interface__msg__BlinkData__are_equal(const blink_interface__msg__BlinkData * lhs, const blink_interface__msg__BlinkData * rhs)
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
  // end_time_ns
  if (lhs->end_time_ns != rhs->end_time_ns) {
    return false;
  }
  // start_time_ns
  if (lhs->start_time_ns != rhs->start_time_ns) {
    return false;
  }
  return true;
}

bool
blink_interface__msg__BlinkData__copy(
  const blink_interface__msg__BlinkData * input,
  blink_interface__msg__BlinkData * output)
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
  // end_time_ns
  output->end_time_ns = input->end_time_ns;
  // start_time_ns
  output->start_time_ns = input->start_time_ns;
  return true;
}

blink_interface__msg__BlinkData *
blink_interface__msg__BlinkData__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  blink_interface__msg__BlinkData * msg = (blink_interface__msg__BlinkData *)allocator.allocate(sizeof(blink_interface__msg__BlinkData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(blink_interface__msg__BlinkData));
  bool success = blink_interface__msg__BlinkData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
blink_interface__msg__BlinkData__destroy(blink_interface__msg__BlinkData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    blink_interface__msg__BlinkData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
blink_interface__msg__BlinkData__Sequence__init(blink_interface__msg__BlinkData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  blink_interface__msg__BlinkData * data = NULL;

  if (size) {
    data = (blink_interface__msg__BlinkData *)allocator.zero_allocate(size, sizeof(blink_interface__msg__BlinkData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = blink_interface__msg__BlinkData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        blink_interface__msg__BlinkData__fini(&data[i - 1]);
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
blink_interface__msg__BlinkData__Sequence__fini(blink_interface__msg__BlinkData__Sequence * array)
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
      blink_interface__msg__BlinkData__fini(&array->data[i]);
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

blink_interface__msg__BlinkData__Sequence *
blink_interface__msg__BlinkData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  blink_interface__msg__BlinkData__Sequence * array = (blink_interface__msg__BlinkData__Sequence *)allocator.allocate(sizeof(blink_interface__msg__BlinkData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = blink_interface__msg__BlinkData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
blink_interface__msg__BlinkData__Sequence__destroy(blink_interface__msg__BlinkData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    blink_interface__msg__BlinkData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
blink_interface__msg__BlinkData__Sequence__are_equal(const blink_interface__msg__BlinkData__Sequence * lhs, const blink_interface__msg__BlinkData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!blink_interface__msg__BlinkData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
blink_interface__msg__BlinkData__Sequence__copy(
  const blink_interface__msg__BlinkData__Sequence * input,
  blink_interface__msg__BlinkData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(blink_interface__msg__BlinkData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    blink_interface__msg__BlinkData * data =
      (blink_interface__msg__BlinkData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!blink_interface__msg__BlinkData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          blink_interface__msg__BlinkData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!blink_interface__msg__BlinkData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
