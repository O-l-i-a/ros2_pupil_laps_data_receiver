# generated from rosidl_generator_py/resource/_idl.py.em
# with input from egocentric_msg:msg/GazeData.idl
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


class Metaclass_GazeData(type):
    """Metaclass of message 'GazeData'."""

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
            module = import_type_support('egocentric_msg')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'egocentric_msg.msg.GazeData')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__gaze_data
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__gaze_data
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__gaze_data
            cls._TYPE_SUPPORT = module.type_support_msg__msg__gaze_data
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__gaze_data

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GazeData(metaclass=Metaclass_GazeData):
    """Message class 'GazeData'."""

    __slots__ = [
        '_x',
        '_y',
        '_worn',
        '_pupil_diameter_left',
        '_eyeball_center_left_x',
        '_eyeball_center_left_y',
        '_eyeball_center_left_z',
        '_optical_axis_left_x',
        '_optical_axis_left_y',
        '_optical_axis_left_z',
        '_pupil_diameter_right',
        '_eyeball_center_right_x',
        '_eyeball_center_right_y',
        '_eyeball_center_right_z',
        '_optical_axis_right_x',
        '_optical_axis_right_y',
        '_optical_axis_right_z',
        '_timestamp_unix_seconds',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'x': 'float',
        'y': 'float',
        'worn': 'boolean',
        'pupil_diameter_left': 'float',
        'eyeball_center_left_x': 'float',
        'eyeball_center_left_y': 'float',
        'eyeball_center_left_z': 'float',
        'optical_axis_left_x': 'float',
        'optical_axis_left_y': 'float',
        'optical_axis_left_z': 'float',
        'pupil_diameter_right': 'float',
        'eyeball_center_right_x': 'float',
        'eyeball_center_right_y': 'float',
        'eyeball_center_right_z': 'float',
        'optical_axis_right_x': 'float',
        'optical_axis_right_y': 'float',
        'optical_axis_right_z': 'float',
        'timestamp_unix_seconds': 'float',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
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
        self.x = kwargs.get('x', float())
        self.y = kwargs.get('y', float())
        self.worn = kwargs.get('worn', bool())
        self.pupil_diameter_left = kwargs.get('pupil_diameter_left', float())
        self.eyeball_center_left_x = kwargs.get('eyeball_center_left_x', float())
        self.eyeball_center_left_y = kwargs.get('eyeball_center_left_y', float())
        self.eyeball_center_left_z = kwargs.get('eyeball_center_left_z', float())
        self.optical_axis_left_x = kwargs.get('optical_axis_left_x', float())
        self.optical_axis_left_y = kwargs.get('optical_axis_left_y', float())
        self.optical_axis_left_z = kwargs.get('optical_axis_left_z', float())
        self.pupil_diameter_right = kwargs.get('pupil_diameter_right', float())
        self.eyeball_center_right_x = kwargs.get('eyeball_center_right_x', float())
        self.eyeball_center_right_y = kwargs.get('eyeball_center_right_y', float())
        self.eyeball_center_right_z = kwargs.get('eyeball_center_right_z', float())
        self.optical_axis_right_x = kwargs.get('optical_axis_right_x', float())
        self.optical_axis_right_y = kwargs.get('optical_axis_right_y', float())
        self.optical_axis_right_z = kwargs.get('optical_axis_right_z', float())
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
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.worn != other.worn:
            return False
        if self.pupil_diameter_left != other.pupil_diameter_left:
            return False
        if self.eyeball_center_left_x != other.eyeball_center_left_x:
            return False
        if self.eyeball_center_left_y != other.eyeball_center_left_y:
            return False
        if self.eyeball_center_left_z != other.eyeball_center_left_z:
            return False
        if self.optical_axis_left_x != other.optical_axis_left_x:
            return False
        if self.optical_axis_left_y != other.optical_axis_left_y:
            return False
        if self.optical_axis_left_z != other.optical_axis_left_z:
            return False
        if self.pupil_diameter_right != other.pupil_diameter_right:
            return False
        if self.eyeball_center_right_x != other.eyeball_center_right_x:
            return False
        if self.eyeball_center_right_y != other.eyeball_center_right_y:
            return False
        if self.eyeball_center_right_z != other.eyeball_center_right_z:
            return False
        if self.optical_axis_right_x != other.optical_axis_right_x:
            return False
        if self.optical_axis_right_y != other.optical_axis_right_y:
            return False
        if self.optical_axis_right_z != other.optical_axis_right_z:
            return False
        if self.timestamp_unix_seconds != other.timestamp_unix_seconds:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._x = value

    @builtins.property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._y = value

    @builtins.property
    def worn(self):
        """Message field 'worn'."""
        return self._worn

    @worn.setter
    def worn(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'worn' field must be of type 'bool'"
        self._worn = value

    @builtins.property
    def pupil_diameter_left(self):
        """Message field 'pupil_diameter_left'."""
        return self._pupil_diameter_left

    @pupil_diameter_left.setter
    def pupil_diameter_left(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'pupil_diameter_left' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pupil_diameter_left' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pupil_diameter_left = value

    @builtins.property
    def eyeball_center_left_x(self):
        """Message field 'eyeball_center_left_x'."""
        return self._eyeball_center_left_x

    @eyeball_center_left_x.setter
    def eyeball_center_left_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'eyeball_center_left_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'eyeball_center_left_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._eyeball_center_left_x = value

    @builtins.property
    def eyeball_center_left_y(self):
        """Message field 'eyeball_center_left_y'."""
        return self._eyeball_center_left_y

    @eyeball_center_left_y.setter
    def eyeball_center_left_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'eyeball_center_left_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'eyeball_center_left_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._eyeball_center_left_y = value

    @builtins.property
    def eyeball_center_left_z(self):
        """Message field 'eyeball_center_left_z'."""
        return self._eyeball_center_left_z

    @eyeball_center_left_z.setter
    def eyeball_center_left_z(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'eyeball_center_left_z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'eyeball_center_left_z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._eyeball_center_left_z = value

    @builtins.property
    def optical_axis_left_x(self):
        """Message field 'optical_axis_left_x'."""
        return self._optical_axis_left_x

    @optical_axis_left_x.setter
    def optical_axis_left_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'optical_axis_left_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'optical_axis_left_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._optical_axis_left_x = value

    @builtins.property
    def optical_axis_left_y(self):
        """Message field 'optical_axis_left_y'."""
        return self._optical_axis_left_y

    @optical_axis_left_y.setter
    def optical_axis_left_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'optical_axis_left_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'optical_axis_left_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._optical_axis_left_y = value

    @builtins.property
    def optical_axis_left_z(self):
        """Message field 'optical_axis_left_z'."""
        return self._optical_axis_left_z

    @optical_axis_left_z.setter
    def optical_axis_left_z(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'optical_axis_left_z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'optical_axis_left_z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._optical_axis_left_z = value

    @builtins.property
    def pupil_diameter_right(self):
        """Message field 'pupil_diameter_right'."""
        return self._pupil_diameter_right

    @pupil_diameter_right.setter
    def pupil_diameter_right(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'pupil_diameter_right' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pupil_diameter_right' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pupil_diameter_right = value

    @builtins.property
    def eyeball_center_right_x(self):
        """Message field 'eyeball_center_right_x'."""
        return self._eyeball_center_right_x

    @eyeball_center_right_x.setter
    def eyeball_center_right_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'eyeball_center_right_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'eyeball_center_right_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._eyeball_center_right_x = value

    @builtins.property
    def eyeball_center_right_y(self):
        """Message field 'eyeball_center_right_y'."""
        return self._eyeball_center_right_y

    @eyeball_center_right_y.setter
    def eyeball_center_right_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'eyeball_center_right_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'eyeball_center_right_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._eyeball_center_right_y = value

    @builtins.property
    def eyeball_center_right_z(self):
        """Message field 'eyeball_center_right_z'."""
        return self._eyeball_center_right_z

    @eyeball_center_right_z.setter
    def eyeball_center_right_z(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'eyeball_center_right_z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'eyeball_center_right_z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._eyeball_center_right_z = value

    @builtins.property
    def optical_axis_right_x(self):
        """Message field 'optical_axis_right_x'."""
        return self._optical_axis_right_x

    @optical_axis_right_x.setter
    def optical_axis_right_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'optical_axis_right_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'optical_axis_right_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._optical_axis_right_x = value

    @builtins.property
    def optical_axis_right_y(self):
        """Message field 'optical_axis_right_y'."""
        return self._optical_axis_right_y

    @optical_axis_right_y.setter
    def optical_axis_right_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'optical_axis_right_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'optical_axis_right_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._optical_axis_right_y = value

    @builtins.property
    def optical_axis_right_z(self):
        """Message field 'optical_axis_right_z'."""
        return self._optical_axis_right_z

    @optical_axis_right_z.setter
    def optical_axis_right_z(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'optical_axis_right_z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'optical_axis_right_z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._optical_axis_right_z = value

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
