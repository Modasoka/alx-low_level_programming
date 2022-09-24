#include "main.h"
/**
 * swap_int - swaps value of 2 intergers
 * @a: interger set to be swapped with b
 * @b: interger set to eb swapped with a
 * Return: brings no value (returns nothing)
 */

void swap_int(int *a, int *b)
{
	int temp; /*variable that is temporary and contains value of one pointer */

	temp = *a; /* shows value of a, saved in temp */
	*a = *b;
	*b = temp;
}
