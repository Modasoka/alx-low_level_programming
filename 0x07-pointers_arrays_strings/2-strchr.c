#include "main.h"

/**
 * *_strchr - function that locates a character in a string
 * @s: string
 * @c: character to be found by the function
 * Return: pointer to first occurrence of c in s,
 *         null if character if not found
 */

char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	if (*s == c)
	{
		return (s);
	}
	return (0);
}
