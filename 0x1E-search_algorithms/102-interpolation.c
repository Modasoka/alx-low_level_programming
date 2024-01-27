#include "search_algos.h"

/**
 *interpolation_search - searches for value in sorted
 * 						 array of integers
 *@array: ptr to first element of array to search in
 *@size: no of elements in array
 *@value: value to search for
 *Return: returns 1st index where value is located
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t i, left, right;

	if (array == NULL)
		return (-1);

	for (left = 0, (right = size - 1); right >= left;)
	{
		i = left + (((double)(right - left) / (array[right] - array[left])) * \
			(value - array[left]));
		if (i < size)
		{
			printf("Value checked array [%ld] = [%d]\n", i, array[i]);
		}
		else
		{
			printf("Value checked array [%ld] is out of range\n", i);
			break;
		}

		if (array[i] == value)
			return (i);
		if (array[i] > value)
			right = i - 1;
		else
			left = i + 1;
	}
	return (-1);

}
