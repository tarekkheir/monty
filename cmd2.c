#include "monty.h"

/**
 *add - adds the top two elements of the stack
 *@head: stack
 *@n: line
 */
void add(stack_t **head, unsigned int n)
{
	stack_t *tmp = *head;
	int i = 0;

	while (*head)
	{
		i++;
		*head = (*head)->next;
	}

	if (i < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", n);
		exit(EXIT_FAILURE);
	}

	*head = tmp;
	tmp->next->n += tmp->n;
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	free(tmp);
}
