// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from blink_interface:msg/BlinkData.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "blink_interface/msg/detail/blink_data__functions.h"
#include "blink_interface/msg/detail/blink_data__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace blink_interface
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void BlinkData_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) blink_interface::msg::BlinkData(_init);
}

void BlinkData_fini_function(void * message_memory)
{
  auto typed_message = static_cast<blink_interface::msg::BlinkData *>(message_memory);
  typed_message->~BlinkData();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember BlinkData_message_member_array[3] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(blink_interface::msg::BlinkData, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "end_time_ns",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(blink_interface::msg::BlinkData, end_time_ns),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "start_time_ns",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(blink_interface::msg::BlinkData, start_time_ns),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers BlinkData_message_members = {
  "blink_interface::msg",  // message namespace
  "BlinkData",  // message name
  3,  // number of fields
  sizeof(blink_interface::msg::BlinkData),
  false,  // has_any_key_member_
  BlinkData_message_member_array,  // message members
  BlinkData_init_function,  // function to initialize message memory (memory has to be allocated)
  BlinkData_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t BlinkData_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &BlinkData_message_members,
  get_message_typesupport_handle_function,
  &blink_interface__msg__BlinkData__get_type_hash,
  &blink_interface__msg__BlinkData__get_type_description,
  &blink_interface__msg__BlinkData__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace blink_interface


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<blink_interface::msg::BlinkData>()
{
  return &::blink_interface::msg::rosidl_typesupport_introspection_cpp::BlinkData_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, blink_interface, msg, BlinkData)() {
  return &::blink_interface::msg::rosidl_typesupport_introspection_cpp::BlinkData_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
