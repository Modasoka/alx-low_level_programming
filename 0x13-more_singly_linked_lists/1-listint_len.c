#include "lists.h"
/**
 * listint_len - returns number of elements
 * @h: pointer to first node
 * Return: number of elements
 */

size_t listint_len(const listint_t *h)
{
	size_t count = 0;
	listint_t *nodeptr = NULL;

	nodeptr = malloc(sizeof(listint_t));

	if (h == NULL)
		return (0);
	if (nodeptr == NULL)
		return (0);
	while (nodeptr != NULL)
	{
		count++;
		nodeptr = nodeptr->next;
	}
	return (count);
}
