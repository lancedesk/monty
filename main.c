/* Enable POSIX.1-2008 features including getline */
#define  _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/* Define an array of function pointers */
void (*handlers[])(stack_t **stack, unsigned int line_number) = {
	pint_handler,
	pop_handler,
	swap_handler,
	add_handler,
	sub_handler,
	div_handler,
	mul_handler,
	mod_handler
};

const char *handler_names[] = {
	"pint",
	"pop",
	"swap",
	"add",
	"sub",
	"div",
	"mul",
	"mod"
};

#define NUM_HANDLERS (sizeof(handlers) / sizeof(handlers[0]))

void handle_instruction(
		char *opcode,
		char *arg,
		stack_t **stack,
		unsigned int line_number
		);

void process_file(FILE *file, unsigned int *line_number);

/**
 * main - Entry point of the Monty interpreter program.
 * @argc: Number of command-line arguments.
 * @argv: Array of strings containing the command-line arguments.
 *
 * This function serves as the entry point of the Monty interpreter.
 * It checks the command-line arguments,
 * opens and processes the specified Monty bytecode file,
 * and handles errors related to file processing and execution.
 *
 * Return: Always returns 0 to indicate successful execution.
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	stack_t *stack = NULL;
	unsigned int line_number = 0; /* line_number as a local variable */

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	process_file(file, &line_number);  /* line_number as an argument */

	fclose(file);
	free(line);
	free_stack(&stack, line_number);
	return (0);
}

/**
 * handle_instruction - Handles instructions based on opcode & argument.
 * @opcode: Opcode representing the operation to be performed.
 * @arg: Argument associated with the opcode (if any).
 * @stack: Pointer to the top of the stack.
 * @line_number: Current line number in the Monty bytecode file.
 *
 * It interprets the given opcode & performs the corresponding operation
 * on the stack.
 */

void handle_instruction(
		char *opcode,
		char *arg,
		stack_t **stack,
		unsigned int line_number
		)
{
	unsigned long i;

	if (strcmp(opcode, "push") == 0)
	{
		push_handler(stack, arg, line_number);
		return;
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall_handler(stack);
		return;
	}
	else if (strcmp(opcode, "nop") == 0)
	{
		/* Handle nop instruction (do nothing) */
		return;
	}
	else
	{
		/* Find handler for other instructions in array of function pointers */
		for (i = 0; i < NUM_HANDLERS; i++)
		{
			if (strcmp(opcode, handler_names[i]) == 0)
			{
				handlers[i](stack, line_number);
				return;
			}
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	free_stack(stack, line_number);
	exit(EXIT_FAILURE);
}


/**
 * process_file - Processes a file containing Monty bytecode instructions.
 * @file: Pointer to the FILE structure of the input file.
 * @line_number: Current line number in the Monty bytecode file.
 *
 * This function reads Monty bytecode instructions from the given file,
 * interprets and executes them, and handles errors accordingly.
 */

void process_file(FILE *file, unsigned int *line_number)
{
	char *opcode, *arg;
	char *line = NULL;
	size_t len = 0;
	stack_t *stack = NULL;

	while (getline(&line, &len, file) != -1)
	{
		(*line_number)++;  /* Increment value of line_number */

		opcode = strtok(line, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
		{
			continue;  /* Skip empty lines or comments */
		}

		arg = strtok(NULL, " \t\n");
		handle_instruction(opcode, arg, &stack, *line_number);
	}

	free(line);
	free_stack(&stack, *line_number);
}

