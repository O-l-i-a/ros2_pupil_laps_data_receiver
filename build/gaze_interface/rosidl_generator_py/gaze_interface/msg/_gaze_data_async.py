# generated from rosidl_generator_py/resource/_idl.py.em
# with input from gaze_interface:msg/GazeDataAsync.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GazeDataAsync(type):
    """Metaclass of message 'GazeDataAsync'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('gaze_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'gaze_interface.msg.GazeDataAsync')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__gaze_data_async
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__gaze_data_async
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__gaze_data_async
            cls._TYPE_SUPPORT = module.type_support_msg__msg__gaze_data_async
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__gaze_data_async

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GazeDataAsync(metaclass=Metaclass_GazeDataAsync):
    """Message class 'GazeDataAsync'."""

    __slots__ = [
        '_header',
        '_norm_pos_x',
        '_norm_pos_y',
        '_timestamp_unix_seconds',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'norm_pos_x': 'float',
        'norm_pos_y': 'float',
        'timestamp_unix_seconds': 'float',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.norm_pos_x = kwargs.get('norm_pos_x', float())
        self.norm_pos_y = kwargs.get('norm_pos_y', float())
        self.timestamp_unix_seconds = kwargs.get('timestamp_unix_seconds', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.norm_pos_x != other.norm_pos_x:
            return False
        if self.norm_pos_y != other.norm_pos_y:
            return False
        if self.timestamp_unix_seconds != other.timestamp_unix_seconds:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if self._check_fields:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def norm_pos_x(self):
        """Message field 'norm_pos_x'."""
        return self._norm_pos_x

    @norm_pos_x.setter
    def norm_pos_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'norm_pos_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'norm_pos_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._norm_pos_x = value

    @builtins.property
    def norm_pos_y(self):
        """Message field 'norm_pos_y'."""
        return self._norm_pos_y

    @norm_pos_y.setter
    def norm_pos_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'norm_pos_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'norm_pos_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._norm_pos_y = value

    @builtins.property
    def timestamp_unix_seconds(self):
        """Message field 'timestamp_unix_seconds'."""
        return self._timestamp_unix_seconds

    @timestamp_unix_seconds.setter
    def timestamp_unix_seconds(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'timestamp_unix_seconds' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'timestamp_unix_seconds' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._timestamp_unix_seconds = value
