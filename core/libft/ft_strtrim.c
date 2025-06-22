/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pachkyah <pachkyah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:25:57 by ypachkou          #+#    #+#             */
/*   Updated: 2025/06/22 22:33:05 by pachkyah         ###   ########.fr       */
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

char	*ft_strtrim(char const *s1, char const *set)
/*
	This function allocates memory (using malloc(3)) and returns
	a copy of ’s1’ with characters from ’set’ 
	removed from the beginning and the end.
*/
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
