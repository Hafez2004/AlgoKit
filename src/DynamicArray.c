#include "../include/DynamicArray.h"

DynamicArray da_init(dataType type){
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
    if(!da && !da->arr) return;
    free(da->arr);
    da->arr = NULL;
    da->size = 0;
    da->capacity = 0;
    da = NULL;
}

void da_push_back(DynamicArray* da, void* const value){
    if(!da || !value) return;
    if(da->size >= da->capacity){
        da->capacity *= 2;
        switch(da->type){
            case _char_:
            da->arr = (char*)realloc(da->arr, sizeof(char) * da->capacity);
            break;
            case _short_:
            da->arr = (short*)realloc(da->arr, sizeof(short) * da->capacity);
            break;
            case _int_:
                da->arr = (int*)realloc(da->arr, sizeof(int) * da->capacity);
                break;
            case _float_:
                da->arr = (float*)realloc(da->arr, sizeof(float) * da->capacity);
                break;
            case _double_:
                da->arr = (double*)realloc(da->arr, sizeof(double) * da->capacity);
                break;
            case _long_:
                da->arr = (long*)realloc(da->arr, sizeof(long) * da->capacity);
                break;
            case _long_double_:
                da->arr = (long double*)realloc(da->arr, sizeof(long double) * da->capacity);
                break;
            default:
                fprintf(stderr, "Unsupported data type\n");
                exit(EXIT_FAILURE);
        }
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

    if(!da || da->size <= 0) return;
    da->size--;
    if(da->size <= da->capacity / 4 && da->capacity > 1){
        da->capacity /= 2;
        switch(da->type){
            case _char_:
                da->arr = (char*)realloc(da->arr, sizeof(char) * da->capacity);
                break;
            case _int_:
                da->arr = (int*)realloc(da->arr, sizeof(int) * da->capacity);
                break;
            case _short_:
                da->arr = (short*)realloc(da->arr, sizeof(short) * da->capacity);
                break;
            case _float_:
                da->arr = (float*)realloc(da->arr, sizeof(float) * da->capacity);
                break;
            case _double_:
                da->arr = (double*)realloc(da->arr, sizeof(double) * da->capacity);
                break;
            case _long_:
                da->arr = (long*)realloc(da->arr, sizeof(long) * da->capacity);
                break;
            case _long_double_:
                da->arr = (long double*)realloc(da->arr, sizeof(long double) * da->capacity);
                break;
            default:
                fprintf(stderr, "Unsupported data type\n");
                exit(EXIT_FAILURE);
        }
        if(NULL == da->arr){
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
}

void da_print(const DynamicArray* da){
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
    da_print(da);
    printf("\n");
}

int da_get_size(const DynamicArray* da){
    if(!da) return -1;
    return da->size;
}

int da_get_capacity(const DynamicArray* da){
    if(!da) return -1;
    return da->capacity;
}

variant da_get(const DynamicArray* da, int index){
    variant at;
    if(!da || !da->arr || index < 0 || index >= da->size){
        fprintf(stderr, "Index out of bounds or invalid DynamicArray\n");
        exit(EXIT_FAILURE);
    }
    switch (da->type)
    {
    case _char_:
        at.c = ((char*)da->arr)[index];
        break;
    case _short_:
        at.s = ((short*)da->arr)[index];
        break;
    case _int_:
        at.i = ((int*)da->arr)[index];
        break;
    case _float_:
        at.f = ((float*)da->arr)[index];
        break;
    case _double_:
        at.d = ((double*)da->arr)[index];
        break;
    case _long_:
        at.l = ((long*)da->arr)[index];
        break;
    default:
        fprintf(stderr, "Unsupported data type\n");
        exit(EXIT_FAILURE);
    }
    return at;
}

void da_set(DynamicArray* da, const variant value, int index){
    if(!da || !da->arr || index < 0 || index >= da->size){
        fprintf(stderr, "Index out of bounds or invalid DynamicArray\n");
        exit(EXIT_FAILURE);
    }
    switch (da->type)
    {
    case _char_:
        ((char*)da->arr)[index] = value.c;
        break;
    case _short_:
        ((short*)da->arr)[index] = value.s;
        break;
    case _int_:
        ((int*)da->arr)[index] = value.i;
        break;
    case _float_:
        ((float*)da->arr)[index] = value.f;
        break;
    case _double_:
        ((double*)da->arr)[index] = value.d;
        break;
    case _long_:
        ((long*)da->arr)[index] = value.l;
        break;
    default:
        fprintf(stderr, "Unsupported data type\n");
        exit(EXIT_FAILURE);
    }
}

variant da_find(const DynamicArray* da, const variant value){
    if(!da || !da->arr){
        fprintf(stderr, "Invalid DynamicArray\n");
        exit(EXIT_FAILURE);
    }
    switch (da->type)
    {
    case _char_:
        for(int i = 0; i < da->size; i++){
            if(((char*)da->arr)[i] == value.c) return (variant){.i = i};
        }
        break;
    case _short_:
        for(int i = 0; i < da->size; i++){
            if(((short*)da->arr)[i] == value.s) return (variant){.i = i};
        }
        break;
    case _int_:
        for(int i = 0; i < da->size; i++){
            if(((int*)da->arr)[i] == value.i) return (variant){.i = i};
        }
        break;
    case _float_:
        for(int i = 0; i < da->size; i++){
            if(((float*)da->arr)[i] == value.f) return (variant){.i = i};
        }
        break;
    case _double_:
        for(int i = 0; i < da->size; i++){
            if(((double*)da->arr)[i] == value.d) return (variant){.i = i};
        }
        break;
    case _long_:
        for(int i = 0; i < da->size; i++){
            if(((long*)da->arr)[i] == value.l) return (variant){.i = i};
        }
        break;
    default:
        fprintf(stderr, "Unsupported data type\n");
        exit(EXIT_FAILURE);
    }
}

void da_insert(DynamicArray* da, int index, const variant value){
    if(!da || !da->arr || index < 0 || index > da->size){  // allow index == size
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
    // shift elements
    for(int i = da->size - 1; i >= index; i--){
        switch(da->type){
            case _int_: ((int*)da->arr)[i + 1] = ((int*)da->arr)[i]; break;
            case _char_: ((char*)da->arr)[i + 1] = ((char*)da->arr)[i]; break;
            case _short_: ((short*)da->arr)[i + 1] = ((short*)da->arr)[i]; break;
            case _float_: ((float*)da->arr)[i + 1] = ((float*)da->arr)[i]; break;
            case _double_: ((double*)da->arr)[i + 1] = ((double*)da->arr)[i]; break;
            case _long_: ((long*)da->arr)[i + 1] = ((long*)da->arr)[i]; break;
            case _long_double_: ((long double*)da->arr)[i + 1] = ((long double*)da->arr)[i]; break;
            default: exit(EXIT_FAILURE);
        }
    }
    // insert new value
    switch(da->type){
        case _int_: ((int*)da->arr)[index] = value.i; break;
        case _char_: ((char*)da->arr)[index] = value.c; break;
        case _short_: ((short*)da->arr)[index] = value.s; break;
        case _float_: ((float*)da->arr)[index] = value.f; break;
        case _double_: ((double*)da->arr)[index] = value.d; break;
        case _long_: ((long*)da->arr)[index] = value.l; break;
        default: exit(EXIT_FAILURE);
    }
    da->size++;
}

void da_remove(DynamicArray* da, int index){
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