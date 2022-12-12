#include "monty.h"
/**
 * push - adding element to stack
 * @stack: linked list
 * @line_number: line number
 *
 * Return: Nothing.
 */
void push(stack_t **stack, unsigned int line_number)
{
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
	newNode->n = line_number;
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
	printf("work");
	while (stack)
	{
		printf("%i", (*stack)->n);
		if ((*stack)->next != NULL)
			*stack = (*stack)->next;
	}
}
/**
 * coupage - fonction qui va permettre d'avoir le premier mot
 * @buffer: la ligne
 * @mot: les mots qui vont etre stocker
 * Return: le premier mot
 */
char *coupage(char *buffer, char *mot[])
{
	int k;
	char *ticket = NULL;

	ticket = strtok(buffer, " ");
	mot[0] = ticket;
	for (k = 1; ticket != NULL; k++)
	{
		ticket = strtok(NULL, buffer);
		mot[k] = ticket;
	}
	return (ticket);
}
