#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pointer_arithmetic_example();
void pointer_to_pointer_example();
void pointers_and_arrays_example();
void pointers_as_function_args(int *x);
int* pointers_as_function_return();
void function_pointer_example();
void pointer_to_const_example();
void const_pointer_example();
void const_pointer_to_const_example();

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }

int main() {
    printf("*** Pointer Arithmetic ***\n");
    pointer_arithmetic_example();

    printf("\n*** Pointer to Pointer (Double Pointer) ***\n");
    pointer_to_pointer_example();

    printf("\n*** Pointers and Arrays ***\n");
    pointers_and_arrays_example();

    printf("\n*** Pointers as Function Arguments (Pass by Reference) ***\n");
    int num = 10;
    printf("Value before function call: %d\n", num);
    pointers_as_function_args(&num);
    printf("Value after function call: %d\n", num);

    printf("\n*** Pointers as Function Return Values ***\n");
    int *ret_ptr = pointers_as_function_return();
    if (ret_ptr != NULL) {
        printf("Value from returned pointer: %d\n", *ret_ptr);
        free(ret_ptr);
    }

    printf("\n*** Function Pointers ***\n");
    function_pointer_example();

    printf("\n*** Const and Pointers ***\n");
    pointer_to_const_example();
    const_pointer_example();
    const_pointer_to_const_example();

    return 0;
}

void pointer_arithmetic_example() {
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;

    printf("Initial pointer p points to value: %d\n", *p);

    p++;
    printf("After p++, p points to value: %d\n", *p);

    p = p + 2;
    printf("After p = p + 2, p points to value: %d\n", *p);

    int *q = &arr[1];
    printf("Difference between p (&arr[3]) and q (&arr[1]) is %ld elements\n", p - q);
}

void pointer_to_pointer_example() {
    int x = 123;
    int *p = &x;
    int **pp = &p;

    printf("Value of x: %d\n", x);
    printf("Value using single pointer (*p): %d\n", *p);
    printf("Value using double pointer (**pp): %d\n", **pp);

    printf("\nAddress of x: %p\n", (void*)&x);
    printf("Address stored in p: %p\n", (void*)p);
    printf("Address of p: %p\n", (void*)&p);
    printf("Address stored in pp: %p\n", (void*)pp);
}

void pointers_and_arrays_example() {
    int arr[] = {5, 10, 15, 20};
    int *p = arr;

    printf("Accessing array elements using array notation:\n");
    printf("arr[2] = %d\n", arr[2]);

    printf("Accessing array elements using pointer notation:\n");
    printf("*(arr + 2) = %d\n", *(arr + 2));
    printf("*(p + 2) = %d\n", *(p + 2));
    printf("p[2] = %d\n", p[2]);
}

void pointers_as_function_args(int *x) {
    printf("  (Inside function) Value received: %d\n", *x);
    *x = 99;
    printf("  (Inside function) Value changed to: %d\n", *x);
}

int* pointers_as_function_return() {
    int *ptr = (int*)malloc(sizeof(int));
    if (ptr != NULL) {
        *ptr = 42;
    }
    return ptr;
}

void function_pointer_example() {
    int (*op)(int, int);

    op = &add;
    int result = op(10, 5);
    printf("Result of op(10, 5) when op=&add: %d\n", result);

    op = &subtract;
    result = op(10, 5);
    printf("Result of op(10, 5) when op=&subtract: %d\n", result);
}

void pointer_to_const_example() {
    int x = 10;
    int y = 20;
    const int *p = &x;

    // *p = 15; // ILLEGAL: Cannot change the value through the pointer.
    p = &y;   // LEGAL: The pointer can be moved to point to another variable.
    printf("Pointer to const: p now points to value %d\n", *p);
}

void const_pointer_example() {
    int x = 10;
    int y = 20;
    int * const p = &x;

    *p = 15;   // LEGAL: The value can be changed.
    // p = &y; // ILLEGAL: The pointer itself is constant and cannot be reassigned.
    printf("Const pointer: The value pointed to is now %d\n", *p);
}

void const_pointer_to_const_example() {
    int x = 10;
    int y = 20;
    const int * const p = &x;

    // *p = 15; // ILLEGAL: Cannot change the value.
    // p = &y; // ILLEGAL: Cannot change the pointer.
    printf("Const pointer to const: The value is %d\n", *p);
}