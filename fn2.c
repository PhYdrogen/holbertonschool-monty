#include "monty.h"
/**
 * _isnumber - verif si c'est que des nombres
 * @s: la chaine de char
 * Return: 0 si c'est que des nombres
 */
int _isnumber(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (isdigit(s[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}