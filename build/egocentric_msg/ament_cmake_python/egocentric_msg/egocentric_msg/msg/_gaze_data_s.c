// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from egocentric_msg:msg/GazeData.idl
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
#include "egocentric_msg/msg/detail/gaze_data__struct.h"
#include "egocentric_msg/msg/detail/gaze_data__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool egocentric_msg__msg__gaze_data__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[39];
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
    assert(strncmp("egocentric_msg.msg._gaze_data.GazeData", full_classname_dest, 38) == 0);
  }
  egocentric_msg__msg__GazeData * ros_message = _ros_message;
  {  // x
    PyObject * field = PyObject_GetAttrString(_pymsg, "x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y
    PyObject * field = PyObject_GetAttrString(_pymsg, "y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // worn
    PyObject * field = PyObject_GetAttrString(_pymsg, "worn");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->worn = (Py_True == field);
    Py_DECREF(field);
  }
  {  // pupil_diameter_left
    PyObject * field = PyObject_GetAttrString(_pymsg, "pupil_diameter_left");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pupil_diameter_left = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // eyeball_center_left_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "eyeball_center_left_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->eyeball_center_left_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // eyeball_center_left_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "eyeball_center_left_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->eyeball_center_left_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // eyeball_center_left_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "eyeball_center_left_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->eyeball_center_left_z = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // optical_axis_left_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "optical_axis_left_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->optical_axis_left_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // optical_axis_left_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "optical_axis_left_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->optical_axis_left_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // optical_axis_left_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "optical_axis_left_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->optical_axis_left_z = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pupil_diameter_right
    PyObject * field = PyObject_GetAttrString(_pymsg, "pupil_diameter_right");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pupil_diameter_right = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // eyeball_center_right_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "eyeball_center_right_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->eyeball_center_right_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // eyeball_center_right_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "eyeball_center_right_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->eyeball_center_right_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // eyeball_center_right_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "eyeball_center_right_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->eyeball_center_right_z = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // optical_axis_right_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "optical_axis_right_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->optical_axis_right_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // optical_axis_right_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "optical_axis_right_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->optical_axis_right_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // optical_axis_right_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "optical_axis_right_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->optical_axis_right_z = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // timestamp_unix_seconds
    PyObject * field = PyObject_GetAttrString(_pymsg, "timestamp_unix_seconds");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->timestamp_unix_seconds = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * egocentric_msg__msg__gaze_data__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GazeData */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("egocentric_msg.msg._gaze_data");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GazeData");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  egocentric_msg__msg__GazeData * ros_message = (egocentric_msg__msg__GazeData *)raw_ros_message;
  {  // x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // worn
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->worn ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "worn", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pupil_diameter_left
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pupil_diameter_left);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pupil_diameter_left", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // eyeball_center_left_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->eyeball_center_left_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "eyeball_center_left_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // eyeball_center_left_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->eyeball_center_left_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "eyeball_center_left_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // eyeball_center_left_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->eyeball_center_left_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "eyeball_center_left_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // optical_axis_left_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->optical_axis_left_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "optical_axis_left_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // optical_axis_left_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->optical_axis_left_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "optical_axis_left_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // optical_axis_left_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->optical_axis_left_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "optical_axis_left_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pupil_diameter_right
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pupil_diameter_right);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pupil_diameter_right", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // eyeball_center_right_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->eyeball_center_right_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "eyeball_center_right_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // eyeball_center_right_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->eyeball_center_right_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "eyeball_center_right_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // eyeball_center_right_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->eyeball_center_right_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "eyeball_center_right_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // optical_axis_right_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->optical_axis_right_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "optical_axis_right_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // optical_axis_right_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->optical_axis_right_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "optical_axis_right_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // optical_axis_right_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->optical_axis_right_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "optical_axis_right_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // timestamp_unix_seconds
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->timestamp_unix_seconds);
    {
      int rc = PyObject_SetAttrString(_pymessage, "timestamp_unix_seconds", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
