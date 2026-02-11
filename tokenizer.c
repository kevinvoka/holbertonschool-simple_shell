#include "shell.h"


char **split_line(char *line)
{
    size_t bufsize = 64, i = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char **new_tokens;
    char *tok;

    if (!tokens)
        return NULL;

    tok = strtok(line, " \t\r\n");
    while (tok)
    {
        if (i + 1 >= bufsize)
        {
            bufsize *= 2;
            new_tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!new_tokens)
            {
                free(tokens);
                return NULL;
            }
            tokens = new_tokens;
        }
        tokens[i++] = tok;
        tok = strtok(NULL, " \t\r\n");
    }
    tokens[i] = NULL;
    return tokens;
}

void free_argv(char **argv)
{

    free(argv);
}
