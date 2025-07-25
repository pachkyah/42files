/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pachkyah <pachkyah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:26:05 by ypachkou          #+#    #+#             */
/*   Updated: 2025/06/25 01:35:37 by pachkyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts a lowercase letter to uppercase.
 *
 * If @p c is a lowercase letter, converts it to its uppercase equivalent.
 * Otherwise, returns @p c unchanged.
 *
 * @param c The character to convert.
 * @return The uppercase equivalent if lowercase, otherwise @p c.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}
