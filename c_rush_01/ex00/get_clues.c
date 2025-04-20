/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_clues.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojewod <mwojewod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:37:02 by mwojewod          #+#    #+#             */
/*   Updated: 2025/04/20 12:12:25 by mwojewod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*get_clues(char *str)
/*
    creates and returns an array with the parameters from main
	top 4, bottom 4, left 4, right 4
*/
{
	int	i;
	int	j;
	int	*seen;

	seen = (int *)malloc(sizeof(int) * 16);
	i = 0;
	j = 0;
	while (str[j] && i < 16)
	{
		if (str[j] >= '1' && str[j] <= '4')
		{
			seen[i] = str[j] - '0';
			i++;
		}
		j++;
	}
	return (seen);
}
