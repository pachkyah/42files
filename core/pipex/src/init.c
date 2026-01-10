#include "pipex.h"
#include <stdio.h>

static void init_basic_fields(t_pipex *px, int argc, char **argv, char **envp)
{
    px->argc = argc;
    px->argv = argv;
    px->envp = envp;
    px->infile = -1;
    px->outfile = -1;
    px->pipes = NULL;
    px->cmds = NULL;
    px->paths = NULL;
    px->pids = NULL;
}

static void detect_heredoc(t_pipex *px)
{
    px->here_doc = 0;
    px->limiter = NULL;
    if (px->argc > 1 && ft_strncmp(px->argv[1], "here_doc", 9) == 0)
    {
        px->here_doc = 1;
        px->limiter = px->argv[2];
    }
}

static void set_command_counts(t_pipex *px)
{
    if (px->here_doc)
        px->cmd_count = px->argc - 4;
    else
        px->cmd_count = px->argc - 3;
    px->pipe_count = px->cmd_count - 1;
}

static void allocate_arrays(t_pipex *px)
{
    px->cmds = malloc(sizeof(char **) * px->cmd_count);
    if (!px->cmds)
        error_exit("malloc cmds");
    px->pids = malloc(sizeof(pid_t) * px->cmd_count);
    if (!px->pids)
        error_exit("malloc pids");
}

void init_pipex(t_pipex *px, int argc, char **argv, char **envp)
{
    //debug
    printf("step 1: init\n");

    init_basic_fields(px, argc, argv, envp);
    detect_heredoc(px);
    set_command_counts(px);
    allocate_arrays(px);
}
