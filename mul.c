#include "monty.h"
/**
 * f_mul - multiplication of the top two elements of the stack.
 * @head: ptr to stack head
 * @counter: line_number to be processed
 * Return: no return
 */
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *p;
	int len = 0, current;

	p = *head;
	while (p)
	{
		p = p->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	p = *head;
	current = p->next->n * p->n;
	p->next->n = current;
	*head = p->next;
	free(p);
}
