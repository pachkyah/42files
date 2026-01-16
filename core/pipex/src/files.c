/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:28:38 by ypachkou          #+#    #+#             */
/*   Updated: 2026/01/10 22:28:39 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

static void open_infile(t_pipex *px)
{
    if (px->here_doc)
        return;
    px->infile = open(px->argv[1], O_RDONLY);
    printf("infile fd = %d\n", px->infile); //debugginh
    if (px->infile < 0)
        perror(px->argv[1]);
}

static void open_outfile(t_pipex *px)
{
    if (px->here_doc)
        px->outfile = open(px->argv[px->argc - 1],
                O_WRONLY | O_CREAT | O_APPEND, 0644);
    else
        px->outfile = open(px->argv[px->argc - 1],
                O_WRONLY | O_CREAT | O_TRUNC, 0644);
    printf("outfile fd = %d\n", px->outfile); //debuggin
    if (px->outfile < 0)
        perror(px->argv[px->argc - 1]);
}

void open_files(t_pipex *px)
{
    //debug
    printf("step 2: open files\n");

    open_infile(px);
    handle_heredoc(px);
    open_outfile(px);
}
