#include "main.h"

/**
 * flip_bits - this function returns number of bits one would need to flip
 *              to get from one number to another
 * @n: the first number
 * @m: the second number
 * Return: number of bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int num;
	unsigned int count = 0;

	num = n ^ m;

	while (num)
	{
		count += num & 1;
		num = num >> 1;
	}
	return (count);
}
