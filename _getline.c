#include "main.h"

/**
 * read_instruction- this is a function which reads command
 * from the standard input.
 * @next: standard input
 * Return: the char that is read from keyboard
 */

char * read_instruction(file* next)
{
	char *func = NULL;
	ssize_t byte_read;
	size_t length = 0;

	byte_read = getline(&func, &length, next);
	if (byte_read == -1)
	{
		free(func);
		exit(EXIT_SUCCESS);
		return (NULL);
	}
	return (func);
}
