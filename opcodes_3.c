#include "monty.h"


/**
 * divs - Divides the second top element by the top element of the stack
 * @stack: points to top node of the stack
 * @line_number: Current line of the file being executed
 */
void divs(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int div;

	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	div = tmp->next->n / tmp->n;
	pop(stack, line_number);
	(*stack)->n = div;
}

/**
 * mul - Multiplies the second top element with the top element of the stack
 * @stack: points to the top node of the stack
 * @line_number: Line number of the file being executed
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int mul;

	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	mul = tmp->next->n * tmp->n;
	pop(stack, line_number);
	(*stack)->n = mul;
}


/**
 * pchar - Prints the char at the top of the stack
 * @stack: Stack to print the element from
 * @line_number: The line number of the opcode currently being executed
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int c;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;

	c = tmp->n;

	if (c < 0 || c > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", c);
}
