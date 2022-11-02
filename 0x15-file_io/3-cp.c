#include "main.h"

/**
 *
 *
 */

void check97(int argc)
{
	if (argc != 3)
	{
		dprintf(STERR_FILENO, "cp file_from file_to\n");
		exit(97);
	}
}

/**
 *
 *
 */

void check 98(ssize_t check, char *file, int fd_from, int fd_to)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: cannot read from this file - %s\n", file);
		if (fd_from != -1)
			close(fd_from);
		if (fd_to != -1)
			close(fd_to);
		exit(98);
	}
}
/**
 *
 *
 */

void check 99(ssize_t check, char *file, int fd_from, int fd_to)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: unable to write to %s\n", file);
		if (fd_from != -1)
			close (fd_from);
		if (fd_to != -1)
			close (fd_to);
		
		exit (99);
	}
