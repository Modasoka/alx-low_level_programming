#include "main.h"

/**
 * _power - this functs calculates the base ^ power
 * @n_base: the exponent base
 * @n_power: the power of the exponent
 * Return: returns the value of base ^ powe
 */

unsigned long int _power(unsigned int n_base, unsigned int n_power)
{
	unsigned long int number;
	unsigned int a;

	number = 1;
	for (a = 1; a <= n_power; a++)
		number *= n_base;
	return (number);
}

/**
 * print_binary - this prints a num in its binary notation
 * @n: the num to be printed
 * Return: returns oid
 */

void print_binary(unsigned long int n)
{
	unsigned long int divi, checker;
	char flags;

	flags = 0;
	divi = _power(2, sizeof(unsigned long int) * 8 - 1);
	while (divi != 0)
	{
		checker = n & divi;
		if (checker == divi)
		{
			flags = 1;
			_putchar('1');
		}
		else if (flags == 1 || divi == 1)
		{
			_putchar('0');
		}
		divi >>= 1;
	}
}

