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
	int fd;
	ssize_t lenr, lenw;
	char *buff;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
	{
		close(fd);
		return (0);
	}

	lenr = read(fd, buff, letters);
	close(fd);
	if (lenr == -1)
	{
		free(buff);
		return (0);
	}

	lenw = write(STDOUT_FILENO, buff, lenr);
	free(buff);
	if (lenr != lenw)
		return (0);
	return (lenw);
}
