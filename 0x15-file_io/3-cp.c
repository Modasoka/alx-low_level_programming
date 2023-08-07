#include "main.h"

/**
 * check_97 - funct checks for correct no of args
 * @argc: arg number
 *
 * Return: returns void
 */

void check_97(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * check_98 - funct checks that file_from exists & can be read
 * @checker: checks if true or false
 * @file: name (file_from)
 * @filed_from: file descriptor of file_from, or -1
 * @filed_to: file descriptor of file_to, or -1
 *
 * Return: returns void
 */

void check_98(ssize_t checker, char *file, int filed_from, int filed_to)
{
	if (checker == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		if (filed_from != -1)
			close(filed_from);
		if (filed_to != -1)
			close(filed_to);
		exit(98);
	}
}

/**
 * check_99 - funct checks that file_to was created and/or can be written to
 * @checker: this checks if true or false
 * @file: name(file_to)
 * @filed_from: file descriptor of file_from, or -1
 * @filed_to: file descriptor of file_to, or -1
 *
 * Return: returns void
 */

void check_99(ssize_t checker, char *file, int filed_from, int filed_to)
{
	if (checker == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		if (filed_from != -1)
			close(filed_from);
		if (filed_to != -1)
			close(filed_to);
		exit(99);
	}
}

/**
 * check_100 - funct checks that file descriptors were closed properly
 * @checker: checks if true or false
 * @file_des: file descriptor
 *
 * Return: returns void
 */

void check_100(int checker, int file_des)
{
	if (checker == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_des);
		exit(100);
	}
}

/**
 * main -funct c opies content of file to another file.
 * @argc: number of passed args
 * @argv: array of pointers to the args
 *
 * Return: returns 0 on success
 */

int main(int argc, char *argv[])
{
	int filed_from, filed_to, close_to, close_frm;
	ssize_t lengr, lengw;
	char buff[1024];
	mode_t file_permi;

	check_97(argc);
	filed_from = open(argv[1], O_RDONLY);
	check_98((ssize_t)filed_from, argv[1], -1, -1);
	file_permi = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	filed_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_permi);
	check_99((ssize_t)filed_to, argv[2], filed_from, -1);
	lengr = 1024;
	while (lengr == 1024)
	{
		lengr = read(filed_from, buff, 1024);
		check_98(lengr, argv[1], filed_from, filed_to);
		lengw = write(filed_to, buff, lengr);
		if (lengw != lengr)
			lengw = -1;
		check_99(lengw, argv[2], filed_from, filed_to);
	}
	close_to = close(filed_to);
	close_frm = close(filed_from);
	check_100(close_to, filed_to);
	check_100(close_frm, filed_from);
	return (0);
}

