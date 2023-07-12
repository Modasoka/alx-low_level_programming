#include "main.h"

/**
 * append_text_to_file - this function appends text to a file
 * @filename: file name
 * @text_content: the text to be appended to the file
 *
 * Return: returns 1 on success, otherwise -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	FILE *fp;
	int i = 0;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		text_content = "";

	fp = fopen(filename, "a");

	if (fp == NULL)
		return (-1);

	while (text_content[i])
	{
		putc(text_content[i], fp);
		i++;
	}
	fclose(fp);
	return (1);
}

