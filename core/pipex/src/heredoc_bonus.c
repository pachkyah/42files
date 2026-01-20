/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:28:42 by ypachkou          #+#    #+#             */
/*   Updated: 2026/01/20 15:28:38 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void handle_heredoc(t_pipex *px)
{
    int     pipefd[2];
    char    *line;
    size_t  len;

    if (!px->here_doc)
        return;

    if (pipe(pipefd) < 0)
    {
        cleanup_pipex(px);
        error_exit("pipe");
    }

    len = ft_strlen(px->limiter);
    while (1)
    {
        write(1, "heredoc> ", 9);
        line = get_next_line(0);
        if (!line)
            break;

        // compare with limiter
        if (ft_strncmp(line, px->limiter, len) == 0 && line[len] == '\n')
        {
            free(line);
            break;
        }

        write(pipefd[1], line, ft_strlen(line));
        free(line);
    }

    close(pipefd[1]);
    px->infile = pipefd[0];
}
