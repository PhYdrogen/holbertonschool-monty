#include "monty.h"
#define OP 4
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
	char *buffer = 0, *mot[3];
	int j = 0, res = 0;
	stack_t *head = NULL;

	instruction_t liste[] = {
		{"push", push},
		{"pop", pop},
		{"pall", print_all},
		{"pint", print_int},
		{0, NULL}
	};

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr ,"Error: Can't open file %s", av[1]);
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
		for (j = 0; j < OP; j++)
		{
			/*
			 * si j == (OP - 1) alors err il doit avoir une
			 * instruction
			 */
			res = strncmp(mot[0], liste[j].opcode, strlen(mot[0]));
			if (res == 0)
			{
				if (mot[1] != NULL)
				{
					liste[j].f(&head, atoi(mot[1]));
					break;
				}
				else
				{
					liste[j].f(&head, 0);
					break;
				}
			}
			/*
			 * si l'utilisateur se trompe de cmd ne pas
			 * exec et direct sortir
			 */
		}
	}
	free(buffer);
	fclose(fd);
	return (0);
}
