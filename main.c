#include "monty.h"

/**
 *main - execute command from the monty file
 *@ac: number of arguments
 *@av: arguments
 *Return: 0
 */
int main(int ac, char **av)
{
	stack_t *stack = NULL;
	unsigned int n = 0;
	char *str = NULL;
	char chaine[512];
	char cmd[2][512];
	FILE *file;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(chaine, 512, file) != NULL)
	{
		n++;
		str = strtok(chaine, "\n\t\r ");
		if (str == NULL || str == '\0')
			continue;
		strcpy(cmd[0], str);
		if (strcmp(cmd[0], "push") == 0)
		{
			str = strtok(NULL, "\n\t\r ");
			strcpy(cmd[1], str);
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


/**
 *exec_f - execute function than the main send
 *@head: stack
 *@cmd: string
 *@n: line
 */
void exec_f(stack_t **head, char *cmd, unsigned int n)
{
	int i = 0;
	instruction_t inst[] = {
		{"pall", pall}, {"pint", pint}, {"pop", pop}, {"swap", swap},
		{"add", add}, {NULL, NULL}
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
 *free_stack - free the list allocation
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
