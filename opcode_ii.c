#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * pall_handler - Prints all elements of the stack.
 * @stack: Pointer to the top of the stack.
 *
 * This function prints all the elements of the stack,
 * starting from the top.
 */

void pall_handler(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * sub_handler - Subtracts the top element from the second
 * top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Current line number in the Monty bytecode file.
 *
 */

void sub_handler(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * div_handler - Divides second top element by top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Current line number in the Monty bytecode file.
 *
 */

void div_handler(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}

