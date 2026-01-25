#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void print_usage(void);
void error_read(char *file);
void error_write(char *file);
void error_close(int fd);

/**
 * main - copies content of a file to another file
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_from, fd_to, r, w;
	char buffer[1024];

	if (ac != 3)
		print_usage();

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		error_read(av[1]);

	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		error_write(av[2]);

	while ((r = read(fd_from, buffer, 1024)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w == -1 || w != r)
			error_write(av[2]);
	}

	if (r == -1)
		error_read(av[1]);

	if (close(fd_from) == -1)
		error_close(fd_from);

	if (close(fd_to) == -1)
		error_close(fd_to);

	return (0);
}

/**
 * print_usage - prints usage error
 */
void print_usage(void)
{
	dprintf(1, "Usage: cp file_from file_to\n");
	exit(97);
}

/**
 * error_read - prints read error
 * @file: filename
 */
void error_read(char *file)
{
	dprintf(1, "Error: Can't read from file %s\n", file);
	exit(98);
}

/**
 * error_write - prints write error
 * @file: filename
 */
void error_write(char *file)
{
	dprintf(1, "Error: Can't write to %s\n", file);
	exit(99);
}

/**
 * error_close - prints close error
 * @fd: file descriptor
 */
void error_close(int fd)
{
	dprintf(1, "Error: Can't close fd %d\n", fd);
	exit(100);
}
