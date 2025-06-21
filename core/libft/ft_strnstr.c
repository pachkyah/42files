/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:25:53 by ypachkou          #+#    #+#             */
/*   Updated: 2025/06/01 01:43:45 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
/*
	This function searches for a substring 'needle'
	in the first 'len' characters of a string 'hay',
	and returns a pointer to the first occurrence,
	or NULL if not found.
*/
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return ((char *)hay);
	while (hay[i] && i < len)
	{
		j = 0;
		while (needle[j] && hay[i + j] == needle[j] && (i + j) < len)
		{
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)(hay + i));
		i++;
	}
	return (NULL);
}
