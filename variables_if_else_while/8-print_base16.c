#include <stdio.h>

/**
 * main - Prints all numbers of base 16 in lowercase
 *
 * Return: Always 0
 */
int main(void)
{
	int n;

	for (n = 0; n < 16; n++)
	{
		if (n < 10)
			putchar(n + '0');   /* 0–9 */
		else
			putchar(n - 10 + 'a'); /* a–f */
	}

	putchar('\n');

	return (0);
}
