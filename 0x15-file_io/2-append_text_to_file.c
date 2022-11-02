#include "main.h"

/**
 * _strnlen - this function finds the length of a string
 * @str: points to the string
 *
 * Return: returns the length of the string
 */

size_t _strlen(char *str)
{
	size_t a;

	for (a = 0; str[a]; a++)
		;
	return (a);
}

/**
 * append_text_to_file - function that appends text at the end of file
 * @filename: the name of the file
 * @text_content: is the NULL terminated string to be added at end of file
 *                return 1 (file exists); -1 (file does not exit/ lack of
 *                authorization to write file(s))
 * Return: 1(success)
 *         -1 (failure)
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t leng;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	if (text_content != NULL)
		leng = write(fd, text_content, _strlen(text_content));

	close(fd);

	if (leng == -1)
		return (-1);

	return (1);
}
