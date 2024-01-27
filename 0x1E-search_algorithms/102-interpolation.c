#include "search_algos.h"

/**
 * interpolation_search - search for value in sorted array of integers
 * 						  using an interpolation search algorithm
 * @array: ptr to first element of array to search
 * @size: num of elements in array
 * @value: value to search for
 *
 * Return: return first index containing `value`, or -1 if `value` not found or
 *		   `array` is NULL
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0;
	size_t high = size - 1;
	size_t position;

	if (!array)
		return (-1);

	while ((array[high] != array[low]) &&
	       (value >= array[low]) && (value <= array[high]))
	{
		position = low + (((double)(high - low) / (array[high] - array[low]))
			    * (value - array[low]));
		printf("Value checked array[%lu] = [%d]\n", position, array[position]);
		if (array[position] < value)
			low = position + 1;
		else if (value < array[position])
			high = position - 1;
		else
			return (position);
	}
	if (value == array[low])
	{
		printf("Value checked array[%lu] = [%d]\n", low, array[low]);
		return (low);
	}
	position = low + (((double)(high - low) / (array[high] - array[low]))
		     * (value - array[low]));
	printf("Value checked array[%lu] is out of range\n", position);
	return (-1);
}