#include "monty.h"
/**
 * f_swap - func to swap the two stack element
 * @head: ptr to stack head
 * @counter: line_number to be processed
 * Return: no return
 */
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *p;
	int len = 0, aux;

	p = *head;
	while (p)
	{
		p = p->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	p = *head;
	aux = p->n;
	p->n = p->next->n;
	p->next->n = aux;
}
