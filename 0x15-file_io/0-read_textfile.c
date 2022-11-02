#include "main.h"

/**
 * read_textfile - this function reads a text file and prints it
 *                to the standard output
 * @letters: the number of letters to be read and printed
 * @filename: this is the file to be read from
 *
 * Return: returns actual number of letters that function is
 *         able to read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd = open(filename, O_RDONLY);
	size_t count = 0;
	char j;
	int rd = 0, wr = 0;

	if (filename == NULL)
		return (0);

	while (count < letters)
	{
		rd = read(fd, &j, 1);
		if (rd == -1)
			return (0);
		wr = write(STDOUT_FILENO, &j, 1);
		if (wr == -1)
			return (0);
		count++;
	}

	close(fd);

	return (count);
}
