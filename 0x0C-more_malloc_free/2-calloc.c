#include <stdlib.h>
#include "main.h"

/**
 * _calloc - a function that allocates memory of an array using malloc
 * @nmemb: number of elements in the array
 * @size: size of the elements in the array
 * Return: NULL if malloc fails
 * otherwise return pointer to memory allocated
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *p;
	unsigned int i;

	if (nmemb == 0; || size == 0)
		return (NULL);

	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < (nmemb * size); i++)
	{
		*((char *)(p) + 1) = 0;
	}

	return (0);
}
