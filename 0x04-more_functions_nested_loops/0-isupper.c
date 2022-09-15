#include "main.h"

/**
 * _isupper - function that checks for the existence of an uppercase letter
 * @c: character that is supposed to be checked by the function
 *
 * Return: returns 1 if c is an uppercase letter, else returns 0
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
