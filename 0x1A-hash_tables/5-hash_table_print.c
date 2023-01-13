#include "hash_tables.h"

/**
 * hash_table_print - function that prints a hashtable
 * @ht: hashtable
 * Returns - 
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i, j = 0;
	hash_node_t *tmp;

	if (!ht)
		return;
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		tmp = ht->array[i];
		while (tmp)
		{
			if (j)
				printf(", ");
			printf("'%s' : '%s'", tmp->key, tmp->value);
			tmp = tmp->next;
			j++;
		}
	}
	printf("}\n");
}
