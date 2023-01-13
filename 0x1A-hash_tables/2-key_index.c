#include "hash_tables.h"

/**
 * key_index - generates an index
 * @key: key to assign index
 * @size: size of the hashtable
 * Return: the key index
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
