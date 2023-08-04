#include "main.h"

/**
 * set_bit - this funct sets the val of a bit to 1 at given index
 * @n: the num to set
 * @index: the index at which to set bit
 * Return: returns 1 if working, otherwise -1 on error
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int setter;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	setter = 1 << index;
	*n = *n | setter;
	return (1);
}

