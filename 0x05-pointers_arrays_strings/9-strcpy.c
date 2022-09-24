#include "main.h"

/**
 * *_strcpy - function that copies string pointed to by src including
 *            null byte (\0) to buffer pointed to by dest
 * @src: this is the source of the string to be copied
 * @dest: this is the destination of the copied string
 * Return: this is the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int a, b = 0;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[b] = src[a];
		b++;
	}
	dest[b] = '\0';

	return (dest);
}
