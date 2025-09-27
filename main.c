#include <stdio.h>
#include <stdlib.h>
#include "AlgoKit_lib.h"

int main(void){
    DynamicArray DA = da_init(_int_), DA2;
    for(int i = 0; i < 10; i++){
        da_push_back(&DA, PTR(3, int));
    }
    da_println(&DA);
    da_insert(&DA, 1, PTR(5, int));
    da_println(&DA);
    da_copy(&DA2, &DA);
    printf("Copied array: ");
    da_println(&DA2);
    return 0;
}

/*
    constant variable:
    - const int a = 10; // a is a constant integer
    - int const b = 20; // b is a constant integer
    - const int* p = &a; // pointer to a constant integer
    - int const* q = &b; // pointer to a constant integer

    constant pointer:
    - int* const p = &a; // constant pointer to an integer
    - const int* const q = &b; // constant pointer to a constant integer
    - int const* const r = &a; // constant pointer to a constant integer
*/