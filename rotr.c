#include "monty.h"
/**
 *f_rotr- rotates the stack to the bottom
 *The last element of the stack becomes the top element of the stack
 *@head: stack head ptr
 *@counter: line_number being processed
 *Return: no return
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *dupe;

	dupe = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (dupe->next)
	{
		dupe = dupe->next;
	}
	dupe->next = *head;
	dupe->prev->next = NULL;
	dupe->prev = NULL;
	(*head)->prev = dupe;
	(*head) = dupe;
}
