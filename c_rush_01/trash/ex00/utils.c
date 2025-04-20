/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:45:40 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/20 22:03:52 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool is_unique(int N, int grid[N][N], int row, int col, int height)
{
    // Check row uniqueness
    for (int c = 0; c < N; c++)
        if (c != col && grid[row][c] == height)
            return false;
    // Check column uniqueness
    for (int r = 0; r < N; r++)
        if (r != row && grid[r][col] == height)
            return false;
    return true;
}

int visible_count(int *array, int size)
{
    int count = 0, max_height = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > max_height) {
            count++;
            max_height = array[i];
        }
    }
    return count;
}
