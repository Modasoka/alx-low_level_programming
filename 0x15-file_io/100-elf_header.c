#include "main.h"

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
size_t elf_class(const unsigned char *buffer)
{
	printf("  %-34s ", "Class:");

	if (buffer[EI_CLASS] == ELFCLASS64)
	{
		printf("ELF64\n");
		return (64);
	}
	if (buffer[EI_CLASS] == ELFCLASS32)
	{
		printf("ELF32\n");
		return (32);
	}
	printf("<unknown: %x>\n", buffer[EI_CLASS]);
	return (32);
}

/**
 * elf_data - print ELF data
 * @buffer: header ELF
 * Return: returns 1 if big endian, else returns 0
 */
int elf_data(const unsigned char *buffer)
{
	printf("  %-34s ", "Data:");

	if (buffer[EI_DATA] == ELFDATA2MSB)
	{
		printf("2's complement, big endian\n");
		return (1);
	}
	if (buffer[EI_DATA] == ELFDATA2LSB)
	{
		printf("2's complement, little endian\n");
		return (0);
	}
	printf("Invalid data encoding\n");
	return (0);
}

/**
 * elf_version - this funct prints the ELF version
 * @buffer: header ELF
 */
void elf_version(const unsigned char *buffer)
{
	printf("  %-34s %u", "Version:", buffer[EI_VERSION]);
	
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
        _read(fd, (char *) bu	if (buffer[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * elf_osabi - funct prints ELF OS/ABI
 * @buffer: header ELF
 */
void elf_osabi(const unsigned char *buffer)
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

	if (buffer[EI_OSABI] < 19)
		printf("%s\n", os_table[(unsigned int) buffer[EI_OSABI]]);
	else
		printf("<unknown: %x>\n", buffer[EI_OSABI]);
}

/**
 * elf_abivers - funct prints ELF ABI version
 * @buffer: header ELF
 */
void elf_abivers(const unsigned char *buffer)
{
	printf("  %-34s %u\n", "ABI Version:", buffer[EI_ABIVERSION]);
}

/**
 * elf_type - funct prints the ELF type
 * @buffer: header ELF
 * @big_endian: level of endiannes ( if non-zero, big endian)
 */
void elf_type(const unsigned char *buffer, int big_endian)
{
	char *type_table[5] = {
		"NONE (No file type)",
		"REL (Relocatable file)",
		"EXEC (Executable file)",
		"DYN (Shared object file)",
		"CORE (Core file)"
	};
	unsigned int type;

	printf("  %-34s ", "Type:");

	if (big_endian)
		type = 0x100 * buffer[16] + buffer[17];
	else
		type = 0x100 * buffer[17] + buffer[16];

	if (type < 5)
		printf("%s\n", type_table[type]);
	else if (type >= ET_LOOS && type <= ET_HIOS)
		printf("OS Specific: (%4x)\n", type);
	else if (type >= ET_LOPROC && type <= ET_HIPROC)
		printf("Processor Specific: (%4x)\n", type);
	else
		printf("<unknown: %x>\n", type);
}

/**
 * elf_entry - funct that prints the entry point address
 * @buffer: a str that contains entry point address
 * @bit_mode: the bit mode - either 32/64
 * @big_endian: level of endiannes
 */
void elf_entry(const unsigned char *buffer, size_t bit_mode, int big_endian)
{
	int address_size = bit_mode / 8;

	printf("  %-34s 0x", "Entry point address:");

	if (big_endian)
	{
		while (address_size && !*(buffer))
			--address_size, ++buffer;

		printf("%x", *buffer & 0xff);

		while (--address_size > 0)
			printf("%02x", *(++buffer) & 0xff);
	}
	else
	{
		buffer += address_size;

		while (address_size && !*(--buffer))
			--address_size;

		printf("%x", *buffer & 0xff);

		while (--address_size > 0)
			printf("%02x", *(--buffer) & 0xff);
	}

	printf("\n");
}

