#include "main.h"

/**
 * read_textfile - funct that reads txt file & prints it to POSIX stdout
 * @filename: the name of the file to read
 * @letters: no of letters to be read & printed out
 *
 * Return: returns the actual no of letters it could read & print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int filedes;
	ssize_t lengr, lengw;
	char *buff;

	if (filename == NULL)
		return (0);
	filedes = open(filename, O_RDONLY);
	if (filedes == -1)
		return (0);
	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
	{
		close(filedes);
		return (0);
	}
	lengr = read(filedes, buff, letters);
	close(filedes);
	if (lengr == -1)
	{
		free(buff);
		return (0);
	}
	lengw = write(STDOUT_FILENO, buff, lengr);
	free(buff);
	if (lengr != lengw)
		return (0);
	return (lengw);
}

