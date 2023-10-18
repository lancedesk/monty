#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * pchar_handler - Prints the character at the top of the stack,
 * followed by a newline.
 * @stack: Pointer to the top of the stack.
 * @line_number: Current line number in the Monty bytecode file.
 *
 */

void pchar_handler(stack_t **stack, unsigned int line_number)
{
	int ascii_value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	ascii_value = (*stack)->n;
	if (ascii_value >= 0 && ascii_value <= 127)
	{
		putchar(ascii_value);
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr_handler - Handles the pstr opcode.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Current line number in the Monty bytecode file.
 */

void pstr_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (
			current != NULL && current->n != 0 &&
			(current->n >= 32 && current->n <= 126)
	      )
	{
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}

/**
 * rotl_handler - Rotates the stack to the top.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */

void rotl_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}

		tmp->next = *stack;
		(*stack)->prev = tmp;
		tmp = *stack;
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		tmp->next = NULL;
	}

	(void)line_number;
}

/**
 * rotr_handler - Rotates the stack to the bottom.
 * @stack: Pointer to the top of the stack.
 * @line_number: Current line number in the Monty bytecode file.
 *
 */

void rotr_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}

		tmp->next = *stack;
		(*stack)->prev = tmp;
		tmp = *stack;
		(*stack) = tmp->prev;
		(*stack)->prev = NULL;
		tmp->prev = NULL;
	}

	(void)line_number;
}

