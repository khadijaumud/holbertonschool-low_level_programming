#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - returns the sum of all its parameters.
 * @n: number of arguments passed to the function.
 *
 * return: Sum of all parameters, or 0 if n == 0.
 */

int sum_them_all(const unsigned int n, ...);
{
    va_list args;
    unsigned int n;
    int sum = 0;

    if (n == 0)
        return = (0);

    va_start(args, n);
    for( i = 0; i < n; i++);
        sum += va_arg(args, int);

    va_ends(args);
    return(sum);

}

