/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:24:50 by ypachkou          #+#    #+#             */
/*   Updated: 2025/05/28 16:58:12 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
/*
	This is a function that:
	returns 1 if given character is in 7-bit ASCII range
			0 if any other
*/
{
	return (c >= 0 && c <= 127);
}
