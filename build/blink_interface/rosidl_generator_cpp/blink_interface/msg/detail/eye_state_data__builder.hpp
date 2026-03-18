// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from blink_interface:msg/EyeStateData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "blink_interface/msg/eye_state_data.hpp"


#ifndef BLINK_INTERFACE__MSG__DETAIL__EYE_STATE_DATA__BUILDER_HPP_
#define BLINK_INTERFACE__MSG__DETAIL__EYE_STATE_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "blink_interface/msg/detail/eye_state_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace blink_interface
{

namespace msg
{

namespace builder
{

class Init_EyeStateData_max_velocity
{
public:
  explicit Init_EyeStateData_max_velocity(::blink_interface::msg::EyeStateData & msg)
  : msg_(msg)
  {}
  ::blink_interface::msg::EyeStateData max_velocity(::blink_interface::msg::EyeStateData::_max_velocity_type arg)
  {
    msg_.max_velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::blink_interface::msg::EyeStateData msg_;
};

class Init_EyeStateData_mean_velocity
{
public:
  explicit Init_EyeStateData_mean_velocity(::blink_interface::msg::EyeStateData & msg)
  : msg_(msg)
  {}
  Init_EyeStateData_max_velocity mean_velocity(::blink_interface::msg::EyeStateData::_mean_velocity_type arg)
  {
    msg_.mean_velocity = std::move(arg);
    return Init_EyeStateData_max_velocity(msg_);
  }

private:
  ::blink_interface::msg::EyeStateData msg_;
};

class Init_EyeStateData_amplitude_angle_deg
{
public:
  explicit Init_EyeStateData_amplitude_angle_deg(::blink_interface::msg::EyeStateData & msg)
  : msg_(msg)
  {}
  Init_EyeStateData_mean_velocity amplitude_angle_deg(::blink_interface::msg::EyeStateData::_amplitude_angle_deg_type arg)
  {
    msg_.amplitude_angle_deg = std::move(arg);
    return Init_EyeStateData_mean_velocity(msg_);
  }

private:
  ::blink_interface::msg::EyeStateData msg_;
};

class Init_EyeStateData_amplitude_pixels
{
public:
  explicit Init_EyeStateData_amplitude_pixels(::blink_interface::msg::EyeStateData & msg)
  : msg_(msg)
  {}
  Init_EyeStateData_amplitude_angle_deg amplitude_pixels(::blink_interface::msg::EyeStateData::_amplitude_pixels_type arg)
  {
    msg_.amplitude_pixels = std::move(arg);
    return Init_EyeStateData_amplitude_angle_deg(msg_);
  }

private:
  ::blink_interface::msg::EyeStateData msg_;
};

class Init_EyeStateData_mean_gaze_y
{
public:
  explicit Init_EyeStateData_mean_gaze_y(::blink_interface::msg::EyeStateData & msg)
  : msg_(msg)
  {}
  Init_EyeStateData_amplitude_pixels mean_gaze_y(::blink_interface::msg::EyeStateData::_mean_gaze_y_type arg)
  {
    msg_.mean_gaze_y = std::move(arg);
    return Init_EyeStateData_amplitude_pixels(msg_);
  }

private:
  ::blink_interface::msg::EyeStateData msg_;
};

class Init_EyeStateData_mean_gaze_x
{
public:
  explicit Init_EyeStateData_mean_gaze_x(::blink_interface::msg::EyeStateData & msg)
  : msg_(msg)
  {}
  Init_EyeStateData_mean_gaze_y mean_gaze_x(::blink_interface::msg::EyeStateData::_mean_gaze_x_type arg)
  {
    msg_.mean_gaze_x = std::move(arg);
    return Init_EyeStateData_mean_gaze_y(msg_);
  }

private:
  ::blink_interface::msg::EyeStateData msg_;
};

class Init_EyeStateData_end_gaze_y
{
public:
  explicit Init_EyeStateData_end_gaze_y(::blink_interface::msg::EyeStateData & msg)
  : msg_(msg)
  {}
  Init_EyeStateData_mean_gaze_x end_gaze_y(::blink_interface::msg::EyeStateData::_end_gaze_y_type arg)
  {
    msg_.end_gaze_y = std::move(arg);
    return Init_EyeStateData_mean_gaze_x(msg_);
  }

private:
  ::blink_interface::msg::EyeStateData msg_;
};

class Init_EyeStateData_end_gaze_x
{
public:
  explicit Init_EyeStateData_end_gaze_x(::blink_interface::msg::EyeStateData & msg)
  : msg_(msg)
  {}
  Init_EyeStateData_end_gaze_y end_gaze_x(::blink_interface::msg::EyeStateData::_end_gaze_x_type arg)
  {
    msg_.end_gaze_x = std::move(arg);
    return Init_EyeStateData_end_gaze_y(msg_);
  }

private:
  ::blink_interface::msg::EyeStateData msg_;
};

class Init_EyeStateData_start_gaze_y
{
public:
  explicit Init_EyeStateData_start_gaze_y(::blink_interface::msg::EyeStateData & msg)
  : msg_(msg)
  {}
  Init_EyeStateData_end_gaze_x start_gaze_y(::blink_interface::msg::EyeStateData::_start_gaze_y_type arg)
  {
    msg_.start_gaze_y = std::move(arg);
    return Init_EyeStateData_end_gaze_x(msg_);
  }

private:
  ::blink_interface::msg::EyeStateData msg_;
};

class Init_EyeStateData_start_gaze_x
{
public:
  explicit Init_EyeStateData_start_gaze_x(::blink_interface::msg::EyeStateData & msg)
  : msg_(msg)
  {}
  Init_EyeStateData_start_gaze_y start_gaze_x(::blink_interface::msg::EyeStateData::_start_gaze_x_type arg)
  {
    msg_.start_gaze_x = std::move(arg);
    return Init_EyeStateData_start_gaze_y(msg_);
  }

private:
  ::blink_interface::msg::EyeStateData msg_;
};

class Init_EyeStateData_has_end_time
{
public:
  explicit Init_EyeStateData_has_end_time(::blink_interface::msg::EyeStateData & msg)
  : msg_(msg)
  {}
  Init_EyeStateData_start_gaze_x has_end_time(::blink_interface::msg::EyeStateData::_has_end_time_type arg)
  {
    msg_.has_end_time = std::move(arg);
    return Init_EyeStateData_start_gaze_x(msg_);
  }

private:
  ::blink_interface::msg::EyeStateData msg_;
};

class Init_EyeStateData_rtp_ts_unix_seconds
{
public:
  explicit Init_EyeStateData_rtp_ts_unix_seconds(::blink_interface::msg::EyeStateData & msg)
  : msg_(msg)
  {}
  Init_EyeStateData_has_end_time rtp_ts_unix_seconds(::blink_interface::msg::EyeStateData::_rtp_ts_unix_seconds_type arg)
  {
    msg_.rtp_ts_unix_seconds = std::move(arg);
    return Init_EyeStateData_has_end_time(msg_);
  }

private:
  ::blink_interface::msg::EyeStateData msg_;
};

class Init_EyeStateData_end_time_ns
{
public:
  explicit Init_EyeStateData_end_time_ns(::blink_interface::msg::EyeStateData & msg)
  : msg_(msg)
  {}
  Init_EyeStateData_rtp_ts_unix_seconds end_time_ns(::blink_interface::msg::EyeStateData::_end_time_ns_type arg)
  {
    msg_.end_time_ns = std::move(arg);
    return Init_EyeStateData_rtp_ts_unix_seconds(msg_);
  }

private:
  ::blink_interface::msg::EyeStateData msg_;
};

class Init_EyeStateData_start_time_ns
{
public:
  explicit Init_EyeStateData_start_time_ns(::blink_interface::msg::EyeStateData & msg)
  : msg_(msg)
  {}
  Init_EyeStateData_end_time_ns start_time_ns(::blink_interface::msg::EyeStateData::_start_time_ns_type arg)
  {
    msg_.start_time_ns = std::move(arg);
    return Init_EyeStateData_end_time_ns(msg_);
  }

private:
  ::blink_interface::msg::EyeStateData msg_;
};

class Init_EyeStateData_event_type
{
public:
  explicit Init_EyeStateData_event_type(::blink_interface::msg::EyeStateData & msg)
  : msg_(msg)
  {}
  Init_EyeStateData_start_time_ns event_type(::blink_interface::msg::EyeStateData::_event_type_type arg)
  {
    msg_.event_type = std::move(arg);
    return Init_EyeStateData_start_time_ns(msg_);
  }

private:
  ::blink_interface::msg::EyeStateData msg_;
};

class Init_EyeStateData_event_name
{
public:
  explicit Init_EyeStateData_event_name(::blink_interface::msg::EyeStateData & msg)
  : msg_(msg)
  {}
  Init_EyeStateData_event_type event_name(::blink_interface::msg::EyeStateData::_event_name_type arg)
  {
    msg_.event_name = std::move(arg);
    return Init_EyeStateData_event_type(msg_);
  }

private:
  ::blink_interface::msg::EyeStateData msg_;
};

class Init_EyeStateData_header
{
public:
  Init_EyeStateData_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EyeStateData_event_name header(::blink_interface::msg::EyeStateData::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_EyeStateData_event_name(msg_);
  }

private:
  ::blink_interface::msg::EyeStateData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::blink_interface::msg::EyeStateData>()
{
  return blink_interface::msg::builder::Init_EyeStateData_header();
}

}  // namespace blink_interface

#endif  // BLINK_INTERFACE__MSG__DETAIL__EYE_STATE_DATA__BUILDER_HPP_
