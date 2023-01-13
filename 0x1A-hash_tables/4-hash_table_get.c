#include "hash_tables.h"

/**
 * hash_table_get - gets the key value in hashtable
 * @ht: hashtable to conduct search in
 * @key: key to be searched for
 * Return: returns a value, otherwise NULL
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *temp;

	if (!ht || !key)
		return (NULL);
	index = key_index((unsigned char *)key, ht->size);
	temp = ht->array[index];

	while (temp != NULL)
	{
		if (temp->key)
		{
			if (strcmp(temp->key, key) == 0)
				return (temp->value);
		}
		temp = temp->next;
	}
	return (NULL);
}
