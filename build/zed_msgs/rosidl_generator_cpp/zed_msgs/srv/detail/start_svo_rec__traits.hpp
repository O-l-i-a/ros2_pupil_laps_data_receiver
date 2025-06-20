// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from zed_msgs:srv/StartSvoRec.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "zed_msgs/srv/start_svo_rec.hpp"


#ifndef ZED_MSGS__SRV__DETAIL__START_SVO_REC__TRAITS_HPP_
#define ZED_MSGS__SRV__DETAIL__START_SVO_REC__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "zed_msgs/srv/detail/start_svo_rec__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace zed_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const StartSvoRec_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: bitrate
  {
    out << "bitrate: ";
    rosidl_generator_traits::value_to_yaml(msg.bitrate, out);
    out << ", ";
  }

  // member: compression_mode
  {
    out << "compression_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.compression_mode, out);
    out << ", ";
  }

  // member: target_framerate
  {
    out << "target_framerate: ";
    rosidl_generator_traits::value_to_yaml(msg.target_framerate, out);
    out << ", ";
  }

  // member: input_transcode
  {
    out << "input_transcode: ";
    rosidl_generator_traits::value_to_yaml(msg.input_transcode, out);
    out << ", ";
  }

  // member: svo_filename
  {
    out << "svo_filename: ";
    rosidl_generator_traits::value_to_yaml(msg.svo_filename, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StartSvoRec_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: bitrate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bitrate: ";
    rosidl_generator_traits::value_to_yaml(msg.bitrate, out);
    out << "\n";
  }

  // member: compression_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "compression_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.compression_mode, out);
    out << "\n";
  }

  // member: target_framerate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_framerate: ";
    rosidl_generator_traits::value_to_yaml(msg.target_framerate, out);
    out << "\n";
  }

  // member: input_transcode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "input_transcode: ";
    rosidl_generator_traits::value_to_yaml(msg.input_transcode, out);
    out << "\n";
  }

  // member: svo_filename
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "svo_filename: ";
    rosidl_generator_traits::value_to_yaml(msg.svo_filename, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StartSvoRec_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace zed_msgs

namespace rosidl_generator_traits
{

[[deprecated("use zed_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const zed_msgs::srv::StartSvoRec_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  zed_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use zed_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const zed_msgs::srv::StartSvoRec_Request & msg)
{
  return zed_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<zed_msgs::srv::StartSvoRec_Request>()
{
  return "zed_msgs::srv::StartSvoRec_Request";
}

template<>
inline const char * name<zed_msgs::srv::StartSvoRec_Request>()
{
  return "zed_msgs/srv/StartSvoRec_Request";
}

template<>
struct has_fixed_size<zed_msgs::srv::StartSvoRec_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<zed_msgs::srv::StartSvoRec_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<zed_msgs::srv::StartSvoRec_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace zed_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const StartSvoRec_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StartSvoRec_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StartSvoRec_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace zed_msgs

namespace rosidl_generator_traits
{

[[deprecated("use zed_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const zed_msgs::srv::StartSvoRec_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  zed_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use zed_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const zed_msgs::srv::StartSvoRec_Response & msg)
{
  return zed_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<zed_msgs::srv::StartSvoRec_Response>()
{
  return "zed_msgs::srv::StartSvoRec_Response";
}

template<>
inline const char * name<zed_msgs::srv::StartSvoRec_Response>()
{
  return "zed_msgs/srv/StartSvoRec_Response";
}

template<>
struct has_fixed_size<zed_msgs::srv::StartSvoRec_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<zed_msgs::srv::StartSvoRec_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<zed_msgs::srv::StartSvoRec_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace zed_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const StartSvoRec_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StartSvoRec_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StartSvoRec_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace zed_msgs

namespace rosidl_generator_traits
{

[[deprecated("use zed_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const zed_msgs::srv::StartSvoRec_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  zed_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use zed_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const zed_msgs::srv::StartSvoRec_Event & msg)
{
  return zed_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<zed_msgs::srv::StartSvoRec_Event>()
{
  return "zed_msgs::srv::StartSvoRec_Event";
}

template<>
inline const char * name<zed_msgs::srv::StartSvoRec_Event>()
{
  return "zed_msgs/srv/StartSvoRec_Event";
}

template<>
struct has_fixed_size<zed_msgs::srv::StartSvoRec_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<zed_msgs::srv::StartSvoRec_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<zed_msgs::srv::StartSvoRec_Request>::value && has_bounded_size<zed_msgs::srv::StartSvoRec_Response>::value> {};

template<>
struct is_message<zed_msgs::srv::StartSvoRec_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<zed_msgs::srv::StartSvoRec>()
{
  return "zed_msgs::srv::StartSvoRec";
}

template<>
inline const char * name<zed_msgs::srv::StartSvoRec>()
{
  return "zed_msgs/srv/StartSvoRec";
}

template<>
struct has_fixed_size<zed_msgs::srv::StartSvoRec>
  : std::integral_constant<
    bool,
    has_fixed_size<zed_msgs::srv::StartSvoRec_Request>::value &&
    has_fixed_size<zed_msgs::srv::StartSvoRec_Response>::value
  >
{
};

template<>
struct has_bounded_size<zed_msgs::srv::StartSvoRec>
  : std::integral_constant<
    bool,
    has_bounded_size<zed_msgs::srv::StartSvoRec_Request>::value &&
    has_bounded_size<zed_msgs::srv::StartSvoRec_Response>::value
  >
{
};

template<>
struct is_service<zed_msgs::srv::StartSvoRec>
  : std::true_type
{
};

template<>
struct is_service_request<zed_msgs::srv::StartSvoRec_Request>
  : std::true_type
{
};

template<>
struct is_service_response<zed_msgs::srv::StartSvoRec_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ZED_MSGS__SRV__DETAIL__START_SVO_REC__TRAITS_HPP_
