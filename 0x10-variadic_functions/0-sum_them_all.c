#include "variadic_functions.h"
<<<<<<< HEAD

/**
 * sum_them_all - this function sums all arguments
 * @n: number of arguments
 * Return: sum of all arguments
 */

int sum_them_all(const unsigned int n, ...)
{
	register unsigned int i;
	int sum = 0;
	va_list arguments;

	va_start(arguments, n);
	for (i = 0; i < n; i++)
		sum += va_arg(arguments, int);
	va_end(arguments);
	return (sum);
}
=======
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
>>>>>>> b81f2f214b382d81507434345e87214f59523719
