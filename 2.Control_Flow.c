#include <stdio.h>
#include <setjmp.h>

void nested_loops();
void switch_statement();
void goto_statement();
void setjmp_longjmp();
double safe_divide(int a, int b);
void ternary_operator();

int main() {
    printf("***Demonstrating Control Flow in C ***\n\n");

    nested_loops();
    switch_statement();
    goto_statement();
    setjmp_longjmp();
    ternary_operator();

    printf("\n***End of Demonstration***\n");
    return 0;
}

void nested_loops() {
    printf("***Nested Loops***\n");
    printf("Printing a 3x3 matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("(%d, %d) ", i, j);
        }
        printf("\n");
    }
    printf("\n");
}

void switch_statement() {
    printf("*** Switch Statement ***\n");
    char grade = 'B';
    printf("Grade: %c\n", grade);
    printf("Evaluation: ");
    switch (grade) {
        case 'A':
            printf("Excellent! ");
            // fallthrough
        case 'B':
            printf("Good job! ");
            // fallthrough
        case 'C':
            printf("You passed. ");
            break;
        case 'D':
            printf("Needs improvement. ");
            // fallthrough
        case 'F':
            printf("You fucked up ");
            break;
        default:
            printf("Invalid grade. ");
    }
    printf("\n\n");
}

void goto_statement() {
    printf("*** Goto Statement ***\n");
    int i = 0;
    
loop_start:
    if (i >= 5) {
        goto loop_end;
    }
    printf("i = %d\n", i);
    i++;
    goto loop_start;

loop_end:
    printf("Loop finished with goto.\n\n");
}

static jmp_buf jump_buffer;

double safe_divide(int a, int b) {
    if (b == 0) {
        longjmp(jump_buffer, 1);
    }
    return (double)a / b;
}

void setjmp_longjmp() {
    printf("*** setjmp/longjmp for Emulating Exception Handling ***\n");
    if (setjmp(jump_buffer) == 0) {
        printf("Attempting to divide 10 by 2...\n");
        double result1 = safe_divide(10, 2);
        printf("Result: %.2f\n", result1);

        printf("\nAttempting to divide 10 by 0...\n");
        double result2 = safe_divide(10, 0);
        printf("This line will not be printed: %.2f\n", result2);
    } else {
        printf("Caught an exception: Division by zero!\n");
    }
    printf("\n");
}

void ternary_operator() {
    printf("*** Ternary Operator ***\n");
    int a = 10;
    int b = 20;
    
    int max = (a > b) ? a : b;
    printf("Between %d and %d, the maximum is %d.\n", a, b, max);
    
    char* result_string = (max % 2 == 0) ? "Even" : "Odd";
    printf("The maximum value (%d) is %s.\n", max, result_string);
}