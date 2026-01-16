/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:28:29 by ypachkou          #+#    #+#             */
/*   Updated: 2026/01/10 22:28:31 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void free_cmds(t_pipex *px)
{
    int i;

    if (!px->cmds)
        return;
    i = 0;
    while (i < px->cmd_count)
    {
        free_split(px->cmds[i]);
        i++;
    }
    free(px->cmds);
    px->cmds = NULL;
}

static void free_pipes(t_pipex *px)
{
    int i;

    if (!px->pipes)
        return;
    i = 0;
    while (i < px->pipe_count)
    {
        free(px->pipes[i]);
        i++;
    }
    free(px->pipes);
    px->pipes = NULL;
}

static void close_files(t_pipex *px)
{
    if (px->infile >= 0)
        close(px->infile);
    if (px->outfile >= 0)
        close(px->outfile);
    px->infile = -1;
    px->outfile = -1;
}

void cleanup_pipex(t_pipex *px)
{
    //debug
    printf("step 6: open files\n");

    close_files(px);
    free_cmds(px);
    free_pipes(px);
    free(px->pids);
    px->pids = NULL;
}
