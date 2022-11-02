#include "main.h"

/**
 * get_bit - this function returns the value of a bit at given index
 * @n: number to be converted first to binary
 * @index: the position of bit in binary number
 * Return: bit at index, or -1 if error occured
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (n == 0 || index >= 64)
		return (-1);

	if ((n & (1 << index)) == 0)
		return (0);

	return (1);
}
