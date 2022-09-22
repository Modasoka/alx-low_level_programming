#include "main.h"

/**
 * *_strncpy - function that copies a string
 * @dest: destination of string
 * @src: source of the string
 * @n: number of bytes that are to be copied
 * Return: pointer to the dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
