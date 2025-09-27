#include "../include/Sorting.h"

void swap(void* const a, void* const b, const size_t size) {
    void* temp = malloc(size);
    if (!temp) return;
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}
