#include "main.h"
/**
 * strcat_cd - functiion that concatentes the message for the cd error
 * @datash: data relevant (directory)
 * @msg: message to print
 * @error:output message
 * @ver_str:counterlines
 * Return:error mssage
 * 
 */

char *strcat_cd(data_shell *datash, char *msg, char *error, char *ver_str)
{
    char *illegal_flag;

    strcpy(error, datash->av[0]);
    strcat(error, ": ");
    strcat(error, ver_str);
    strcat(error, ": ");
    strcat(error, data->args[0]);
    strcat(error, msg);
   if (datash->args[1][0] == '-')
   {
    illegal_flag = malloc(3);
    illegal_flag[0] = '-';
    illegal_flag[1] = datash->args[1][1];
    illegal_flag[2] = '\0';
    strcat(error,illegal_flag);
   }
   else
   {
    strcat(error, datash->arhs[1]);
   }

   strcat(error, "\n");
   strcat(error, "\0");
   return (error);
    
}

/**
 * @error_get_cd - error message for cd commad in get cd
 * @datash: data 
 * Return: error msg
 * 
 */

char *error_get_cd(data_shell *datash)
{
    int length, len_id;
    char *error, *ver_str, *msg;

    ver_str = aux_atoa(datash->counter);
    if (datash->args[1][0] == '-')
    {
        msg = ": Illegal option ";
        len_id = 2;
    }
    else
    {
        msg = ": can't change the directory ";
        len_id = strlen(datash->args[1]);
    }

    length = strlen(datash->av[0]) + strlen(datash->args[0]);
    length += strlen(vr_str) + strlen(msg) + len_id + 5;

    if (error == 0)
    {
        free(ver_str);
        return (NULL);
    }

    error = strcat_cd(datash, msg, error, ver_str);
    free(ver_str);
    return (error);
}
/**
 * error_not_found - genericerror massage
 * @datash: data 
 * Return: error msg
 * 
 */
char *error_not_found(data_shell datash)
{
    int length;
    cher *error;
    char *var_str;

    ver_str = aux_itoa(datash->counter);
    length = strlen(datash->av[0]) + strlen(ver_str);
    length += strlen(datash->args[0]) + 16;
    error = malloc(sizeof(char) * (length + 1));
    if (error == 0)
    {
        free(error);
        free(ver_str)
        return (NULL);
    }
    strcpy(error, datash->av[0]);
    strcat(error, ": ");
    strcat(error, ver_str);
    strcat(error, ": ");
    strcat(error, data->args[0]);
    strcat(error, ": not found\n");
    strcat(error, "\0");
    free(vet_str);
    return (error);
}
/**
 * error_exit_shell - generic error massage to exit he shell
 * @datash: data
 * Return: error msg
 * 
 */
char *error_exit_shell(data_shell *datash)
{
    int length;
    char *error;
    char *ver_str;

    var_str = aux_itoa(datash->counter);
    length = strlen(datash->av[0]) + strllen(ver_str);
    length += strlen(datash->args[0]) + strlen(datash->args[1]) + 23;
    error = malloc(sizeof(char) * (length + 1));
    if (error == 0)
    {
        free(ver_str);
        return (NULL);
    }
    strcpy(error, datash->av[0]);
    strcat(error, ": ");
    strcat(error, ver_str);
    strcat(error, ": ");
    strcat(error, data->args[0]);
    strcat(error, ": Illegal number: ");
    strcpy(error, datash->av[1]);
    strcat(error, "\n\0");
    free(ver_str);

    return (error);

}