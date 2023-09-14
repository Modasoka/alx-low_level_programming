#include "lists.h"

/**
 * print_dlistint - function prints all elements of doubly linked list
 * @h: the ptr to the head of list
 * Return: number of nodes in list
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t counter = 0;

	if (h == NULL)
		return (0);

	while (h != NULL)
	{
		printf("%d\n", h->n);
		counter++;
		h = h->next;
	}

	return (counter);
}
