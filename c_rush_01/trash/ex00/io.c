/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:49:34 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/20 23:01:29 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
/* 
	writes 1 character,
	write args:
	1 means stdout,
	1 means length
*/
{
	write(1, &c, 1);
}

void	ft_error(void)
/*
	writes error
*/
{
	char	*str;

	str = "Error";
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
	write(1, "\n", 1);
}

void	print_solution(int N, int grid[N][N])
/*
	prints output
*/
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			ft_putchar('0' + grid[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
