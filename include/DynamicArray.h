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


#include <stdio.h>
#include <stdlib.h>

typedef enum{
    _char_,
    _short_,
    _int_,
    _float_,
    _double_,
    _long_,
    _long_double_
}dataType;

typedef union{
    char c;
    short s;
    int i;
    float f;
    double d;
    long l;
}variant;

typedef struct{
    int size;
    int capacity;
    void* arr;
    dataType type;
}DynamicArray;

DynamicArray da_init(dataType type);

void da_free(DynamicArray* da);

void da_push_back(DynamicArray* da, void* const value);

void da_pop_back(DynamicArray* da);

void da_print(const DynamicArray* da);

void da_println(const DynamicArray* da);

int da_get_size(const DynamicArray* da);

int da_get_capacity(const DynamicArray* da);

variant da_get(const DynamicArray* da, int index);

void da_set(DynamicArray* da, const variant value, int index);

variant da_find(const DynamicArray* da, const variant value);

void da_insert(DynamicArray* da, int index, const variant value);

// incomplete function
void da_remove(DynamicArray* da, int index);

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