#include "main.h"

/**
 * free_data - frees data structure
 * @datash: data structure
 * Return: nothing
 * 
 */

void free_data(data_shell *datash)
{
    unsigned int i;

    for (i = 0; datash->_environ[i]; i++)
    {
        free(datash->_environ[i]);
    }

    free(datash->_environ);
    free(datash->pid);

}
/**
 * set_data - create the structure
 * @datash: structute 
 * @av: argument vector
 * Return: no return
 * 
 */
void set_data(data_shell *datash, char **av)
{
    unsigned int i;

    datash->av = av;
    datash->input = NULL;
    datash->status =0;
    datash->counter = 1;

    for (i = 0; environ[i]; i++)
        ;

    datash->_environ = malloc(sizeof(char *) * (i + 1));

    for (i = 0; environ[i]; i++)
    {
        datash->_environ[i] = _stdup(environ[i]);
    }

    datash->_environ[i] = NULL;
    datash->pid = aux_itoa(getpid());

}

/**
 * main - entry point
 * @ac: argument count
 * @av: argumet vector
 * Return: 0
 * 
 */
int main(int ac, char **av)
{
    data_shell datash;
    (void) ac;

    signal(SIGINT, get_sigint);
    set_data(&datash, av);
    free_data(&datash);
    free_data(&datash);

    if (datash.status < 0)
        return (255);
    return (datash.status);
}