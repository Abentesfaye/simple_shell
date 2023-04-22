#include "main.h"
/**
 * @file main.c
 * @brief Simple Shell
 * 
 * Implementation of basic unit command line interpreter that reads user command
 * @main- th execution point of the program
 * Return:nothing
 * 
 */
int main()
{
    char user_input[MAX_INPUT_LENGTH];
    pid_t pid;
    int status;

    while (1)
    {
        /* display prompt */
        printf("($) ");
        fflush(stdout);  /* Add fflush(stdout) to flush the output buffer*/

        fgets(user_input, MAX_INPUT_LENGTH, stdin);

        /* check for end of file condition (Ctrl+D) */
        if (feof(stdin))
        {
            break;
        }

        /*Remove new line character from user input*/
        user_input[strcspn(user_input, "\n")] = '\0';

        /* Fork a new process */
        pid = fork();

        if (pid < 0)
        {
            perror("Error: Fork failed");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            /* child process */
            if (strcmp(user_input, "") == 0)
            {
                /* If user input is empty, exit without executing any command */
                exit(EXIT_SUCCESS);
            }
            execlp(user_input, user_input, (char *)NULL);
            /* If execlp returns, it means the command was not found */
            perror("Error: Command not found");
            exit(EXIT_FAILURE);
        }
        else
        {
            /* parent process */
            wait(&status);
        }
    }
    return 0;
}
