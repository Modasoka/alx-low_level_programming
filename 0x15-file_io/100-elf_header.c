#include "main.h"

/**
 * _strncmp - function compares 2 strings
 * @s1: first string
 * @s2: second string
 * @n: maximum number of bytes for comparison
 * Return: returns 0 if first n bytes of s1 & s2 are equal,
 * 	   otherwise returns non-zero
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	for ( ; n && *s1 && *s2; --n, ++s1, ++s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
	}
	if (n)
	{
		if (*s1)
			return (1);
		if (*s2)
			return (-1);
	}
	return (0);
}

/**
 * _close - funct that closes a file descriptor & prints error msg upon failure
 * @fd: file descriptor to be closed
 */

void _close(int fd)
{
	if (close(fd) != -1)
		return;
	write(STDERR_FILENO, "Error: cannot close fd\n", 22);
	exit(98);
}

/**
 * _read - funct reads from a file & prints error msg upon failure
 * @fd: file descriptor to be read from
 * @buf: buffer that is being written to
 * @count: total number of bytes that are to be read
 */

void _read(int fd, char *buf, size_t count)
{
	if (read(fd, buf, count) != -1)
		return;
	write(STDERR_FILENO, "Error: cannot read from file\n", 28);
	_close(fd);
	exit(98);
}

/**
 * elf_magic - funct to print ELF magic
 * @buffer: header (ELF)
 */

void elf_magic(const unsigned char *buffer)
{
	unsigned int a;

	if (_strncmp((const char *) buffer, ELFMAG, 4))
	{
		write(STDERR_FILENO, "Error: not an ELF file\n", 23);
		exit(98);
	}
	printf("ELF header:\n Magic:  ");

	for (a = 0; a < 16; a++)
		printf("%02x%c", buffer[a], a < 15 ? ' ' : '\n');
}

/**
 * elf_class - funct prints an ELf class
 * @buffer: the header(ELF)
 * Return: returns bit mode (either 32 or 64)
 */

