#include "monty.h"
/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: Stack to print the element from
 * @line_number: The line number of the opcode currently being executed
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int c;
	(void) line_number;

	while (tmp != NULL)
	{
		c = tmp->n;
		if (c < 1 || c > 127)
			break;
		printf("%c", c);
		tmp = tmp->next;
	}
	printf("\n");
}
