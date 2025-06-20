// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from gaze_interface:msg/GazeDataAsync.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "gaze_interface/msg/detail/gaze_data_async__functions.h"
#include "gaze_interface/msg/detail/gaze_data_async__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace gaze_interface
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void GazeDataAsync_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) gaze_interface::msg::GazeDataAsync(_init);
}

void GazeDataAsync_fini_function(void * message_memory)
{
  auto typed_message = static_cast<gaze_interface::msg::GazeDataAsync *>(message_memory);
  typed_message->~GazeDataAsync();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GazeDataAsync_message_member_array[4] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gaze_interface::msg::GazeDataAsync, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "norm_pos_x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gaze_interface::msg::GazeDataAsync, norm_pos_x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "norm_pos_y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gaze_interface::msg::GazeDataAsync, norm_pos_y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "timestamp_unix_seconds",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gaze_interface::msg::GazeDataAsync, timestamp_unix_seconds),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GazeDataAsync_message_members = {
  "gaze_interface::msg",  // message namespace
  "GazeDataAsync",  // message name
  4,  // number of fields
  sizeof(gaze_interface::msg::GazeDataAsync),
  false,  // has_any_key_member_
  GazeDataAsync_message_member_array,  // message members
  GazeDataAsync_init_function,  // function to initialize message memory (memory has to be allocated)
  GazeDataAsync_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GazeDataAsync_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GazeDataAsync_message_members,
  get_message_typesupport_handle_function,
  &gaze_interface__msg__GazeDataAsync__get_type_hash,
  &gaze_interface__msg__GazeDataAsync__get_type_description,
  &gaze_interface__msg__GazeDataAsync__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace gaze_interface


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<gaze_interface::msg::GazeDataAsync>()
{
  return &::gaze_interface::msg::rosidl_typesupport_introspection_cpp::GazeDataAsync_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, gaze_interface, msg, GazeDataAsync)() {
  return &::gaze_interface::msg::rosidl_typesupport_introspection_cpp::GazeDataAsync_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
