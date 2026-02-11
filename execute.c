#include "shell.h"

/*
 * print_error - Print error message to stderr
 * @progname: Program name
 * @cmd: Command that was not found
 */
static void print_error(const char *progname, const char *cmd)
{
    write(STDERR_FILENO, progname, strlen(progname));
    write(STDERR_FILENO, ": 1: ", 5);
    write(STDERR_FILENO, cmd, strlen(cmd));
    write(STDERR_FILENO, ": not found\n", 12);
}

/*
 * execute_command:
 *  - Kontrollon nese komanda ekziston (resolve_command)
 *  - Nese nuk ekziston → printo error tek stderr dhe kthe 127 (standard "not found")
 *  - Nese ekziston → fork + execve, ruaj last_status
 *  - Kthen 0 gjithmone; rezultati real vendoset ne *last_status
 */
int execute_command(char **argv, char **env, const char *progname, int *last_status)
{
    pid_t pid;
    int status = 0;
    char *full = resolve_command(argv[0], env);

    if (!full)
    {
        print_error(progname, argv[0]);
        *last_status = 127;
        return 0;
    }

    pid = fork();
    if (pid == -1)
    {
        perror(progname);
        free(full);
        *last_status = 1;
        return 0;
    }

    if (pid == 0)
    {
        execve(full, argv, env);
    
        perror(progname);
        _exit(126);
    }


    free(full);
    if (waitpid(pid, &status, 0) == -1)
    {
        perror(progname);
        *last_status = 1;
        return 0;
    }

    if (WIFEXITED(status))
        *last_status = WEXITSTATUS(status);
    else
        *last_status = 1;

    return 0;
}
