#include "monty.h"
/**
 *f_sub- Subtracts top element from second element
 *@head: ptr to stack head
 *@counter: line_number being processed
 *Return: no return
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int sub, element_num;

	current = *head;
	for (element_num = 0; current != NULL; element_num++)
		current = current->next;
	if (element_num < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	sub = current->next->n - current->n;
	current->next->n = sub;
	*head = current->next;
	free(current);
}
