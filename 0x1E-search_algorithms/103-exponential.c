#include "search_algos.h"

int binary_search_helper(int *array, int value,
			 size_t low, size_t high);
size_t min(size_t a, size_t b);

/**
 * min - returns the min of two size_t values
 * @a: first value
 * @b: second value
 *
 * Return: returns `a` if lower or equal to `b`, `b` otherwise
 */
size_t min(size_t a, size_t b)
{
	return (a <= b ? a : b);
}

/**
 * binary_search_helper - search for value in integer array using
 * binarysearch algorithm, not guaranteed to return lowest index if `value`
 * appears twice in `array` (modified from `binary_search`)
 * @array: ptr to first element of array to search
 * @value: value to search for
 * @low: starting index
 * @high: ending index
 *
 * Return: return index containing `value`, or -1 if `value` not found or
 *		   `array` is NULL
 */

int binary_search_helper(int *array, int value,
			 size_t low, size_t high)
{
	size_t middle, i;

	if (!array)
		return (-1);

	while (low <= high)
	{
		middle = (low + high) / 2;
		printf("Searching in array: ");
		for (i = low; i <= high; i++)
			printf("%i%s", array[i], i == high ? "\n" : ", ");
		if (array[middle] < value)
			low = middle + 1;
		else if (array[middle] > value)
			high = middle - 1;
		else
			return ((int)middle);
	}

	return (-1);
}

/**
 * exponential_search - search for value in sorted array of integers
 * using an exponential search algorithm
 * @array: ptr to first element of array to search
 * @size: num of elements in array
 * @value: value to search for
 *
 * Return: return first index containing `value`, or -1 if `value` not found
 *  or`array` is NULL
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t lowest, highest, bound = 1;

	if (!array || size == 0)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n",
		       bound, array[bound]);
		bound *= 2;
	}

	lowest = bound / 2;
	highest = min(bound, size - 1);
	/* 'found' message generated even if array[highest] < value */
	printf("Value found between indexes [%lu] and [%lu]\n", lowest, highest);
	return (binary_search_helper(array, value, lowest, highest));
}
