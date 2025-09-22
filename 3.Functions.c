#include <stdio.h>
#include <string.h>

void greet(void);
int add(int a, int b);
void swap_by_value(int x, int y);
void swap_by_reference(int *x, int *y);
int factorial(int n);
void scope_and_storage(void);


int global_var = 100;
int extern_var = 500;


int main() {
    printf("*** Function Examples in C ***\n\n");

    printf("1. Calling a simple function:\n");
    greet();
    printf("\n");

    
    printf("2. Function with parameters and return value:\n");
    int num1 = 10, num2 = 20;
    int sum = add(num1, num2);
    printf("   The sum of %d and %d is %d\n\n", num1, num2, sum);

    
    printf("3. Pass by Value vs. Pass by Reference:\n");
    int a = 5, b = 10;
    printf("   Before swap: a = %d, b = %d\n", a, b);
    
    
    swap_by_value(a, b);
    printf("   After swap_by_value: a = %d, b = %d (unchanged)\n", a, b);

    
    swap_by_reference(&a, &b);
    printf("   After swap_by_reference: a = %d, b = %d (changed)\n\n", a, b);

    
    printf("4. Recursive function (Factorial):\n");
    int number = 5;
    int result = factorial(number);
    printf("   The factorial of %d is %d\n\n", number, result);

    
    printf("5. Scope and Storage Classes:\n");
    printf("   Accessing global_var from main: %d\n", global_var);
    scope_and_storage();
    scope_and_storage(); 
    printf("\n");

    return 0;
}


void greet(void) {
    printf("   Hello from the greet \n");
}

int add(int a, int b) {
    return a + b;
}

void swap_by_value(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
    printf("   Inside swap_by_value: x = %d, y = %d\n", x, y);
}

void swap_by_reference(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
    printf("   Inside swap_by_reference: x = %d, y = %d\n", *x, *y);
}

int factorial(int n) {
    
    if (n == 0) {
        return 1;
    }
    
    else {
        return n * factorial(n - 1);
    }
}

void scope_and_storage(void) {
    
    auto int local_auto_var = 10;
    local_auto_var++;
    printf("   - local_auto_var (auto): %d\n", local_auto_var);

    static int static_var = 0;
    static_var++;
    printf("   - static_var (static): %d (value persists across calls)\n", static_var);

    printf("   - Accessing global_var from function: %d\n", global_var);


    register int register_var = 20;
    printf("   - register_var: %d\n", register_var);

    extern int extern_var;
    printf("   - extern_var: %d\n", extern_var);
}