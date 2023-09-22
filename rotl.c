#include "monty.h"
/**
 *f_rotl- rotates the stack to the top second bcome first
 *@head: stack head ptr
 *@counter: line_number to be processed
 *Return: no return
 */
void f_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *current;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	current = (*head)->next;
	current->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = current;
}
