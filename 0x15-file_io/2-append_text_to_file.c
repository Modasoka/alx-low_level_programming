#include "main.h"

/**
 * str_leng - this functfinds the len of a string
 * @string: the ptr to the string
 *
 * Return: returns the len of the string
 */

size_t str_leng(char *string)
{
	size_t a;

	for (a = 0; string[a]; a++)
		;
	return (a);
}

/**
 * append_text_to_file - funct appends txt at end of file.
 * @filename: the file name
 * @text_content: the NULL terminated str to add at end of file
 *
 * Return: returns 1 on success, otherwise -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int file_des;
	ssize_t leng;

	if (filename == NULL)
		return (-1);
	file_des = open(filename, O_WRONLY | O_APPEND);
	if (file_des == -1)
		return (-1);
	if (text_content != NULL)
		leng = write(file_des, text_content, str_leng(text_content));
	close(file_des);
	if (leng == -1)
		return (-1);
	return (1);
}

