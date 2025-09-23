#include <stdio.h>
#include <stdlib.h>
#include "AlgoKit_lib.h"

int main(void){
    DynamicArray da = da_init(_int_);
    for(int i = 0; i < 10; i++){
        int x = i * 10;
        da_push_back(&da, &x);
    }
    da_print(&da);
    return 0;
}