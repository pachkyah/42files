/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:25:23 by ypachkou          #+#    #+#             */
/*   Updated: 2025/06/23 17:28:52 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
/*
    This function outputs the string ’s’ to the specified file
    descriptor 'fd'
*/
{
	if (!s || fd < 0)
		return ;
	while (*s)
		write(fd, s++, 1);
}
