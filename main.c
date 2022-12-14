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

	instruction_t liste[] = {{"push", push}, {"pop", pop},
		{"swap", swap},	{"pall", print_all}, {"pint", print_int},
		{"add", adding}, {"nop", nonmerci}, {"sub", sub}, {0, NULL}
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
		if (buffer[0] == '\n')
		{
			ligne++;
			continue;
		}
		coupage(buffer, mot);
		if (**mot == 32)
		{
			ligne++;
			continue;
		}
		for (j = 0; liste[j].opcode != NULL; j++)
		{
			res = strncmp(mot[0], liste[j].opcode, strlen(mot[0]));
			if (res == 0)
			{

				if (!strcmp(mot[0], "push") && (_isnumber(mot[1]) == 1 || mot[1] == NULL))
				{
					fprintf(stderr, "L%i: usage: push integer\n", ligne);
					exit(EXIT_FAILURE);
				}
				liste[j].f(&head, ligne);
				break;
			}
		}
		if (liste[j].opcode == 0)
		{
			fprintf(stderr, "L%i: unknown instruction %s\n", ligne, mot[0]);
			exit(EXIT_FAILURE);
		}
		ligne++;
	}
	free(buffer);
	_free(head);
	fclose(fd);
	return (0);
}
