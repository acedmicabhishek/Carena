#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;
};

typedef struct {
    char title[100];
    char author[100];
    int year;
} Book;

typedef struct {
    char name[50];
    struct Point center; // A struct can contain another struct
    int radius;
} Circle;

// *** Structure with Flexible Array Member (C99+) ***
typedef struct {
    int length;
    char data[]; // Flexible array member
} String;

// *** Union Definition ***
// A union stores different data types in the same memory location.
// The size of the union is the size of its largest member.
typedef union {
    int i;
    float f;
    char c;
} Data;

// *** Bit-Fields ***
// Bit-fields allow specifying the number of bits for each member.
// Useful for memory-sensitive applications or hardware registers.
typedef struct {
    unsigned int isActive : 1;  // 1 bit
    unsigned int hasError : 1;  // 1 bit
    unsigned int level    : 4;  // 4 bits (0-15)
    unsigned int reserved : 2;  // 2 bits (padding/unused)
} Status;


void print_book(Book b);
void update_book_year(Book *b_ptr, int new_year);
void flexible_array_member_example();
void union_example();
void bit_field_example();

int main() {
    printf("*** Basic Structure and Typedef ***\n");
    Book book1;
    strcpy(book1.title, "The C Programming Language");
    strcpy(book1.author, "Kernighan & Ritchie");
    book1.year = 1978;
    print_book(book1);

    printf("\n*** Pointers to Structures ***\n");
    printf("Original year: %d\n", book1.year);
    update_book_year(&book1, 1988); // Pass by reference (pointer)
    printf("Updated year: %d\n", book1.year);

    printf("\n*** Nested Structures ***\n");
    Circle c1 = {"MyCircle", {10, 20}, 5};
    printf("Circle '%s' is at (%d, %d) with radius %d\n",
           c1.name, c1.center.x, c1.center.y, c1.radius);

    printf("\n*** Flexible Array Member ***\n");
    flexible_array_member_example();

    printf("\n*** Unions ***\n");
    union_example();

    printf("\n*** Bit-Fields ***\n");
    bit_field_example();

    return 0;
}

void print_book(Book b) {
    printf("Title: %s\nAuthor: %s\nYear: %d\n", b.title, b.author, b.year);
}

/**
 * Updates a book's year using a pointer to the struct (passed by reference).
 * This is more efficient as it avoids copying the entire struct.
 */
void update_book_year(Book *b_ptr, int new_year) {
    // The '->' operator is used to access members via a structure pointer.
    // It's equivalent to (*b_ptr).year
    b_ptr->year = new_year;
}

void flexible_array_member_example() {
    char *source_str = "Hello Flexible Array!";
    size_t str_len = strlen(source_str);

    // Allocate memory for the struct AND the flexible array data.
    String *my_string = malloc(sizeof(String) + (str_len + 1) * sizeof(char));
    if (!my_string) {
        printf("Memory allocation failed!\n");
        return;
    }

    my_string->length = str_len;
    strcpy(my_string->data, source_str); // Copy data into the flexible member

    printf("String length: %d\n", my_string->length);
    printf("String data: %s\n", my_string->data);

    free(my_string);
}

/**
 * the behavior of a union.
 */
void union_example() {
    Data data;
    printf("Size of Data union: %zu bytes\n", sizeof(Data));

    data.i = 97;
    printf("As integer: %d\n", data.i);
    printf("As float:   %f (garbage value)\n", data.f);
    printf("As char:    '%c'\n", data.c); // 'a' has ASCII value 97

    printf("\n");

    data.f = 3.14;
    printf("As integer: %d (garbage value)\n", data.i);
    printf("As float:   %f\n", data.f);
    printf("As char:    '%c' (garbage value)\n", data.c);
}

/**
 * @brief Demonstrates the use of bit-fields to pack data.
 */
void bit_field_example() {
    // The size of this struct is often just 4 bytes (one int)
    // because the bits are packed together.
    printf("Size of Status struct: %zu bytes\n", sizeof(Status));

    Status s;
    s.isActive = 1;    // Set active flag
    s.hasError = 0;    // Clear error flag
    s.level = 10;      // Set level to 10 (binary 1010)
    s.reserved = 0;

    printf("Status: Active=%u, Error=%u, Level=%u\n",
           s.isActive, s.hasError, s.level);

    if (s.isActive) {
        printf("System is active.\n");
    }

    // If we try to assign a value larger than the bit-field can hold,
    // it will be truncated.
    s.level = 20; // 20 is 10100 in binary. The 4 bits can only hold 0100 (4).
    printf("After setting level to 20, it becomes: %u\n", s.level);
}