#include "monty.h"
/**
 * f_div - division of top two elements of the stack.
 * @head: ptr to the stack head
 * @counter: line_number to be processed
 * Return: no return
 */
void f_div(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	p = *head;
	if (p->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = p->next->n / p->n;
	p->next->n = current;
	*head = p->next;
	free(p);
}
