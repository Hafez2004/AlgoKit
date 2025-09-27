#include "../include/DynamicArray.h"

DynamicArray da_init(dataType type){
    /*
    Initializes a DynamicArray with the specified data type.
    Example usage:
    - DynamicArray my_dynamic_array = da_init(_int_);
    - DynamicArray my_dynamic_array = da_init(_char_);
    Note: The initial capacity is set to 1 and the size is set to 0.
    The user is responsible for freeing the allocated memory using da_free().
    */
    DynamicArray da;
    da.size = 0;
    da.capacity = 1;
    switch(type){
        case _char_:
            da.arr = (char*)malloc(sizeof(char) * da.capacity);
            da.type = _char_;
            break;
        case _short_:
            da.arr = (short*)malloc(sizeof(short) * da.capacity);
            da.type = _short_;
            break;
        case _int_:
            da.arr = (int*)malloc(sizeof(int) * da.capacity);
            da.type = _int_;
            break;
        case _float_:
            da.arr = (float*)malloc(sizeof(float) * da.capacity);
            da.type = _float_;
            break;
        case _double_:
            da.arr = (double*)malloc(sizeof(double) * da.capacity);
            da.type = _double_;
            break;
        case _long_:
            da.arr = (long*)malloc(sizeof(long) * da.capacity);
            da.type = _long_;
            break;
        case _long_double_:
            da.arr = (long double*)malloc(sizeof(long double) * da.capacity);
            da.type = _long_double_;
            break;
        default:
            fprintf(stderr, "Unsupported data type\n");
            exit(EXIT_FAILURE);
    }
    if(NULL == da.arr){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return da;    
}

void da_free(DynamicArray* da){
    /*
    Frees the memory allocated for the dynamic array and resets its fields.
    Example usage:
    - da_free(&my_dynamic_array);
    Note: After calling this function, the dynamic array should not be used unless re-initial
    */
    if(!da && !da->arr) return;
    free(da->arr);
    da->arr = NULL;
    da->size = 0;
    da->capacity = 0;
    da = NULL;
}

void da_push_back(DynamicArray* da, void* const value){
    /*
    Adds the given value to the end of the dynamic array.
    Example usage:
    - da_push_back(&my_dynamic_array, &new_value);
    */
    if(!da || !value) return;
    if(da->size >= da->capacity){
        da->capacity *= 2;
        da->arr = realloc(da->arr, da->capacity * (da->type == _int_ ? sizeof(int) :
                                                   da->type == _char_ ? sizeof(char) :
                                                   da->type == _short_ ? sizeof(short) :
                                                   da->type == _float_ ? sizeof(float) :
                                                   da->type == _double_ ? sizeof(double) :
                                                   da->type == _long_ ? sizeof(long) :
                                                   sizeof(long double)));
        if(NULL == da->arr){
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }

    }
    switch (da->type)
    {
    case _char_:
        ((char*)da->arr)[da->size] = *(char*)value;
        da->size++;
        break;
    case _short_:
        ((short*)da->arr)[da->size] = *(short*)value;
        da->size++;
        break;
    case _int_:
        ((int*)da->arr)[da->size] = *(int*)value;
        da->size++;
        break;
    case _float_:
        ((float*)da->arr)[da->size] = *(float*)value;
        da->size++;
        break;
    case _double_:
        ((double*)da->arr)[da->size] = *(double*)value;
        da->size++;
        break;
    case _long_:
        ((long*)da->arr)[da->size] = *(long*)value;
        da->size++;
        break;
    case _long_double_:
        ((long double*)da->arr)[da->size] = *(long double*)value;
        da->size++;
        break;
    default:
        break;
    }
}

void da_pop_back(DynamicArray* da){
    /*
    Removes the last element from the dynamic array.
    Example usage:
    - da_pop_back(&my_dynamic_array);
    Note: Does nothing if the array is empty.
    */
    if(!da || da->size <= 0) return;
    da->size--;
    if(da->size <= da->capacity / 4 && da->capacity > 1){
        da->capacity /= 2;
        da->arr = realloc(da->arr, da->capacity * (da->type == _int_ ? sizeof(int) :
                                                   da->type == _char_ ? sizeof(char) :
                                                   da->type == _short_ ? sizeof(short) :
                                                   da->type == _float_ ? sizeof(float) :
                                                   da->type == _double_ ? sizeof(double) :
                                                   da->type == _long_ ? sizeof(long) :
                                                   sizeof(long double)));
        if(NULL == da->arr){
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
}

void da_print(const DynamicArray* da){
    /*
    Prints the elements of the dynamic array to the standard output.
    Example usage:
    - da_print(&my_dynamic_array);
    */
    if(!da || !da->arr) return;
    for(int i = 0; i < da->size; i++){
        switch (da->type)
        {
        case _char_:
            printf("%c", ((char*)da->arr)[i]);
            break;
        case _int_:
            printf("%d", ((int*)da->arr)[i]);
            break;
        case _short_:
            printf("%d", ((short*)da->arr)[i]);
            break;
        case _float_:
            printf("%f", ((float*)da->arr)[i]);
            break;
        case _double_:
            printf("%lf", ((double*)da->arr)[i]);
            break;
        case _long_:
            printf("%ld", ((long*)da->arr)[i]);
            break;
        case _long_double_:
            printf("%Lf", ((long double*)da->arr)[i]);
            break;
        default:
            break;
        }
        if(i < da->size - 1) printf(" ");
    }
}

void da_println(const DynamicArray* da){
    /*
    Prints the elements of the dynamic array to the standard output followed by a newline.
    Example usage:
    - da_println(&my_dynamic_array);
    */
    da_print(da);
    printf("\n");
}

int da_get_size(const DynamicArray* da){
    /*
    Returns the current number of elements in the dynamic array.
    Example usage:
    - int size = da_get_size(&my_dynamic_array);
    */
    if(!da) return -1;
    return da->size;
}

int da_get_capacity(const DynamicArray* da){
    /*
    Returns the current capacity of the dynamic array.
    Example usage:
    - int capacity = da_get_capacity(&my_dynamic_array);
    */
    if(!da) return -1;
    return da->capacity;
}

void da_insert(DynamicArray* da, const int index, const void* value){
    /*
    Inserts the given value at the specified index in the dynamic array.
    Example usage:
    - da_insert(&my_dynamic_array, 2, &new_value); // Inserts new
    Note: index can be equal to size (inserts at the end)
    */
    if(!da || !value || index < 0 || index > da->size){
        fprintf(stderr, "Index out of bounds or invalid DynamicArray\n");
        exit(EXIT_FAILURE);
    }
    if(da->size >= da->capacity){
        da->capacity *= 2;
        da->arr = realloc(da->arr, da->capacity * (da->type == _int_ ? sizeof(int) :
                                                   da->type == _char_ ? sizeof(char) :
                                                   da->type == _short_ ? sizeof(short) :
                                                   da->type == _float_ ? sizeof(float) :
                                                   da->type == _double_ ? sizeof(double) :
                                                   da->type == _long_ ? sizeof(long) :
                                                   sizeof(long double)));
        if(NULL == da->arr){
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    // shift elements to the right
    switch (da->type)
    {
    case _char_:
        for(size_t i = da->size; i > index; i--){
            ((char*)da->arr)[i] = ((char*)da->arr)[i - 1];
        }
        ((char*)da->arr)[index] = *(char*)value;
        da->size++;
        break;
    case _short_:
        for (int i = da->size; i > index; i--) {
            ((short*)da->arr)[i] = ((short*)da->arr)[i - 1];
        }
        ((short*)da->arr)[index] = *(short*)value;
        da->size++;
        break;
    case _int_:
        for (int i = da->size; i > index; i--) {
            ((int*)da->arr)[i] = ((int*)da->arr)[i - 1];
        }
        ((int*)da->arr)[index] = *(int*)value;
        da->size++;
        break;
    case _float_:
        for (int i = da->size; i > index; i--) {
            ((float*)da->arr)[i] = ((float*)da->arr)[i - 1];
        }
        ((float*)da->arr)[index] = *(float*)value;
        da->size++;
        break;
    case _double_:
        for (int i = da->size; i > index; i--) {
            ((double*)da->arr)[i] = ((double*)da->arr)[i - 1];
        }
        ((double*)da->arr)[index] = *(double*)value;
        da->size++;
        break;
    case _long_:
        for (int i = da->size; i > index; i--) {
            ((long*)da->arr)[i] = ((long*)da->arr)[i - 1];
        }
        ((long*)da->arr)[index] = *(long*)value;
        da->size++;
        break;
    case _long_double_:
        for (int i = da->size; i > index; i--) {
            ((long double*)da->arr)[i] = ((long double*)da->arr)[i - 1];
        }
        ((long double*)da->arr)[index] = *(long double*)value;
        da->size++;
        break;
    default:
        break;
    }
}

void da_set(DynamicArray* da, const void* value, const int index){
    /*
    Sets the element at the specified index to the given value.
    Example usage:
    - da_set(&my_dynamic_array, &new_value, 0); // Sets the element at index 0 to new_value
    */
    if(!da || !value || index < 0 || index >= da->size){
        fprintf(stderr, "Index out of bounds or invalid DynamicArray\n");
        exit(EXIT_FAILURE);
    }
    switch (da->type)
    {
    case _char_:
        ((char*)da->arr)[index] = *(char*)value;
        break;
    case _short_:
        ((short*)da->arr)[index] = *(short*)value;
        break;
    case _int_:
        ((int*)da->arr)[index] = *(int*)value;
        break;
    case _float_:
        ((float*)da->arr)[index] = *(float*)value;
        break;
    case _double_:
        ((double*)da->arr)[index] = *(double*)value;
        break;
    case _long_:
        ((long*)da->arr)[index] = *(long*)value;
        break;
    case _long_double_:
        ((long double*)da->arr)[index] = *(long double*)value;
        break;
    default:
        break;
    }
}

void* da_get(const DynamicArray* da, const int index){
    /*
    Returns a pointer to the element at the specified index in the dynamic array.
    Example usage:
    - char data = *(char*)da_get(&my_dynamic_array, 0);
    - int data = *(int*)da_get(&my_dynamic_array, 0);
    */
    if(!da || index < 0 || index >= da->size){
        fprintf(stderr, "Index out of bounds or invalid DynamicArray\n");
        exit(EXIT_FAILURE);
    }
    switch (da->type)
    {
    case _char_:
        return &((char*)da->arr)[index];
    case _short_:
        return &((short*)da->arr)[index];
    case _int_:
        return &((int*)da->arr)[index];
    case _float_:
        return &((float*)da->arr)[index];
    case _double_:
        return &((double*)da->arr)[index];
    case _long_:
        return &((long*)da->arr)[index];
    case _long_double_:
        return &((long double*)da->arr)[index];
    default:
        return NULL;
    }
}

void* da_find(const DynamicArray* da, const void* value){
    /*
    Searches for the first occurrence of the specified value in the dynamic array.
    Returns a pointer to the element if found, or NULL if not found.
    Example usage:
    - char found_char = *(char*)da_find(&my_dynamic_array, &search_value);
    - int found_int = *(int*)da_find(&my_dynamic_array, &search_value);
    */
    if(!da || !value) return NULL;
    switch(da->type){
        case _char_:
            for(int i = 0; i < da->size; i++){
                if(((char*)da->arr)[i] == *(char*)value) return &((char*)da->arr)[i];
            }
            break;
        case _short_:
            for(int i = 0; i < da->size; i++){
                if(((short*)da->arr)[i] == *(short*)value) return &((short*)da->arr)[i];
            }
            break;
        case _int_:
            for(int i = 0; i < da->size; i++){
                if(((int*)da->arr)[i] == *(int*)value) return &((int*)da->arr)[i];
            }
            break;
        case _float_:
            for(int i = 0; i < da->size; i++){
                if(((float*)da->arr)[i] == *(float*)value) return &((float*)da->arr)[i];
            }
            break;
        case _double_:
            for(int i = 0; i < da->size; i++){
                if(((double*)da->arr)[i] == *(double*)value) return &((double*)da->arr)[i];
            }
            break;
        case _long_:
            for(int i = 0; i < da->size; i++){
                if(((long*)da->arr)[i] == *(long*)value) return &((long*)da->arr)[i];
            }
            break;
        case _long_double_:
            for(int i = 0; i < da->size; i++){
                if(((long double*)da->arr)[i] == *(long double*)value) return &((long double*)da->arr)[i];
            }
            break;
        default:
            break;
    }
    return NULL;
}

void da_copy(DynamicArray* dest, const DynamicArray* src){
    /*
    Copies the contents of the source dynamic array to the destination dynamic array.
    The destination array is resized if necessary to accommodate the contents of the source array.
    Example usage:
    - DynamicArray dest = da_init(_int_);
    - DynamicArray src = da_init(_int_);
    - da_copy(&dest, &src);
    */
    if(!dest || !src || !src->arr) return;
    dest->size = src->size;
    dest->capacity = src->capacity;
    dest->type = src->type;
    dest->arr = malloc(dest->capacity * (dest->type == _int_ ? sizeof(int) :
                                         dest->type == _char_ ? sizeof(char) :
                                         dest->type == _short_ ? sizeof(short) :
                                         dest->type == _float_ ? sizeof(float) :
                                         dest->type == _double_ ? sizeof(double) :
                                         dest->type == _long_ ? sizeof(long) :
                                         sizeof(long double)));
    if(NULL == dest->arr){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    memcpy(dest->arr, src->arr, dest->size * (dest->type == _int_ ? sizeof(int) :
                                             dest->type == _char_ ? sizeof(char) :
                                             dest->type == _short_ ? sizeof(short) :
                                             dest->type == _float_ ? sizeof(float) :
                                             dest->type == _double_ ? sizeof(double) :
                                             dest->type == _long_ ? sizeof(long) :
                                             sizeof(long double)));
}

void da_remove(DynamicArray* da, const int index){
    /*
    Removes the element at the specified index from the dynamic array.
    Example usage:
    - da_remove(&my_dynamic_array, 2); // Removes the element at index
    */
    if(!da || !da->arr || index < 0 || index >= da->size){
        fprintf(stderr, "Index out of bounds or invalid DynamicArray\n");
        exit(EXIT_FAILURE);
    }
    // shift elements
    for(int i = index; i < da->size - 1; i++){
        switch(da->type){
            case _int_: ((int*)da->arr)[i] = ((int*)da->arr)[i + 1]; break;
            case _char_: ((char*)da->arr)[i] = ((char*)da->arr)[i + 1]; break;
            case _short_: ((short*)da->arr)[i] = ((short*)da->arr)[i + 1]; break;
            case _float_: ((float*)da->arr)[i] = ((float*)da->arr)[i + 1]; break;
            case _double_: ((double*)da->arr)[i] = ((double*)da->arr)[i + 1]; break;
            case _long_: ((long*)da->arr)[i] = ((long*)da->arr)[i + 1]; break;
            case _long_double_: ((long double*)da->arr)[i] = ((long double*)da->arr)[i + 1]; break;
            default: exit(EXIT_FAILURE);
        }
    }
    da->size--;
    if(da->size <= da->capacity / 4 && da->capacity > 1){
        da->capacity /= 2;
        da->arr = realloc(da->arr, da->capacity * (da->type == _int_ ? sizeof(int) :
                                                   da->type == _char_ ? sizeof(char) :
                                                   da->type == _short_ ? sizeof(short) :
                                                   da->type == _float_ ? sizeof(float) :
                                                   da->type == _double_ ? sizeof(double) :
                                                   da->type == _long_ ? sizeof(long) :
                                                   sizeof(long double)));
        if(NULL == da->arr){
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
}