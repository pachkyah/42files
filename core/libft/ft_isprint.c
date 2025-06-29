/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pachkyah <pachkyah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:24:56 by ypachkou          #+#    #+#             */
/*   Updated: 2025/06/25 01:06:24 by pachkyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a character is printable.
 *
 * Returns 1 if @p c is a printable character, including space,
 * and 0 otherwise. Printable characters have ASCII values from 32 to 126.
 *
 * @param c The character to check.
 * @return 1 if printable, 0 otherwise.
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
