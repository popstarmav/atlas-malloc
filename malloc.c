#include <unistd.h>
#include <stddef.h>
#include "malloc.h"

static void *heap_start;
static size_t total_size;

/**
 * _malloc - Allocates memory on the heap
 * @size: Number of bytes to allocate
 *
 * Return: Pointer to allocated memory, or NULL if allocation fails
 */
void *_malloc(size_t size)
{
	size_t *header;
	size_t aligned_size;
	size_t page_size;

	page_size = sysconf(_SC_PAGESIZE);
	aligned_size = (size + sizeof(size_t) + 7) & ~7;

	if (heap_start == NULL || (total_size + aligned_size > page_size))
	{
		heap_start = sbrk(page_size);
		if (heap_start == (void *)-1)
			return (NULL);
		total_size = 0;
	}

	header = (size_t *)((char *)heap_start + total_size);
	*header = size;
	total_size += aligned_size;

	return ((void *)(header + 1));
}

