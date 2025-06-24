/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pachkyah <pachkyah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:25:53 by ypachkou          #+#    #+#             */
/*   Updated: 2025/06/25 01:34:15 by pachkyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates a substring in a string, limited by length.
 *
 * Searches for the first occurrence of the substring @p needle
 * in the first @p len characters of the string @p hay.
 * Returns a pointer to the beginning of the substring, or NULL if not found.
 *
 * @param hay The string to search in.
 * @param needle The substring to find.
 * @param len The maximum number of characters to search.
 * @return Pointer to the first occurrence of @p needle, or NULL if not found.
 */
char	*ft_strnstr(const char *hay, const char *needle, size_t len)
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
