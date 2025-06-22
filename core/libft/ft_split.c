/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pachkyah <pachkyah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:25:26 by ypachkou          #+#    #+#             */
/*   Updated: 2025/06/22 17:05:29 by pachkyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c)
/*
	Helper function for counting words (strings separated by character 'c')
*/
{
	size_t	count = 0;
	int		in_word = 0;

	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	free_all(char **arr, size_t i)
/*
	Helper function for freeing allocated memory
*/
{
	while (i--)
		free(arr[i]);
	free(arr);
}

char	**ft_split(char const *s, char c)
/*
    This function allocates memory (using malloc(3)) and returns an
    array of strings obtained by splitting ’s’ using
    the character ’c’ as a delimiter. The array ends with a NULL pointer.    
*/
{
	char	**res;
	size_t	start;
    size_t end;
    size_t i;
 
    end = 0;    
    i = 0;
	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!res)
		return (NULL);
	while (s[end])
	{
		while (s[end] == c)
			end++;
		start = end;
		while (s[end] && s[end] != c)
			end++;
		if (end > start)
		{
			res[i] = ft_substr(s, start, end - start);
			if (!res[i++])
				return (free_all(res, i - 1), NULL);
		}
	}
	res[i] = NULL;
	return (res);
}
