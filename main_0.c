#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "malloc.h"

#define ALLOC_SIZE 2048

int main(void)
{
    void *ptr;
    void *heap_start;

    heap_start = sbrk(0);
    printf("Heap start: %p\n", heap_start);

    ptr = _malloc(ALLOC_SIZE);
    printf("First allocated memory: %p\n", ptr);

    return (EXIT_SUCCESS);
}

