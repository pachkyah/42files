/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:13:50 by ypachkou          #+#    #+#             */
/*   Updated: 2025/06/01 02:26:10 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
/*
    The memcpy() function copies n bytes from memory area src to memory area dest.
	The memory areas must not overlap (check memmove())
*/
{
	unsigned char			*d;
	const unsigned char		*s;
	size_t					i;

	s = src;
	i = 0;
	d = dest;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
