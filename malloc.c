#include <unistd.h>
#include <stddef.h>
#include "malloc.h"

/**
 * _malloc - Allocates memory on the heap
 * @size: Number of bytes to allocate
 *
 * Return: Pointer to allocated memory, or NULL if allocation fails
 */
void *_malloc(size_t size)
{
	void *block;
	size_t *header;
	size_t aligned_size;

	if (size == 0)
		return (NULL);

	/* Align to 8-byte boundary */
	aligned_size = (size + sizeof(size_t) + 7) & ~7;
	block = sbrk(aligned_size);

	if (block == (void *)-1)
		return (NULL);

	header = (size_t *)block;
	*header = size;

	return ((void *)(header + 1));
}

