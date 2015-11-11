#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"


void vector_add(const int *vec1, const int *vec2, int *result, const size_t size) {
    for (size_t i = 0; i < size; ++i) {
        result[i] = vec1[i] + vec2[i];
    }
}


int main(int argc, char *argv[]) {
    size_t num_elements = 10000;
    size_t num_bytes = sizeof(int) * num_elements;

    // ---- DECLARE VARIABLES --------------
    int *vec_a;
    int *vec_b;
    int *vec_r;

    // ---- ALLOCATE MEMORY ----------------
    vec_a = (int *)malloc(num_bytes);
    vec_b = (int *)malloc(num_bytes);
    vec_r = (int *)malloc(num_bytes);

    // ---- INITIALIZE DATA ----------------
    fill_array_constant(vec_a, num_elements, 1);
    fill_array_constant(vec_b, num_elements, 2);

    // ---- PERFORM COMPUTATION ------------
    vector_add(vec_a, vec_b, vec_r, num_elements);

    // ---- DO SOMETHING WITH THE DATA -----
    print_array(vec_r, num_elements);

    // ---- CLEANUP ------------------------
    free(vec_a);
    free(vec_b);
    free(vec_r);

    return 0;
}
