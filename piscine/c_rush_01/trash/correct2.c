/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:38:15 by mwojewod          #+#    #+#             */
/*   Updated: 2025/04/20 19:56:26 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	left_to_right(int *row, int left);

int	right_to_left(int *row, int right);

int	top_to_bottom(int *col, int top);

int	bottom_to_top(int *col, int botttom);

int	rows(int *row, int left, int right)
{
	int	a;
	int	b;

	a = left_to_right(row, left);
	b = right_to_left(row, right);
	if (a && b)
		return (1);
	return (0);
}

int	cols(int *col, int top, int bottom)
{
	int	a;
	int	b;

	a = top_to_bottom(col, top);
	b = bottom_to_top(col, bottom);
	if (a && b)
		return (1);
	return (0);
}

void	get_col(int grid[4][4], int col_i, int *col)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		col[i] = grid[i][col_i];
		i++; 
	}
}

int	all(int grid[4][4], int *clues)
{
	int	col[4];
	int	row[4];
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			row[j] = grid[i][j];
			j++;
		}
		if(!rows(row, clues[8 + i], clues[12 + i]))
			return (0);
		get_col(grid, i, col);
		if(!cols(col, clues[i], clues[i + 4]))
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>

// int main(void)
// {
// 	int grid[4][4] = {{1, 2, 3, 4}, {2, 3, 4, 1}, {3, 4, 1, 2}, {4, 1, 2, 3}};
// 	int clues[16] = {4, 3, 2, 2, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};

// 	int res = all(grid, clues);
// 	printf("%d\n", res);
// 	return (1);
// }