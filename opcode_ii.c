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
