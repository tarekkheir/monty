#include "monty.h"

/**
 *pall - prints all the values on the stack, starting from the top of the stack
 *@head: stack
 *@n: line
 */
void pall(stack_t **head, unsigned int n)
{
	stack_t *new = *head;

	if (new != NULL)
	{
		while (new)
		{
			fprintf(stdout, "%u\n", new->n);
			new = new->next;
		}
	}
	(void)n;
}

/**
 *push - pushes an element to the stack.
 *@head: stack
 *@n: line
 *@cmd: string
 */
void push(stack_t **head, char *cmd, unsigned int n)
{
	unsigned int i = 0;

	while (i < strlen(cmd))
	{
		if (cmd[i] == '-')
			i++;
		if (isdigit(cmd[i]) == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", n);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	add_node(head, atoi(cmd));
}

/**
 *pint - prints the value at the top of the stack, followed by a new line.
 *@head: stack
 *@n: line
 */
void pint(stack_t **head, unsigned int n)
{
	stack_t *new = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", n);
		exit(EXIT_FAILURE);
	}
	printf("%u\n", new->n);
}

/**
 *pop - removes the top element of the stack.
 *@head: stack
 *@n: line
 */
void pop(stack_t **head, unsigned int n)
{
	stack_t *tmp = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop, stack empty\n", n);
		exit(EXIT_FAILURE);
	}

	tmp = *head;
	*head = (*head)->next;
	if (*head)
		(*head)->prev = NULL;
	free(tmp);
}


/**
 *swap - swaps the top two elements of the stack.
 *@head: stack
 *@n: line
 */
void swap(stack_t **head, unsigned int n)
{
	stack_t *tmp = *head;
	stack_t *new = *head;
	int nb = 0;
	int i = 0;

	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}

	if (i < 2 || *head == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	new = new->next;
	nb = tmp->n;
	tmp->n = new->n;
	new->n = nb;
}
