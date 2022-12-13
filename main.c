#include "monty.h"
#define OP 5

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
	int ligne = 1, j = 0, res = 0;
	stack_t *head = NULL;

	instruction_t liste[] = {
		{0, NULL},
		{"push", push},
		{"pop", pop},
		{"pall", print_all},
		{"pint", print_int},
		{NULL, NULL}
	};

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((lu = getline(&buffer, &nb, fd)) != (size_t) -1)
	{
		if (*buffer == '\n')
			return (1); /* l'utilisateur doit mettre un truc */

		coupage(buffer, mot);
		if (mot == NULL)
		{
			return (1);
		}
		for (j = 1; j < OP; j++)
		{
			if ((j + 1) == OP)
			{
				fprintf(stderr, "L%i: unknown instruction %s", ligne, mot[0]);
				exit(EXIT_FAILURE);
			}
			printf("-- %s - %s --\n", mot[0], liste[j].opcode);
			res = strncmp(mot[0], liste[j].opcode, strlen(mot[0]));
			if (res == 0)
			{
				liste[j].f(&head, ligne);
				break;
			}
		}
		ligne++;
	}
	free(buffer);
	fclose(fd);
	return (0);
}
