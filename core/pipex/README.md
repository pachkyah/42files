*This project has been created as part of the 42 curriculum by ypachkou.*

# Pipex

## Description

**Pipex** is a systems programming project that aims to reproduce the behavior of Unix shell pipes (`|`) using low-level system calls in C.

The goal of the project is to deepen the understanding of:
- Process creation
- Inter-process communication
- File descriptors
- Redirections
- The `execve` family of functions

The program takes an input file, executes two commands connected by a pipe, and writes the result to an output file, mimicking the following shell command:

```bash
< infile cmd1 | cmd2 > outfile
```

## Instructions
### Compilation

Compile the project using:

make

Useful Makefile rules:

make clean

make fclean

make re

### Execution

The program must be executed as follows:

./pipex infile "cmd1" "cmd2" outfile

# Example:

./pipex input.txt "grep hello" "wc -l" output.txt

Equivalent shell behavior:

< input.txt grep hello | wc -l > output.txt

Error Handling

Invalid files, commands, and system call failures are handled.

Error messages are printed to standard error.

## Resources
Technical References

man pipe

man fork

man execve

man dup2

man wait

Advanced Programming in the UNIX Environment – W. Richard Stevens

GNU Bash documentation (pipeline behavior)

## AI Usage

AI tools were used as a learning aid for:

- Understanding Unix system calls and process flow

- Structuring the README.md file

- Reasoning about edge cases and error handling

All code implementation, debugging, and final decisions were performed manually by the student.

## Notes

This project follows the 42 Norm and subject requirements.
