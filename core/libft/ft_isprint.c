/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:24:56 by ypachkou          #+#    #+#             */
/*   Updated: 2025/05/28 16:56:36 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
/*
	This is a function that:
	returns 1 if given character is printable
			0 if any other
*/
{
	return (c >= 32 && c <= 126);
}
