#ifndef UTILS_H_RYSWJSMD
#define UTILS_H_RYSWJSMD

#include <stdio.h>

void fill_array_constant(int *arr, const size_t size, const int val) {
    for (int i = 0; i < size; ++i) {
        arr[i] = val;
    }
}

void fill_array_counting(int *arr, const size_t size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = i;
    }
}

void print_array(int *arr, const size_t size) {
    if (size > 0) { printf("%d", arr[0]); }
    for (int i = 1; i < size; ++i) {
        printf(", %d", arr[i]);
    }
    putchar('\n');
}

#endif /* end of include guard: UTILS_H_RYSWJSMD */
