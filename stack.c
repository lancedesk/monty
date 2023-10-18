#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * init_stack - Initializes a stack.
 * @stack: A pointer to a pointer to the top of the stack.
 *
 * This function initializes a stack by setting its top pointer
 * to NULL, indicating an empty stack.
 */

void init_stack(stack_t **stack)
{
	*stack = NULL;
}

/**
 * push - Pushes an element onto the stack.
 * @stack: A pointer to a pointer to the top of the stack.
 * @value: The integer value to be pushed onto the stack.
 *
 * This function pushes an element with the given value onto
 * the top of the stack.
 */

void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * pop - Pops an element from the stack.
 * @stack: A pointer to a pointer to the top of the stack.
 * @line_number: Current line number in the Monty bytecode file.
 *
 * This function removes and returns the top element of the stack.
 *
 * Return: The value of the popped element.
 */

int pop(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *temp;

	if (is_empty(stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
	return (value);
}

/**
 * is_empty - Checks if the stack is empty.
 * @stack: A pointer to a pointer to the top of the stack.
 *
 * This function checks if the stack is empty (contains no elements).
 *
 * Return: 1 if the stack is empty, 0 otherwise.
 */

int is_empty(stack_t **stack)
{
	return (*stack == NULL);
}

/**
 * free_stack - Frees the memory allocated for the stack.
 * @stack: A pointer to a pointer to the top of the stack.
 * @line_number: Current line number in the Monty bytecode file.
 *
 * This function frees the memory allocated for all elements
 * in the stack and sets the top pointer to NULL,
 * effectively deallocating the entire stack.
 */

void free_stack(stack_t **stack, unsigned int line_number)
{
	while (!is_empty(stack))
	{
		pop(stack, line_number);
	}
}

