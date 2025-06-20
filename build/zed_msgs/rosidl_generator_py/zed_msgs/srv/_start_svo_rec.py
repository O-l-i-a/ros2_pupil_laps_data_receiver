# generated from rosidl_generator_py/resource/_idl.py.em
# with input from zed_msgs:srv/StartSvoRec.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_StartSvoRec_Request(type):
    """Metaclass of message 'StartSvoRec_Request'."""

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
            module = import_type_support('zed_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'zed_msgs.srv.StartSvoRec_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__start_svo_rec__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__start_svo_rec__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__start_svo_rec__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__start_svo_rec__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__start_svo_rec__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class StartSvoRec_Request(metaclass=Metaclass_StartSvoRec_Request):
    """Message class 'StartSvoRec_Request'."""

    __slots__ = [
        '_bitrate',
        '_compression_mode',
        '_target_framerate',
        '_input_transcode',
        '_svo_filename',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'bitrate': 'uint32',
        'compression_mode': 'uint8',
        'target_framerate': 'uint32',
        'input_transcode': 'boolean',
        'svo_filename': 'string',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
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
        self.bitrate = kwargs.get('bitrate', int())
        self.compression_mode = kwargs.get('compression_mode', int())
        self.target_framerate = kwargs.get('target_framerate', int())
        self.input_transcode = kwargs.get('input_transcode', bool())
        self.svo_filename = kwargs.get('svo_filename', str())

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
        if self.bitrate != other.bitrate:
            return False
        if self.compression_mode != other.compression_mode:
            return False
        if self.target_framerate != other.target_framerate:
            return False
        if self.input_transcode != other.input_transcode:
            return False
        if self.svo_filename != other.svo_filename:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def bitrate(self):
        """Message field 'bitrate'."""
        return self._bitrate

    @bitrate.setter
    def bitrate(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'bitrate' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'bitrate' field must be an unsigned integer in [0, 4294967295]"
        self._bitrate = value

    @builtins.property
    def compression_mode(self):
        """Message field 'compression_mode'."""
        return self._compression_mode

    @compression_mode.setter
    def compression_mode(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'compression_mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'compression_mode' field must be an unsigned integer in [0, 255]"
        self._compression_mode = value

    @builtins.property
    def target_framerate(self):
        """Message field 'target_framerate'."""
        return self._target_framerate

    @target_framerate.setter
    def target_framerate(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'target_framerate' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'target_framerate' field must be an unsigned integer in [0, 4294967295]"
        self._target_framerate = value

    @builtins.property
    def input_transcode(self):
        """Message field 'input_transcode'."""
        return self._input_transcode

    @input_transcode.setter
    def input_transcode(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'input_transcode' field must be of type 'bool'"
        self._input_transcode = value

    @builtins.property
    def svo_filename(self):
        """Message field 'svo_filename'."""
        return self._svo_filename

    @svo_filename.setter
    def svo_filename(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'svo_filename' field must be of type 'str'"
        self._svo_filename = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_StartSvoRec_Response(type):
    """Metaclass of message 'StartSvoRec_Response'."""

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
            module = import_type_support('zed_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'zed_msgs.srv.StartSvoRec_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__start_svo_rec__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__start_svo_rec__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__start_svo_rec__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__start_svo_rec__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__start_svo_rec__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class StartSvoRec_Response(metaclass=Metaclass_StartSvoRec_Response):
    """Message class 'StartSvoRec_Response'."""

    __slots__ = [
        '_success',
        '_message',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'message': 'string',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
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
        self.success = kwargs.get('success', bool())
        self.message = kwargs.get('message', str())

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
        if self.success != other.success:
            return False
        if self.message != other.message:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_StartSvoRec_Event(type):
    """Metaclass of message 'StartSvoRec_Event'."""

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
            module = import_type_support('zed_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'zed_msgs.srv.StartSvoRec_Event')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__start_svo_rec__event
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__start_svo_rec__event
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__start_svo_rec__event
            cls._TYPE_SUPPORT = module.type_support_msg__srv__start_svo_rec__event
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__start_svo_rec__event

            from service_msgs.msg import ServiceEventInfo
            if ServiceEventInfo.__class__._TYPE_SUPPORT is None:
                ServiceEventInfo.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class StartSvoRec_Event(metaclass=Metaclass_StartSvoRec_Event):
    """Message class 'StartSvoRec_Event'."""

    __slots__ = [
        '_info',
        '_request',
        '_response',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'info': 'service_msgs/ServiceEventInfo',
        'request': 'sequence<zed_msgs/StartSvoRec_Request, 1>',
        'response': 'sequence<zed_msgs/StartSvoRec_Response, 1>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['service_msgs', 'msg'], 'ServiceEventInfo'),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['zed_msgs', 'srv'], 'StartSvoRec_Request'), 1),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['zed_msgs', 'srv'], 'StartSvoRec_Response'), 1),  # noqa: E501
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
        from service_msgs.msg import ServiceEventInfo
        self.info = kwargs.get('info', ServiceEventInfo())
        self.request = kwargs.get('request', [])
        self.response = kwargs.get('response', [])

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
        if self.info != other.info:
            return False
        if self.request != other.request:
            return False
        if self.response != other.response:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def info(self):
        """Message field 'info'."""
        return self._info

    @info.setter
    def info(self, value):
        if self._check_fields:
            from service_msgs.msg import ServiceEventInfo
            assert \
                isinstance(value, ServiceEventInfo), \
                "The 'info' field must be a sub message of type 'ServiceEventInfo'"
        self._info = value

    @builtins.property
    def request(self):
        """Message field 'request'."""
        return self._request

    @request.setter
    def request(self, value):
        if self._check_fields:
            from zed_msgs.srv import StartSvoRec_Request
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) <= 1 and
                 all(isinstance(v, StartSvoRec_Request) for v in value) and
                 True), \
                "The 'request' field must be a set or sequence with length <= 1 and each value of type 'StartSvoRec_Request'"
        self._request = value

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if self._check_fields:
            from zed_msgs.srv import StartSvoRec_Response
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) <= 1 and
                 all(isinstance(v, StartSvoRec_Response) for v in value) and
                 True), \
                "The 'response' field must be a set or sequence with length <= 1 and each value of type 'StartSvoRec_Response'"
        self._response = value


class Metaclass_StartSvoRec(type):
    """Metaclass of service 'StartSvoRec'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('zed_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'zed_msgs.srv.StartSvoRec')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__start_svo_rec

            from zed_msgs.srv import _start_svo_rec
            if _start_svo_rec.Metaclass_StartSvoRec_Request._TYPE_SUPPORT is None:
                _start_svo_rec.Metaclass_StartSvoRec_Request.__import_type_support__()
            if _start_svo_rec.Metaclass_StartSvoRec_Response._TYPE_SUPPORT is None:
                _start_svo_rec.Metaclass_StartSvoRec_Response.__import_type_support__()
            if _start_svo_rec.Metaclass_StartSvoRec_Event._TYPE_SUPPORT is None:
                _start_svo_rec.Metaclass_StartSvoRec_Event.__import_type_support__()


class StartSvoRec(metaclass=Metaclass_StartSvoRec):
    from zed_msgs.srv._start_svo_rec import StartSvoRec_Request as Request
    from zed_msgs.srv._start_svo_rec import StartSvoRec_Response as Response
    from zed_msgs.srv._start_svo_rec import StartSvoRec_Event as Event

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
