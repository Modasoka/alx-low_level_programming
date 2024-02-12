#include "search_algos.h"


/**
  * advanced_binary_recursive - Searche recursively for value in sorted
  *                             array of integers using binary search.
  * @array: ptr to first element of [sub]array to search.
  * @left: The starting index of [sub]array to search.
  * @right: ending index of [sub]array to search.
  * @value:  value to search for.
  *
  * Return: If value is not present, -1.
  *         Otherwise, index where value is located.
  *
  * Description: Prints [sub]array being searched after each change.
  */

int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t j;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (j = left; j < right; j++)
		printf("%d, ", array[j]);
	printf("%d\n", array[j]);

	j = left + (right - left) / 2;
	if (array[j] == value && (j == left || array[j - 1] != value))
		return (j);
	if (array[j] >= value)
		return (advanced_binary_recursive(array, left, j, value));
	return (advanced_binary_recursive(array, j + 1, right, value));
}



/**
 *advanced_binary -  func that searches for
 * value in sorted array of integers.
 *
 * @array: ptr to first element in array
 * @size: Size of array to search in
 * @value: Element to be searched
 * Return: return index of searched element
 */

int advanced_binary(int *array, size_t size, int value)
	{
		if (array == NULL || size == 0)
			return (-1);

		return (advanced_binary_recursive(array, 0, size - 1, value));
	}
