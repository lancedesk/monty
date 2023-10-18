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

