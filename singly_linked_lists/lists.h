#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct list_s - singly linked list node
 * @str: string stored in the node
 * @len: length of the string
 * @next: points to the next node in the list
 *
 * Description: This struct defines a node of a singly linked list.
 * Each node stores a string, its length, and a pointer to the next node.
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

/* Function prototype */
size_t print_list(const list_t *h);

#endif
