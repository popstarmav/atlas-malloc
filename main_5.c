#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "malloc.h"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	char *str;
	int i;

	str = _malloc(10);
	if (str == NULL)
		return (EXIT_FAILURE);

	strcpy(str, "Holberton");
	for (i = 0; i < 10; i++)
		printf("%c", str[i]);
	printf("\n");

	_free(str);
	return (EXIT_SUCCESS);
}

