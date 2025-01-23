#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "malloc.h"

int main(void)
{
    char *str;
    void *curr_brk;
    int i;

    for (i = 0; i < 10; i++) {
        str = naive_malloc(10);
        strcpy(str, "Holberton");
        printf("0x%08lx -> [%s]\n", (unsigned long)((char *)str - (char *)sbrk(0)), str);
        curr_brk = sbrk(0);
        printf("Current break is 0x%lx\n", (unsigned long)curr_brk);
    }

    return (EXIT_SUCCESS);
}

