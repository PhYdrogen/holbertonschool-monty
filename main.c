#include "monty.h"

/**
 * coupage - fonction qui va permettre d'avoir le premier mot
 * @buffer: la ligne
 * Return: le premier mot
 */
char *coupage(char *buffer)
{
	char *ticket = NULL;

	ticket = strtok(buffer, " ");
	return (ticket);
}
/**
 * main - entry point
 * @ac: nm d'arg
 * @av: tableau d'arg
 * Return: 0 si pas d'err
 */
int main(int ac, char **av)
{
	instruction_t liste[] = {
		{"push", push},
		{"pop", pop},
		{0, NULL}
	};
	FILE *fd = 0;
	size_t nb = 0, lu = 0;
	char *buffer = 0;

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		printf("Error: Can't open file %s", av[1]);
		exit(EXIT_FAILURE);
	}
	;
	while ((lu = getline(&buffer, &nb, fd)) != (size_t) -1)
	{
		printf("Retrieved line of length %zu :\n", lu);
		printf("%s", buffer);
		for (j = 0; liste[j].opcode; j++)
		{
			if(
		}
	}
	free(buffer);
	fclose(fd);
	return (0);
}
