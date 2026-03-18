// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from blink_interface:msg/BlinkData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "blink_interface/msg/blink_data.h"


#ifndef BLINK_INTERFACE__MSG__DETAIL__BLINK_DATA__FUNCTIONS_H_
#define BLINK_INTERFACE__MSG__DETAIL__BLINK_DATA__FUNCTIONS_H_

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
#include "blink_interface/msg/rosidl_generator_c__visibility_control.h"

#include "blink_interface/msg/detail/blink_data__struct.h"

/// Initialize msg/BlinkData message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * blink_interface__msg__BlinkData
 * )) before or use
 * blink_interface__msg__BlinkData__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_blink_interface
bool
blink_interface__msg__BlinkData__init(blink_interface__msg__BlinkData * msg);

/// Finalize msg/BlinkData message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_blink_interface
void
blink_interface__msg__BlinkData__fini(blink_interface__msg__BlinkData * msg);

/// Create msg/BlinkData message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * blink_interface__msg__BlinkData__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_blink_interface
blink_interface__msg__BlinkData *
blink_interface__msg__BlinkData__create(void);

/// Destroy msg/BlinkData message.
/**
 * It calls
 * blink_interface__msg__BlinkData__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_blink_interface
void
blink_interface__msg__BlinkData__destroy(blink_interface__msg__BlinkData * msg);

/// Check for msg/BlinkData message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_blink_interface
bool
blink_interface__msg__BlinkData__are_equal(const blink_interface__msg__BlinkData * lhs, const blink_interface__msg__BlinkData * rhs);

/// Copy a msg/BlinkData message.
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
ROSIDL_GENERATOR_C_PUBLIC_blink_interface
bool
blink_interface__msg__BlinkData__copy(
  const blink_interface__msg__BlinkData * input,
  blink_interface__msg__BlinkData * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_blink_interface
const rosidl_type_hash_t *
blink_interface__msg__BlinkData__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_blink_interface
const rosidl_runtime_c__type_description__TypeDescription *
blink_interface__msg__BlinkData__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_blink_interface
const rosidl_runtime_c__type_description__TypeSource *
blink_interface__msg__BlinkData__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_blink_interface
const rosidl_runtime_c__type_description__TypeSource__Sequence *
blink_interface__msg__BlinkData__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/BlinkData messages.
/**
 * It allocates the memory for the number of elements and calls
 * blink_interface__msg__BlinkData__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_blink_interface
bool
blink_interface__msg__BlinkData__Sequence__init(blink_interface__msg__BlinkData__Sequence * array, size_t size);

/// Finalize array of msg/BlinkData messages.
/**
 * It calls
 * blink_interface__msg__BlinkData__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_blink_interface
void
blink_interface__msg__BlinkData__Sequence__fini(blink_interface__msg__BlinkData__Sequence * array);

/// Create array of msg/BlinkData messages.
/**
 * It allocates the memory for the array and calls
 * blink_interface__msg__BlinkData__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_blink_interface
blink_interface__msg__BlinkData__Sequence *
blink_interface__msg__BlinkData__Sequence__create(size_t size);

/// Destroy array of msg/BlinkData messages.
/**
 * It calls
 * blink_interface__msg__BlinkData__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_blink_interface
void
blink_interface__msg__BlinkData__Sequence__destroy(blink_interface__msg__BlinkData__Sequence * array);

/// Check for msg/BlinkData message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_blink_interface
bool
blink_interface__msg__BlinkData__Sequence__are_equal(const blink_interface__msg__BlinkData__Sequence * lhs, const blink_interface__msg__BlinkData__Sequence * rhs);

/// Copy an array of msg/BlinkData messages.
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
ROSIDL_GENERATOR_C_PUBLIC_blink_interface
bool
blink_interface__msg__BlinkData__Sequence__copy(
  const blink_interface__msg__BlinkData__Sequence * input,
  blink_interface__msg__BlinkData__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // BLINK_INTERFACE__MSG__DETAIL__BLINK_DATA__FUNCTIONS_H_
