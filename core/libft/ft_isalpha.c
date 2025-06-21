/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:09:36 by ypachkou          #+#    #+#             */
/*   Updated: 2025/05/28 16:59:06 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(char c)
/*
	This is a function that:
	returns 1 if given character is in the alphabet
			0 if any other
*/
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
