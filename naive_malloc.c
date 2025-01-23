#include <unistd.h>
#include <stddef.h>
#include "malloc.h"

void *naive_malloc(size_t size) {
    size_t *header;
    size_t page_size = sysconf(_SC_PAGESIZE);
    size_t total_size = sizeof(size_t) + size;
    
    // Round up to nearest page size
    total_size = ((total_size + page_size - 1) / page_size) * page_size;
    
    header = sbrk(total_size);
    if (header == (void *)-1) {
        return NULL;
    }
    
    // Store total size in header
    *header = total_size;
    
    // Return address after header
    return (void *)(header + 1);
}
