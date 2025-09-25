#include <stdio.h>
#include <stdlib.h>

// *** 1. Simple Macros ***
#define MAX_VALUE 100
#define PI 3.14

// *** 2. Macro Functions (Parameterized Macros) ***
// Use parentheses around parameters and the entire expression to avoid side effects.
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// *** 3. Stringification (#) ***
// Converts a macro argument into a string literal.
#define TO_STRING(x) #x

// *** 4. Token Pasting (##) ***
// Concatenates two tokens into a single token.
#define CONCAT(a, b) a##b

// *** 5. Conditional Compilation ***
#define DEBUG_MODE
// #define RELEASE_MODE

#ifdef DEBUG_MODE
    #define LOG_MESSAGE(msg) printf("[DEBUG] %s:%d - %s\n", __FILE__, __LINE__, msg)
#else
    #define LOG_MESSAGE(msg) // Do nothing in release mode
#endif

// Nested conditional compilation
#define FEATURE_A
// #define FEATURE_B

#ifdef FEATURE_A
    #define FEATURE_A_ENABLED 1
    #ifdef FEATURE_B
        #define COMBO_FEATURE_ENABLED 1
    #else
        #define COMBO_FEATURE_ENABLED 0
    #endif
#else
    #define FEATURE_A_ENABLED 0
    #define COMBO_FEATURE_ENABLED 0
#endif

// #if, #elif, #else, #endif
#define OS_LINUX 1
#define OS_WINDOWS 2
#define OS_MACOS 3

#define CURRENT_OS OS_LINUX

#if CURRENT_OS == OS_LINUX
    #define OS_NAME "Linux"
#elif CURRENT_OS == OS_WINDOWS
    #define OS_NAME "Windows"
#elif CURRENT_OS == OS_MACOS
    #define OS_NAME "macOS"
#else
    #define OS_NAME "Unknown OS"
#endif

// *** 6. #undef ***
// Undefines a previously defined macro.
#define TEMP_MACRO "I am temporary"
#undef TEMP_MACRO

// *** 7. Predefined Macros ***
// __FILE__, __LINE__, __DATE__, __TIME__, __STDC__ (C standard compliance)
// __func__ (C99) - not strictly a preprocessor macro, but related.

// *** 8. #error and #warning ***
// #error "This is a fatal error message during compilation!"
// #warning "This is a warning message during compilation!"

// *** 9. #pragma ***
// Compiler-specific directives. Example for GCC/Clang to suppress warnings.
// #pragma GCC warning "This is a pragma warning!"
// #pragma message "This is a pragma message!"

// Function Prototypes
void macro_examples();
void conditional_compilation_examples();
void predefined_macros_example();

int main() {
    printf("*** 1. Macro Examples ***\n");
    macro_examples();

    printf("\n*** 2. Conditional Compilation Examples ***\n");
    conditional_compilation_examples();

    printf("\n*** 3. Predefined Macros Example ***\n");
    predefined_macros_example();

    // Example of #undef
    // printf("TEMP_MACRO: %s\n", TEMP_MACRO); // This would cause a compilation error

    return 0;
}

void macro_examples() {
    printf("MAX_VALUE: %d\n", MAX_VALUE);
    printf("PI: %f\n", PI);

    int a = 5, b = 10;
    printf("SQUARE(%d): %d\n", a, SQUARE(a));
    printf("MAX(%d, %d): %d\n", a, b, MAX(a, b));

    // Macro with side effect warning
    int x = 3;
    printf("SQUARE(x++): %d (Expected 9, might be 12 due to x*x with x incrementing twice)\n", SQUARE(x++));
    printf("x after SQUARE(x++): %d\n", x); // x is now 5

    printf("Stringification of MAX_VALUE: %s\n", TO_STRING(MAX_VALUE));
    printf("Stringification of SQUARE(5): %s\n", TO_STRING(SQUARE(5)));

    int CONCAT(var, Name) = 25; // Creates a variable named varName
    printf("Token pasting (varName): %d\n", varName);
}


void conditional_compilation_examples() {
    LOG_MESSAGE("This is a log message.");

    printf("Feature A Enabled: %d\n", FEATURE_A_ENABLED);
    printf("Combo Feature Enabled: %d\n", COMBO_FEATURE_ENABLED);

    printf("Current Operating System: %s\n", OS_NAME);

    #ifndef UNDEFINED_MACRO
        printf("UNDEFINED_MACRO is not defined.\n");
    #endif
}

void predefined_macros_example() {
    printf("This file: %s\n", __FILE__);
    printf("Current line: %d\n", __LINE__);
    printf("Compilation date: %s\n", __DATE__);
    printf("Compilation time: %s\n", __TIME__);

    #ifdef __STDC__
        printf("This compiler conforms to the C standard.\n");
    #else
        printf("This compiler does NOT conform to the C standard.\n");
    #endif

    // __func__ is a C99 feature, not strictly a preprocessor macro
    printf("Current function: %s\n", __func__);
}