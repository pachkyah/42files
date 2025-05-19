/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:09:36 by ypachkou          #+#    #+#             */
/*   Updated: 2025/05/19 11:30:48 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char c)
/*
	This is a function that:
	returns 1 if given character is in the alphabet
			0 if any other
*/
{
	if (!((c >= 'A' && c <= 'Z')
			|| (c >= 'a' && c <= 'z')))
	{
		return (0);
	}
	return (1);
}
