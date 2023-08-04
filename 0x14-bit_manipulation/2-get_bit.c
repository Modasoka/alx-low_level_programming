#include "main.h"

/**
 * get_bit - this funct returns val of bit at given endex
 * @n: the num to check the bits in
 * @index: the index where the bits are to be checked
 * Return: returns the bit val, or -1 on error
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int divi, checkers;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	divi = 1 << index;
	checkers = n & divi;
	if (checkers == divi)
		return (1);
	return (0);
}

