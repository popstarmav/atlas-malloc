#include <unistd.h>
#include <stddef.h>
#include "malloc.h"

static void *page_start = NULL
static size_t page_size = 0
static size_t used_space = 0

/**
 * naive_malloc - Allocates memory of requested size
 * @size: Number of bytes to allocate
 *
 * Return: Pointer to allocated memory, or NULL if allocation fails
 */
void *naive_malloc(size_t size)
{
	size_t *header;
	size_t aligned_size;

	/* Initialize page size */
	if (page_size == 0)
	{
		page_size = sysconf(_SC_PAGESIZE);
	}

	/* Align the size to 8 bytes (64-bit alignment) */
	aligned_size = (size + sizeof(size_t) + 7) & ~7;

	/* First allocation or need new page */
	if (page_start == NULL || (used_space + aligned_size > page_size))
	{
		page_start = sbrk(page_size);
		if (page_start == (void *)-1)
		{
			return (NULL);
		}

		used_space = 0;
	}

	/* Set up header and allocation */
	header = (size_t *)((char *)page_start + used_space);
	*header = size;
	used_space += aligned_size;

	return ((void *)(header + 1));
}

