/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:25:26 by ypachkou          #+#    #+#             */
/*   Updated: 2025/06/23 17:46:40 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c)
/*
	Helper function for counting words (strings separated by character 'c')
*/
{
	size_t	count;
	int		in_word;

	in_word = 0;
	count = 0;
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

static char	*next_word(const char *s, char c, size_t *index)
/*
	Helper function for creation of arrays for new words
*/
{
	size_t	start;
	size_t	end;

	start = *index;
	while (s[start] == c)
		start++;
	end = start;
	while (s[end] && s[end] != c)
		end++;
	if (end > start)
	{
		*index = end;
		return (ft_substr(s, start, end - start));
	}
	*index = end;
	return (NULL);
}

char	**ft_split(char const *s, char c)
/*
    This function allocates memory (using malloc(3)) and returns an
    array of strings obtained by splitting ’s’ using
    the character ’c’ as a delimiter. The array ends with a NULL pointer.    
*/
{
	char	**res;
	size_t	new_start;
	size_t	i;
	size_t	w_count;

	new_start = 0;
	i = 0;
	if (!s)
		return (NULL);
	w_count = word_count(s, c);
	res = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!res)
		return (NULL);
	while (i < w_count)
	{
		res[i] = next_word(s, c, &new_start);
		if (!res[i])
		{
			free_all(res, i);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}
