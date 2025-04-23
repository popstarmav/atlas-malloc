# C - MALLOC

## Overview

This repository contains a custom implementation of the `malloc` and `free` functions in C. The project aims to understand memory allocation at a deeper level by recreating these fundamental memory management functions.

## Description

The standard library functions `malloc` and `free` are essential for dynamic memory allocation in C. This project provides a custom implementation of these functions to demonstrate the underlying mechanisms of memory management.

- **malloc**: Allocates a specified number of bytes and returns a pointer to the allocated memory
- **free**: Deallocates memory previously allocated by malloc

## Files in the Repository

| File | Description |
|------|-------------|
| `malloc.c` | Main implementation of the malloc function |
| `free.c` | Implementation of the free function |
| `malloc.h` | Header file with function prototypes and necessary structures |
| `naive_malloc.c` | A simpler implementation of malloc for educational purposes |
| `main_0.c`, `main_1.c`, `main_5.c` | Test files to demonstrate the functionality |
| `libmalloc.a` | Static library containing the compiled malloc and free functions |

## Features

- Memory allocation with proper alignment
- Efficient memory reuse
- Memory block tracking
- Handling of edge cases (NULL pointers, zero-size allocations)
- Prevention of memory leaks

## Implementation Details

Our malloc implementation uses the following approach:

1. Uses the `sbrk` system call to request memory from the operating system
2. Maintains a linked list of free memory blocks
3. Implements a first-fit algorithm to find suitable memory blocks
4. Splits blocks when allocating to minimize waste
5. Coalesces adjacent free blocks when memory is freed

## Compilation

To compile the library:

```bash
gcc -Wall -Werror -Wextra -pedantic -c *.c
ar -rc libmalloc.a *.o
ranlib libmalloc.a

Execute

To compile with a test file:

gcc -Wall -Werror -Wextra -pedantic main_0.c libmalloc.a -o malloc_test

Execute

Usage
After compilation, you can run the test programs:

./malloc_test

Execute

To use the custom malloc in your own programs:

#include "malloc.h"

int main(void)
{
    char *str;
    
    str = malloc(10);
    strcpy(str, "Hello");
    printf("%s\n", str);
    free(str);
    
    return (0);
}



Differences from Standard Malloc
This implementation is primarily for educational purposes
It may not be as optimized as the standard library implementation
It focuses on clarity of code over maximum performance
It may have limitations with thread safety and very large allocations
Learning Objectives
Understanding how memory allocation works
Learning about memory management algorithms
Gaining insight into system calls and the heap
Implementing efficient data structures for memory tracking
Requirements
All files are compiled on Ubuntu 20.04 LTS using gcc with the options -Wall -Werror -Wextra -pedantic
Code follows the Betty style
No global variables are used
No more than 5 functions per file
