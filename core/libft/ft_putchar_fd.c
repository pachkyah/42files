/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pachkyah <pachkyah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:25:15 by ypachkou          #+#    #+#             */
/*   Updated: 2025/06/22 16:04:11 by pachkyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putchar_fd(char c, int fd)
/*
    This function outputs the character ’c’ to the specified file
    descriptor 'fd'
*/
{
    if (fd < 0)
        return;
    write(fd, &c, 1);
}
