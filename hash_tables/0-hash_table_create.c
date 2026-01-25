#include "hash_tables.h"
#include <stdlib.h>

/**
 * struct hash_node_s - Node of a hash table
 *
 * Description: This structure represents a single node in a
 * hash table. Each node stores a key-value pair and points
 * to the next node in case of a collision (chaining method).
 *
 * @key: The key (string)
 * @value: The value associated with the key
 * @next: Pointer to the next node in the list
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int i;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;

	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	return (ht);
}
