#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to pointer to the head of the list
 * @idx: index where the new node should be added
 * @n: value to store in the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h,
		unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *temp;
	unsigned int count = 0;

	if (h == NULL)
		return (NULL);

	/* If inserting at the beginning */
	if (idx == 0)
		return (add_dnodeint(h, n));

	temp = *h;
	while (temp != NULL)
	{
		if (count == idx - 1)
		{
			/* If inserting at the end */
			if (temp->next == NULL)
				return (add_dnodeint_end(h, n));

			new_node = malloc(sizeof(dlistint_t));
			if (new_node == NULL)
				return (NULL);

			new_node->n = n;
			new_node->next = temp->next;
			new_node->prev = temp;

			temp->next->prev = new_node;
			temp->next = new_node;

			return (new_node);
		}

		temp = temp->next;
		count++;
	}

	return (NULL);
}
