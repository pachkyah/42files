/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:29:06 by ypachkou          #+#    #+#             */
/*   Updated: 2026/01/10 22:29:07 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
