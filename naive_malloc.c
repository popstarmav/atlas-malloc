#include <unistd.h>
#include <stddef.h>
#include "malloc.h"

static void *page_start = NULL;
static size_t page_size = 0;
static size_t used_space = 0;

void *naive_malloc(size_t size) {
    size_t total_size;
    size_t *header;
    void *allocated_mem;

    /* Initialize page size if not done */
    if (page_size == 0) {
        page_size = sysconf(_SC_PAGESIZE);
    }

    /* Add header size to requested size */
    total_size = sizeof(size_t) + size;

    /* Check if we need a new page */
    if (page_start == NULL || (used_space + total_size > page_size)) {
        page_start = sbrk(page_size);
        if (page_start == (void *)-1) {
            return NULL;
        }
        used_space = 0;
    }

    /* Calculate allocation address */
    allocated_mem = (char *)page_start + used_space;
    header = (size_t *)allocated_mem;
    *header = size;

    /* Update used space */
    used_space += total_size;

    /* Return address after header */
    return (void *)(header + 1);
}
