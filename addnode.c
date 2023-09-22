#include "monty.h"
/**
 * addnode - adds node to the head stack element
 * @head: ptr to the head of the stack
 * @n: new_value to be processed
 * Return: no return
 */
void addnode(stack_t **head, int n)
{

	stack_t *node_new, *current;

	current = *head;
	node_new = malloc(sizeof(stack_t));
	if (node_new == NULL)
	{ printf("Error\n");
		exit(0); }
	if (current)
		current->prev = node_new;
	node_new->n = n;
	node_new->next = *head;
	node_new->prev = NULL;
	*head = node_new;
}
