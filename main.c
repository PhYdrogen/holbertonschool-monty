#include "monty.h"
#include <sys/stat.h>
#include <fcntl.h>
/**
 * main - entry point
 * @ac: nm d'arg
 * @av: tableau d'arg
 * Return: 0 si pas d'err
 */
int main(int ac, char **av)
{
	int fd = 0;

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't open file %s", av[1]);
		exit(EXIT_FAILURE);
	}
}
