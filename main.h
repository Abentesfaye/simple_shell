#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/*points to an array of pointer to string called the "environment" .*/
 extern char **environ;


 /**
  * struct data strut that contains all relevant data on runtime
  * @av: argument vector
  * @input: command line written by user
  * @status: last status of the shell
  * @counter: lines counter
  * @_enviro: environmental variable
  * @pid: process ID of the shell
  * 
  */
 typedef struct data
 {
    char **av;
    char *input;
    char **args;
    int status;
    char **_environ;
    char *pid;
 } data_shell;

 /**
  * struct line_list_s - single linked list
  * @line: command line
  * Description: single linked list tp store command lines
  * 
  */
 typedef struct line_list_s
 {
    char *line;
    struct line_list_s *next;
 } line_list;

 /**
  * struct r_var_list - single linked list 
  * @len_var: length of the variable
  * @val: value of the variable
  * @len_val: length of the value
  * @next: next node
  * Description: single linked list to stor variable
  * 
  */

 typedef struct r_var_list
 {
    int len_var;
    char *val;
    int len_val;
    struct r_var_list *next;
 } r_var;
 /**
  * struct builtin_s - builtin struct for command args.
  * @name: the name of the command builtin 
  * @f: data type pointer function
  * 
  */

 typedef struct builtin_s
 {
    char *name;
    int (*f)(datashell *datash)
 } builtin_t;
 
 int cmp_env_name(const char *nenv, const *name);
 char *_getenv(const char *name, char **_environ);
 int _env(data_shell *datash);
 int exec_line(data_shell *datash);
 char *read_line(int *i_eof);
 void free_rvar_list(r_var **head);
 r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval);
 void rev_string(char *s);
 char *error_path_126(data_shell *datash);
 char *error_env(data_shell *datash);
 void aux_help_cd(void);
 void aux_help_alias(void);
 void aux_help(void)
#endif

