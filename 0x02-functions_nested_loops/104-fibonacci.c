#include <stdio.h>

/**
 * main - entry point for execution of program
 *
 * Return: prints the first 98 fibonacci numbers, it starts with 1 and 2
 */
int main(void)
{
	int count;
	unsigned long a = 0, b = 1, sum;
	unsigned long a_half1, a_half2, b_half1, b_half2;
	unsigned long half1, half2;

	for (count = 0; count < 92; count++)
	{
		sum = a + b;
		printf("%lu, ", sum);

		a = b;
		b = sum;
	}

	a_half1 = a / 10000000000;
	b_half1 = b / 10000000000;
	a_half2 = a % 10000000000;
	b_half2 = b % 10000000000;

	for (count = 93; count < 99; count++)
	{
		half1 = a_half1 + b_half1;
		half2 = a_half2 + b_half2;
		if (a_half2 + b_half2 > 9999999999)
		{
			half1 += 1;
			half2 %= 10000000000;
		}

		printf("%lu%lu", half1, half2);
		if (count != 98)
			printf(", ");

		a_half1 = b_half1;
		a_half2 = b_half2;
		b_half1 = half1;
		b_half2 = half2;
	}
	printf("\n");
	return (0);
}
