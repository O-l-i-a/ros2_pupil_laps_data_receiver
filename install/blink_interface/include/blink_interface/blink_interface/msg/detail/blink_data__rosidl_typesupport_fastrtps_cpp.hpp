// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from blink_interface:msg/BlinkData.idl
// generated code does not contain a copyright notice

#ifndef BLINK_INTERFACE__MSG__DETAIL__BLINK_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define BLINK_INTERFACE__MSG__DETAIL__BLINK_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "blink_interface/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "blink_interface/msg/detail/blink_data__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace blink_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_blink_interface
cdr_serialize(
  const blink_interface::msg::BlinkData & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_blink_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  blink_interface::msg::BlinkData & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_blink_interface
get_serialized_size(
  const blink_interface::msg::BlinkData & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_blink_interface
max_serialized_size_BlinkData(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_blink_interface
cdr_serialize_key(
  const blink_interface::msg::BlinkData & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_blink_interface
get_serialized_size_key(
  const blink_interface::msg::BlinkData & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_blink_interface
max_serialized_size_key_BlinkData(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace blink_interface

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_blink_interface
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, blink_interface, msg, BlinkData)();

#ifdef __cplusplus
}
#endif

#endif  // BLINK_INTERFACE__MSG__DETAIL__BLINK_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
