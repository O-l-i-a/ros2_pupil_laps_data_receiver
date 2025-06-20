// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from zed_msgs:srv/StartSvoRec.idl
// generated code does not contain a copyright notice
#include "zed_msgs/srv/detail/start_svo_rec__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `svo_filename`
#include "rosidl_runtime_c/string_functions.h"

bool
zed_msgs__srv__StartSvoRec_Request__init(zed_msgs__srv__StartSvoRec_Request * msg)
{
  if (!msg) {
    return false;
  }
  // bitrate
  // compression_mode
  // target_framerate
  // input_transcode
  // svo_filename
  if (!rosidl_runtime_c__String__init(&msg->svo_filename)) {
    zed_msgs__srv__StartSvoRec_Request__fini(msg);
    return false;
  }
  return true;
}

void
zed_msgs__srv__StartSvoRec_Request__fini(zed_msgs__srv__StartSvoRec_Request * msg)
{
  if (!msg) {
    return;
  }
  // bitrate
  // compression_mode
  // target_framerate
  // input_transcode
  // svo_filename
  rosidl_runtime_c__String__fini(&msg->svo_filename);
}

bool
zed_msgs__srv__StartSvoRec_Request__are_equal(const zed_msgs__srv__StartSvoRec_Request * lhs, const zed_msgs__srv__StartSvoRec_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // bitrate
  if (lhs->bitrate != rhs->bitrate) {
    return false;
  }
  // compression_mode
  if (lhs->compression_mode != rhs->compression_mode) {
    return false;
  }
  // target_framerate
  if (lhs->target_framerate != rhs->target_framerate) {
    return false;
  }
  // input_transcode
  if (lhs->input_transcode != rhs->input_transcode) {
    return false;
  }
  // svo_filename
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->svo_filename), &(rhs->svo_filename)))
  {
    return false;
  }
  return true;
}

bool
zed_msgs__srv__StartSvoRec_Request__copy(
  const zed_msgs__srv__StartSvoRec_Request * input,
  zed_msgs__srv__StartSvoRec_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // bitrate
  output->bitrate = input->bitrate;
  // compression_mode
  output->compression_mode = input->compression_mode;
  // target_framerate
  output->target_framerate = input->target_framerate;
  // input_transcode
  output->input_transcode = input->input_transcode;
  // svo_filename
  if (!rosidl_runtime_c__String__copy(
      &(input->svo_filename), &(output->svo_filename)))
  {
    return false;
  }
  return true;
}

zed_msgs__srv__StartSvoRec_Request *
zed_msgs__srv__StartSvoRec_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zed_msgs__srv__StartSvoRec_Request * msg = (zed_msgs__srv__StartSvoRec_Request *)allocator.allocate(sizeof(zed_msgs__srv__StartSvoRec_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(zed_msgs__srv__StartSvoRec_Request));
  bool success = zed_msgs__srv__StartSvoRec_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
zed_msgs__srv__StartSvoRec_Request__destroy(zed_msgs__srv__StartSvoRec_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    zed_msgs__srv__StartSvoRec_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
zed_msgs__srv__StartSvoRec_Request__Sequence__init(zed_msgs__srv__StartSvoRec_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zed_msgs__srv__StartSvoRec_Request * data = NULL;

  if (size) {
    data = (zed_msgs__srv__StartSvoRec_Request *)allocator.zero_allocate(size, sizeof(zed_msgs__srv__StartSvoRec_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = zed_msgs__srv__StartSvoRec_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        zed_msgs__srv__StartSvoRec_Request__fini(&data[i - 1]);
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
zed_msgs__srv__StartSvoRec_Request__Sequence__fini(zed_msgs__srv__StartSvoRec_Request__Sequence * array)
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
      zed_msgs__srv__StartSvoRec_Request__fini(&array->data[i]);
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

zed_msgs__srv__StartSvoRec_Request__Sequence *
zed_msgs__srv__StartSvoRec_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zed_msgs__srv__StartSvoRec_Request__Sequence * array = (zed_msgs__srv__StartSvoRec_Request__Sequence *)allocator.allocate(sizeof(zed_msgs__srv__StartSvoRec_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = zed_msgs__srv__StartSvoRec_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
zed_msgs__srv__StartSvoRec_Request__Sequence__destroy(zed_msgs__srv__StartSvoRec_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    zed_msgs__srv__StartSvoRec_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
zed_msgs__srv__StartSvoRec_Request__Sequence__are_equal(const zed_msgs__srv__StartSvoRec_Request__Sequence * lhs, const zed_msgs__srv__StartSvoRec_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!zed_msgs__srv__StartSvoRec_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
zed_msgs__srv__StartSvoRec_Request__Sequence__copy(
  const zed_msgs__srv__StartSvoRec_Request__Sequence * input,
  zed_msgs__srv__StartSvoRec_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(zed_msgs__srv__StartSvoRec_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    zed_msgs__srv__StartSvoRec_Request * data =
      (zed_msgs__srv__StartSvoRec_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!zed_msgs__srv__StartSvoRec_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          zed_msgs__srv__StartSvoRec_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!zed_msgs__srv__StartSvoRec_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
zed_msgs__srv__StartSvoRec_Response__init(zed_msgs__srv__StartSvoRec_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    zed_msgs__srv__StartSvoRec_Response__fini(msg);
    return false;
  }
  return true;
}

void
zed_msgs__srv__StartSvoRec_Response__fini(zed_msgs__srv__StartSvoRec_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
zed_msgs__srv__StartSvoRec_Response__are_equal(const zed_msgs__srv__StartSvoRec_Response * lhs, const zed_msgs__srv__StartSvoRec_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
zed_msgs__srv__StartSvoRec_Response__copy(
  const zed_msgs__srv__StartSvoRec_Response * input,
  zed_msgs__srv__StartSvoRec_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

zed_msgs__srv__StartSvoRec_Response *
zed_msgs__srv__StartSvoRec_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zed_msgs__srv__StartSvoRec_Response * msg = (zed_msgs__srv__StartSvoRec_Response *)allocator.allocate(sizeof(zed_msgs__srv__StartSvoRec_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(zed_msgs__srv__StartSvoRec_Response));
  bool success = zed_msgs__srv__StartSvoRec_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
zed_msgs__srv__StartSvoRec_Response__destroy(zed_msgs__srv__StartSvoRec_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    zed_msgs__srv__StartSvoRec_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
zed_msgs__srv__StartSvoRec_Response__Sequence__init(zed_msgs__srv__StartSvoRec_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zed_msgs__srv__StartSvoRec_Response * data = NULL;

  if (size) {
    data = (zed_msgs__srv__StartSvoRec_Response *)allocator.zero_allocate(size, sizeof(zed_msgs__srv__StartSvoRec_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = zed_msgs__srv__StartSvoRec_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        zed_msgs__srv__StartSvoRec_Response__fini(&data[i - 1]);
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
zed_msgs__srv__StartSvoRec_Response__Sequence__fini(zed_msgs__srv__StartSvoRec_Response__Sequence * array)
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
      zed_msgs__srv__StartSvoRec_Response__fini(&array->data[i]);
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

zed_msgs__srv__StartSvoRec_Response__Sequence *
zed_msgs__srv__StartSvoRec_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zed_msgs__srv__StartSvoRec_Response__Sequence * array = (zed_msgs__srv__StartSvoRec_Response__Sequence *)allocator.allocate(sizeof(zed_msgs__srv__StartSvoRec_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = zed_msgs__srv__StartSvoRec_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
zed_msgs__srv__StartSvoRec_Response__Sequence__destroy(zed_msgs__srv__StartSvoRec_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    zed_msgs__srv__StartSvoRec_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
zed_msgs__srv__StartSvoRec_Response__Sequence__are_equal(const zed_msgs__srv__StartSvoRec_Response__Sequence * lhs, const zed_msgs__srv__StartSvoRec_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!zed_msgs__srv__StartSvoRec_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
zed_msgs__srv__StartSvoRec_Response__Sequence__copy(
  const zed_msgs__srv__StartSvoRec_Response__Sequence * input,
  zed_msgs__srv__StartSvoRec_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(zed_msgs__srv__StartSvoRec_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    zed_msgs__srv__StartSvoRec_Response * data =
      (zed_msgs__srv__StartSvoRec_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!zed_msgs__srv__StartSvoRec_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          zed_msgs__srv__StartSvoRec_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!zed_msgs__srv__StartSvoRec_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "zed_msgs/srv/detail/start_svo_rec__functions.h"

bool
zed_msgs__srv__StartSvoRec_Event__init(zed_msgs__srv__StartSvoRec_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    zed_msgs__srv__StartSvoRec_Event__fini(msg);
    return false;
  }
  // request
  if (!zed_msgs__srv__StartSvoRec_Request__Sequence__init(&msg->request, 0)) {
    zed_msgs__srv__StartSvoRec_Event__fini(msg);
    return false;
  }
  // response
  if (!zed_msgs__srv__StartSvoRec_Response__Sequence__init(&msg->response, 0)) {
    zed_msgs__srv__StartSvoRec_Event__fini(msg);
    return false;
  }
  return true;
}

void
zed_msgs__srv__StartSvoRec_Event__fini(zed_msgs__srv__StartSvoRec_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  zed_msgs__srv__StartSvoRec_Request__Sequence__fini(&msg->request);
  // response
  zed_msgs__srv__StartSvoRec_Response__Sequence__fini(&msg->response);
}

bool
zed_msgs__srv__StartSvoRec_Event__are_equal(const zed_msgs__srv__StartSvoRec_Event * lhs, const zed_msgs__srv__StartSvoRec_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!zed_msgs__srv__StartSvoRec_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!zed_msgs__srv__StartSvoRec_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
zed_msgs__srv__StartSvoRec_Event__copy(
  const zed_msgs__srv__StartSvoRec_Event * input,
  zed_msgs__srv__StartSvoRec_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!zed_msgs__srv__StartSvoRec_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!zed_msgs__srv__StartSvoRec_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

zed_msgs__srv__StartSvoRec_Event *
zed_msgs__srv__StartSvoRec_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zed_msgs__srv__StartSvoRec_Event * msg = (zed_msgs__srv__StartSvoRec_Event *)allocator.allocate(sizeof(zed_msgs__srv__StartSvoRec_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(zed_msgs__srv__StartSvoRec_Event));
  bool success = zed_msgs__srv__StartSvoRec_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
zed_msgs__srv__StartSvoRec_Event__destroy(zed_msgs__srv__StartSvoRec_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    zed_msgs__srv__StartSvoRec_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
zed_msgs__srv__StartSvoRec_Event__Sequence__init(zed_msgs__srv__StartSvoRec_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zed_msgs__srv__StartSvoRec_Event * data = NULL;

  if (size) {
    data = (zed_msgs__srv__StartSvoRec_Event *)allocator.zero_allocate(size, sizeof(zed_msgs__srv__StartSvoRec_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = zed_msgs__srv__StartSvoRec_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        zed_msgs__srv__StartSvoRec_Event__fini(&data[i - 1]);
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
zed_msgs__srv__StartSvoRec_Event__Sequence__fini(zed_msgs__srv__StartSvoRec_Event__Sequence * array)
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
      zed_msgs__srv__StartSvoRec_Event__fini(&array->data[i]);
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

zed_msgs__srv__StartSvoRec_Event__Sequence *
zed_msgs__srv__StartSvoRec_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zed_msgs__srv__StartSvoRec_Event__Sequence * array = (zed_msgs__srv__StartSvoRec_Event__Sequence *)allocator.allocate(sizeof(zed_msgs__srv__StartSvoRec_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = zed_msgs__srv__StartSvoRec_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
zed_msgs__srv__StartSvoRec_Event__Sequence__destroy(zed_msgs__srv__StartSvoRec_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    zed_msgs__srv__StartSvoRec_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
zed_msgs__srv__StartSvoRec_Event__Sequence__are_equal(const zed_msgs__srv__StartSvoRec_Event__Sequence * lhs, const zed_msgs__srv__StartSvoRec_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!zed_msgs__srv__StartSvoRec_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
zed_msgs__srv__StartSvoRec_Event__Sequence__copy(
  const zed_msgs__srv__StartSvoRec_Event__Sequence * input,
  zed_msgs__srv__StartSvoRec_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(zed_msgs__srv__StartSvoRec_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    zed_msgs__srv__StartSvoRec_Event * data =
      (zed_msgs__srv__StartSvoRec_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!zed_msgs__srv__StartSvoRec_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          zed_msgs__srv__StartSvoRec_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!zed_msgs__srv__StartSvoRec_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
