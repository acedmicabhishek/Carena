# C Programming Practice Repository

My arena for C stuff


### Compiling and Running Code

Use the `make run <number>` command, where `<number>` is the topic number you want to run.

For example, to compile and run `1.C_Language_Basics.c`, use the following command:
```bash
make run 1
```

**To compile all files:**
```bash
make all
```

**To clean up all compiled executables:**
```bash
make clean
```

---

# C Programming Topics: From Beginner to Advanced

## 1. C Language Basics
- [ ] Variables and Data Types (int, char, float, double)
- [ ] Constants (const, #define)
- [ ] Keywords and Identifiers
- [ ] Input/Output (printf, scanf)
- [ ] Operators (Arithmetic, Relational, Logical, Bitwise, Assignment)
- [ ] Type Casting

## 2. Control Flow
- [ ] `if`, `if-else`, `nested if-else`
- [ ] `switch` statement
- [ ] `for` loop
- [ ] `while` loop
- [ ] `do-while` loop
- [ ] `break` and `continue`
- [ ] `goto` statement (and why to avoid it)

## 3. Functions
- [ ] Function Declaration, Definition, and Call
- [ ] Function Parameters and Arguments
- [ ] Return Values
- [ ] Recursion
- [ ] Scope of Variables (Local, Global, Static)
- [ ] Storage Classes (auto, extern, static, register)

## 4. Arrays and Strings
- [ ] One-Dimensional Arrays
- [ ] Multi-Dimensional Arrays
- [ ] Passing Arrays to Functions
- [ ] Strings (as character arrays)
- [ ] String Manipulation Functions (`<string.h>`)

## 5. Pointers
- [ ] Introduction to Pointers (Address and Dereference Operators)
- [ ] Pointer Declaration and Initialization
- [ ] Pointers and Arrays
- [ ] Pointer Arithmetic
- [ ] Pointers and Functions (Call by Value vs. Call by Reference)
- [ ] Array of Pointers
- [ ] Pointer to a Pointer (Double Pointer)
- [ ] Pointers and Strings
- [ ] Function Pointers

## 6. Structures and Unions
- [ ] `struct`: Defining and Using Structures
- [ ] Array of Structures
- [ ] Pointers to Structures
- [ ] Nested Structures
- [ ] `union`: Defining and Using Unions
- [ ] Difference between Structures and Unions
- [ ] Bit-fields in Structures

## 7. File Handling
- [ ] Opening and Closing Files (`fopen`, `fclose`)
- [ ] Reading from and Writing to Files (`fgetc`, `fputc`, `fgets`, `fputs`, `fprintf`, `fscanf`)
- [ ] Binary File I/O (`fread`, `fwrite`)
- [ ] File Positioning (`fseek`, `ftell`, `rewind`)
- [ ] Error Handling (`ferror`, `feof`)

## 8. Dynamic Memory Allocation
- [ ] `malloc`, `calloc`, `realloc`, `free`
- [ ] Memory Leaks
- [ ] Dangling Pointers

## 9. Preprocessor Directives
- [ ] `#include`
- [ ] `#define` (Macros)
- [ ] `#undef`
- [ ] Conditional Compilation (`#ifdef`, `#ifndef`, `#if`, `#else`, `#elif`, `#endif`)
- [ ] `#error`, `#pragma`

## 10. Advanced Topics
- [ ] Command Line Arguments
- [ ] Bitwise Operations
- [ ] `volatile` and `const` qualifiers
- [ ] Data Structures in C (Linked Lists, Stacks, Queues, Trees, Graphs)
- [ ] Standard Library Functions (`<stdlib.h>`, `<math.h>`, `<time.h>`, etc.)
- [ ] Error Handling (`errno`, `perror`, `strerror`)
- [ ] Type `defs`

## 11. C Standards and Portability
- [ ] ANSI C, C89, C99, C11, C18
- [ ] Writing Portable Code
- [ ] Endianness (Big vs. Little)

## 12. Concurrency and Multithreading
- [ ] Introduction to Threads
- [ ] POSIX Threads (pthreads)
- [ ] Thread Creation and Management
- [ ] Mutexes and Semaphores
- [ ] Atomics (`<stdatomic.h>`)

## 13. Networking
- [ ] Socket Programming (TCP/IP)
- [ ] Creating a Simple Client/Server

## 14. Inter-Process Communication (IPC)
- [ ] Pipes
- [ ] Shared Memory
- [ ] Message Queues

## 15. Extreme Advanced Topics
- [ ] Inline Assembly
- [ ] Memory Management Internals
- [ ] Compiler Design and Internals
- [ ] Writing Custom Memory Allocators
- [ ] Metaprogramming with Macros
- [ ] Setjmp/Longjmp for Non-Local Jumps
- [ ] Signal Handling
- [ ] Interfacing with other languages (e.g., Python, Assembly)