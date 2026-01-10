#include "pipex.h"

void error_exit(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

void free_split(char **split)
{
    int i;

    if (!split)
        return;
    i = 0;
    while (split[i])
        free(split[i++]);
    free(split);
}
