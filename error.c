#include <stdio.h>
#include <stdlib.h>

/**
 * handle_error - Handles errors by printing an error message to stderr
 *                and exiting the program with EXIT_FAILURE status.
 *
 * @message: The error message to be displayed.
 * @line_number: The line number in the source file where the error occurred.
 *
 */

void handle_error(const char *message, unsigned int line_number)
{
	fprintf(stderr, "L%d: %s\n", line_number, message);
	exit(EXIT_FAILURE);
}

