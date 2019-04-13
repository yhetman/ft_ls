# ft_ls
Recoding of the original function ls with additional flags.



WHAT ls FUNCTION ACTUALLY IS?

On the superficial level, typing ls -l displays all the files and directories in the current working
directory, along with respective permissions, owners, and created date and time.

On the deeper level, this is what happens when you type “ls -l” and “enter” in the shell:

First and foremost, the shell prints the prompt, prompting the user to enter a command.
The shell reads the command ls -l from the getline() function’s STDIN, parsing the command line
into arguments that it is passing to the program it is executing.

The shell checks if ls is an alias. If it is, the alias replaces ls with its value.

If ls isn’t an alias, the shell checks if the word of a command is a built-in.
Then, the shell looks for a program file called ls where all the executable files are in the system —
in the shell’s environment (an array of strings), specifically in the $PATH variable. The $PATH variable
is a list of directories the shell searches every time a command is entered. $PATH, one of the environment
variables, is parsed using the ‘=’ as a delimiter. Once the $PATH is identified, all the directories in
$PATH are tokenized, parsed further using ‘:’ as a delimiter.

To execute ls, three system calls are made:

    fork / execve / wait

To create new processes in Unix, the system call fork() is made to duplicate the
parent process, creating a child process of the parent process.

The system call execve() is made and does three things: the operating system stops the duplicated process,
loads up the new program, and starts. execve() replaces defining parts of the current process’ 
memory stack with the new stuff loaded from the ls executable file.

Meanwhile, the parent process continues to do other things, keeping track of its children as well, using
the system call wait().

If the executable binary file does not exist, an error will be printed.

Lastly, after ls -l is executed, the shell executes shutdown commands, frees up memory, exits, and
re-prompts the user for input.

