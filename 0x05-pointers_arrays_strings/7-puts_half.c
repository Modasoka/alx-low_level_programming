#include "main.h"

int _strlen(char *s);

/**
 * puts_half - function that prints second half of the string
 *           - if the no. of characters is odd, print n = (length - 1) / 2
 * @str: string to be manipulated by the function
 * Return: nothing
 */

void puts_half(char *str)
{
	int len, len_half_even, len_half_odd;

	len = _strlen(str);

	len_half_even = len / 2;
	len_half_odd = ((len - 1) / 2) + 1;

	if (len == 0)
		;
	else if (len % 2 == 0)
	{
		while (len_half_even < len)
		{
			_putchar(*(str + len_half_even));
			len_half_even++;
		}
	}
	else
	{
		while ((len_half_odd) < len)
		{
			_putchar(*(str + len_half_odd));
			len_half_odd++;
		}
	}
	_putchar('\n');
}



/**
 * _strlen - function that returns the length of a string
 * @s: string whose length is to be determined by the function
 * Return: Always 0
 */

int _strlen(char *s)
{
	int a;

	for (a = 0; *s != '\0'; s++) /*counts characters in string until \0. */
		a++;

	return (a);
}
