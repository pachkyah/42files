#include "pipex.h"
#include <stdio.h>

void create_pipes(t_pipex *px)
{
    //debug
    printf("step 4: creating pipes\n");

    int i;

    px->pipes = malloc(sizeof(int *) * px->pipe_count);
    if (!px->pipes)
        error_exit("malloc pipes");
    i = 0;
    while (i < px->pipe_count)
    {
        px->pipes[i] = malloc(sizeof(int) * 2);
        if (!px->pipes[i])
            error_exit("malloc pipe");
        if (pipe(px->pipes[i]) < 0)
            error_exit("pipe");
        i++;
    }
}
