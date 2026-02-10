// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from imu_interface:msg/ImuData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "imu_interface/msg/imu_data.hpp"


#ifndef IMU_INTERFACE__MSG__DETAIL__IMU_DATA__BUILDER_HPP_
#define IMU_INTERFACE__MSG__DETAIL__IMU_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "imu_interface/msg/detail/imu_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace imu_interface
{

namespace msg
{

namespace builder
{

class Init_ImuData_quaternion
{
public:
  explicit Init_ImuData_quaternion(::imu_interface::msg::ImuData & msg)
  : msg_(msg)
  {}
  ::imu_interface::msg::ImuData quaternion(::imu_interface::msg::ImuData::_quaternion_type arg)
  {
    msg_.quaternion = std::move(arg);
    return std::move(msg_);
  }

private:
  ::imu_interface::msg::ImuData msg_;
};

class Init_ImuData_gyroscope
{
public:
  explicit Init_ImuData_gyroscope(::imu_interface::msg::ImuData & msg)
  : msg_(msg)
  {}
  Init_ImuData_quaternion gyroscope(::imu_interface::msg::ImuData::_gyroscope_type arg)
  {
    msg_.gyroscope = std::move(arg);
    return Init_ImuData_quaternion(msg_);
  }

private:
  ::imu_interface::msg::ImuData msg_;
};

class Init_ImuData_acceleration
{
public:
  explicit Init_ImuData_acceleration(::imu_interface::msg::ImuData & msg)
  : msg_(msg)
  {}
  Init_ImuData_gyroscope acceleration(::imu_interface::msg::ImuData::_acceleration_type arg)
  {
    msg_.acceleration = std::move(arg);
    return Init_ImuData_gyroscope(msg_);
  }

private:
  ::imu_interface::msg::ImuData msg_;
};

class Init_ImuData_timestamp_unix_seconds
{
public:
  explicit Init_ImuData_timestamp_unix_seconds(::imu_interface::msg::ImuData & msg)
  : msg_(msg)
  {}
  Init_ImuData_acceleration timestamp_unix_seconds(::imu_interface::msg::ImuData::_timestamp_unix_seconds_type arg)
  {
    msg_.timestamp_unix_seconds = std::move(arg);
    return Init_ImuData_acceleration(msg_);
  }

private:
  ::imu_interface::msg::ImuData msg_;
};

class Init_ImuData_timestamp_unix_ns
{
public:
  explicit Init_ImuData_timestamp_unix_ns(::imu_interface::msg::ImuData & msg)
  : msg_(msg)
  {}
  Init_ImuData_timestamp_unix_seconds timestamp_unix_ns(::imu_interface::msg::ImuData::_timestamp_unix_ns_type arg)
  {
    msg_.timestamp_unix_ns = std::move(arg);
    return Init_ImuData_timestamp_unix_seconds(msg_);
  }

private:
  ::imu_interface::msg::ImuData msg_;
};

class Init_ImuData_header
{
public:
  Init_ImuData_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImuData_timestamp_unix_ns header(::imu_interface::msg::ImuData::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ImuData_timestamp_unix_ns(msg_);
  }

private:
  ::imu_interface::msg::ImuData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::imu_interface::msg::ImuData>()
{
  return imu_interface::msg::builder::Init_ImuData_header();
}

}  // namespace imu_interface

#endif  // IMU_INTERFACE__MSG__DETAIL__IMU_DATA__BUILDER_HPP_
