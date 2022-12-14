#include "monty.h"
/**
 * sub - substracts the top element of the stack from the second top element
 * of stack
 * @stack: linked list
 * @line_number: line number
 *
 * Return: Nothing.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int sub;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	sub = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = sub;
}	
