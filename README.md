Simple shell 0.4.1 -Simple shell 0.4 + handle arguments for the built-in exit -Usage: exit status, where status is an integer used to exit the shell
setenv, unsetenv -Simple shell 1.0 + Implement the setenv and unsetenv builtin commands -setenv -Initialize a new environment variable, or modify an existing one -Command syntax: setenv VARIABLE VALUE -Should print something on stderr on failure -unsetenv -Remove an environment variable -Command syntax: unsetenv VARIABLE -Should print something on stderr on failure
cd -Simple shell 1.0 + Implement the builtin command cd: -Changes the current directory of the process. -Command syntax: cd [DIRECTORY] -If no argument is given to cd the command must be interpreted like cd $HOME -You have to handle the command cd - -You have to update the environment variable PWD when you change directory man chdir, man getcwd
; -Simple shell 1.0 + Handle the commands separator ;
&& and || -Simple shell 1.0 + Handle the && and || shell logical operators
alias -Simple shell 1.0 + Implement the alias builtin command -Usage: alias [name[='value'] ...] -alias: Prints a list of all aliases, one per line, in the form name='value' -alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the fo rm name='value' -alias name='value' [...]: Defines an alias for each name whose value is given. If name is already an alias, replaces its value with value
Variables -Simple shell 1.0 + Handle variables replacement -Handle the $? variable

