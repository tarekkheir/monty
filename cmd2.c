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

/**
 *sub - sub the top two elements of the stack
 *@head: stack
 *@n: line
 */
void sub(stack_t **head, unsigned int n)
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
		fprintf(stderr, "L%u: can't sub, stack too short\n", n);
		exit(EXIT_FAILURE);
	}

	*head = tmp;
	tmp->next->n -= tmp->n;
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	free(tmp);
}


/**
 *mul - mul the top two elements of the stack
 *@head: stack
 *@n: line
 */
void mul(stack_t **head, unsigned int n)
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
		fprintf(stderr, "L%u: can't mul, stack too short\n", n);
		exit(EXIT_FAILURE);
	}

	*head = tmp;
	tmp->next->n *= tmp->n;
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	free(tmp);
}

/**
 *div_funct - div the top two elements of the stack
 *@head: stack
 *@n: line
 */
void div_funct(stack_t **head, unsigned int n)
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
		fprintf(stderr, "L%u: can't div, stack too short\n", n);
		exit(EXIT_FAILURE);
	}

	*head = tmp;
	tmp->next->n /= tmp->n;
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	free(tmp);
}

/**
 *mod - mod the top two elements of the stack
 *@head: stack
 *@n: line
 */
void mod(stack_t **head, unsigned int n)
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
		fprintf(stderr, "L%u: can't mod, stack too short\n", n);
		exit(EXIT_FAILURE);
	}

	*head = tmp;
	if (tmp->n != 0)
		tmp->next->n %= tmp->n;
	else
	{
		fprintf(stderr, "L%u: division by zero\n", n);
		exit(EXIT_FAILURE);
	}
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	free(tmp);
}
