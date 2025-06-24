/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pachkyah <pachkyah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:25:57 by ypachkou          #+#    #+#             */
/*   Updated: 2025/06/25 01:34:36 by pachkyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	is_in_set(char c, const char *set)
// /*
// 	Helper function for checking if character 'c' is in array 'set'
// */
// {
// 	while (*set)
// 	{
// 		if (*set == c)
// 			return (1);
// 		set++;
// 	}
// 	return (0);
// }

/**
 * @brief Trims characters from the start and end of a string.
 *
 * Allocates and returns a copy of the string @p s1 with all characters
 * from @p set removed from the beginning and the end.
 *
 * @param s1 The string to trim.
 * @param set The set of characters to remove.
 * @return A newly allocated trimmed string, or NULL on failure.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]) != NULL )
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]) != NULL)
	{
		end--;
	}
	len = end - start;
	trimmed = (char *)malloc(len + 1);
	if (!trimmed)
		return (NULL);
	ft_memcpy(trimmed, s1 + start, len);
	trimmed[len] = '\0';
	return (trimmed);
}
