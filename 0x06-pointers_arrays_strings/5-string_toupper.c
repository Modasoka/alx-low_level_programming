#include "main.h"

/**
 * *string_toupper - function that makes changes to all lowercase letters
 *                   to switch to uppercase
 * @a: input string
 * Return:a
 */

char *string_toupper(char *a)
{
	int i = 0;
	int gap_to_start = 0;

	for (; a[i] != '\0';)
	{
		if (!(a[i] >= 97 && a[i] <= 122))
			i++;
		else
		{
			gap_to_start = a[i] - 'a';
			a[i] = gap_to_start + 'A';
			i++;
		}
	}
	return (a);
}
