# Holberton School — Simple Shell

![Holberton](https://img.shields.io/badge/Holberton-School-red?style=flat-square) ![C](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c)

## Description

A custom UNIX command-line interpreter (**shell**) built in C from scratch. This project replicates core features of `/bin/sh`, including command parsing, process creation with `fork()`, and program execution with `execve()`.

## Features

- Display a prompt and wait for user input
- Execute commands with and without their full path
- Handle the `PATH` environment variable
- Built-in commands: `exit`, `env`
- Handle `Ctrl+D` (EOF) gracefully
- Support command arguments
- Handle errors (command not found, permission denied)

## How It Works

```
1. Print prompt "$ "
2. Read user input with getline()
3. Tokenize the input string
4. Search for the command in PATH
5. Fork a child process
6. Execute the command with execve()
7. Parent waits for child to finish
8. Repeat
```

## Usage

```bash
# Compile
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

# Interactive mode
./hsh
$ ls -la
$ echo "Hello, World!"
$ exit

# Non-interactive mode
echo "ls -la" | ./hsh
```

## Built-in Commands

| Command | Description |
|---------|-------------|
| `exit` | Exit the shell |
| `env` | Print environment variables |

## Technologies

| Tool | Version |
|------|---------|
| Ubuntu | 22.04 LTS |
| GCC | 12.x |
| Betty Linter | Latest |
| Valgrind | 3.x |

## Author

**Kevin Voka** — [GitHub](https://github.com/kevinvoka)

