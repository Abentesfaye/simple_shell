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
    pid_d pid;
    int status;

    while (1)
    {
        /* display promot*/
        printf("$ ");
        fgets(user_input, MAX_INPUT_LENGTH, stdin);

        /* check for end of file condition (Ctrl+D)*/
        if (feof(stdin))
        {
            printf("Exiting...");
            break;
        }

        /*Remove newLine character from user input*/
        user_input[strcspn(user_input, "\n")] = '\0';

        /* Fork a new process*/

        pid = fork();

        if (pid < 0)
        {
            perror("Error: Fork faild");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            /*child process*/
            execlp(user_input, user_input, (char *)NULL);
            /*if excelp returns, it means the command was not found*/
            perror("./shell: ");
            exit(EXIT_FAILURE);
        }
        else
        {
            /*parent process*/
            wait(&status);
        }
    }
    return (0);
}