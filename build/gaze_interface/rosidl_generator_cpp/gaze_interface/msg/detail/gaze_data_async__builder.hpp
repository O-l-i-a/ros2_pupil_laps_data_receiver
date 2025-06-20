// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gaze_interface:msg/GazeDataAsync.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gaze_interface/msg/gaze_data_async.hpp"


#ifndef GAZE_INTERFACE__MSG__DETAIL__GAZE_DATA_ASYNC__BUILDER_HPP_
#define GAZE_INTERFACE__MSG__DETAIL__GAZE_DATA_ASYNC__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gaze_interface/msg/detail/gaze_data_async__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gaze_interface
{

namespace msg
{

namespace builder
{

class Init_GazeDataAsync_timestamp_unix_seconds
{
public:
  explicit Init_GazeDataAsync_timestamp_unix_seconds(::gaze_interface::msg::GazeDataAsync & msg)
  : msg_(msg)
  {}
  ::gaze_interface::msg::GazeDataAsync timestamp_unix_seconds(::gaze_interface::msg::GazeDataAsync::_timestamp_unix_seconds_type arg)
  {
    msg_.timestamp_unix_seconds = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gaze_interface::msg::GazeDataAsync msg_;
};

class Init_GazeDataAsync_norm_pos_y
{
public:
  explicit Init_GazeDataAsync_norm_pos_y(::gaze_interface::msg::GazeDataAsync & msg)
  : msg_(msg)
  {}
  Init_GazeDataAsync_timestamp_unix_seconds norm_pos_y(::gaze_interface::msg::GazeDataAsync::_norm_pos_y_type arg)
  {
    msg_.norm_pos_y = std::move(arg);
    return Init_GazeDataAsync_timestamp_unix_seconds(msg_);
  }

private:
  ::gaze_interface::msg::GazeDataAsync msg_;
};

class Init_GazeDataAsync_norm_pos_x
{
public:
  explicit Init_GazeDataAsync_norm_pos_x(::gaze_interface::msg::GazeDataAsync & msg)
  : msg_(msg)
  {}
  Init_GazeDataAsync_norm_pos_y norm_pos_x(::gaze_interface::msg::GazeDataAsync::_norm_pos_x_type arg)
  {
    msg_.norm_pos_x = std::move(arg);
    return Init_GazeDataAsync_norm_pos_y(msg_);
  }

private:
  ::gaze_interface::msg::GazeDataAsync msg_;
};

class Init_GazeDataAsync_header
{
public:
  Init_GazeDataAsync_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GazeDataAsync_norm_pos_x header(::gaze_interface::msg::GazeDataAsync::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_GazeDataAsync_norm_pos_x(msg_);
  }

private:
  ::gaze_interface::msg::GazeDataAsync msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gaze_interface::msg::GazeDataAsync>()
{
  return gaze_interface::msg::builder::Init_GazeDataAsync_header();
}

}  // namespace gaze_interface

#endif  // GAZE_INTERFACE__MSG__DETAIL__GAZE_DATA_ASYNC__BUILDER_HPP_
