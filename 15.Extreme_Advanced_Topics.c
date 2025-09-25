#define _GNU_SOURCE // Required for strsignal on some systems

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h> // For setjmp/longjmp
#include <signal.h> // For signal handling
#include <unistd.h> // For sleep (in signal handling)

// *** 1. Inline Assembly (GCC/Clang specific) ***
void inline_assembly_example();

// *** 2. Memory Management Internals (Conceptual) ***
void memory_management_internals_conceptual();

// *** 3. Compiler Design and Internals (Conceptual) ***
void compiler_design_internals_conceptual();

// *** 4.Custom Memory Allocators ***
// A very simplified custom allocator
#define HEAP_SIZE 1024
static char custom_heap[HEAP_SIZE];
static size_t heap_offset = 0;

void* custom_malloc(size_t size);
void custom_free(void* ptr);
void custom_allocator_example();

// *** 5. Metaprogramming with Macros ***
#define FOREACH_ITEM(ITEM, LIST) \
    for (size_t i = 0; i < sizeof(LIST)/sizeof(LIST[0]); ++i) { \
        ITEM = LIST[i];

#define END_FOREACH }

#define CREATE_STRUCT_AND_PRINT(name, type, value) \
    type name = value; \
    printf("Created %s of type %s with value %d\n", #name, #type, name);

void metaprogramming_macros_example();

// *** 6. Setjmp/Longjmp for Non-Local Jumps ***
jmp_buf jump_buffer; // Global buffer to store environment
void function_a();
void function_b();
void setjmp_longjmp_example();

// *** 7. Signal Handling ***
void signal_handler(int signum);
void signal_handling_example();

// *** 8. Interfacing with other languages (Conceptual) ***
void interfacing_with_other_languages_conceptual();


int main() {
    printf("*** 1. Inline Assembly ***\n");
    inline_assembly_example();

    printf("\n*** 2. Memory Management Internals (Conceptual) ***\n");
    memory_management_internals_conceptual();

    printf("\n*** 3. Compiler Design and Internals (Conceptual) ***\n");
    compiler_design_internals_conceptual();

    printf("\n*** 4. Writing Custom Memory Allocators ***\n");
    custom_allocator_example();

    printf("\n*** 5. Metaprogramming with Macros ***\n");
    metaprogramming_macros_example();

    printf("\n*** 6. Setjmp/Longjmp for Non-Local Jumps ***\n");
    setjmp_longjmp_example();

    printf("\n*** 7. Signal Handling ***\n");
    signal_handling_example();

    printf("\n*** 8. Interfacing with other languages (Conceptual) ***\n");
    interfacing_with_other_languages_conceptual();

    return 0;
}

void inline_assembly_example() {
    int a = 10, b = 20, sum;

    // Basic inline assembly syntax:
    // "assembly code" : output_operands : input_operands : clobbered_registers
    __asm__ __volatile__(
        "addl %%ebx, %%eax;" // Add ebx to eax, store in eax
        : "=a" (sum)         // Output: sum is stored in eax
        : "a" (a), "b" (b)   // Input: a is in eax, b is in ebx
        :                    // No clobbered registers (registers modified but not listed as output)
    );

    printf("Inline Assembly: %d + %d = %d\n", a, b, sum);

    // Another example: move value from one variable to another
    int val = 50;
    int result_val;
    __asm__ __volatile__(
        "movl %1, %0;" // Move value from %1 (input) to %0 (output)
        : "=r" (result_val) // Output: result_val in a general-purpose register
        : "r" (val)         // Input: val in a general-purpose register
    );
    printf("Inline Assembly: Moved %d to result_val: %d\n", val, result_val);
}


/**
 * metaprogramming techniques using C macros.
 */
void metaprogramming_macros_example() {
    printf("Metaprogramming with Macros:\n");

    int numbers[] = {1, 2, 3, 4, 5};
    int num;
    printf("FOREACH_ITEM example:\n");
    FOREACH_ITEM(num, numbers)
        printf("  Item: %d\n", num);
    END_FOREACH

    printf("CREATE_STRUCT_AND_PRINT example:\n");
    CREATE_STRUCT_AND_PRINT(myInteger, int, 42);
    CREATE_STRUCT_AND_PRINT(anotherValue, int, 99);
}


void signal_handler(int signum) {
    printf("\nSignal handler: Caught signal %d (%s)\n", signum, strsignal(signum));
    if (signum == SIGINT) {
        printf("Gracefully exiting...\n");
        exit(EXIT_SUCCESS);
    }
}

void signal_handling_example() {
    printf("Signal Handling Example:\n");
    printf("Registering signal handler for SIGINT (Ctrl+C).\n");
    
    // Register the signal handler
    if (signal(SIGINT, signal_handler) == SIG_ERR) {
        perror("signal registration failed");
        return;
    }

    printf("Press Ctrl+C to trigger the signal handler. Waiting for 5 seconds...\n");
    sleep(5);
    printf("No signal caught within 5 seconds. Exiting normally.\n");
}
