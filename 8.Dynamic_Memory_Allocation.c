#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void malloc_example();
void calloc_example();
void realloc_example();
void common_pitfalls();
void print_array(int *arr, int size, const char *name);

int main() {
    printf("*** 1. malloc: Allocate memory for an array ***\n");
    malloc_example();

    printf("\n*** 2. calloc: Allocate and zero-initialize an array ***\n");
    calloc_example();

    printf("\n*** 3. realloc: Resize a memory block ***\n");
    realloc_example();

    printf("\n*** 4. Common Pitfalls and Best Practices ***\n");
    common_pitfalls();

    return 0;
}

// malloc
void malloc_example() {
    int n = 5;
    int *arr;

    // Allocate memory for 5 integers
    arr = (int*)malloc(n * sizeof(int));

    // ALWAYS check if malloc was successful
    if (arr == NULL) {
        fprintf(stderr, "malloc failed to allocate memory!\n");
        return;
    }

    printf("Memory allocated successfully using malloc.\n");
    
    // The allocated memory is not initialized. Let's print it (will be garbage).
    print_array(arr, n, "arr (after malloc)");
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    print_array(arr, n, "arr (after initialization)");

    free(arr);
    printf("Memory has been freed.\n");
}

// calloc
void calloc_example() {
    int n = 5;
    int *arr;

    // Allocate memory for 5 integers and initialize them to zero
    arr = (int*)calloc(n, sizeof(int));

    if (arr == NULL) {
        fprintf(stderr, "calloc failed to allocate memory!\n");
        return;
    }

    printf("Memory allocated and zero-initialized successfully using calloc.\n");
    print_array(arr, n, "arr (after calloc)");

    free(arr);
    printf("Memory has been freed.\n");
}
// realloc
void realloc_example() {
    int n1 = 5;
    int *arr = (int*)malloc(n1 * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Initial malloc failed!\n");
        return;
    }

    for (int i = 0; i < n1; i++) {
        arr[i] = i * 10;
    }
    printf("Original array (size %d):\n", n1);
    print_array(arr, n1, "arr");

    // --- Expand the array ---
    int n2 = 10;
    int *temp = (int*)realloc(arr, n2 * sizeof(int));

    // realloc can fail and return NULL. If it does, the original memory (arr) is still valid.
    if (temp == NULL) {
        fprintf(stderr, "realloc failed to expand memory!\n");
        free(arr);
        return;
    }
    arr = temp;

    printf("\nArray expanded to size %d.\n", n2);
    // Initialize the new elements
    for (int i = n1; i < n2; i++) {
        arr[i] = i * 10;
    }
    print_array(arr, n2, "arr (expanded)");

    // --- Shrink the array ---
    int n3 = 3;
    temp = (int*)realloc(arr, n3 * sizeof(int));
    if (temp == NULL) {
        fprintf(stderr, "realloc failed to shrink memory!\n");
        free(arr);
        return;
    }
    arr = temp;

    printf("\nArray shrunk to size %d.\n", n3);
    print_array(arr, n3, "arr (shrunk)");

    free(arr);
    printf("Memory has been freed.\n");
}

/**
 common dynamic memory pitfalls.
 */
void common_pitfalls() {
    // 1. Memory Leak: Forgetting to free allocated memory.
    int *leak_ptr = (int*)malloc(sizeof(int));
    *leak_ptr = 100;
    // If we don't call free(leak_ptr), this memory is "leaked" and cannot be reused.
    // In a long-running program, this can exhaust system memory.
    free(leak_ptr); // Correct: Always free what you allocate.
    printf("Pitfall 1: Memory leak avoided by calling free().\n");

    // 2. Dangling Pointer: Using a pointer after it has been freed.
    int *dangle_ptr = (int*)malloc(sizeof(int));
    *dangle_ptr = 200;
    free(dangle_ptr);
    // *dangle_ptr = 300; // UNDEFINED BEHAVIOR! This is a dangling pointer.
    // The memory might be used by something else now.
    dangle_ptr = NULL; // Best practice: Set freed pointers to NULL.
    printf("Pitfall 2: Dangling pointer access avoided by setting pointer to NULL after free.\n");

    // 3. Double Free: Freeing the same memory twice.
    int *double_free_ptr = (int*)malloc(sizeof(int));
    free(double_free_ptr);
    // free(double_free_ptr); // UNDEFINED BEHAVIOR! Can corrupt memory management structures.
    printf("Pitfall 3: Double free would cause a crash or corruption.\n");
}

void print_array(int *arr, int size, const char *name) {
    printf("  %s: [ ", name);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}