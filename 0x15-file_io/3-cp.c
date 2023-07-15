#include "main.h"

/**
 * check97 - checks for the correct number of args
 * @argc: number of args
 *
 * Return: void
 */

void check97(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * check98 - this funct checks that file_from exists and can be read
 * @check: checks if it is true or false
 * @file: name - file_from
 * @fd_from: file descriptor (-1) of file_from
 * @fd_to: file descriptor (-1) of file_to
 *
 * Returns void
 */

void check98(ssize_t check, char *file, int fd_from, int fd_to)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: cannot read from file %s\n", file);
		if (fd_from != -1)
			close(fd_from);
		if (fd_to != -1)
			close(fd_to);
		exit(98);
	}
}

/**
 * check99 - funct checks that file_to was created and/or can be written to
 * @check: checks if it is true or false
 * @file: name - file_to
 * @fd_from: file descriptor (-1) of file_from
 * @fd_to: file descriptor (-1) of file_to
 *
 * Returns void
 */

void check99(ssize_t check, char *file, int fd_from, int fd_to)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: cannot write to %s\n", file);
		if (fd_from == -1)
			close(fd_from);
		if (fd_to != -1)
			close(fd_to);
		exit(99);
	}
}

/**
 * check100 - funct checks that file descriptors were closed properly
 * @check: checks if it is true or false
 * @fd: the file descriptor
 *
 * Returns void
 */

void check100(int check, int fd)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: cannot close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - funct copies the content of a file to another file
 * @argc: number of passed args
 * @argv: array of pointers to the args
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	int fd_from, fd_to, close_to, close_from;
	ssize_t lenr, lenw;
	char buffer[1024];
	mode_t file_perm;

	check97(argc);
	fd_from = open(argv[1], O_RDONLY);
	check98((ssize_t)fd_from, argv[1], -1, -1);
	file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
	check99((ssize_t)fd_to, argv[2], fd_from, -1);
	lenr = 1024;
	while (lenr == 1024)
	{
		lenr = read(fd_from, buffer, 1024);
		check98(lenr, argv[1], fd_from, fd_to);
		lenw = write(fd_to, buffer, lenr);
		if (lenw != lenr)
			lenw = -1;
		check99(lenw, argv[2], fd_from, fd_to);
	}
	close_to = close(fd_to);
	close_from = close(fd_from);
	check100(close_to, fd_to);
	check100(close_from, fd_from);
	return (0);
}

