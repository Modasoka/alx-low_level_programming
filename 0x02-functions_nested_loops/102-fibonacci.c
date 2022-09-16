#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point for program
 *
 * Return: beginning with 1 and 2, the first fifty Fibonacci number are printed
 */

int main(void)
{
	int n;
	long int a = 1;
	long int b = 2;
	long int c;

	printf("%ld, %ld ,", a, b);

	for (n = 0; n <= 47; n++)
	{
		c = a + b;

		if (n != 47)
		{
			printf("%ld, ", c);
			a = b;
			b = c;
		}
		else
			printf("%ld", c);
	}

	printf("\n");
	return (0);
}
