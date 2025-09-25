#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void endianness_example();

int main() {
    printf("*** Endianness (Big vs. Little) ***\n");
    endianness_example();

    return 0;
}
void endianness_example() {
    unsigned int i = 0x01234567; // A 4-byte integer
    unsigned char *c = (unsigned char*)&i; // Pointer to the first byte of 'i'

    printf("Value of integer i: 0x%X\n", i);
    printf("Address of i: %p\n", (void*)&i);
    printf("Bytes in memory (from lowest address):\n");
    printf("Byte 0: 0x%X (at %p)\n", c[0], (void*)&c[0]);
    printf("Byte 1: 0x%X (at %p)\n", c[1], (void*)&c[1]);
    printf("Byte 2: 0x%X (at %p)\n", c[2], (void*)&c[2]);
    printf("Byte 3: 0x%X (at %p)\n", c[3], (void*)&c[3]);

    if (c[0] == 0x67) {
        printf("System is Little-Endian.\n");
    } else if (c[0] == 0x01) {
        printf("System is Big-Endian.\n");
    } else {
        printf("Unknown endianness.\n");
    }

    union {
        uint32_t integer;
        uint8_t bytes[4];
    } endian_check;

    endian_check.integer = 0x01020304; // Assign a known value

    printf("\nChecking endianness with a union:\n");
    if (endian_check.bytes[0] == 0x04) {
        printf("Union check: Little-Endian (bytes[0] is LSB)\n");
    } else if (endian_check.bytes[0] == 0x01) {
        printf("Union check: Big-Endian (bytes[0] is MSB)\n");
    } else {
        printf("Union check: Unknown endianness.\n");
    }
}