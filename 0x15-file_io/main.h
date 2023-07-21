#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>


ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);

#include "main.h"

/**
 * _strncmp - function compares 2 strings
 * @s1: first string
 * @s2: second string
 * @n: maximum number of bytes for comparison
 * Return: returns 0 if first n bytes of s1 & s2 are equal,
 *         otherwise returns non-zero
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
 * main - funct that copies file contens to another file
 * @argc: arg count
 * @argv: values of the args
 * Return: always 0
 */
int main(int argc, const char *argv[])
{
        unsigned char buffer[18];
        unsigned int bit_mode;
        int big_endian;
        int fd;

        if (argc != 2)
        {
                write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
                exit(98);
        }

        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
                write(STDERR_FILENO, "Error: Can't read from file\n", 28);
                exit(98);
        }

        _read(fd, (char *) buffer, 18);

        elf_magic(buffer);
        bit_mode = elf_class(buffer);
        big_endian = elf_data(buffer);
        elf_version(buffer);
        elf_osabi(buffer);
        elf_abivers(buffer);
        elf_type(buffer, big_endian);

	lseek(fd, 24, SEEK_SET);
	_read(fd, (char *) buffer, bit_mode / 8);

	elf_entry(buffer, bit_mode, big_endian);

	_close(fd);

	return (0);
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



#endif /* MAIN_H */
