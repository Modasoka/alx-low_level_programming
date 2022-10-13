#include <stdio.h>

/**
 * main - program starts here
 *
 * Return: Computes and prints the sum of the multiples
 * of 3 or 5 below 1024 excluded, 0 otherwise
 *
 */

int main(void)
{
	int sum = 0;
	int i;

	for (i = 0; i < 1024; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	}

	printf("%d\n", sum);
	return (0);
}
