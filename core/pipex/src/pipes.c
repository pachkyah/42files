/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:29:03 by ypachkou          #+#    #+#             */
/*   Updated: 2026/01/20 15:35:56 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void create_pipes(t_pipex *px)
{
    //debug
    //printf("step 4: creating pipes\n");

    int i;

    px->pipes = malloc(sizeof(int *) * px->pipe_count);
    if (!px->pipes)
    {
        cleanup_pipex(px);
        error_exit("malloc all pipes error");
    }
    i = 0;
    while (i < px->pipe_count)
    {
        px->pipes[i] = malloc(sizeof(int) * 2);
        if (!px->pipes[i])
        {
            cleanup_pipex(px);
            error_exit("malloc 1 pipe error");
        }
        if (pipe(px->pipes[i]) < 0)
        {
            cleanup_pipex(px);
            error_exit("pipe failed");
        }
        i++;
    }
}
