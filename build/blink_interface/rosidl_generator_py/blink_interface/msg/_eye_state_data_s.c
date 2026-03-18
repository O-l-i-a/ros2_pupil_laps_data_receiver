// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from blink_interface:msg/EyeStateData.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "blink_interface/msg/detail/eye_state_data__struct.h"
#include "blink_interface/msg/detail/eye_state_data__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool blink_interface__msg__eye_state_data__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[49];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("blink_interface.msg._eye_state_data.EyeStateData", full_classname_dest, 48) == 0);
  }
  blink_interface__msg__EyeStateData * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // event_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "event_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->event_name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // event_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "event_type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->event_type = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // start_time_ns
    PyObject * field = PyObject_GetAttrString(_pymsg, "start_time_ns");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->start_time_ns = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // end_time_ns
    PyObject * field = PyObject_GetAttrString(_pymsg, "end_time_ns");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->end_time_ns = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rtp_ts_unix_seconds
    PyObject * field = PyObject_GetAttrString(_pymsg, "rtp_ts_unix_seconds");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rtp_ts_unix_seconds = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // has_end_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "has_end_time");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->has_end_time = (Py_True == field);
    Py_DECREF(field);
  }
  {  // start_gaze_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "start_gaze_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->start_gaze_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // start_gaze_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "start_gaze_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->start_gaze_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // end_gaze_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "end_gaze_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->end_gaze_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // end_gaze_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "end_gaze_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->end_gaze_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // mean_gaze_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "mean_gaze_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mean_gaze_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // mean_gaze_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "mean_gaze_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mean_gaze_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // amplitude_pixels
    PyObject * field = PyObject_GetAttrString(_pymsg, "amplitude_pixels");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->amplitude_pixels = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // amplitude_angle_deg
    PyObject * field = PyObject_GetAttrString(_pymsg, "amplitude_angle_deg");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->amplitude_angle_deg = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // mean_velocity
    PyObject * field = PyObject_GetAttrString(_pymsg, "mean_velocity");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mean_velocity = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // max_velocity
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_velocity");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_velocity = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * blink_interface__msg__eye_state_data__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of EyeStateData */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("blink_interface.msg._eye_state_data");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "EyeStateData");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  blink_interface__msg__EyeStateData * ros_message = (blink_interface__msg__EyeStateData *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // event_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->event_name.data,
      strlen(ros_message->event_name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "event_name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // event_type
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->event_type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "event_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // start_time_ns
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->start_time_ns);
    {
      int rc = PyObject_SetAttrString(_pymessage, "start_time_ns", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // end_time_ns
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->end_time_ns);
    {
      int rc = PyObject_SetAttrString(_pymessage, "end_time_ns", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rtp_ts_unix_seconds
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rtp_ts_unix_seconds);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rtp_ts_unix_seconds", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // has_end_time
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->has_end_time ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "has_end_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // start_gaze_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->start_gaze_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "start_gaze_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // start_gaze_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->start_gaze_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "start_gaze_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // end_gaze_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->end_gaze_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "end_gaze_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // end_gaze_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->end_gaze_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "end_gaze_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mean_gaze_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mean_gaze_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mean_gaze_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mean_gaze_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mean_gaze_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mean_gaze_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // amplitude_pixels
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->amplitude_pixels);
    {
      int rc = PyObject_SetAttrString(_pymessage, "amplitude_pixels", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // amplitude_angle_deg
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->amplitude_angle_deg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "amplitude_angle_deg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mean_velocity
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mean_velocity);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mean_velocity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_velocity
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_velocity);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_velocity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
