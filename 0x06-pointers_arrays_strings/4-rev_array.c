#include "main.h"

/**
 * reverse_array - function that reverses the content of an array
 * @a: array that contains integers
 * @n: number of elements in array
 *
 * Return: nothing
 */

void reverse_array(int *a, int n)
{
	int temp;
	int i = 0;

	n -= 1;

	while (i <= n)
	{
		temp = a[i];
		a[i++] = a[n];
		a[n--] = temp;
	}
}
