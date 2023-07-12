#include "main.h"

/**
* read_textfile - this function reads a text file and prints it to POSIX
*                 standard output
* @filename: the name of the textfile
 * @letters: no. of chars in txt file
 *
 * Return: returns the number of characters read and printed
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *fp;
	size_t i = 0;
	int c;

	if (filename == NULL)
		return (0);

	fp = fopen(filename, "r");

	if (fp == NULL)
		return (0);

	c = fgetc(fp);

	while (i < letters && c != EOF)
	{
		write(STDOUT_FILENO, &c, 1);
		c = fgetc(fp);
		i++;
	}
	fclose(fp);
	return (i);
}

