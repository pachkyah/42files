/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pachkyah <pachkyah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:25:23 by ypachkou          #+#    #+#             */
/*   Updated: 2025/06/22 16:03:55 by pachkyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putstr_fd(char *s, int fd)
/*
    This function outputs the string ’s’ to the specified file
    descriptor 'fd'
*/
{
    if (!s || fd < 0)
        return;
    while (*s)
        write(fd, s++, 1);
}
