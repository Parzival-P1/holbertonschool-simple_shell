<h1 align="center"> Simple Shell </h1>

### Learning Objectives 🎯
- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C programming language)
- Who is Ken Thompson
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of ``main``
- How does the shell use the ``PATH`` to find the programs
- How to execute another program with the ``execve`` system call
- How to suspend the execution of a process until one of its children terminates
- What is ``EOF`` / “end-of-file”?

### Tasks 📚

0. __README, man, AUTHORS__

- Write a ``README``
- Write a ``man`` for your shell.
- You should have an ``AUTHORS`` file at the root of your repository, listing all individuals having contributed content to the repository. Format, see ``Docker``

1. __Betty would be proud__

- Write a beautiful code that passes the Betty checks

2. __Simple shell 0.1__
- Write a UNIX command line interpreter.
	- Usage:``simple_shell``

- Your Shell should:
	- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
	- The prompt is displayed again each time a command has been executed.
	- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
	- The command lines are made only of one word. No arguments will be passed to programs.
	- If an executable cannot be found, print an error message and display the prompt again.
	- Handle errors.
	- You have to handle the “end of file” condition (``Ctrl+D``)

- You don’t have to:
	- use the ``PATH``
	- implement built-ins
	- handle special characters : ``"``, ``'``, ````, ``\``, ``*``, ``&``, ``#``
	- be able to move the cursor
	- handle commands with arguments
``execve`` will be the core part of your Shell, don’t forget to pass the environ to it…

3. __Simple shell 0.2__

- Simple shell 0.1 +
	- Handle command lines with arguments

4. __Simple shell 0.3__

- Simple shell 0.2 +
	- Handle the ``PATH``
	- ``fork`` must not be called if the command doesn’t exist

5. __Simple shell 0.4__	

- Simple shell 0.3 +
	- Implement the exit built-in, that exits the shell
	- Usage: exit
	- You don’t have to handle any argument to the built-in exit


6. __Simple shell 1.0__

- Simple shell 0.4 +
	- Implement the env built-in, that prints the current environment

