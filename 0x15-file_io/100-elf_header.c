#include "main.h"

/**
 * strn_comp - compare two strings
 * @str1: first string
 * @str2: second string
 * @num_bytes:  max number of bytes to compare
 *
 * Return: returns 0 if the first n bytes of str1 and str2 are equal,
 * otherwise returns non-zero
 */

int strn_comp(const char *str1, const char *str2, size_t num_bytes)
{
	for ( ; num_bytes && *str1 && *str2; --num_bytes, ++str1, ++str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
	}
	if (num_bytes)
	{
		if (*str1)
			return (1);
		if (*str2)
			return (-1);
	}
	return (0);
}

/**
 * close_fd - funct closes file descriptor & prints err message upon failure
 * @file_d: the file descriptor to be closed
 */
void close_fd(int file_d)
{
	if (close(file_d) != -1)
		return;
	write(STDERR_FILENO, "Error: Can't close fd\n", 22);
	exit(98);
}

/**
 * read_f - funct reads from file & prints err message upon failure
 * @file_d: file descriptor to read from
 * @buffer: buffer to write to
 * @count_bytes: number of bytes to read
 */

void read_f(int file_d, char *buffer, size_t count_bytes)
{
	if (read(file_d, buffer, count_bytes) != -1)
		return;
	write(STDERR_FILENO, "Error: Can't read from file\n", 28);
	close_fd(file_d);
	exit(98);
}

/**
 * elf_magic - funct that prints ELF magic
 * @buff: the ELF header
 */

void elf_magic(const unsigned char *buff)
{
	unsigned int a;

	if (strn_comp((const char *) buff, ELFMAG, 4))
	{
		write(STDERR_FILENO, "Error: Not an ELF file\n", 23);
		exit(98);
	}

	printf("ELF Header:\n  Magic:   ");

	for (a = 0; a < 16; ++a)
		printf("%02x%c", buff[a], a < 15 ? ' ' : '\n');
}

/**
 * elf_class - funct that prints ELF class
 * @buff: the ELF header
 *
 * Return: returns bit mode (32 or 64)
 */

size_t elf_class(const unsigned char *buff)
{
	printf("  %-34s ", "Class:");

	if (buff[EI_CLASS] == ELFCLASS64)
	{
		printf("ELF64\n");
		return (64);
	}
	if (buff[EI_CLASS] == ELFCLASS32)
	{
		printf("ELF32\n");
		return (32);
	}
	printf("<unknown: %x>\n", buff[EI_CLASS]);
	return (32);
}

/**
 * elf_data - this funct prints ELF data
 * @buff: ELF header
 *
 * Return: returns 1 if big endian, otherwise 0
 */

int elf_data(const unsigned char *buff)
{
	printf("  %-34s ", "Data:");

	if (buff[EI_DATA] == ELFDATA2MSB)
	{
		printf("2's complement, big endian\n");
		return (1);
	}
	if (buff[EI_DATA] == ELFDATA2LSB)
	{
		printf("2's complement, little endian\n");
		return (0);
	}
	printf("Invalid data encoding\n");
	return (0);
}

/**
 * elf_vers -funct that prints ELF version
 * @buff: ELF header
 */

void elf_vers(const unsigned char *buff)
{
	printf("  %-34s %u", "Version:", buff[EI_VERSION]);

	if (buff[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * elf_osabi - funct that prinst ELF OS/ABI
 * @buff: ELF header
 */

void elf_osabi(const unsigned char *buff)
{
	const char *os_table[19] = {
		"UNIX - System V",
		"UNIX - HP-UX",
		"UNIX - NetBSD",
		"UNIX - GNU",
		"<unknown: 4>",
		"<unknown: 5>",
		"UNIX - Solaris",
		"UNIX - AIX",
		"UNIX - IRIX",
		"UNIX - FreeBSD",
		"UNIX - Tru64",
		"Novell - Modesto",
		"UNIX - OpenBSD",
		"VMS - OpenVMS",
		"HP - Non-Stop Kernel",
		"AROS",
		"FenixOS",
		"Nuxi CloudABI",
		"Stratus Technologies OpenVOS"
	};

	printf("  %-34s ", "OS/ABI:");

	if (buff[EI_OSABI] < 19)
		printf("%s\n", os_table[(unsigned int) buff[EI_OSABI]]);
	else
		printf("<unknown: %x>\n", buff[EI_OSABI]);
}

/**
 * elf_abivers - prints the ELF ABI version
 * @buff: ELF header
 */

void elf_abivers(const unsigned char *buff)
{
	printf("  %-34s %u\n", "ABI Version:", buff[EI_ABIVERSION]);
}

/**
 * elf_type - print ELF type
 * @buff: the ELF header
 * @big_endian: endianness (big endian if non-zero)
 */

void elf_type(const unsigned char *buff, int big_endian)
{
	char *type_table[5] = {
		"NONE (No file type)",
		"REL (Relocatable file)",
		"EXEC (Executable file)",
		"DYN (Shared object file)",
		"CORE (Core file)"
	};
	unsigned int type_t;

	printf("  %-34s ", "Type:");

	if (big_endian)
		type_t = 0x100 * buff[16] + buff[17];
	else
		type_t = 0x100 * buff[17] + buff[16];

	if (type_t < 5)
		printf("%s\n", type_table[type_t]);
	else if (type_t >= ET_LOOS && type_t <= ET_HIOS)
		printf("OS Specific: (%4x)\n", type_t);
	else if (type_t >= ET_LOPROC && type_t <= ET_HIPROC)
		printf("Processor Specific: (%4x)\n", type_t);
	else
		printf("<unknown: %x>\n", type_t);
}

/**
 * elf_entry - prints the entry point address
 * @buff: string containing the entry point address
 * @bit_mode: bit mode (32 or 64)
 * @big_endian: endianness (big endian if non-zero)
 */

void elf_entry(const unsigned char *buff, size_t bit_mode, int big_endian)
{
	int addr_size = bit_mode / 8;

	printf("  %-34s 0x", "Entry point address:");

	if (big_endian)
	{
		while (addr_size && !*(buff))
			--addr_size, ++buff;

		printf("%x", *buff & 0xff);

		while (--addr_size > 0)
			printf("%02x", *(++buff) & 0xff);
	}
	else
	{
		buff += addr_size;

		while (addr_size && !*(--buff))
			--addr_size;

		printf("%x", *buff & 0xff);

		while (--addr_size > 0)
			printf("%02x", *(--buff) & 0xff);
	}

	printf("\n");
}

/**
 * main - funct to copy file's contents to another file
 * @argc: the arg count
 * @argv: the arg values
 *
 * Return: Always returns 0
 */
int main(int argc, const char *argv[])
{
	unsigned char buff[18];
	unsigned int bit_mode;
	int big_endian;
	int file_d;

	if (argc != 2)
	{
		write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
		exit(98);
	}

	file_d = open(argv[1], O_RDONLY);
	if (file_d == -1)
	{
		write(STDERR_FILENO, "Error: Can't read from file\n", 28);
		exit(98);
	}

	read_f(file_d, (char *) buff, 18);

	elf_magic(buff);
	bit_mode = elf_class(buff);
	big_endian = elf_data(buff);
	elf_vers(buff);
	elf_osabi(buff);
	elf_abivers(buff);
	elf_type(buff, big_endian);

	lseek(file_d, 24, SEEK_SET);
	read_f(file_d, (char *) buff, bit_mode / 8);

	elf_entry(buff, bit_mode, big_endian);

	close_fd(file_d);

	return (0);
}

