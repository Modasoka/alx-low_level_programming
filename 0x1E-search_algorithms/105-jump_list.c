#include "search_algos.h"

/**
 * jump_list - Searche for an algo in sorted singly
 *             linked list of integers using jump search.
 * @list: ptr to head of linked list to search.
 * @size: number of nodes in list.
 * @value: value to search for.
 *
 * Return: If value is not present or head of list is NULL, NULL.
 *         Otherwise, a ptr to first node where value is located.
 *
 * Description: Prints a value every time it is compared in a list.
 *              Uses square root of list size as jump step.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t stepper, step_size;
	listint_t *node, *jumper;

	if (list == NULL || size == 0)
		return (NULL);

	stepper = 0;
	step_size = sqrt(size);
	for (node = jumper = list; jumper->index + 1 < size && jumper->n < value;)
	{
		node = jumper;
		for (stepper += step_size; jumper->index < stepper; jumper = jumper->next)
		{
			if (jumper->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", jumper->index, jumper->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, jumper->index);

	for (; node->index < jumper->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

	return (node->n == value ? node : NULL);
}
