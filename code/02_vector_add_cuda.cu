#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"


__global__
void vector_add(const int *vec1, const int *vec2, int *result, const size_t size) {
    int thread_id = theadIdx.x + blockIdx.x * blockDim.x;
    if (thread_id > size)
        return;

    result[thread_id] = vec1[thread_id] + vec2[thread_id];
}


int main(int argc, char *argv[]) {
    size_t num_elements = 10000;
    if (argc > 1) { sscanf(argv[1], "%zu", &num_elements); }
    size_t num_bytes = sizeof(int) * num_elements;

    // ---- DECLARE VARIABLES -----------------------
    int *host_a, *host_b, *host_r;
    int *dev_a, *dev_b, *dev_r;

    // ---- ALLOCATE MEMORY ON HOST -----------------
    host_a = (int *)malloc(num_bytes);
    host_b = (int *)malloc(num_bytes);
    host_r = (int *)malloc(num_bytes);

    // ---- INITIALIZE DATA ON HOST -----------------
    fill_array_constant(host_a, num_elements, 1);
    fill_array_constant(host_b, num_elements, 2);

    // ---- ALLOCATE MEMORY ON DEVICE ---------------
    // cudaMalloc(void **dev_ptr, size_t count)
    cudaMalloc(&dev_a, num_bytes);
    cudaMalloc(&dev_b, num_bytes);
    cudaMalloc(&dev_r, num_bytes);

    // ---- COPY DATA OVER TO DEVICE ----------------
    // cudaMemcpy(void *dst, const void *src, size_t count, cudaMemcpyKind kind)
    cudaMemcpy(dev_a, host_a, num_bytes, cudaMemcpyHostToDevice);
    cudaMemcpy(dev_b, host_b, num_bytes, cudaMemcpyHostToDevice);

    // ---- PERFORM COMPUTATION ---------------------
    // ... skip over nThreads, nBlocks etc ...
    vector_add<<<blocks_per_grid, threads_per_block>>>(dev_a, dev_b, dev_r, num_elements);

    // ---- COPY RESULT DATA BACK TO HOST -----------
    cudaMemcpy(host_r, dev_r, num_bytes, cudaMemcpyDeviceToHost);

    // ---- DO SOMETHING WITH THE DATA --------------
    print_array(host_r, num_elements);

    // ---- CLEANUP ---------------------------------
    free(host_a); free(host_b); free(host_r);
    cudaFree(dev_a); cudaFree(dev_b); cudaFree(dev_r);

    return 0;
}

