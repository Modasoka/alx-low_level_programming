#include "main.h"
/**
 * _isdigit -function that makes a  check for a digit from 0 to 9
 * @c: variable set to be checked
 *
 * Return: returns 1 if c is a digit, otherwise 0
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{return (0);
	}
}
