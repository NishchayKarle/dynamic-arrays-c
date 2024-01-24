#ifndef array_h
#define array_h

#include <stddef.h>
#include <string.h>

/**
 * Initialize dynamic array
 *
 * @param _array_reference: reference to the array
 * @param _capacity: array initial capacity
 * @param _element_size: size of each element in the array
 */
extern void array_initialize(void *_array_reference, unsigned int _capacity, size_t _element_size);

/**
 * Length of the array
 *
 * @param _array_reference: reference to the array
 * @return int: length of the array
 */
extern int array_length(void *_array_reference);

/**
 * Push back / append new element on to the end of the array
 *
 * @param _array_reference: reference to the array
 * @param _element: element to be added to the array
 */
extern void array_push_back(void *_array_reference, void *_element);

/**
 * Pop back / remove element from end of the array
 *
 * @param _array_reference: reference to the array
 * @param _element: element to be added to the array
 */
extern void array_pop_back(void *_array_reference, void *_element);

/**
 * Clear all the elements in the array
 *
 * @param _array_reference: reference to the array
 */
extern void array_clear(void *_array_reference);

/**
 * Free memory allocated to the array
 *
 * @param _array_reference: reference to the array
 */
extern void array_free(void *_array_reference);

#endif