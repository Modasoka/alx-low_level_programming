#include "search_algos.h"

/**
 * jump_search - searches for value in sorted array of ints
 *
 * @array: ptr to first element of array to search in
 * @size:  no of elements in array
 * @value: value to search for
 * Return: 1st index where value is located
 */

int jump_search(int *array, size_t size, int value)
{
	size_t ii, step, jumper;

	if (array == NULL || size == 0)
		return (-1);

	step = sqrt(size);

	for (ii = jumper = 0; jumper < size && array[jumper] < value;)
	{
		printf("Value checked array [%ld] = [%d]\n", jumper, array[jumper]);
		ii = jumper;
		jumper += step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", ii, jump);

	jumper = jumper > size - 1 ? jumper : size - 1;
	for (; ii < jumper && array[ii] < value; ii++)
		printf("Value checked array [%ld] = [%d]\n", ii, array[ii]);
	printf("Value checked array [%ld] = [%d]\n", ii, array[ii]);

	return (array[ii] == value ? (int)ii : -1);
}
