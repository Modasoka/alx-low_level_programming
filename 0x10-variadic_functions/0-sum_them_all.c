#include "variadic_functions.h"
#include <stadarg.h>

/**
* sum_them_all - function that returns sum of all its parameters
* @n: constant the constant interger
* Return: the sum of integers passed to sum_them_all
*/

int sum_them_all(const unsigned int n, ...)
{
    int sum = 0;
    unsigned int i;

    va_list ptr;

    if (n == 0) {
        return 0;
    }
    va_start(ptr, n);

    for (i = 0; i < n; i++) {
        sum += va_arg(ptr, int)
    }

    va_end(ptr);
    return (sum);
}