#include "monty.h"

/**
 * check_comment - Checks if line is comment and changes it accordingly
 * @arr: pointer to token string
 * Return: 1 if comment, 0 if not a comment
 */

int check_comment(char **arr)
{
	if (*arr[0] == '#')
	{
		*arr[0] = '\0';
		return (1);
	}
	return (0);
}

/**
 * mod - divides second top element by top element and gets remainder
 * @stack: head to the stack
 * @line_number: line number where the opcode is located
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack);
	temp2 = temp->next;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp->n = temp2->n % temp->n;
	temp->next = temp2->next;
	if (temp2->next != NULL)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}

/**
 * stack - sets the format of the data to a stack
 * @stack: head of the stack
 * @line_number: line number of the opcode
 */


/** void stack(stack_t **stack, unsigned int line_number)
* {
*	(void) stack;
*	(void) line_number;
*}
*/

/**
 * queue - sets the format of the data to a queue
 * @stack: head of the stack
 * @line_number: line number of the opcode
 */

/* void queue(stack_t **stack, unsigned int line_number) */
/*{ */
/*	(void) stack; */
/*	(void) line_number; */
/* } */
