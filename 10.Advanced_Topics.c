#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <errno.h>

// *** 1. Command Line Arguments ***
void command_line_arguments_example(int argc, char *argv[]);

// *** 2. Bitwise Operations ***
void bitwise_operations_example();

// *** 3. `volatile` and `const` qualifiers ***
void volatile_const_qualifiers_example();

// *** 4. Data Structures in C (Linked Lists - basic example) ***
// Node structure for a singly linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data);
Node* insertAtBeginning(Node *head, int data);
void printList(Node *head);
void freeList(Node *head);

// *** 5. Standard Library Functions ***
void standard_library_functions_example();

// *** 6. Error Handling (`errno`, `perror`, `strerror`) ***
void error_handling_example();

// *** 7. Type `defs` (already used above, but will show more examples) ***
typedef unsigned int UINT;
typedef char* StringPtr;

void typedef_example();
int add(int a, int b); // Function prototype for the add function


int main(int argc, char *argv[]) {
    printf("*** 1. Command Line Arguments ***\n");
    command_line_arguments_example(argc, argv);

    printf("\n*** 2. Bitwise Operations ***\n");
    bitwise_operations_example();

    printf("\n*** 3. `volatile` and `const` qualifiers ***\n");
    volatile_const_qualifiers_example();

    printf("\n*** 4. Data Structures in C (Linked List) ***\n");
    Node *head = NULL;
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);
    printf("Linked List: ");
    printList(head);
    freeList(head);

    printf("\n*** 5. Standard Library Functions ***\n");
    standard_library_functions_example();

    printf("\n*** 6. Error Handling ***\n");
    error_handling_example();

    printf("\n*** 7. Type `defs` ***\n");
    typedef_example();

    return 0;
}

void command_line_arguments_example(int argc, char *argv[]) {
    printf("Number of arguments: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    if (argc > 1) {
        printf("First argument (program name): %s\n", argv[0]);
        printf("Second argument (if exists): %s\n", argv[1]);
        long value = strtol(argv[1], NULL, 10);
        printf("Second argument as long: %ld\n", value);
    } else {
        printf("No additional command line arguments provided.\n");
        printf("Try running: ./a.out hello 123\n");
    }
}

void bitwise_operations_example() {
    unsigned int a = 5;  // 0101 in binary
    unsigned int b = 12; // 1100 in binary

    printf("a = %u (0x%x), b = %u (0x%x)\n", a, a, b, b);

    // Bitwise AND (&)
    printf("a & b = %u (0x%x)\n", a & b, a & b); // 0100 (4)

    // Bitwise OR (|)
    printf("a | b = %u (0x%x)\n", a | b, a | b); // 1101 (13)

    // Bitwise XOR (^)
    printf("a ^ b = %u (0x%x)\n", a ^ b, a ^ b); // 1001 (9)

    // Bitwise NOT (~)
    printf("~a = %u (0x%x) (depends on integer size)\n", ~a, ~a);

    // Left Shift (<<)
    printf("a << 1 = %u (0x%x)\n", a << 1, a << 1); // 1010 (10)

    // Right Shift (>>)
    printf("b >> 2 = %u (0x%x)\n", b >> 2, b >> 2); // 0011 (3)

    // Check if a bit is set
    unsigned int flag = 0x01; // 0001
    unsigned int status = 0x05; // 0101
    if (status & flag) {
        printf("Bit 0 is set in status.\n");
    }

    // Set a bit
    status |= (1 << 1); // Set bit 1 (0010)
    printf("Status after setting bit 1: %u (0x%x)\n", status, status); // 0111 (7)

    // Clear a bit
    status &= ~(1 << 0); // Clear bit 0 (0001)
    printf("Status after clearing bit 0: %u (0x%x)\n", status, status); // 0110 (6)
}

void volatile_const_qualifiers_example() {
    // const: The value cannot be changed after initialization.
    const int constant_value = 100;
    // constant_value = 101; // ERROR: assignment of read-only variable 'constant_value'
    printf("Const value: %d\n", constant_value);

    // volatile: Tells the compiler that a variable's value may change
    // at any time without any action being taken by the code.
    // Prevents the compiler from optimizing away reads/writes to this variable.
    // Useful for memory-mapped hardware registers, global variables modified by ISRs, etc.
    volatile int sensor_reading = 0;
    printf("Volatile sensor reading (initial): %d\n", sensor_reading);
    // In a real scenario, an external event would change sensor_reading.
    // For demonstration, we'll simulate a change.
    sensor_reading = 50;
    printf("Volatile sensor reading (updated): %d\n", sensor_reading);

    // const volatile: A value that cannot be changed by the program,
    // but might be changed by external factors (e.g., a read-only hardware register).
    const volatile int hardware_status = 1;
    printf("Const volatile hardware status: %d\n", hardware_status);
    // hardware_status = 0; // ERROR: assignment of read-only variable 'hardware_status'
}

// Linked List functions
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtBeginning(Node *head, int data) {
    Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(Node *head) {
    Node *current = head;
    Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
void standard_library_functions_example() {
    // <stdlib.h>
    printf("--- <stdlib.h> ---\n");
    int rand_num = rand(); // Generate a pseudo-random number
    printf("Random number: %d\n", rand_num);
    srand(time(NULL)); // Seed the random number generator
    rand_num = rand();
    printf("New random number after seeding: %d\n", rand_num);

    char num_str[] = "12345";
    int converted_int = atoi(num_str);
    printf("atoi(\"%s\"): %d\n", num_str, converted_int);

    char float_str[] = "3.14159";
    double converted_double = atof(float_str);
    printf("atof(\"%s\"): %f\n", float_str, converted_double);

    // <math.h>
    printf("\n--- <math.h> ---\n");
    double x = 4.0;
    printf("sqrt(%.1f): %.2f\n", x, sqrt(x));
    printf("pow(2.0, 3.0): %.2f\n", pow(2.0, 3.0));
    printf("sin(0.0): %.2f\n", sin(0.0));

    // <time.h>
    printf("\n--- <time.h> ---\n");
    time_t current_time;
    time(&current_time);
    printf("Current time (seconds since epoch): %ld\n", (long)current_time);
    printf("Current local time: %s", ctime(&current_time));
}

/**
 * error handling using `errno`, `perror`, and `strerror`.
 */
void error_handling_example() {
    FILE *fp;
    
    // Attempt to open a non-existent file for reading
    fp = fopen("non_existent_file.txt", "r");
    if (fp == NULL) {
        printf("Error opening file (manual check).\n");
        printf("errno value: %d\n", errno); // Print the error number
        perror("Error details from perror"); // Prints a descriptive error message
        printf("Error details from strerror: %s\n", strerror(errno)); // Get error string
    } else {
        printf("File opened successfully (this should not happen).\n");
        fclose(fp);
    }

    // Example with division by zero (runtime error, not caught by errno directly)
    // int a = 10, b = 0;
    // int result = a / b; // This will cause a crash or trap
    // printf("Result of division: %d\n", result);
}

void typedef_example() {
    UINT count = 100;
    printf("UINT count: %u\n", count);

    StringPtr message = "Hello from typedef!";
    printf("StringPtr message: %s\n", message);

    // typedef for function pointers
    typedef int (*Operation)(int, int);
    // Operation add_op = add;
    // For this example, we'll use the global 'add' function or define a local one if needed.
    // int local_add(int a, int b) { return a + b; } // Moved to global scope
    Operation local_add_op = add;

    printf("Typedef for function pointer: local_add_op(5, 7) = %d\n", local_add_op(5, 7));
}

int add(int a, int b) {
    return a + b;
}