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
		{0, NULL}
	};

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
				printf("HEEE\n");
				liste[j].f(&head, atoi(mot[1]));
				break;
			}
		}
	}
	free(buffer);
	fclose(fd);
	return (0);
}
