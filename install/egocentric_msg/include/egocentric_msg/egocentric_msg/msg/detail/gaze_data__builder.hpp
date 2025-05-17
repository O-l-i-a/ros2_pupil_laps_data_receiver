// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from egocentric_msg:msg/GazeData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "egocentric_msg/msg/gaze_data.hpp"


#ifndef EGOCENTRIC_MSG__MSG__DETAIL__GAZE_DATA__BUILDER_HPP_
#define EGOCENTRIC_MSG__MSG__DETAIL__GAZE_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "egocentric_msg/msg/detail/gaze_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace egocentric_msg
{

namespace msg
{

namespace builder
{

class Init_GazeData_timestamp_unix_seconds
{
public:
  explicit Init_GazeData_timestamp_unix_seconds(::egocentric_msg::msg::GazeData & msg)
  : msg_(msg)
  {}
  ::egocentric_msg::msg::GazeData timestamp_unix_seconds(::egocentric_msg::msg::GazeData::_timestamp_unix_seconds_type arg)
  {
    msg_.timestamp_unix_seconds = std::move(arg);
    return std::move(msg_);
  }

private:
  ::egocentric_msg::msg::GazeData msg_;
};

class Init_GazeData_optical_axis_right_z
{
public:
  explicit Init_GazeData_optical_axis_right_z(::egocentric_msg::msg::GazeData & msg)
  : msg_(msg)
  {}
  Init_GazeData_timestamp_unix_seconds optical_axis_right_z(::egocentric_msg::msg::GazeData::_optical_axis_right_z_type arg)
  {
    msg_.optical_axis_right_z = std::move(arg);
    return Init_GazeData_timestamp_unix_seconds(msg_);
  }

private:
  ::egocentric_msg::msg::GazeData msg_;
};

class Init_GazeData_optical_axis_right_y
{
public:
  explicit Init_GazeData_optical_axis_right_y(::egocentric_msg::msg::GazeData & msg)
  : msg_(msg)
  {}
  Init_GazeData_optical_axis_right_z optical_axis_right_y(::egocentric_msg::msg::GazeData::_optical_axis_right_y_type arg)
  {
    msg_.optical_axis_right_y = std::move(arg);
    return Init_GazeData_optical_axis_right_z(msg_);
  }

private:
  ::egocentric_msg::msg::GazeData msg_;
};

class Init_GazeData_optical_axis_right_x
{
public:
  explicit Init_GazeData_optical_axis_right_x(::egocentric_msg::msg::GazeData & msg)
  : msg_(msg)
  {}
  Init_GazeData_optical_axis_right_y optical_axis_right_x(::egocentric_msg::msg::GazeData::_optical_axis_right_x_type arg)
  {
    msg_.optical_axis_right_x = std::move(arg);
    return Init_GazeData_optical_axis_right_y(msg_);
  }

private:
  ::egocentric_msg::msg::GazeData msg_;
};

class Init_GazeData_eyeball_center_right_z
{
public:
  explicit Init_GazeData_eyeball_center_right_z(::egocentric_msg::msg::GazeData & msg)
  : msg_(msg)
  {}
  Init_GazeData_optical_axis_right_x eyeball_center_right_z(::egocentric_msg::msg::GazeData::_eyeball_center_right_z_type arg)
  {
    msg_.eyeball_center_right_z = std::move(arg);
    return Init_GazeData_optical_axis_right_x(msg_);
  }

private:
  ::egocentric_msg::msg::GazeData msg_;
};

class Init_GazeData_eyeball_center_right_y
{
public:
  explicit Init_GazeData_eyeball_center_right_y(::egocentric_msg::msg::GazeData & msg)
  : msg_(msg)
  {}
  Init_GazeData_eyeball_center_right_z eyeball_center_right_y(::egocentric_msg::msg::GazeData::_eyeball_center_right_y_type arg)
  {
    msg_.eyeball_center_right_y = std::move(arg);
    return Init_GazeData_eyeball_center_right_z(msg_);
  }

private:
  ::egocentric_msg::msg::GazeData msg_;
};

class Init_GazeData_eyeball_center_right_x
{
public:
  explicit Init_GazeData_eyeball_center_right_x(::egocentric_msg::msg::GazeData & msg)
  : msg_(msg)
  {}
  Init_GazeData_eyeball_center_right_y eyeball_center_right_x(::egocentric_msg::msg::GazeData::_eyeball_center_right_x_type arg)
  {
    msg_.eyeball_center_right_x = std::move(arg);
    return Init_GazeData_eyeball_center_right_y(msg_);
  }

private:
  ::egocentric_msg::msg::GazeData msg_;
};

class Init_GazeData_pupil_diameter_right
{
public:
  explicit Init_GazeData_pupil_diameter_right(::egocentric_msg::msg::GazeData & msg)
  : msg_(msg)
  {}
  Init_GazeData_eyeball_center_right_x pupil_diameter_right(::egocentric_msg::msg::GazeData::_pupil_diameter_right_type arg)
  {
    msg_.pupil_diameter_right = std::move(arg);
    return Init_GazeData_eyeball_center_right_x(msg_);
  }

private:
  ::egocentric_msg::msg::GazeData msg_;
};

class Init_GazeData_optical_axis_left_z
{
public:
  explicit Init_GazeData_optical_axis_left_z(::egocentric_msg::msg::GazeData & msg)
  : msg_(msg)
  {}
  Init_GazeData_pupil_diameter_right optical_axis_left_z(::egocentric_msg::msg::GazeData::_optical_axis_left_z_type arg)
  {
    msg_.optical_axis_left_z = std::move(arg);
    return Init_GazeData_pupil_diameter_right(msg_);
  }

private:
  ::egocentric_msg::msg::GazeData msg_;
};

class Init_GazeData_optical_axis_left_y
{
public:
  explicit Init_GazeData_optical_axis_left_y(::egocentric_msg::msg::GazeData & msg)
  : msg_(msg)
  {}
  Init_GazeData_optical_axis_left_z optical_axis_left_y(::egocentric_msg::msg::GazeData::_optical_axis_left_y_type arg)
  {
    msg_.optical_axis_left_y = std::move(arg);
    return Init_GazeData_optical_axis_left_z(msg_);
  }

private:
  ::egocentric_msg::msg::GazeData msg_;
};

class Init_GazeData_optical_axis_left_x
{
public:
  explicit Init_GazeData_optical_axis_left_x(::egocentric_msg::msg::GazeData & msg)
  : msg_(msg)
  {}
  Init_GazeData_optical_axis_left_y optical_axis_left_x(::egocentric_msg::msg::GazeData::_optical_axis_left_x_type arg)
  {
    msg_.optical_axis_left_x = std::move(arg);
    return Init_GazeData_optical_axis_left_y(msg_);
  }

private:
  ::egocentric_msg::msg::GazeData msg_;
};

class Init_GazeData_eyeball_center_left_z
{
public:
  explicit Init_GazeData_eyeball_center_left_z(::egocentric_msg::msg::GazeData & msg)
  : msg_(msg)
  {}
  Init_GazeData_optical_axis_left_x eyeball_center_left_z(::egocentric_msg::msg::GazeData::_eyeball_center_left_z_type arg)
  {
    msg_.eyeball_center_left_z = std::move(arg);
    return Init_GazeData_optical_axis_left_x(msg_);
  }

private:
  ::egocentric_msg::msg::GazeData msg_;
};

class Init_GazeData_eyeball_center_left_y
{
public:
  explicit Init_GazeData_eyeball_center_left_y(::egocentric_msg::msg::GazeData & msg)
  : msg_(msg)
  {}
  Init_GazeData_eyeball_center_left_z eyeball_center_left_y(::egocentric_msg::msg::GazeData::_eyeball_center_left_y_type arg)
  {
    msg_.eyeball_center_left_y = std::move(arg);
    return Init_GazeData_eyeball_center_left_z(msg_);
  }

private:
  ::egocentric_msg::msg::GazeData msg_;
};

class Init_GazeData_eyeball_center_left_x
{
public:
  explicit Init_GazeData_eyeball_center_left_x(::egocentric_msg::msg::GazeData & msg)
  : msg_(msg)
  {}
  Init_GazeData_eyeball_center_left_y eyeball_center_left_x(::egocentric_msg::msg::GazeData::_eyeball_center_left_x_type arg)
  {
    msg_.eyeball_center_left_x = std::move(arg);
    return Init_GazeData_eyeball_center_left_y(msg_);
  }

private:
  ::egocentric_msg::msg::GazeData msg_;
};

class Init_GazeData_pupil_diameter_left
{
public:
  explicit Init_GazeData_pupil_diameter_left(::egocentric_msg::msg::GazeData & msg)
  : msg_(msg)
  {}
  Init_GazeData_eyeball_center_left_x pupil_diameter_left(::egocentric_msg::msg::GazeData::_pupil_diameter_left_type arg)
  {
    msg_.pupil_diameter_left = std::move(arg);
    return Init_GazeData_eyeball_center_left_x(msg_);
  }

private:
  ::egocentric_msg::msg::GazeData msg_;
};

class Init_GazeData_worn
{
public:
  explicit Init_GazeData_worn(::egocentric_msg::msg::GazeData & msg)
  : msg_(msg)
  {}
  Init_GazeData_pupil_diameter_left worn(::egocentric_msg::msg::GazeData::_worn_type arg)
  {
    msg_.worn = std::move(arg);
    return Init_GazeData_pupil_diameter_left(msg_);
  }

private:
  ::egocentric_msg::msg::GazeData msg_;
};

class Init_GazeData_y
{
public:
  explicit Init_GazeData_y(::egocentric_msg::msg::GazeData & msg)
  : msg_(msg)
  {}
  Init_GazeData_worn y(::egocentric_msg::msg::GazeData::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_GazeData_worn(msg_);
  }

private:
  ::egocentric_msg::msg::GazeData msg_;
};

class Init_GazeData_x
{
public:
  Init_GazeData_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GazeData_y x(::egocentric_msg::msg::GazeData::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_GazeData_y(msg_);
  }

private:
  ::egocentric_msg::msg::GazeData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::egocentric_msg::msg::GazeData>()
{
  return egocentric_msg::msg::builder::Init_GazeData_x();
}

}  // namespace egocentric_msg

#endif  // EGOCENTRIC_MSG__MSG__DETAIL__GAZE_DATA__BUILDER_HPP_
