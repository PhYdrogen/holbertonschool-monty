#include "monty.h"

int n_ext;

/**
 * push - adding element to stack
 * @stack: linked list
 * @line_number: line number
 *
 * Return: Nothing.
 */
void push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *newNode = NULL;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(stack);
		exit(EXIT_FAILURE);
		return;
	}
	newNode->prev = NULL;
	newNode->next = *stack;
	newNode->n = n_ext;
	if (*stack != NULL)
		(*stack)->prev = newNode;
	*stack = newNode;
}

/**
 * pop - removes first element of stack
 * @stack: linked list
 * @line_number: line number
 *
 * Return: Nothing.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack);

	if (*stack != NULL)
		(*stack)->prev = NULL;

	*stack = (*stack)->next;
	free(tmp);
}
/**
 * print_all - print from the start node
 * @stack: the header
 * @line_number: for the error
 */
void print_all(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *tmp;

	tmp = *stack; /* deplace un ptr temporaire*/

	while (tmp != NULL)
	{
		fprintf(stdout, "%i\n", tmp->n);
		if (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		else
			return;
	}
}
/**
 * print_int - print int in top of stack
 * @stack: the header
 * @line_number: still don't know
 */
void print_int(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%i\n", (*stack)->n);

}
/**
 * coupage - fonction qui va permettre d'avoir le premier mot
 * @buffer: la ligne
 * @mot: le tableau
 * Return: le premier mot
 */
char *coupage(char *buffer, char *mot[])
{
	char *ticket = NULL, *delim = " \t\r\n";

	ticket = strtok(buffer, delim);
	if (ticket == NULL)
		return (0);
	mot[0] = ticket;

	if (strcmp(mot[0], "pall") == 0)
	{
		mot[1] = '\0';
	}
	if (strcmp(mot[0], "push") == 0)
	{
		ticket = strtok(NULL, delim);
		mot[1] = ticket;
	}
	if (ticket != NULL)
		if (_isnumber(ticket) == 0)
			n_ext = atoi(ticket);
	return (ticket);
}
