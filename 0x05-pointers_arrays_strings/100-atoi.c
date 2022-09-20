#include "main.h"
<<<<<<< HEAD
=======

/**
 * _atoi - function that converts a string to an interger
 * @s: string to be converted to interger
 * Return: the converted string, otherwise 0 if no numbers
 *         are present in string
 */

int _atoi(char *s)

{
  short boolean;
  int i, minus, result;


  i = minus = result = boolean = 0;

  minus = -1;

  while (s[i] != '\0')
    {

      if (s[i] == '-')

	minus *= -1;
      if (s[i] >= '0'&& s[i] <= '9')
	{

	  result *= 10;
	  result -= (s[i] - '0');
	  boolean = 1;

	}
      else if (boolean == 1)

	break;

      i++;
    }
  result *= minus;

  return (result);
}
>>>>>>> d98c76baccbde3cafb7a4dbbe8dcec4dfec6dd20
