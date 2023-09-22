#include "monty.h"
/**
 * f_queue - prints the top element
 *The top of the stack becomes the front of the queue
 * @head: stack head ptr
 * @counter: line_number to be processed
 * Return: no return
 */
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail stack
 *The front of the queue becomes the top of the stack
 * @n: new_value
 * @head: ptr to the stack head
 * Return: no return
 */
void addqueue(stack_t **head, int n)
{
	stack_t *node_new, *current;

	current = *head;
	node_new = malloc(sizeof(stack_t));
	if (node_new == NULL)
	{
		printf("Error\n");
	}
	node_new->n = n;
	node_new->next = NULL;
	if (current)
	{
		while (current->next)
			current = current->next;
	}
	if (!current)
	{
		*head = node_new;
		node_new->prev = NULL;
	}
	else
	{
		current->next = node_new;
		node_new->prev = current;
	}
}
