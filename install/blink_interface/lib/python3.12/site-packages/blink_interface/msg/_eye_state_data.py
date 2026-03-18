# generated from rosidl_generator_py/resource/_idl.py.em
# with input from blink_interface:msg/EyeStateData.idl
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


class Metaclass_EyeStateData(type):
    """Metaclass of message 'EyeStateData'."""

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
            module = import_type_support('blink_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'blink_interface.msg.EyeStateData')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__eye_state_data
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__eye_state_data
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__eye_state_data
            cls._TYPE_SUPPORT = module.type_support_msg__msg__eye_state_data
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__eye_state_data

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


class EyeStateData(metaclass=Metaclass_EyeStateData):
    """Message class 'EyeStateData'."""

    __slots__ = [
        '_header',
        '_event_name',
        '_event_type',
        '_start_time_ns',
        '_end_time_ns',
        '_rtp_ts_unix_seconds',
        '_has_end_time',
        '_start_gaze_x',
        '_start_gaze_y',
        '_end_gaze_x',
        '_end_gaze_y',
        '_mean_gaze_x',
        '_mean_gaze_y',
        '_amplitude_pixels',
        '_amplitude_angle_deg',
        '_mean_velocity',
        '_max_velocity',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'event_name': 'string',
        'event_type': 'int32',
        'start_time_ns': 'double',
        'end_time_ns': 'double',
        'rtp_ts_unix_seconds': 'double',
        'has_end_time': 'boolean',
        'start_gaze_x': 'float',
        'start_gaze_y': 'float',
        'end_gaze_x': 'float',
        'end_gaze_y': 'float',
        'mean_gaze_x': 'float',
        'mean_gaze_y': 'float',
        'amplitude_pixels': 'float',
        'amplitude_angle_deg': 'float',
        'mean_velocity': 'float',
        'max_velocity': 'float',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
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
        self.event_name = kwargs.get('event_name', str())
        self.event_type = kwargs.get('event_type', int())
        self.start_time_ns = kwargs.get('start_time_ns', float())
        self.end_time_ns = kwargs.get('end_time_ns', float())
        self.rtp_ts_unix_seconds = kwargs.get('rtp_ts_unix_seconds', float())
        self.has_end_time = kwargs.get('has_end_time', bool())
        self.start_gaze_x = kwargs.get('start_gaze_x', float())
        self.start_gaze_y = kwargs.get('start_gaze_y', float())
        self.end_gaze_x = kwargs.get('end_gaze_x', float())
        self.end_gaze_y = kwargs.get('end_gaze_y', float())
        self.mean_gaze_x = kwargs.get('mean_gaze_x', float())
        self.mean_gaze_y = kwargs.get('mean_gaze_y', float())
        self.amplitude_pixels = kwargs.get('amplitude_pixels', float())
        self.amplitude_angle_deg = kwargs.get('amplitude_angle_deg', float())
        self.mean_velocity = kwargs.get('mean_velocity', float())
        self.max_velocity = kwargs.get('max_velocity', float())

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
        if self.event_name != other.event_name:
            return False
        if self.event_type != other.event_type:
            return False
        if self.start_time_ns != other.start_time_ns:
            return False
        if self.end_time_ns != other.end_time_ns:
            return False
        if self.rtp_ts_unix_seconds != other.rtp_ts_unix_seconds:
            return False
        if self.has_end_time != other.has_end_time:
            return False
        if self.start_gaze_x != other.start_gaze_x:
            return False
        if self.start_gaze_y != other.start_gaze_y:
            return False
        if self.end_gaze_x != other.end_gaze_x:
            return False
        if self.end_gaze_y != other.end_gaze_y:
            return False
        if self.mean_gaze_x != other.mean_gaze_x:
            return False
        if self.mean_gaze_y != other.mean_gaze_y:
            return False
        if self.amplitude_pixels != other.amplitude_pixels:
            return False
        if self.amplitude_angle_deg != other.amplitude_angle_deg:
            return False
        if self.mean_velocity != other.mean_velocity:
            return False
        if self.max_velocity != other.max_velocity:
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
    def event_name(self):
        """Message field 'event_name'."""
        return self._event_name

    @event_name.setter
    def event_name(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'event_name' field must be of type 'str'"
        self._event_name = value

    @builtins.property
    def event_type(self):
        """Message field 'event_type'."""
        return self._event_type

    @event_type.setter
    def event_type(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'event_type' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'event_type' field must be an integer in [-2147483648, 2147483647]"
        self._event_type = value

    @builtins.property
    def start_time_ns(self):
        """Message field 'start_time_ns'."""
        return self._start_time_ns

    @start_time_ns.setter
    def start_time_ns(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'start_time_ns' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'start_time_ns' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._start_time_ns = value

    @builtins.property
    def end_time_ns(self):
        """Message field 'end_time_ns'."""
        return self._end_time_ns

    @end_time_ns.setter
    def end_time_ns(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'end_time_ns' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'end_time_ns' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._end_time_ns = value

    @builtins.property
    def rtp_ts_unix_seconds(self):
        """Message field 'rtp_ts_unix_seconds'."""
        return self._rtp_ts_unix_seconds

    @rtp_ts_unix_seconds.setter
    def rtp_ts_unix_seconds(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'rtp_ts_unix_seconds' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'rtp_ts_unix_seconds' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._rtp_ts_unix_seconds = value

    @builtins.property
    def has_end_time(self):
        """Message field 'has_end_time'."""
        return self._has_end_time

    @has_end_time.setter
    def has_end_time(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'has_end_time' field must be of type 'bool'"
        self._has_end_time = value

    @builtins.property
    def start_gaze_x(self):
        """Message field 'start_gaze_x'."""
        return self._start_gaze_x

    @start_gaze_x.setter
    def start_gaze_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'start_gaze_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'start_gaze_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._start_gaze_x = value

    @builtins.property
    def start_gaze_y(self):
        """Message field 'start_gaze_y'."""
        return self._start_gaze_y

    @start_gaze_y.setter
    def start_gaze_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'start_gaze_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'start_gaze_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._start_gaze_y = value

    @builtins.property
    def end_gaze_x(self):
        """Message field 'end_gaze_x'."""
        return self._end_gaze_x

    @end_gaze_x.setter
    def end_gaze_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'end_gaze_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'end_gaze_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._end_gaze_x = value

    @builtins.property
    def end_gaze_y(self):
        """Message field 'end_gaze_y'."""
        return self._end_gaze_y

    @end_gaze_y.setter
    def end_gaze_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'end_gaze_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'end_gaze_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._end_gaze_y = value

    @builtins.property
    def mean_gaze_x(self):
        """Message field 'mean_gaze_x'."""
        return self._mean_gaze_x

    @mean_gaze_x.setter
    def mean_gaze_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'mean_gaze_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'mean_gaze_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._mean_gaze_x = value

    @builtins.property
    def mean_gaze_y(self):
        """Message field 'mean_gaze_y'."""
        return self._mean_gaze_y

    @mean_gaze_y.setter
    def mean_gaze_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'mean_gaze_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'mean_gaze_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._mean_gaze_y = value

    @builtins.property
    def amplitude_pixels(self):
        """Message field 'amplitude_pixels'."""
        return self._amplitude_pixels

    @amplitude_pixels.setter
    def amplitude_pixels(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'amplitude_pixels' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'amplitude_pixels' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._amplitude_pixels = value

    @builtins.property
    def amplitude_angle_deg(self):
        """Message field 'amplitude_angle_deg'."""
        return self._amplitude_angle_deg

    @amplitude_angle_deg.setter
    def amplitude_angle_deg(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'amplitude_angle_deg' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'amplitude_angle_deg' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._amplitude_angle_deg = value

    @builtins.property
    def mean_velocity(self):
        """Message field 'mean_velocity'."""
        return self._mean_velocity

    @mean_velocity.setter
    def mean_velocity(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'mean_velocity' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'mean_velocity' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._mean_velocity = value

    @builtins.property
    def max_velocity(self):
        """Message field 'max_velocity'."""
        return self._max_velocity

    @max_velocity.setter
    def max_velocity(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'max_velocity' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'max_velocity' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._max_velocity = value
