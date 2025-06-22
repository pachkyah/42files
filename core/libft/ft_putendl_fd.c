/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pachkyah <pachkyah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:25:18 by ypachkou          #+#    #+#             */
/*   Updated: 2025/06/22 16:03:43 by pachkyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putendl_fd(char *s, int fd) 
/*
    This function outputs the string ’s’ to the specified file
    descriptor 'fd' followed by a newline
*/
{
    if (!s || fd < 0)
        return;
    while (*s)
        write(fd, s++, 1);
    write(fd, "\n", 1);
}
