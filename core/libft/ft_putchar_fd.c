/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:25:15 by ypachkou          #+#    #+#             */
/*   Updated: 2025/06/23 17:28:45 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
/*
    This function outputs the character ’c’ to the specified file
    descriptor 'fd'
*/
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
