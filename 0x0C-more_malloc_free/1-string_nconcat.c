#include <stdlib.h>
#include "main.h"

/**
 * _strlen - function that calculates and returns the string length
 * @string: string
 * Return: length of string
 *
 */

int _strlen(char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
	;
	return (i);
}

/**
 * string_nconcat - function that concatenates s1 and n bytes of s2:
 * returns ptr to the string
 * @s1: string 1
 * @s2: string 2
 * @n: n bytes to be concatenated from string 2
 * Return: pointer to the concatenated string
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *ptr;
	int num, len, i, j;

	num = n;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	if (num < 0)
		return (NULL);
	if (num >= _strlen(s2))
		num = _strlen(s2);

	len = _strlen(s1) + num + 1;
	ptr = malloc(sizeof(*ptr) * len);

	if (ptr == NULL)
		return (NULL);
	for (i = 0; s1[i] != '\0'; i++)
		ptr[i] = s1[i];
	for (j = 0; j < num; j++)
		ptr[i + j] = s2[j];
	ptr[i + j] = '\0';

	return (ptr);
}

