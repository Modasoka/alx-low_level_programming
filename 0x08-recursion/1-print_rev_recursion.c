#include "main.h"

/**
 * _print_rev_recursion - functio that prints a string in reverse
 * @s: string that is to be reversed
 *
 * Return: nothing
 */

void _print_rev_recursion(char *s)
{
	if (*s)
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
}
