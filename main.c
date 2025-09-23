#include <stdio.h>
#include <stdlib.h>
#include "AlgoKit_lib.h"

int main(void){
    DynamicArray da = da_init(_int_);
    variant x;
    da_push_back(&da, &(variant){.i = 5});
    da_push_back(&da, &(variant){.i = 10});
    da_insert(&da, 0, (variant){.i = 10});
    da_insert(&da, 1, (variant){.i = 20});
    da_insert(&da, 1, (variant){.i = 15});
    da_println(&da);   // prints: 10 15 20
    printf("index = %d", da_find(&da, (variant){.i = 20}).i);

    return 0;
}