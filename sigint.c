#include "main.h"
/**
 * @get_sigint - handle the ctrl + c call promot
 * @sig: Signal handler
 * 
 */
void get_sigint(int sig)
{
    (void)sig;
    write(STDOUT_FILENO, "\n^-^ ", 5);
}