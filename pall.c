#include "monty.h"
/**
 * f_pall - prints the stack element in LIFO
 * @head: stack head ptr
 * @counter: line_number to be processed
 * Return: no return
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *p;
	(void)counter;

	p = *head;
	if (p == NULL)
		return;
	while (p)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
}
