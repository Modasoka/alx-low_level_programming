#include "function_pointers.h"
/**
 * array_iterator - this function iterates an array
 *@array: the array to be iterated
 *@size: the size of the array.
 *@action: this a function pointer.
 * Description: this function iterates an array
 * Return: return nothing
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array && size && action)
	{
		for (i = 0; i < size; i++)
			action(*(array + i));
	}
}
