#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * push_handler - Pushes an element onto the stack.
 * @stack: Pointer to the top of the stack.
 * @arg: Argument to be pushed onto the stack.
 * @line_number: Current line number in the Monty bytecode file.
 *
 * This function pushes the given argument onto the stack.
 */

void push_handler(stack_t **stack, char *arg, unsigned int line_number)
{
	int value = 0;
	char *endptr;

	if (arg == NULL || (!isdigit(*arg) && *arg != '-' && *arg != '+'))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = strtol(arg, &endptr, 10);
	if (*endptr != '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	push(stack, value);
}

/**
 * pint_handler - Prints the value at the top of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Current line number in the Monty bytecode file.
 *
 * This function prints the value at the top of the stack.
 */

void pint_handler(stack_t **stack, unsigned int line_number)
{
	if (is_empty(stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop_handler - Removes the top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Current line number in the Monty bytecode file.
 *
 * This function removes the top element of the stack.
 */

void pop_handler(stack_t **stack, unsigned int line_number)
{
	if (is_empty(stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	pop(stack, line_number);
}

/**
 * swap_handler - Swaps the top two elements of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Current line number in the Monty bytecode file.
 *
 * This function swaps the top two elements of the stack.
 */

void swap_handler(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (is_empty(stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * add_handler - Adds the top two elements of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Current line number in the Monty bytecode file.
 *
 * This function adds the top two elements of the stack.
 */

void add_handler(stack_t **stack, unsigned int line_number)
{
	if (is_empty(stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

