/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:25:44 by ypachkou          #+#    #+#             */
/*   Updated: 2025/05/31 22:51:11 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
/*
    This function counts and returns
    the number of characters in a string
*/
{
	const char	*s;

	s = str;
	while (*(s++))
	{
	}
	return (s - str - 1);
}
