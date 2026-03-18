// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from blink_interface:msg/BlinkData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "blink_interface/msg/detail/blink_data__rosidl_typesupport_introspection_c.h"
#include "blink_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "blink_interface/msg/detail/blink_data__functions.h"
#include "blink_interface/msg/detail/blink_data__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void blink_interface__msg__BlinkData__rosidl_typesupport_introspection_c__BlinkData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  blink_interface__msg__BlinkData__init(message_memory);
}

void blink_interface__msg__BlinkData__rosidl_typesupport_introspection_c__BlinkData_fini_function(void * message_memory)
{
  blink_interface__msg__BlinkData__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember blink_interface__msg__BlinkData__rosidl_typesupport_introspection_c__BlinkData_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(blink_interface__msg__BlinkData, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "end_time_ns",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(blink_interface__msg__BlinkData, end_time_ns),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "start_time_ns",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(blink_interface__msg__BlinkData, start_time_ns),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers blink_interface__msg__BlinkData__rosidl_typesupport_introspection_c__BlinkData_message_members = {
  "blink_interface__msg",  // message namespace
  "BlinkData",  // message name
  3,  // number of fields
  sizeof(blink_interface__msg__BlinkData),
  false,  // has_any_key_member_
  blink_interface__msg__BlinkData__rosidl_typesupport_introspection_c__BlinkData_message_member_array,  // message members
  blink_interface__msg__BlinkData__rosidl_typesupport_introspection_c__BlinkData_init_function,  // function to initialize message memory (memory has to be allocated)
  blink_interface__msg__BlinkData__rosidl_typesupport_introspection_c__BlinkData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t blink_interface__msg__BlinkData__rosidl_typesupport_introspection_c__BlinkData_message_type_support_handle = {
  0,
  &blink_interface__msg__BlinkData__rosidl_typesupport_introspection_c__BlinkData_message_members,
  get_message_typesupport_handle_function,
  &blink_interface__msg__BlinkData__get_type_hash,
  &blink_interface__msg__BlinkData__get_type_description,
  &blink_interface__msg__BlinkData__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_blink_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, blink_interface, msg, BlinkData)() {
  blink_interface__msg__BlinkData__rosidl_typesupport_introspection_c__BlinkData_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!blink_interface__msg__BlinkData__rosidl_typesupport_introspection_c__BlinkData_message_type_support_handle.typesupport_identifier) {
    blink_interface__msg__BlinkData__rosidl_typesupport_introspection_c__BlinkData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &blink_interface__msg__BlinkData__rosidl_typesupport_introspection_c__BlinkData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
