#include "monty.h"
/**
  * main - The monty script interpreter
  * @argc: Argument count
  * @argv: Arguments array
  * Return: 0 when succesful
  */
int main(int argc, char *argv[])
{
	FILE *fp;

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	/* Open the file */
	fp = fopen(argv[1], "r");
	/* Confirm the file has opened succesfully */
	if (fp == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	
	get_cmd(fp);
	fclose(fp);
	return (0);

}
/**
  * get_cmd - gets the command for each opcode
  * fp: opened file
  * Return: nothing
  */
void get_cmd(FILE *fp)
{
	size_t len = 0;
	char *line = NULL, **arr;
	stack_t *stack = NULL;
	void (*f)(stack_t **stack, unsigned int line_number);
	unsigned int line_number = 1;
	int length = 0;

	/* Read the file one line at a time */
	while ((length = getline(&line, &len, fp)) != -1)
	{
		if (empty_line(line))
			continue;
		if (line[length - 1] == '\n')
			line[length - 1] = '\0';
		/* array containing the opcode and data */
		arr = tokenize(line);
		/* Get opcode corresponding function */
		f = get_op_func(arr[0]);
		if (f == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
					line_number, arr[0]);
			exit(EXIT_FAILURE);
		}
		/* Store the data */
		if (arr[1])
			push_value = arr[1];
		/* Execute Function */
		f(&stack, line_number);
		line_number++;
	}
	free(line), free_stack(stack);
}
/**
  * empty_line - checks for an empty line
  * @s: string to check
  * Return: success
  */
int empty_line(const char *s)
{
	while(*s != '\0')
	{
		if (!isspace((const char)*s))
			return (0);
		s++;
	}
	return (1);
}

