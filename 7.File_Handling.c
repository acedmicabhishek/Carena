#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float score;
} Record;

void check_file_status(FILE *fp, const char *filename);
void read_file_line_by_line(const char *filename);
void write_to_file(const char *filename);
void append_to_file(const char *filename);
void file_positioning_example(const char *filename);
void binary_io_example(const char *bin_filename);
void print_records(const char *bin_filename);

int main() {
    const char *filename = "dummyfile/meow.txt";
    const char *binary_filename = "dummyfile/records.bin";

    printf("*** 1. Reading a file line by line ***\n");
    read_file_line_by_line(filename);

    printf("\n*** 2. Writing to a file (overwrite) ***\n");
    write_to_file(filename);
    printf("--- Contents after writing ---\n");
    read_file_line_by_line(filename);

    printf("\n*** 3. Appending to a file ***\n");
    append_to_file(filename);
    printf("--- Contents after appending ---\n");
    read_file_line_by_line(filename);

    printf("\n*** 4. File Positioning (fseek, ftell, rewind) ***\n");
    file_positioning_example(filename);

    printf("\n*** 5. Binary File I/O (fwrite, fread) ***\n");
    binary_io_example(binary_filename);
    printf("--- Reading binary records ---\n");
    print_records(binary_filename);

    remove(binary_filename);

    return 0;
}

void check_file_status(FILE *fp, const char *filename) {
    if (fp == NULL) {
        perror("Error opening file");
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
}

void read_file_line_by_line(const char *filename) {
    FILE *fp = fopen(filename, "r"); // "r" for read mode
    check_file_status(fp, filename);

    char buffer[256];
    int line_num = 1;

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("Line %d: %s", line_num++, buffer);
    }

    if (ferror(fp)) {
        perror("Error reading from file");
    }

    fclose(fp);
}

void write_to_file(const char *filename) {
    FILE *fp = fopen(filename, "w");
    check_file_status(fp, filename);

    fprintf(fp, "This is a new first line.\n");
    fprintf(fp, "Written by the write_to_file function.\n");
    fputs("This line was written by fputs.\n", fp);

    fclose(fp);
    printf("Successfully wrote to %s\n", filename);
}

void append_to_file(const char *filename) {
    FILE *fp = fopen(filename, "a"); // "a" for append mode
    check_file_status(fp, filename);

    fputs("\n*** Appended Content ***\n", fp);
    fputs("This text was added to the end.\n", fp);

    fclose(fp);
    printf("Successfully appended to %s\n", filename);
}
void file_positioning_example(const char *filename) {
    FILE *fp = fopen(filename, "r");
    check_file_status(fp, filename);

    char buffer[50];

    // 1. ftell: Get current position
    long pos = ftell(fp);
    printf("Initial position: %ld\n", pos);

    // 2. fseek: Move to a specific position
    // Move 10 bytes from the beginning of the file (SEEK_SET)
    fseek(fp, 10, SEEK_SET);
    pos = ftell(fp);
    fgets(buffer, sizeof(buffer), fp);
    printf("After fseek(10, SEEK_SET), position is %ld. Read: %s", pos, buffer);

    // 3. rewind: Move the pointer back to the beginning
    rewind(fp);
    pos = ftell(fp);
    printf("After rewind(), position is %ld\n", pos);

    // 4. fseek from end
    // Move back 20 bytes from the end of the file (SEEK_END)
    fseek(fp, -20, SEEK_END);
    pos = ftell(fp);
    fgets(buffer, sizeof(buffer), fp);
    printf("After fseek(-20, SEEK_END), position is %ld. Read: %s", pos, buffer);

    fclose(fp);
}

/**
 * Writes an array of structs to a binary file.
 */
void binary_io_example(const char *bin_filename) {
    FILE *fp = fopen(bin_filename, "wb"); // "wb" for write binary
    check_file_status(fp, bin_filename);

    Record records_to_write[3] = {
        {1, "Alice", 95.5f},
        {2, "Bob", 88.0f},
        {3, "Charlie", 76.2f}
    };

    // fwrite(pointer_to_data, size_of_one_element, number_of_elements, file_pointer)
    size_t written_count = fwrite(records_to_write, sizeof(Record), 3, fp);

    if (written_count != 3) {
        fprintf(stderr, "Error writing to binary file.\n");
    } else {
        printf("Successfully wrote %zu records to %s\n", written_count, bin_filename);
    }

    fclose(fp);
}

/**
 * Reads an array of structs from a binary file.
 */
void print_records(const char *bin_filename) {
    FILE *fp = fopen(bin_filename, "rb"); // "rb" for read binary
    check_file_status(fp, bin_filename);

    Record record_buffer;

    // fread(pointer_to_buffer, size_of_one_element, number_of_elements, file_pointer)
    while (fread(&record_buffer, sizeof(Record), 1, fp) == 1) {
        printf("ID: %d, Name: %s, Score: %.2f\n",
               record_buffer.id, record_buffer.name, record_buffer.score);
    }

    fclose(fp);
}