/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:24:43 by ypachkou          #+#    #+#             */
/*   Updated: 2025/05/28 16:55:15 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
/*
	This is a function that:
	returns 1 if given character is alphanumeric
			0 if any other
*/
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
