#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using the bubble sort algorithm
 * @array: list of integers to be sorted
 * @size: number of integers in @array
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int temp = 0;

	if (size < 2 || array == NULL)
		return;

	for (i = size - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
