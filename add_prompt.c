#include "main.h"
/**
 * add_prompt - prints the prompt
 * @sub: file
 * @buffer: stat buffer
 * Return: nothing
 */
void add_prompt(struct stat buffer, int sub)
{
	fstat(sub, &buffer);

	if (S_ISCHR(buffer.st_mode))
		write(STDOUT_FILENO, "$ ", 2);
}
