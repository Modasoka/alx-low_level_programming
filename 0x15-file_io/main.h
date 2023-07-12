#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

ssize_t read_textfile(const char *filename, size_t letters);

#endif