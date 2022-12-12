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
