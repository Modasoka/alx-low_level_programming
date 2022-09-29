#include "main.h"

/**
 * palind2 -  function that obtains length of a string
 * @a: string whose length is to be obtained
 * @l: integer to count length
 *
 * Return: On success 1, otherwise -1 (error appropriately set)
 */
int palind2(char *a, int l)
{
	if (*a == 0)
		return (l - 1);
	return (palind2(a + 1, l + 1));
}
/**
 * palind3 - function that compares string vs string reverse
 * @a: string
 * @l: length
 *
 * Return: On success 1, otherwise -1 (error appropriately set)
 */

int palind3(char *a, int l)
{
	if (*a != *(a + l))
		return (0);
	else if (*a == 0)
		return (1);
	return (palind3(a + 1, l - 2));
}
/**
 * is_palindrome - function that checks if a string is a palindrome
 * @s: string to be evaluated
 *
 * Return: On success 1, otherwise -1 (error appropriately set)
 */
int is_palindrome(char *s)
{
	int l;

	l = palind2(s, 0);
	return (palind3(s, l));
}