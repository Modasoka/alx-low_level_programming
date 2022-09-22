#include "main.h"

/**
 * _strncat - function that concatenates two strings
 *
 * @dest: string that is being added
 * @src: string that is to be appended
 * @n: the total number of bytes from @src
 *
 * Return: a pointer to the resulting string @dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int len1 = 0; /* string length for src */
	int len2 = 0; /* string length for dest */
	int i;

	while (src[len1] != '\0')
		len1++;

	while (dest[len2] != '\0')
		len2++;

	for (i = 0; i < n; i++)
	{
		dest[len2] = src[i];
		len2++;
	}
	return (dest);
}
