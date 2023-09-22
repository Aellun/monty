#include "monty.h"
/**
 * f_pstr - prints the string starting at the top of the stack,
 * @head: stack head ptr
 * @counter: line_number to be processed
 * Return: no return
 */
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *p;
	(void)counter;

	p = *head;
	while (p)
	{
		if (p->n > 127 || p->n <= 0)
		{
			break;
		}
		printf("%c", p->n);
		p = p->next;
	}
	printf("\n");
}
