#include "main.h"
#include <stdio.h>

/**
 * print_array - function that prints n elements of an array of integers
 * @n: number of elements in array to be printed by the function
 * @a: array that is to be printed
 * Numbers to be separated by comma followed by a space
 * Display of numbers is in same order as in array
 * Return: nothing
 */

void print_array(int *a, int n)
{
	int i = 0;

	for (; i < n; i++)
	{
		if (i != (n - 1))
			printf("%d, ", a[i]);
		else
			printf("%d", a[i]);
	}

	printf("\n");
}
