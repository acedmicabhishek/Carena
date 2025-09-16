#include <stdio.h>

#define PI 3.14
#define MESSAGE "Your mom"

int main() {

    int integerVar = 10;
    char characterVar = 'A';
    float floatVar = 3.14f; 
    double doubleVar = 9.81;
    const int MAX_VALUE = 100;

    printf("--- Variables and Constants ---\n");
    printf("Integer Variable: %d\n", integerVar);
    printf("Character Variable: %c\n", characterVar);
    printf("Float Variable: %f\n", floatVar);
    printf("Double Variable: %lf\n", doubleVar);
    printf("Constant (const): %d\n", MAX_VALUE);
    printf("Constant (#define PI): %f\n", PI);
    printf("Constant (#define MESSAGE): %s\n\n", MESSAGE);

    // Example of taking input
    // int userInput;
    // printf("Enter an integer: ");
    // scanf("%d", &userInput);
    // printf("You entered: %d\n\n", userInput);


    // Operators
    int a = 15, b = 4;

    // Arithmetic Operators
    printf("Arithmetic Operators:\n");
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d (integer division)\n", a / b);
    printf("a %% b = %d (modulo)\n", a % b);

    // Relational Operators
    printf("\nRelational Operators:\n");
    printf("a > b is %d (true)\n", a > b);
    printf("a < b is %d (false)\n", a < b);
    printf("a == 15 is %d (true)\n", a == 15);

    // Logical Operators
    printf("\nLogical Operators:\n");
    printf("(a > 10 && b < 5) is %d (true)\n", (a > 10 && b < 5));
    printf("(a > 20 || b < 5) is %d (true)\n", (a > 20 || b < 5));

    // Bitwise Operators
    printf("\nBitwise Operators:\n");
    printf("a & b = %d\n", a & b); // Bitwise AND
    printf("a | b = %d\n", a | b); // Bitwise OR
    printf("a ^ b = %d\n", a ^ b); // Bitwise XOR
    printf("~a = %d\n", ~a);      // Bitwise NOT
    printf("b << 1 = %d\n", b << 1); // Left shift
    printf("b >> 1 = %d\n", b >> 1); // Right shift

    // Assignment Operators
    int c = 10;
    c += 5; // Equivalent to c = c + 5;
    printf("\nAssignment Operator: c += 5 gives c = %d\n", c);


    // Type Casting
    printf("\n--- Type Casting ---\n");
    int num1 = 17, num2 = 5;
    float result;

    // Implicit type casting (int is promoted to float)
    result = num1 / 5.0;
    printf("Implicit cast (17 / 5.0): %f\n", result);

    // Explicit type casting
    result = (float)num1 / num2;
    printf("Explicit cast ((float)17 / 5): %f\n", result);

    return 0;
}