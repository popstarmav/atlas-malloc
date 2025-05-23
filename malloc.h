#ifndef MALLOC_H
#define MALLOC_H

#include <stddef.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>

void *naive_malloc(size_t size);
void *_malloc(size_t size);
void _free(void *ptr);

#endif
