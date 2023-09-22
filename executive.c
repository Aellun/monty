#include "monty.h"
/**
 * execute - executes the opcode
 * @stack: ptr to head linked list stack
 * @counter: line_counterto be processed
 * @file: ptr to monty file
 * @content:content from line to be processed
 * Return: no return
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{"sub", f_sub},
		{"div", f_div},
		{"mul", f_mul},
		{"mod", f_mod},
		{"pchar", f_pchar},
		{"pstr", f_pstr},
		{"rotl", f_rotl},
		{"rotr", f_rotr},
		{"queue", f_queue},
		{"stack", f_stack},
		{NULL, NULL}
	};
	unsigned int n = 0;
	char *ex;

	ex = strtok(content, " \n\t");
	if (ex && ex[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[n].opcode && ex)
	{
		if (strcmp(ex, opst[n].opcode) == 0)
		{
			opst[n].f(stack, counter);
			return (0);
		}
		n++;
	}
	if (ex && opst[n].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, ex);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
