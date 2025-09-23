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
    free(da);
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
    switch (da->type)
    {
    case _char_:
        ((char*)da->arr)[da->size] = *(char*)value;
        da->size++;
        break;
    case _int_:
        ((int*)da->arr)[da->size] = *(int*)value;
        da->size++;
        break;
    case _short_:
        ((short*)da->arr)[da->size] = *(short*)value;
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