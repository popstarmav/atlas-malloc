#include "malloc.h"

void *naive_malloc(size_t size)
{
    size_t *block;
    size_t total_size;
    size_t page_size = sysconf(_SC_PAGESIZE);
    
    /* Calculate total size needed (header + requested size) */
    total_size = sizeof(size_t) + size;
    
    /* Round up to nearest page size */
    if (total_size % page_size != 0)
        total_size = ((total_size / page_size) + 1) * page_size;
    
    /* Request memory from the system */
    block = sbrk(total_size);
    if (block == (void *)-1)
        return NULL;
    
    /* Store the size in the header */
    *block = size;
    
    /* Return pointer to the usable memory (after the header) */
    return (void *)(block + 1);
}

