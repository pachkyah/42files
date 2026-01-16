/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:28:33 by ypachkou          #+#    #+#             */
/*   Updated: 2026/01/10 22:28:34 by ypachkou         ###   ########.fr       */
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
    if (i == 0)
        dup2(px->infile, STDIN_FILENO);
    else
        dup2(px->pipes[i - 1][0], STDIN_FILENO);
    if (i == px->cmd_count - 1)
        dup2(px->outfile, STDOUT_FILENO);
    else
        dup2(px->pipes[i][1], STDOUT_FILENO);
}

static void exec_child(t_pipex *px, int i)
{
    dup_fds(px, i);
    close_all_pipes(px);
    if (execve(px->cmds[i][0], px->cmds[i], px->envp) < 0)
        error_exit(px->cmds[i][0]);

    printf("child %d: pid=%d, cmd=%s\n", i, getpid(), px->cmds[i][0]); //debug
    printf("stdin=%d stdout=%d\n", STDIN_FILENO, STDOUT_FILENO);    //debug

}

void execute_commands(t_pipex *px)
{
    //debug
    printf("step 5: executing commands\n");
    int i;
    
    i = 0;
    while (i < px->cmd_count)
    {
        px->pids[i] = fork();
        if (px->pids[i] < 0)
            error_exit("fork");
        if (px->pids[i] == 0)
            exec_child(px, i);
        i++;
    }
    close_all_pipes(px);
    i = 0;
    while (i < px->cmd_count)
        waitpid(px->pids[i++], NULL, 0);
}
