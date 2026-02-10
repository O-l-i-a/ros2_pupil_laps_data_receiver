// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from imu_interface:msg/ImuData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "imu_interface/msg/imu_data.h"


#ifndef IMU_INTERFACE__MSG__DETAIL__IMU_DATA__FUNCTIONS_H_
#define IMU_INTERFACE__MSG__DETAIL__IMU_DATA__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "imu_interface/msg/rosidl_generator_c__visibility_control.h"

#include "imu_interface/msg/detail/imu_data__struct.h"

/// Initialize msg/ImuData message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * imu_interface__msg__ImuData
 * )) before or use
 * imu_interface__msg__ImuData__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_imu_interface
bool
imu_interface__msg__ImuData__init(imu_interface__msg__ImuData * msg);

/// Finalize msg/ImuData message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_imu_interface
void
imu_interface__msg__ImuData__fini(imu_interface__msg__ImuData * msg);

/// Create msg/ImuData message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * imu_interface__msg__ImuData__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_imu_interface
imu_interface__msg__ImuData *
imu_interface__msg__ImuData__create(void);

/// Destroy msg/ImuData message.
/**
 * It calls
 * imu_interface__msg__ImuData__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_imu_interface
void
imu_interface__msg__ImuData__destroy(imu_interface__msg__ImuData * msg);

/// Check for msg/ImuData message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_imu_interface
bool
imu_interface__msg__ImuData__are_equal(const imu_interface__msg__ImuData * lhs, const imu_interface__msg__ImuData * rhs);

/// Copy a msg/ImuData message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_imu_interface
bool
imu_interface__msg__ImuData__copy(
  const imu_interface__msg__ImuData * input,
  imu_interface__msg__ImuData * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_imu_interface
const rosidl_type_hash_t *
imu_interface__msg__ImuData__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_imu_interface
const rosidl_runtime_c__type_description__TypeDescription *
imu_interface__msg__ImuData__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_imu_interface
const rosidl_runtime_c__type_description__TypeSource *
imu_interface__msg__ImuData__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_imu_interface
const rosidl_runtime_c__type_description__TypeSource__Sequence *
imu_interface__msg__ImuData__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/ImuData messages.
/**
 * It allocates the memory for the number of elements and calls
 * imu_interface__msg__ImuData__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_imu_interface
bool
imu_interface__msg__ImuData__Sequence__init(imu_interface__msg__ImuData__Sequence * array, size_t size);

/// Finalize array of msg/ImuData messages.
/**
 * It calls
 * imu_interface__msg__ImuData__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_imu_interface
void
imu_interface__msg__ImuData__Sequence__fini(imu_interface__msg__ImuData__Sequence * array);

/// Create array of msg/ImuData messages.
/**
 * It allocates the memory for the array and calls
 * imu_interface__msg__ImuData__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_imu_interface
imu_interface__msg__ImuData__Sequence *
imu_interface__msg__ImuData__Sequence__create(size_t size);

/// Destroy array of msg/ImuData messages.
/**
 * It calls
 * imu_interface__msg__ImuData__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_imu_interface
void
imu_interface__msg__ImuData__Sequence__destroy(imu_interface__msg__ImuData__Sequence * array);

/// Check for msg/ImuData message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_imu_interface
bool
imu_interface__msg__ImuData__Sequence__are_equal(const imu_interface__msg__ImuData__Sequence * lhs, const imu_interface__msg__ImuData__Sequence * rhs);

/// Copy an array of msg/ImuData messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_imu_interface
bool
imu_interface__msg__ImuData__Sequence__copy(
  const imu_interface__msg__ImuData__Sequence * input,
  imu_interface__msg__ImuData__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // IMU_INTERFACE__MSG__DETAIL__IMU_DATA__FUNCTIONS_H_
