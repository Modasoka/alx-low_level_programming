#include "main.h"

/**
* times_table - prints n times table, from zero
*
* Return: null if n > 15 or n < 0
*/
void print_times_table(int n)
{
int i, j, k, l, m;

for (i = 1; i <= n; i++)
       {
       for (j = 0; j <= n; j++)
	      {
	      k = i * j;

	      if (k > n)
	      {
	      l = k % 10;
	      m = (k - l) / 10;

	      _putchar(44);
	      _putchar(32);
	      _putchar(m + '0');
	      _putchar(l + '0');
	      }
	      else
	      {
	      if (j != 0)
	      {
	      _putchar(44);
	      _putchar(32);
	      _putchar(32);
	      }

	      _putchar(k + '0');
	      }
	      }

	      _putchar('\n');
	      }
	      }
