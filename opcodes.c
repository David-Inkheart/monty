#include "monty.h"

/**
  * push - Adds an element to the top of a stack
  * @stack: Adress of the stack where the element is to be added
  * @line_number: The line number of the opcode currently being executed
  */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	int i = 0;

	for (i = 0; push_value[i] != '\0'; i++)
	{
		if (isdigit(push_value[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n",
					line_number);
			exit(EXIT_FAILURE);
		}
	}

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(push_value);
	new_node->prev = NULL;
	new_node->next = NULL;

	/* In case head is an empty list */
	if (*stack == NULL)
	{
		*stack = new_node;
	}
	/* If head is not an empty list */
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}

/**
  * pall - Function that prints all the values of the stack
  * @stack: The adress of the stack to print
  * @line_number: The line number of the opcode being executed
  */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int counter = 0;
	(void) line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		counter++;
		temp = temp->next;
	}

}

/**
  * pint - Prints the element at the top of the stack
  * @stack: Stack to print the element from
  * @line_number: The line number of the opcode currently being executed
  */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", temp->n);
}

/**
  * pop - Removes the element at the top of the stack
  * @stack: The stack whose top element is to be removed
  * @line_number: The line number of the opcode currently being executed
  */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (*stack == NULL)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}

	if (temp->next == NULL)
	{
		free(temp);
		*stack = NULL;
	}
	else
	{
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
}

/**
  * swap - Swaps the top two elements of a stack
  * @stack: Address of stack to be swaped
  * @line_number: Line number of opcode being executed
  */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int data;

	/* Make sure node contains more than 1 element */
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* Swap the data in the nodes */
	data = temp->n;
	temp->n = temp->next->n;
	temp->next->n = data;
}
