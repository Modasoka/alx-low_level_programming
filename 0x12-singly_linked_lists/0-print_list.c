#include "lists.h"

/**
 * print_list - function that lists all elements of a list
 *              list_t; prints 0 if string is NULL
 * @h: the linked list (list_t)
 * Return: returns the number of nodes
 */

size_t print_list(const list_t *h)
{
  size_t count = 0;
  const list_t *ptr = NULL;

  ptr = malloc(sizeof(list_t));

  if(ptr == NULL)
    {
      return 0;
    }
  
  ptr = h;

  while (ptr != NULL)
    {
      if (ptr->str == NULL)
	{
	  printf("[0] (nil)\n");
	}
      else
	printf("[%u] %s\n",)ptr->len, ptr->str);

  ptr = ptr->next;
  count++;
    }
    return count;
}
