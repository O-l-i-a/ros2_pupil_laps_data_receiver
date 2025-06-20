// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from zed_msgs:srv/SetPose.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "zed_msgs/srv/detail/set_pose__rosidl_typesupport_introspection_c.h"
#include "zed_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "zed_msgs/srv/detail/set_pose__functions.h"
#include "zed_msgs/srv/detail/set_pose__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  zed_msgs__srv__SetPose_Request__init(message_memory);
}

void zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_fini_function(void * message_memory)
{
  zed_msgs__srv__SetPose_Request__fini(message_memory);
}

size_t zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__size_function__SetPose_Request__pos(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_const_function__SetPose_Request__pos(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_function__SetPose_Request__pos(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__fetch_function__SetPose_Request__pos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_const_function__SetPose_Request__pos(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__assign_function__SetPose_Request__pos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_function__SetPose_Request__pos(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__size_function__SetPose_Request__orient(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_const_function__SetPose_Request__orient(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_function__SetPose_Request__orient(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__fetch_function__SetPose_Request__orient(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_const_function__SetPose_Request__orient(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__assign_function__SetPose_Request__orient(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_function__SetPose_Request__orient(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_message_member_array[2] = {
  {
    "pos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(zed_msgs__srv__SetPose_Request, pos),  // bytes offset in struct
    NULL,  // default value
    zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__size_function__SetPose_Request__pos,  // size() function pointer
    zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_const_function__SetPose_Request__pos,  // get_const(index) function pointer
    zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_function__SetPose_Request__pos,  // get(index) function pointer
    zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__fetch_function__SetPose_Request__pos,  // fetch(index, &value) function pointer
    zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__assign_function__SetPose_Request__pos,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "orient",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(zed_msgs__srv__SetPose_Request, orient),  // bytes offset in struct
    NULL,  // default value
    zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__size_function__SetPose_Request__orient,  // size() function pointer
    zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_const_function__SetPose_Request__orient,  // get_const(index) function pointer
    zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_function__SetPose_Request__orient,  // get(index) function pointer
    zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__fetch_function__SetPose_Request__orient,  // fetch(index, &value) function pointer
    zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__assign_function__SetPose_Request__orient,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_message_members = {
  "zed_msgs__srv",  // message namespace
  "SetPose_Request",  // message name
  2,  // number of fields
  sizeof(zed_msgs__srv__SetPose_Request),
  false,  // has_any_key_member_
  zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_message_member_array,  // message members
  zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_message_type_support_handle = {
  0,
  &zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_message_members,
  get_message_typesupport_handle_function,
  &zed_msgs__srv__SetPose_Request__get_type_hash,
  &zed_msgs__srv__SetPose_Request__get_type_description,
  &zed_msgs__srv__SetPose_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_zed_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_msgs, srv, SetPose_Request)() {
  if (!zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_message_type_support_handle.typesupport_identifier) {
    zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "zed_msgs/srv/detail/set_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "zed_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "zed_msgs/srv/detail/set_pose__functions.h"
// already included above
// #include "zed_msgs/srv/detail/set_pose__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void zed_msgs__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  zed_msgs__srv__SetPose_Response__init(message_memory);
}

void zed_msgs__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_fini_function(void * message_memory)
{
  zed_msgs__srv__SetPose_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember zed_msgs__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_msgs__srv__SetPose_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_msgs__srv__SetPose_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers zed_msgs__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_message_members = {
  "zed_msgs__srv",  // message namespace
  "SetPose_Response",  // message name
  2,  // number of fields
  sizeof(zed_msgs__srv__SetPose_Response),
  false,  // has_any_key_member_
  zed_msgs__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_message_member_array,  // message members
  zed_msgs__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  zed_msgs__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t zed_msgs__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_message_type_support_handle = {
  0,
  &zed_msgs__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_message_members,
  get_message_typesupport_handle_function,
  &zed_msgs__srv__SetPose_Response__get_type_hash,
  &zed_msgs__srv__SetPose_Response__get_type_description,
  &zed_msgs__srv__SetPose_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_zed_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_msgs, srv, SetPose_Response)() {
  if (!zed_msgs__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_message_type_support_handle.typesupport_identifier) {
    zed_msgs__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &zed_msgs__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "zed_msgs/srv/detail/set_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "zed_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "zed_msgs/srv/detail/set_pose__functions.h"
// already included above
// #include "zed_msgs/srv/detail/set_pose__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "zed_msgs/srv/set_pose.h"
// Member `request`
// Member `response`
// already included above
// #include "zed_msgs/srv/detail/set_pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__SetPose_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  zed_msgs__srv__SetPose_Event__init(message_memory);
}

void zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__SetPose_Event_fini_function(void * message_memory)
{
  zed_msgs__srv__SetPose_Event__fini(message_memory);
}

size_t zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__size_function__SetPose_Event__request(
  const void * untyped_member)
{
  const zed_msgs__srv__SetPose_Request__Sequence * member =
    (const zed_msgs__srv__SetPose_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__get_const_function__SetPose_Event__request(
  const void * untyped_member, size_t index)
{
  const zed_msgs__srv__SetPose_Request__Sequence * member =
    (const zed_msgs__srv__SetPose_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__get_function__SetPose_Event__request(
  void * untyped_member, size_t index)
{
  zed_msgs__srv__SetPose_Request__Sequence * member =
    (zed_msgs__srv__SetPose_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__fetch_function__SetPose_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const zed_msgs__srv__SetPose_Request * item =
    ((const zed_msgs__srv__SetPose_Request *)
    zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__get_const_function__SetPose_Event__request(untyped_member, index));
  zed_msgs__srv__SetPose_Request * value =
    (zed_msgs__srv__SetPose_Request *)(untyped_value);
  *value = *item;
}

void zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__assign_function__SetPose_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  zed_msgs__srv__SetPose_Request * item =
    ((zed_msgs__srv__SetPose_Request *)
    zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__get_function__SetPose_Event__request(untyped_member, index));
  const zed_msgs__srv__SetPose_Request * value =
    (const zed_msgs__srv__SetPose_Request *)(untyped_value);
  *item = *value;
}

bool zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__resize_function__SetPose_Event__request(
  void * untyped_member, size_t size)
{
  zed_msgs__srv__SetPose_Request__Sequence * member =
    (zed_msgs__srv__SetPose_Request__Sequence *)(untyped_member);
  zed_msgs__srv__SetPose_Request__Sequence__fini(member);
  return zed_msgs__srv__SetPose_Request__Sequence__init(member, size);
}

size_t zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__size_function__SetPose_Event__response(
  const void * untyped_member)
{
  const zed_msgs__srv__SetPose_Response__Sequence * member =
    (const zed_msgs__srv__SetPose_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__get_const_function__SetPose_Event__response(
  const void * untyped_member, size_t index)
{
  const zed_msgs__srv__SetPose_Response__Sequence * member =
    (const zed_msgs__srv__SetPose_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__get_function__SetPose_Event__response(
  void * untyped_member, size_t index)
{
  zed_msgs__srv__SetPose_Response__Sequence * member =
    (zed_msgs__srv__SetPose_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__fetch_function__SetPose_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const zed_msgs__srv__SetPose_Response * item =
    ((const zed_msgs__srv__SetPose_Response *)
    zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__get_const_function__SetPose_Event__response(untyped_member, index));
  zed_msgs__srv__SetPose_Response * value =
    (zed_msgs__srv__SetPose_Response *)(untyped_value);
  *value = *item;
}

void zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__assign_function__SetPose_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  zed_msgs__srv__SetPose_Response * item =
    ((zed_msgs__srv__SetPose_Response *)
    zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__get_function__SetPose_Event__response(untyped_member, index));
  const zed_msgs__srv__SetPose_Response * value =
    (const zed_msgs__srv__SetPose_Response *)(untyped_value);
  *item = *value;
}

bool zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__resize_function__SetPose_Event__response(
  void * untyped_member, size_t size)
{
  zed_msgs__srv__SetPose_Response__Sequence * member =
    (zed_msgs__srv__SetPose_Response__Sequence *)(untyped_member);
  zed_msgs__srv__SetPose_Response__Sequence__fini(member);
  return zed_msgs__srv__SetPose_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__SetPose_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_msgs__srv__SetPose_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(zed_msgs__srv__SetPose_Event, request),  // bytes offset in struct
    NULL,  // default value
    zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__size_function__SetPose_Event__request,  // size() function pointer
    zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__get_const_function__SetPose_Event__request,  // get_const(index) function pointer
    zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__get_function__SetPose_Event__request,  // get(index) function pointer
    zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__fetch_function__SetPose_Event__request,  // fetch(index, &value) function pointer
    zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__assign_function__SetPose_Event__request,  // assign(index, value) function pointer
    zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__resize_function__SetPose_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(zed_msgs__srv__SetPose_Event, response),  // bytes offset in struct
    NULL,  // default value
    zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__size_function__SetPose_Event__response,  // size() function pointer
    zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__get_const_function__SetPose_Event__response,  // get_const(index) function pointer
    zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__get_function__SetPose_Event__response,  // get(index) function pointer
    zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__fetch_function__SetPose_Event__response,  // fetch(index, &value) function pointer
    zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__assign_function__SetPose_Event__response,  // assign(index, value) function pointer
    zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__resize_function__SetPose_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__SetPose_Event_message_members = {
  "zed_msgs__srv",  // message namespace
  "SetPose_Event",  // message name
  3,  // number of fields
  sizeof(zed_msgs__srv__SetPose_Event),
  false,  // has_any_key_member_
  zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__SetPose_Event_message_member_array,  // message members
  zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__SetPose_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__SetPose_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__SetPose_Event_message_type_support_handle = {
  0,
  &zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__SetPose_Event_message_members,
  get_message_typesupport_handle_function,
  &zed_msgs__srv__SetPose_Event__get_type_hash,
  &zed_msgs__srv__SetPose_Event__get_type_description,
  &zed_msgs__srv__SetPose_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_zed_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_msgs, srv, SetPose_Event)() {
  zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__SetPose_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__SetPose_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_msgs, srv, SetPose_Request)();
  zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__SetPose_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_msgs, srv, SetPose_Response)();
  if (!zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__SetPose_Event_message_type_support_handle.typesupport_identifier) {
    zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__SetPose_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__SetPose_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "zed_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "zed_msgs/srv/detail/set_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers zed_msgs__srv__detail__set_pose__rosidl_typesupport_introspection_c__SetPose_service_members = {
  "zed_msgs__srv",  // service namespace
  "SetPose",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // zed_msgs__srv__detail__set_pose__rosidl_typesupport_introspection_c__SetPose_Request_message_type_support_handle,
  NULL,  // response message
  // zed_msgs__srv__detail__set_pose__rosidl_typesupport_introspection_c__SetPose_Response_message_type_support_handle
  NULL  // event_message
  // zed_msgs__srv__detail__set_pose__rosidl_typesupport_introspection_c__SetPose_Response_message_type_support_handle
};


static rosidl_service_type_support_t zed_msgs__srv__detail__set_pose__rosidl_typesupport_introspection_c__SetPose_service_type_support_handle = {
  0,
  &zed_msgs__srv__detail__set_pose__rosidl_typesupport_introspection_c__SetPose_service_members,
  get_service_typesupport_handle_function,
  &zed_msgs__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_message_type_support_handle,
  &zed_msgs__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_message_type_support_handle,
  &zed_msgs__srv__SetPose_Event__rosidl_typesupport_introspection_c__SetPose_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    zed_msgs,
    srv,
    SetPose
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    zed_msgs,
    srv,
    SetPose
  ),
  &zed_msgs__srv__SetPose__get_type_hash,
  &zed_msgs__srv__SetPose__get_type_description,
  &zed_msgs__srv__SetPose__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_msgs, srv, SetPose_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_msgs, srv, SetPose_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_msgs, srv, SetPose_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_zed_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_msgs, srv, SetPose)(void) {
  if (!zed_msgs__srv__detail__set_pose__rosidl_typesupport_introspection_c__SetPose_service_type_support_handle.typesupport_identifier) {
    zed_msgs__srv__detail__set_pose__rosidl_typesupport_introspection_c__SetPose_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)zed_msgs__srv__detail__set_pose__rosidl_typesupport_introspection_c__SetPose_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_msgs, srv, SetPose_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_msgs, srv, SetPose_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_msgs, srv, SetPose_Event)()->data;
  }

  return &zed_msgs__srv__detail__set_pose__rosidl_typesupport_introspection_c__SetPose_service_type_support_handle;
}
