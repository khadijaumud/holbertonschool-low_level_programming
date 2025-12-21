#include "main.h"

/**
 * checker - checks if a number has any divisor other than 1 and itself
 * @n: current divisor to test (starts from 2)
 * @base: the number being checked for primality
 *
 * Return: 1 if base is prime, 0 otherwise
 */
int checker(int n, int base)
{
	/* If n squared is greater than base, no divisors exist */
	if (n * n > base)
	{
		return (1);
	}

	/* If base is divisible by n, it is not a prime number */
	if (base % n == 0)
	{
		return (0);
	}

	/* Recursively check the next possible divisor */
	return (checker(n + 1, base));
}

/**
 * is_prime_number - checks if a number is a prime number
 * @n: number to be checked
 *
 * Return: 1 if n is a prime number, otherwise 0
 */
int is_prime_number(int n)
{
	/* Numbers less than or equal to 1 are not prime */
	if (n <= 1)
	{
		return (0);
	}

	/* Start checking divisibility from 2 */
	return (checker(2, n));
}
