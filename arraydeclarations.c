#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000
#define ITER 100000

// Static allocation
void staticArray() {
    static int arr[SIZE];
    arr[0] = 1;  // touch memory so compiler doesn't optimize away
}

// Stack allocation
void stackArray() {
    int arr[SIZE];
    arr[0] = 1;
}

// Heap allocation
void heapArray() {
    int *arr = (int*)malloc(SIZE * sizeof(int));
    if (arr == NULL) {
        printf("Heap allocation failed\n");
        exit(1);
    }
    arr[0] = 1;
    free(arr);
}

int main() {
    clock_t start, end;
    double cpu_time;

    // Static timing
    start = clock();
    for (int i = 0; i < ITER; i++)
        staticArray();
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Static allocation time: %f seconds\n", cpu_time);

    // Stack timing
    start = clock();
    for (int i = 0; i < ITER; i++)
        stackArray();
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Stack allocation time: %f seconds\n", cpu_time);

    // Heap timing
    start = clock();
    for (int i = 0; i < ITER; i++)
        heapArray();
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Heap allocation time: %f seconds\n", cpu_time);

    return 0;
}
