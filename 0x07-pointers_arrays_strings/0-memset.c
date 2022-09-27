#include "main.h"

/**
 * *_memset - function that fills the memory with a constant byte
 * @s: pointer to a string s
 * @b: constant byte
 * @n: the number of bytes of memory
 * Return: pointer to s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
