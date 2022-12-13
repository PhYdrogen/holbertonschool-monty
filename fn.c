#include "monty.h"

int n_ext = 0;
/**
 * push - adding element to stack
 * @stack: linked list
 * @line_number: line number
 *
 * Return: Nothing.
 */
void push(stack_t **stack, unsigned int line_number)
{
	while (n_ext)
	if ()
	{
		fprintf(stderr, "L%i: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *newNode = malloc(sizeof(stack_t));

	if (!newNode)
	{
		free(stack);
		exit(EXIT_FAILURE);
		return;
	}

	if (*stack != NULL)
		(*stack)->prev = newNode;
	newNode->prev = NULL;
	newNode->next = *stack;
	newNode->n = n_ext;
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
	stack_t *currentNode = malloc(sizeof(stack_t));

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(stack);
		exit(EXIT_FAILURE);
	}
	*stack = currentNode->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(currentNode);
}
/**
 * print_all - print from the start node
 * @stack: the header
 * @line_number: for the error
 */
void print_all(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	while (stack)
	{
		fprintf(stdout, "%i\n", (*stack)->n);
		if ((*stack)->next != NULL)
		{
			*stack = (*stack)->next;
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

	if (stack == NULL)
	{
		fprintf(stderr, "L<%u> : can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%i\n", (*stack)->n);

}
/**
 * coupage - fonction qui va permettre d'avoir le premier mot
 * @buffer: la ligne
 * @mot: les mots qui vont être stocker
 * Return: le premier mot
 */
char *coupage(char *buffer, char *mot[])
{
	char *ticket = NULL, *delim = " \r\n";
	int j = 1;

	ticket = strtok(buffer, delim);
	if (ticket == NULL)
		return (0);
	mot[0] = ticket;

	while (ticket != NULL)
	{
		ticket = strtok(NULL, delim);
		if (atoi(ticket) >= 0 && atoi(ticket) <= 9)
			n_ext = atoi(ticket);
		else
			mot[j] = ticket;
		j++;
	}
	mot[j] = NULL;
	return (ticket);
}

int _isnumber(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (isdigit(s[i]) == 0)
			return (0);
	}
	return (1);
}
}
