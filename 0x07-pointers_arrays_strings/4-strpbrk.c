#include "main.h"
#include <stdio.h>

/**
 * _strpbrk - function that locates first occurence of bytes in string s
 * in string accept
 * @s: pointer to char
 * @accept: pointer to char
 * Return: 0
 */

char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s)
	{
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
			{
				return (s);
			}
		}
		s++;
	}
	return (NULL);
}
