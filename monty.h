#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function Prototypes */
void init_stack(stack_t **stack);
void push(stack_t **stack, int value);

int is_empty(stack_t **stack);
void free_stack(stack_t **stack, unsigned int line_number);
void pall_handler(stack_t **stack);
void push_handler(stack_t **stack, char *arg, unsigned int line_number);

int pop(stack_t **stack, unsigned int line_number);
void pint_handler(stack_t **stack, unsigned int line_number);
void pop_handler(stack_t **stack, unsigned int line_number);
void swap_handler(stack_t **stack, unsigned int line_number);
void add_handler(stack_t **stack, unsigned int line_number);
void nop_handler(stack_t **stack, unsigned int line_number);
void sub_handler(stack_t **stack, unsigned int line_number);
void div_handler(stack_t **stack, unsigned int line_number);
void mul_handler(stack_t **stack, unsigned int line_number);
void mod_handler(stack_t **stack, unsigned int line_number);
void pchar_handler(stack_t **stack, unsigned int line_number);
void pstr_handler(stack_t **stack, unsigned int line_number);
void rotl_handler(stack_t **stack, unsigned int line_number);
void rotr_handler(stack_t **stack, unsigned int line_number);

/**
 * struct InstructionHandler - Represents an opcode
 * and its corresponding function.
 * @name: The opcode (instruction name) as a string.
 * @handler: Pointer to the function that implements the opcode's behavior.
 *
 */

typedef struct InstructionHandler
{
	const char *name;
	void (*handler)(stack_t **stack, unsigned int line_number);
} InstructionHandler;

#endif /* MONTY_H */

