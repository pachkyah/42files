/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_clues.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:37:02 by mwojewod          #+#    #+#             */
/*   Updated: 2025/04/20 22:49:27 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*get_clues(int N, char *str)
/*
    creates and returns an array with the parameters from main
	top N, bottom N, left N, right N
*/
{
	int	i;
	int	j;
	int	*seen;

	seen = (int *)malloc(sizeof(int) * 4 * N);
	i = 0;
	j = 0;
	while (str[j] && i < 4 * N)
	{
		if (str[j] >= '1' && str[j] <= '0' + N)
		{
			seen[i] = str[j] - '0';
			i++;
		}
		j++;
	}
	return (seen);
}

void	count_clues(int *total, char *str)
/*
	this function counts input string, assumes its single digits
*/
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '9')
		{
			count++;
		}
		i++;
	}
	*total = count;
}
