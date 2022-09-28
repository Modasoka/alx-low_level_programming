#include "main.h"
#include <string.h>

/**
 * _puts_recursion: function that prints string followed by new line
 * @s: string to be printed by the above function
 * Return: returns no value
 */

void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
		return;
	}

	_putchar(*s);
	s++;
	_puts_recursion(s);
}
