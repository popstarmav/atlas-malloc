#include <unistd.h>
#include <stddef.h>
#include "malloc.h"

typedef struct block_meta {
    size_t size;
    struct block_meta *next;
    int free;
} block_meta;

static block_meta *head = NULL;

void *_malloc(size_t size)
{
    block_meta *current = head;
    block_meta *block;
    size_t total_size;

    total_size = ((size + sizeof(block_meta) + 7) & ~7);

    /* Check existing freed blocks */
    while (current) {
        if (current->free && current->size >= total_size) {
            current->free = 0;
            return ((void*)(current + 1));
        }
        current = current->next;
    }

    /* No suitable freed block found, allocate new */
    block = sbrk(total_size);
    if (block == (void*)-1)
        return (NULL);

    block->size = total_size;
    block->free = 0;
    block->next = head;
    head = block;

    return ((void*)(block + 1));
}

