#include "monty.h"

/**
 * main - entry point
 * @ac: nm d'arg
 * @av: tableau d'arg
 * Return: 0 si pas d'err
 */
int main(int ac, char **av)
{
	FILE *fd = 0;
	size_t nb = 0, lu = 0;
	char *buffer = 0, *mot[2];
	int j = 0;

	instruction_t liste[] = {
		{"push", push},
		{"pop", pop},
		{"pall", print_all},
		{0, NULL}
	};
	stack_t *head;

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
	while ((lu = getline(&buffer, &nb, fd)) != (size_t) -1)
	{
		printf("Retrieved line of length %zu :\n", lu);
		printf("%s", buffer);
		coupage(buffer, mot);
		for (j = 0; liste[j].opcode != NULL; j++)
		{
			if (strcmp(mot[0], liste[j].opcode))
			{
				liste[j].f(&head, atoi(mot[1]));
			}
		}
	}
	free(buffer);
	fclose(fd);
	return (0);
}
