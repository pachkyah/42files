/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:28:33 by ypachkou          #+#    #+#             */
/*   Updated: 2026/01/20 17:06:56 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

static void close_all_pipes(t_pipex *px)
{
    int i;

    i = 0;
    while (i < px->pipe_count)
    {
        close(px->pipes[i][0]);
        close(px->pipes[i][1]);
        i++;
    }
}

static void dup_fds(t_pipex *px, int i)
{
    int in_fd;

    // Set input for first command
    if (i == 0)
    {
        if (px->infile < 0)
            in_fd = open("/dev/null", O_RDONLY); // read from empty source
        else
            in_fd = px->infile;

        if (dup2(in_fd, STDIN_FILENO) < 0)
            error_exit("dup2 infile");

        if (px->infile < 0)
            close(in_fd); // only close /dev/null, not actual infile
    }
    else
    {
        if (dup2(px->pipes[i - 1][0], STDIN_FILENO) < 0)
            error_exit("dup2 pipe read");
    }

    // Set output for last command
    if (i == px->cmd_count - 1)
    {
        if (dup2(px->outfile, STDOUT_FILENO) < 0)
            error_exit("dup2 outfile");
    }
    else
    {
        if (dup2(px->pipes[i][1], STDOUT_FILENO) < 0)
            error_exit("dup2 pipe write");
    }
}



static void exec_child(t_pipex *px, int i)
{
    dup_fds(px, i);
    close_all_pipes(px);
    if (execve(px->cmds[i][0], px->cmds[i], px->envp) < 0)
    {
        cleanup_pipex(px); 
        error_exit(px->cmds[i][0]);
    }

    //printf("child %d: pid=%d, cmd=%s\n", i, getpid(), px->cmds[i][0]); //debug
    //printf("stdin=%d stdout=%d\n", STDIN_FILENO, STDOUT_FILENO);    //debug

}

int execute_commands(t_pipex *px)
{
    //debug
    //printf("step 5: executing commands\n");
    int i;
    int status;
    int last_status = 0;
	
    i = 0;
    while (i < px->cmd_count)
    {
        px->pids[i] = fork();
        if (px->pids[i] < 0)
        {
            close_all_pipes(px);
            cleanup_pipex(px);
            error_exit("fork failed");
        }
        if (px->pids[i] == 0)
            exec_child(px, i);
        i++;
    }
    close_all_pipes(px);
    i = 0;
    while (i < px->cmd_count)
    {
        waitpid(px->pids[i], &status, 0);
        if (i == px->cmd_count - 1) // last command
        {
            if (WIFEXITED(status))
                last_status = WEXITSTATUS(status);
            else
                last_status = 1; // killed by signal
        }
        i++;
    }
    return last_status;
}
