/**
 * @file DynamicArray.h
 * @brief Defines a generic dynamic array structure and associated data types for C/C++ projects.
 *
 * This header provides the definition of a generic dynamic array, allowing storage of elements of various types.
 * It includes an enumeration for supported data types and a structure representing the dynamic array itself.
 *
 * @author Mohamed Hafez
 * @date 2025
 *
 * @note This file is compatible with both C and C++ projects.
 */
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#ifdef __cplusplus
extern "C" {
#endif


#include "std_libraries/package.h"



typedef struct{
    int size;
    int capacity;
    void* arr;
    dataType type;
}DynamicArray;

// Initializes a DynamicArray with the specified data type.
DynamicArray da_init(dataType type);

// Frees the memory allocated for the dynamic array and resets its fields.
void da_free(DynamicArray* da);

// Adds the given value to the end of the dynamic array.
void da_push_back(DynamicArray* da, void* const value);

// Removes the last element from the dynamic array.
void da_pop_back(DynamicArray* da);

// Prints the elements of the dynamic array to the standard output.
void da_print(const DynamicArray* da);

// Prints the elements of the dynamic array to the standard output followed by a newline.
void da_println(const DynamicArray* da);

// Returns the current number of elements in the dynamic array.
int da_get_size(const DynamicArray* da);

// Returns the current capacity of the dynamic array.
int da_get_capacity(const DynamicArray* da);

// Inserts the given value at the specified index in the dynamic array.
void da_insert(DynamicArray* da, const int index, const void* value);

// Sets the element at the specified index to the given value.
void da_set(DynamicArray* da, const void* value, const int index);

// Returns a pointer to the element at the specified index in the dynamic array.
void* da_get(const DynamicArray* da, const int index);

// Searches for the first occurrence of the specified value in the dynamic array.
void* da_find(const DynamicArray* da, const void* value);

// Copies the contents of the source dynamic array to the destination dynamic array.
void da_copy(DynamicArray* dest, const DynamicArray* src);

// Removes the element at the specified index from the dynamic array.
void da_remove(DynamicArray* da, const int index);

#ifdef __cplusplus
}
#endif

#endif // DYNAMICARRAY_H


//Notes:

/*capacity is always a power of 2
1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536
when size == capacity -> capacity *= 2
when size <= capacity / 4 -> capacity /= 2
*/

/*
    constant values:
    - const int a = 10; // a is a constant integer
    - int const b = 20; // b is a constant integer
    - const int* p = &a; // pointer to a constant integer
    - int const* q = &b; // pointer to a constant integer

    constant pointer:
    - int* const p = &a; // constant pointer to an integer
    - const int* const q = &b; // constant pointer to a constant integer
    - int const* const r = &a; // constant pointer to a constant integer
*/