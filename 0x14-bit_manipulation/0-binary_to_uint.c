#include "main.h"

/**
 * binary_to_uint - this funct does the conversion of an unsigned int from
 * a binary number
 * @b: this is a ptr to a str that contains a binary number
 *
 * Return:returns an unsigned int with decimal val of a binary num or 0 on error
 */

unsigned int binary_to_uint(const char *b)
{
	int a;
	unsigned int number;

	number = 0;
	if (!b)
		return (0);
	for (a = 0; b[a] != '\0'; a++)
	{
		if (b[a] != '0' && b[a] != '1')
			return (0);
	}
	for (a = 0; b[a] != '\0'; a++)
	{
		number <<= 1;
		if (b[a] == '1')
			number += 1;
	}
	return (number);
}

