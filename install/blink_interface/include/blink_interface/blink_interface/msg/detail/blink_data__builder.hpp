// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from blink_interface:msg/BlinkData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "blink_interface/msg/blink_data.hpp"


#ifndef BLINK_INTERFACE__MSG__DETAIL__BLINK_DATA__BUILDER_HPP_
#define BLINK_INTERFACE__MSG__DETAIL__BLINK_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "blink_interface/msg/detail/blink_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace blink_interface
{

namespace msg
{

namespace builder
{

class Init_BlinkData_start_time_ns
{
public:
  explicit Init_BlinkData_start_time_ns(::blink_interface::msg::BlinkData & msg)
  : msg_(msg)
  {}
  ::blink_interface::msg::BlinkData start_time_ns(::blink_interface::msg::BlinkData::_start_time_ns_type arg)
  {
    msg_.start_time_ns = std::move(arg);
    return std::move(msg_);
  }

private:
  ::blink_interface::msg::BlinkData msg_;
};

class Init_BlinkData_end_time_ns
{
public:
  explicit Init_BlinkData_end_time_ns(::blink_interface::msg::BlinkData & msg)
  : msg_(msg)
  {}
  Init_BlinkData_start_time_ns end_time_ns(::blink_interface::msg::BlinkData::_end_time_ns_type arg)
  {
    msg_.end_time_ns = std::move(arg);
    return Init_BlinkData_start_time_ns(msg_);
  }

private:
  ::blink_interface::msg::BlinkData msg_;
};

class Init_BlinkData_header
{
public:
  Init_BlinkData_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BlinkData_end_time_ns header(::blink_interface::msg::BlinkData::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_BlinkData_end_time_ns(msg_);
  }

private:
  ::blink_interface::msg::BlinkData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::blink_interface::msg::BlinkData>()
{
  return blink_interface::msg::builder::Init_BlinkData_header();
}

}  // namespace blink_interface

#endif  // BLINK_INTERFACE__MSG__DETAIL__BLINK_DATA__BUILDER_HPP_
