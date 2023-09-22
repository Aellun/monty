#include "monty.h"
/**
 * free_stack - funct that frees a doubly linked list
 * @head: ptr to the head of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *current;

	current = head;
	while (head)
	{
		current = head->next;
		free(head);
		head = current;
	}
}
