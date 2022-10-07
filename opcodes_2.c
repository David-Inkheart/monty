#include "monty.h"

/**
  * add - Adds the top two elements of the stack
  * @stack: The adress of the stack
  * @line_number: The line number of the command being run
  */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sum = 0;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (temp->n) + (temp->next->n);
	pop(stack, line_number);
	(*stack)->n = sum;
}

/**
  * nop - Opcode that does nothing
  * @stack: The adress of the stack
  * @line_number: The line number of opcode currently being executed
  */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
  * sub - Subtracts the top element of the stack from the second top element
  * @stack: Address of stack whose top elements need to be subtracted
  * @line_number: Line number of opcode currently being executed
  */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int result = 0;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (temp->next->n) - (temp->n);
	pop(stack, line_number);
	(*stack)->n = result;
}

/**
 * rotr - rotates the last element of the stack to the top
 * @stack: head of the stack
 * @line_number: line number
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp2;

	(void) line_number;
	temp = (*stack);
	if (temp == NULL)
		return;
	temp2 = temp;
	if (temp->next == NULL)
		;
	else
	{
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->prev->next = NULL;
		temp2->prev = NULL;
		temp2->next = temp;
		temp->prev = temp2;
		(*stack) = temp2;
	}
}
