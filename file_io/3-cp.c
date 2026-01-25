#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 1024

/**
 * main - copies the content of a file to another file
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success, exits on failure
 */


void print_usage(void)
{
	dprintf(2, "Usage: cp file_from file_to\n");
	exit(97);
}

void error_read(char *file)
{
	dprintf(2, "Error: Can't read from file %s\n", file);
	exit(98);
}

void error_write(char *file)
{
	dprintf(2, "Error: Can't write to %s\n", file);
	exit(99);
}

void error_close(int fd)
{
	dprintf(2, "Error: Can't close fd %d\n", fd);
	exit(100);
}

int copy_file(char *from, char *to)
{
	int fd_from, fd_to;
	ssize_t r, w;
	char buffer[BUF_SIZE];

	fd_from = open(from, O_RDONLY);
	if (fd_from == -1)
		error_read(from);

	fd_to = open(to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		error_write(to);

	while ((r = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w != r)
			error_write(to);
	}

	if (r == -1)
		error_read(from);

	if (close(fd_from) == -1)
		error_close(fd_from);

	if (close(fd_to) == -1)
		error_close(fd_to);

	return (1);
}

int main(int ac, char **av)
{
	if (ac != 3)
		print_usage();

	copy_file(av[1], av[2]);

	return (0);
}
