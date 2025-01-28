#include <unistd.h>
#include "malloc.h"

/**
 * _free - Frees allocated memory
 * @ptr: Pointer to memory to be freed
 */
void _free(void *ptr)
{
	if (ptr != NULL)
	{
		/* Move pointer back to header */
		size_t *header = ((size_t *)ptr - 1);
		brk(header);
	}
}

