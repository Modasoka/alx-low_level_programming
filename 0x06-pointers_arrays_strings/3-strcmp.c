#include "main.h"

/**
 * _strcmp - function that compares two strings
 *
 * @s1: string 1
 * @s2: string 2
 * Return: 0 if identical
 *         <0 if ASCII value of 1st char in s1 is less than that of s2
 *         >0 if ASCII value of 1st char in s2 is greater than that of s2
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}
