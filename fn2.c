#include "monty.h"
/**
 * _isnumber - verif si c'est que des nombres
 * @s: la chaine de char
 * Return: 0 si c'est que des nombres
 */
int _isnumber(char *s)
{
	int i;

	if (s == NULL)
		return (1);

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
		{
			continue;
		}
		if (isdigit(s[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * swap - swaps the top two elements of the stack.
 * @stack: linked list
 * @line_number: line number
 *
 * Return: Nothing.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tempNode = NULL;

	int tmp = 0;

	if (*stack == NULL || ((*stack)->next) == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	tempNode = *stack;
	tmp = tempNode->n;
	tempNode->n = tmp;
	tempNode->n = tempNode->next->n;
	tempNode->next->n = tmp;
}
/**
 * _free - libère les noeuds utilisés plus tôt
 * @head: le header
 */
void _free(stack_t *head)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	free(head);
	free(tmp);

}
