#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>


void print_1d_array(int arr[], int size);
void print_2d_array(int rows, int cols, int arr[rows][cols]);
void pointer_to_array_example();
void array_of_pointers_example();
void dynamic_array_example();
void string_literal_vs_char_array();
void advanced_string_functions();
void string_tokenization();
void wide_character_strings();
void variable_length_array_example();
void array_of_function_pointers_example();
void print_multi_array_v1(int arr[][4], int rows);
void print_multi_array_v2(int (*arr)[4], int rows);
void print_multi_array_v3(int rows, int cols, int arr[rows][cols]);


int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);


int main() {
    printf("*** 1D Arrays ***\n");
    int arr[5] = {1, 2, 3, 4, 5};
    print_1d_array(arr, 5);

    printf("\n*** 2D Arrays (Matrices) ***\n");
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    print_2d_array(3, 4, matrix);

    printf("\n*** Pointer to an Array ***\n");
    pointer_to_array_example();

    printf("\n*** Array of Pointers ***\n");
    array_of_pointers_example();

    printf("\n*** Dynamic Arrays (Using Malloc) ***\n");
    dynamic_array_example();

    printf("\n*** String Literals vs Character Arrays ***\n");
    string_literal_vs_char_array();

    printf("\n*** Advanced String Functions ***\n");
    advanced_string_functions();

    printf("\n*** String Tokenization (strtok) ***\n");
    string_tokenization();
    
    printf("\n*** Wide Character Strings (wchar_t) ***\n");
    wide_character_strings();

    printf("\n*** Variable Length Arrays (VLAs) ***\n");
    variable_length_array_example();

    printf("\n*** Passing Multidimensional Arrays ***\n");
    int multi_arr[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    print_multi_array_v1(multi_arr, 3);
    print_multi_array_v2(multi_arr, 3);
    print_multi_array_v3(3, 4, multi_arr);

    printf("\n*** Array of Function Pointers ***\n");
    array_of_function_pointers_example();

    return 0;
}


void print_1d_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print_2d_array(int rows, int cols, int arr[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%-4d", arr[i][j]);
        }
        printf("\n");
    }
}

void pointer_to_array_example() {
    int arr[5] = {10, 20, 30, 40, 50};
    int (*ptr_to_arr)[5]; // ptr_to_arr is a pointer to an array of 5 integers
    ptr_to_arr = &arr;

    printf("Address of array: %p\n", (void*)arr);
    printf("Pointer to array points to: %p\n", (void*)ptr_to_arr);
    printf("Dereferencing pointer to array: (*ptr_to_arr)[0] = %d\n", (*ptr_to_arr)[0]);
    printf("Dereferencing pointer to array: (*ptr_to_arr)[2] = %d\n", (*ptr_to_arr)[2]);
}


void array_of_pointers_example() {
    const char *names[] = {"oppa", "suki", "karl"};
    printf("Names:\n");
    for (int i = 0; i < 3; i++) {
        printf("- %s\n", names[i]);
    }
}

void dynamic_array_example() {
    int n;
    printf("Enter the size of the dynamic array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }


    int *dyn_arr = (int*) malloc(n * sizeof(int));
    if (dyn_arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &dyn_arr[i]) != 1) {
            printf("Invalid input during array population.\n");
            free(dyn_arr);
            while (getchar() != '\n');
            return;
        }
    }

    printf("Dynamic array elements: ");
    print_1d_array(dyn_arr, n);

    free(dyn_arr);
}

void string_literal_vs_char_array() {
    const char *str_literal = "Hello"; // Stored in read-only memory, should be const
    char char_array[] = "MOM"; // Stored on the stack, mutable

    printf("String literal: %s\n", str_literal);
    printf("Character array: %s\n", char_array);

    // Modifying a character array is fine
    char_array[0] = 'w';
    printf("Modified char array: %s\n", char_array);

    // Attempting to modify a string literal results in undefined behavior (often a crash)
    // str_literal[0] = 'h'; // Uncommenting this line will likely cause a segmentation fault
}


void advanced_string_functions() {
    char str1[50] = "The quick brown fox";
    const char *str2 = "brown";
    char *result;

    // strstr: find a substring
    result = strstr(str1, str2);
    if (result) {
        printf("'%s' found in '%s' at position: %td\n", str2, str1, result - str1);
    } else {
        printf("'%s' not found in '%s'\n", str2, str1);
    }

    // strchr: find first occurrence of a character
    result = strchr(str1, 'q');
    if (result) {
        printf("'q' found in '%s' at position: %td\n", str1, result - str1);
    }

    // strrchr: find last occurrence of a character
    char str3[] = "hello world, hello";
    result = strrchr(str3, 'o');
    if (result) {
        printf("Last 'o' in '%s' is at position: %td\n", str3, result - str3);
    }
    
    // strspn: get length of prefix substring
    const char *charset = "The ";
    size_t len = strspn(str1, charset);
    printf("Length of initial segment of '%s' containing only chars from '%s' is %zu\n", str1, charset, len);

    // strcspn: get length of prefix substring not containing certain characters
    const char *reject = "qr";
    len = strcspn(str1, reject);
    printf("Length of initial segment of '%s' not containing any chars from '%s' is %zu\n", str1, reject, len);
}

void string_tokenization() {
    char sentence[] = "This is a sample sentence.";
    char *token;
    const char *delimiter = " ";

    printf("Original sentence: '%s'\n", sentence);
    printf("Tokens:\n");

    token = strtok(sentence, delimiter);
    while (token != NULL) {
        printf("- %s\n", token);
        token = strtok(NULL, delimiter);
    }
}

void wide_character_strings() {
    // Set locale to user's default to handle multi-byte characters correctly
    if (setlocale(LC_ALL, "") == NULL) {
        printf("Could not set locale.\n");
        return;
    }

    wchar_t wstr[] = L"Hello, duck"; // L prefix for wide string literal
    
    printf("Printing wide string using wprintf:\n");
    // Use %ls to print a wide character string with wprintf
    wprintf(L"%ls\n", wstr);
}

/**
 * Variable Length Arrays (VLAs), a C99 feature.
 * The size of a VLA is determined at runtime.
 */
void variable_length_array_example() {
    int rows, cols;
    printf("\nEnter the dimensions for a VLA (rows cols): ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        printf("Invalid dimensions.\n");
        while(getchar() != '\n');
        return;
    }

    int vla[rows][cols]; // Declare a VLA

    printf("Enter the elements for the %d x %d VLA:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &vla[i][j]) != 1) {
                printf("Invalid input.\n");
                while(getchar() != '\n');
                return;
            }
        }
    }

    printf("The VLA contents:\n");
    print_2d_array(rows, cols, vla);
}

// *** Examples for passing multidimensional arrays ***

// Method 1: Specifying column size (most common for fixed-size arrays)
void print_multi_array_v1(int arr[][4], int rows) {
    printf("Printing multi-array (method 1):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%-4d", arr[i][j]);
        }
        printf("\n");
    }
}

// Method 2: Using a pointer to an array
void print_multi_array_v2(int (*arr)[4], int rows) {
     printf("Printing multi-array (method 2):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%-4d", arr[i][j]);
        }
        printf("\n");
    }
}

// Method 3: Using VLAs in function parameters (C99+)
void print_multi_array_v3(int rows, int cols, int arr[rows][cols]) {
    printf("Printing multi-array (method 3 - VLA):\n");
    print_2d_array(rows, cols, arr);
}


/**
 * array of function pointers.
 * Useful for creating dispatch tables or state machines.
 */
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

void array_of_function_pointers_example() {
    // An array of 3 pointers to functions that take (int, int) and return int
    int (*operations[3])(int, int) = {add, subtract, multiply};
    
    int a = 10, b = 5;
    
    printf("Dispatch table using array of function pointers:\n");
    printf("Addition: %d\n", operations[0](a, b));
    printf("Subtraction: %d\n", operations[1](a, b));
    printf("Multiplication: %d\n", operations[2](a, b));
}