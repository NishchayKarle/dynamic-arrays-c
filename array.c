#include "array.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned int length;
    unsigned int capacity;
    size_t element_size;
} array_info;

void array_initialize(void *_array_reference, unsigned int _capacity, size_t _element_size)
{
    /* allocate memory for array_info and the array
     [array_info]->[array_start]-> ... ->[array_end] */
    array_info *info = (array_info *)malloc(sizeof(array_info) + (_capacity * _element_size));
    if (info == NULL)
    {
        printf("ERROR: failed to allocate memory for the array\n");
        exit(1);
    }

    info->length = 0;
    info->capacity = _capacity;
    info->element_size = _element_size;

    /* set array starting point (skip array_info)*/
    *(void **)_array_reference = info + 1;
}

int array_length(void *_array_reference)
{
    array_info *info = *(array_info **)_array_reference - 1;

    return info->length;
}

void array_push_back(void *_array_reference, void *_element)
{
    array_info *info = *(array_info **)_array_reference - 1;

    /* resize array if full */
    if (info->length == info->capacity)
    {
        info = (array_info *)realloc((void *)info,
                                     sizeof(array_info) + (info->capacity * info->element_size * 2));
        if (info == NULL)
        {
            printf("ERROR: failed to resize and reallocate memory for the array\n");
            exit(1);
        }
        *(void **)_array_reference = info + 1;
        info->capacity *= 2;
    }

    /* copy _element of size element-size bytes to the end of the array
        char* is one byte, move dst* in memcpy to end of the array
    */
    memcpy(*(char **)_array_reference + (info->length * info->element_size),
           _element,
           info->element_size);
    info->length++;
}

void array_pop_back(void *_array_reference)
{
    array_info *info = *(array_info **)_array_reference - 1;
    info->length--;
}

void array_clear(void *_array_reference)
{
    array_info *info = *(array_info **)_array_reference - 1;
    info->length = 0;
}

void array_free(void *_array_reference)
{
    array_info *info = *(array_info **)_array_reference - 1;
    free(info);
    *(void **)_array_reference = NULL;
}