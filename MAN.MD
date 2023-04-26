# MAN: SIMPLE SHELL

# NAME
KA_SHELL - A simple shell program

# SYNOPSIS
KA_SHELL

# DESCRIPTION
KA_SHELL is a basic shell program that provides a command-line interface for users to interact with an operating system. It supports basic command execution, piping, and redirection.

# COMMANDS

### KA_SHELL
 supports the following commands:

- cd: Change the current working directory
cd [DIRECTORY]

- ls: List files and directories in the current directory.
ls [OPTIONS] [DIRECTORY]

- pwd: Print the current working directory.
pwd

- echo: Print the arguments to the standard output.
echo [ARGUMENTS...]

- exit: Exit the shell program.
exit [STATUS]

# REDIRECTION

### KA_SHELL supports the following redirection operators:

- '>': Redirect standard output to a file.

- '<': Redirect standard input from a file.
- '>>': Append standard output to a file.

# PIPING

KA_SHELL supports piping multiple commands together using the | operator. For example:

- command1 | command2

This allows the output of command1 to be used as input for command2.

# ENVIRONMENT VARIABLES

KA_SHELL supports the use of environment variables in commands. Environment variables are referenced using the $ symbol followed by the variable name. For example:

- VAR_NAME=value

Environment variables can be used in commands as arguments or for storing values.

# EXIT STATUS

KA_SHELL returns exit status codes to indicate the result of command execution. Exit status 0 indicates success, while non-zero values indicate errors.


# EXAMPLES

Here are some examples of how to use KA_SHELL:

1. Change directory:
cd /home/user/documents

2. List files in the current directory:
ls

3. Redirect standard output to a file:
ls > output.txt

4. Append standard output to a file:
echo "Hello, world!" >> output.txt

5. Use environment variables in commands:
FILE_NAME=output.txt
echo "The file name is: $FILE_NAME"

# AUTHOR

KA_SHELL was developed by Abenezer Tesfaye & Kindinew Dessie as a simple shell project for learning purposes.