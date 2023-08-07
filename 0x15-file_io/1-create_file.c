#include "main.h"

/**
 * str_leng - this funct finds len of string
 * @string: the ptr to the string
 *
 * Return: returns the length of the string
 */

size_t str_leng(char *string)
{
	size_t a;

	for (a = 0; string[a]; a++)
		;
	return (a);
}

/**
 * create_file - this funct creates a file.
 * @filename: the name of file to be created
 * @text_content: the  NULL terminated str to write to file
 *
 * Return: returns 1 on success, otherwise -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int file_des;
	ssize_t leng = 0;

	if (filename == NULL)
		return (-1);
	file_des = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (file_des == -1)
		return (-1);
	if (text_content != NULL)
		leng = write(file_des, text_content, str_leng(text_content));
	close(file_des);
	if (leng == -1)
		return (-1);
	return (1);
}

