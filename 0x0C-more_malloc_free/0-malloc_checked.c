#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * malloc_checked - function that allocates memory using malloc()
 * @b: size that is to be allocated
 * Return: pointer to the allocated memory, otherwise to exit with 98
 */

void *malloc_checked(unsigned int b)
{
	void *p;

	a = malloc(b);
	if (p == NULL)
	{
		exit(98);
	}
	return (p);
}
