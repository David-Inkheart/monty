#include "monty.h"

/**
  * get_op_func - Gets the opcode's corresponding function
  * @s: The opcode to get a function for
  *
  * Return: A pointer to the corresponding function
  */

void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t opcodes[] = {
				{"push", push},
				{"pall", pall},
				{"pint", pint},
				{"pop", pop},
				{"add", add},
				{"swap", swap},
				{"nop", nop},
				{"sub", sub},
				{"div", divs},
				{"mul", mul},
				{"mod", mod},
				{NULL, NULL}
	};

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcodes[i].opcode, s) == 0)
		{
			return (opcodes[i].f);
		}
		i++;
	}

	return (NULL);
}

#include "monty.h"

/**
  * tokenize - Tokenizes a string to return an array of words
  * @s: The string to be tokenized
  *
  * Return: An array of the words
  */

char **tokenize(char *s)
{
	char *token;
	int i = 0;
	static char *arr[10] = {NULL};

	token = strtok(s, " ");
	while (token != NULL)
	{
		arr[i++] = token;
		token = strtok(NULL, " ");
	}

	return (arr);
}
