#include "search_algos.h"

/**
 * linear_search - search for val in sorted array of ints
 * @array: array of ints
 * @size: size of array
 * @value: val to search for
 * Return: return index of val; otherwise -1 if not found
 */


int linear_search(int *array, size_t size, int value)
{
	size_t in;

	if (array == NULL)
		return (-1);
	for (in = 0; in < size; in++)
	{
		printf("Value checked array[%ld] = [%d]\n", in, array[in]);
		if (array[in] == value)
			return (in);
	}
	return (-1);
}
