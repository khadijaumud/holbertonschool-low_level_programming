#include "main.h"

/**
 * print_diagonal - draws a diagonal line on the terminal
 * @n: number of times to print '\'
 */
void print_diagonal(int n)
{
	int i, j;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 0; i < n; i++)
	{
		/* print spaces before the '\' */
		for (j = 0; j < i; j++)
			_putchar(' ');

		_putchar('\\'); /* print the diagonal character */
		_putchar('\n'); /* move to the next line */
	}
}
