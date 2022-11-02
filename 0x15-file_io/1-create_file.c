#include "main.h"

/**
 * create_file - this function creates a file
 * @filename: the name of the file to be created
 * @text_content: NULL terminated string that will write a string
 *
 * Return: 1(success)
 *         -1(failure)
 */

int create_file(const char *filename, char *text_content)
{
	int fd = open(filename, O_CREAT | O_APPEND | O_TRUNC | O_RDWR, 0600);
	int b = 0;

	if (filename == NULL)
		return (-1);
	if (fd == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	else
	{
		while (*(text_content + 1) != '\0')
		{
			write(fd, (text_content + 1), 1);
			b++;
		}
			close(fd);
			return (1);
	}
	return (-1);
}
