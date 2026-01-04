#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <stddef.h>

/**
 * print_name - prints a name using a function pointer
 * @name: name to print
 * @f: function pointer
 */
void print_name(char *name, void (*f)(char *));

#endif /* FUNCTION_POINTERS_H */
