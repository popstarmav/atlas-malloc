# C - MALLOC Implementation

## Overview
This project implements a custom memory allocation system in C, recreating the functionality of the standard `malloc`, `free`, `realloc`, and `calloc` functions.

## Features
- Custom implementation of memory allocation functions
- Memory management with efficient algorithms
- Handling of memory fragmentation
- Thread-safe memory operations

## Functions Implemented
- `void *malloc(size_t size)`: Allocates specified bytes of memory
- `void free(void *ptr)`: Deallocates previously allocated memory
- `void *realloc(void *ptr, size_t size)`: Resizes a memory block
- `void *calloc(size_t nmemb, size_t size)`: Allocates and initializes memory to zero

## Usage
Include the header file in your C programs:
```c
#include "malloc.h"
```

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o malloc_program
```

## Testing
To test the implementation:
```bash
./malloc_program
```

## Requirements
- GCC compiler
- Linux environment (recommended)


