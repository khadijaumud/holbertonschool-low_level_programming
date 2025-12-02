#include <stdio.h>

/**
 * main - prints lowercase and then uppercase alphabet
 *
 * Return: Always 0
 */
int main(void)
{
	char c;

	/* print lowercase */
	c = 'a';
	while (c <= 'z')
	{
		putchar(c);
		c++;
	}

	/* print uppercase */
	c = 'A';
	while (c <= 'Z')
	{
		putchar(c);
		c++;
	}

	putchar('\n');

	return (0);
}
