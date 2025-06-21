/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:24:53 by ypachkou          #+#    #+#             */
/*   Updated: 2025/05/28 16:59:10 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
/*
	This is a function that:
	returns 1 if given character is a digit
			0 if any other
*/
{
	return (c >= '0' && c <= '9');
}
