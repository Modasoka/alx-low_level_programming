#include "search_algos.h"

/**
 * binary_search - search for value in sorted array of integers
 * 				   using binary search algorithm
 * @array: array of integers
 * @size: size of array
 * @value: value to search for
 * Return: returns index of value; otherwise -1 if not found
 */

int binary_search(int *array, size_t size, int value)
{

	size_t ii, left, right;

	if (array == NULL)
		return (-1);

	for (left = 0, right = size - 1; right >= left;)
	{
		printf("Searching in array: ");
		for (ii = left; ii < right; ii++)
			printf("%d, ", array[ii]);
		printf("%d\n", array[ii]);

		ii = left + (right - left) / 2;
		if (array[ii] == value)
			return (ii);
		if (array[ii] > value)
			right = ii - 1;
		else
			left = ii + 1;
	}

	return (-1);
}
