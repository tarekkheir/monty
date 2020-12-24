#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



stack_t *add_node(stack_t **head, const int n);
void push(stack_t **head, char *cmd, unsigned int n);
void exec_f(stack_t **head, char *cmd, unsigned int n);
void exec_push(stack_t **head, char *cmd, char *str, unsigned int n);
void free_stack(stack_t *head, FILE *file);
void pall(stack_t **head, unsigned int n);
void pint(stack_t **head, unsigned int n);
void pop(stack_t **head, unsigned int n);
void swap(stack_t **head, unsigned int n);
void add(stack_t **head, unsigned int n);
void sub(stack_t **head, unsigned int n);
void mul(stack_t **head, unsigned int n);
void div_funct(stack_t **head, unsigned int n);
void mod(stack_t **head, unsigned int n);

#endif
