#include "malloc.h"

static void *heap_start = NULL;
static void *heap_end = NULL;

void *naive_malloc(size_t size)
{
    size_t *block;
    size_t total_size;
    size_t page_size = sysconf(_SC_PAGESIZE);
    
    /* Calculate total size needed (header + requested size) */
    total_size = sizeof(size_t) + size;
    
    /* Initialize heap if first call */
    if (heap_start == NULL) {
        heap_start = sbrk(page_size);
        if (heap_start == (void *)-1)
            return NULL;
        heap_end = heap_start + page_size;
    }
    
    /* Check if we have enough space in current page */
    if (heap_start + total_size > heap_end) {
        return NULL;
    }
    
    /* Allocate from current page */
    block = heap_start;
    *block = size;
    heap_start += total_size;
    
    /* Return pointer to the usable memory (after the header) */
    return (void *)(block + 1);
}

