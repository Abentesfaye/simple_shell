# __SIMPLE UNIX COMMAND LINE INTERPRETER SHELL PROJECT__
this is a simple unix command line interpreter, also know as a shell, implemented in C. it allows users to inter commands, which are then excuted as separate process. The interpreter provides a basic liine interface with a promot where users can type commands, and it execute the command in separete child processes.

## FEATURES

- Display a promot and wait for the useer to type a command
- supports command line with arguments.
- Avoids the PATH to search for commands that do not exits.
- Avoids unnecessary fork calls for command hat do not exit.
- Handle end of file (Ctrl+D) condition to exit gracefully.
Display error message for commands not found.

##USAGE
1. Compile the source code using a C compiler, such as GCC: gcc main.c -o simple_shell
2. Run the compiled executable: ./simple_shell
3. the shell will display a promot ('($)' by default) and wait for the user to type a command.
4. Enter a command and press Enter to execut it. The command will be executed in a separeted child process.
5. The shell will display the promot again after each command is executd, allowing the user to enter another command.
6. To exit the shell, use the end of file condition (Ctrl+D)

## LIMITATION

## LICENSE

## ACKNOWLEDGEMENTS
this project is based on the the requirements specified in a prompt for simple shell project in ALX 
