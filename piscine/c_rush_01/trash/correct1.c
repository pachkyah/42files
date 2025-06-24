/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojewod <mwojewod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:53:10 by mwojewod          #+#    #+#             */
/*   Updated: 2025/04/20 12:37:05 by mwojewod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	left_to_right(int *row, int left)
{
	int	i;
	int	hi;
	int	vis;

	i = 0;
	hi = 0;
	vis = 0;
	while (i < 4)
	{
		if (hi < row[i])
		{
			hi = row[i];
			vis++;
		}
		i++;
	}
	if (vis != left)
		return (0);
	return (1);
}

int	right_to_left(int *row, int right)
{
	int	i;
	int	hi;
	int	vis;

	i = 3;
	hi = 0;
	vis = 0;
	while (i >= 0)
	{
		if (hi < row[i])
		{
			hi = row[i];
			vis++;
		}
		i--;
	}
	if (vis != right)
		return (0);
	return (1);
}

int	top_to_bottom(int *col, int top)
{
	int	i;
	int	hi;
	int	vis;

	i = 0;
	hi = 0;
	vis = 0;
	while (i < 4)
	{
		if (hi < col[i])
		{
			hi = col[i];
			vis++;
		}
		i++;
	}
	if (vis != top)
		return (0);
	return (1);
}

int	bottom_to_top(int *col, int bottom)
{
	int	i;
	int	hi;
	int	vis;

	i = 3;
	hi = 0;
	vis = 0;
	while (i >= 0)
	{
		if (hi < col[i])
		{
			hi = col[i];
			vis++;
		}
		i--;
	}
	if (vis != bottom)
		return (0);
	return (1);
}
/*
#include <stdio.h>

int main ()
{
	int row[] = {3, 4, 1, 2};
	int left = 4;
	int right = 2;
	int col[] = {2, 3, 4, 1};
	int top = 4;
	int bottom = 2;

	printf("%d\n", left_to_right(row, left));
	printf("%d\n", right_to_left(row, right));
	printf("%d\n", top_to_bottom(col, top));
	printf("%d\n", bottom_to_top(col, bottom));
}
*/