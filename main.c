#include "monty.h"

int main(int ac, char **av)
{
	stack_t *stack = NULL;
	unsigned int n = 0;
	char *str = NULL;
	char chaine[2048];
	char cmd[2][1024];
	FILE *file;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen("av[1]", "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(chaine, 2048, file) != NULL)
	{
		n++;
		str = strtok(chaine, "\n\t\r ");
		if (str == NULL || str == '\0')
			continue;
		strcpy(cmd[0], str);
		str = strtok(NULL, "\n\t\r ");
		strcpy(cmd[1], str);

		if (strcmp(cmd[0], "push") == 0)
		{
			if (cmd[1] != NULL)
				push(&stack, cmd[1], n);
			else
				fprintf(stderr, "Usage: push %u\n", n);
		}
		else
			exec_f(&stack, cmd[0], n);

	}

	free_stack(stack);
	return (0);
}

/**
 *add_node - add node in the linked list
 *@head: pointer of list
 *@n: string
 *Return: value
 */
stack_t *add_node(stack_t **head, const int n)
{
	stack_t *cell = malloc(sizeof(cell));

	if (cell == NULL)
		return (NULL);

	cell->n = n;
	cell->prev = NULL;

	if (*head == NULL)
		cell->next = NULL;
	else
	{
		cell->next = *head;
		(*head)->prev = cell;
	}
	*head = cell;
	return (*head);
}

void push(stack_t **head, char *cmd, unsigned int n)
{
	unsigned int i = 0;

	while (i < strlen(cmd))
	{
		if (isdigit(cmd[i]) == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", n);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	add_node(head, atoi(cmd));
}

void exec_f(stack_t **head, char *cmd, unsigned int n)
{
	int i = 0;
	instruction_t inst[] = {
		{"pall", pall}, {NULL, NULL}
	};

	while (inst[i].opcode)
	{
		if (strcmp(cmd, inst[i].opcode) == 0)
		{
			inst[i].f(head, n);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", n, cmd);
	exit(EXIT_FAILURE);
}

/**
 *free_dlistint - free the list allocation
 *@head: list
 *Return: value
 */
void free_stack(stack_t *head)
{
	stack_t *tmp = NULL;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

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
