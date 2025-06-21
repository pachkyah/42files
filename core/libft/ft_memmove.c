/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:25:10 by ypachkou          #+#    #+#             */
/*   Updated: 2025/06/01 02:26:53 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	memmove_forward(unsigned char *d, const unsigned char *s, size_t n)
/*
	Helper function for forward copy
*/
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}

static void	memmove_backward(unsigned char *d, const unsigned char *s, size_t n)
/*
	Helper function for backward copy
*/
{
	while (n > 0)
	{
		n--;
		d[n] = s[n];
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
/*
	This function copies n bytes from memory area src to memory area dest.
	The memory areas may overlap: copy direction is chosen based on relative addresses
	to prevent overwriting bytes.
*/
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == s || n == 0)
	{
		return (dest);
	}
	if (d < s)
		memmove_forward(d, s, n);
	else
		memmove_backward(d, s, n);
	return (dest);
}
