/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:24:30 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/20 23:30:03 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#define N 4

void initialize_grid(int grid[4][4])
/*
	This function initializes the grid to zeros
*/
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            grid[i][j] = 0;
}

int	is_unique(int grid[4][4], int row, int col, int height)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == height || grid[i][col] == height)
			return (0);
		i++;
	}
	return (1);
}

// Function to calculate visible skyscrapers
int visible_count(int *array, int size) {
    int count = 0, max = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            count++;
            max = array[i];
        }
    }
    return count;
}

// Main solver function
int solve_puzzle_iterative(int *clues, int grid[N][N]) {
    // Parse clues into directions
    int top[N], bottom[N], left[N], right[N];
    for (int i = 0; i < N; i++) {
        top[i] = clues[i];
        bottom[i] = clues[N + i];
        left[i] = clues[2*N + i]; // Reverse bottom clues
        right[i] = clues[3*N + i];   // Reverse left clues
    }

    int stack[N*N][3]; // [row, col, height]
    int stack_pos = 0;
    int row = 0, col = 0, height = 1;

    // Initialize grid
    initialize_grid(grid);

    while (stack_pos >= 0) {
        // If all heights tried, backtrack
        if (height > N) {
            grid[row][col] = 0;
            if (--stack_pos < 0) return 0;
            row = stack[stack_pos][0];
            col = stack[stack_pos][1];
            height = stack[stack_pos][2] + 1;
            continue;
        }

        // Try current height
        if (is_unique(grid, row, col, height)) {
            grid[row][col] = height;

            // Check constraints immediately
            bool valid = true;
            
            // Check row if completed
            if (col == N-1) {
                int row_view[N], reversed_row[N];
                for (int c = 0; c < N; c++) {
                    row_view[c] = grid[row][c];
                    reversed_row[N-1 - c] = row_view[c];
                }
                if (visible_count(row_view, N) != left[row] || 
                    visible_count(reversed_row, N) != right[row]) {
                    valid = false;
                }
            }

            // Check column if in last row
            if (row == N-1) {
                int col_view[N], reversed_col[N];
                for (int r = 0; r < N; r++) {
                    col_view[r] = grid[r][col];
                    reversed_col[N-1 - r] = col_view[r];
                }
                if (visible_count(col_view, N) != top[col] || 
                    visible_count(reversed_col, N) != bottom[col]) {
                    valid = false;
                }
            }

            if (!valid) {
                grid[row][col] = 0;
                height++;
                continue;
            }

            // Store current state
            stack[stack_pos][0] = row;
            stack[stack_pos][1] = col;
            stack[stack_pos][2] = height;
            stack_pos++;

            // Move to next cell
            if (col < N-1) col++;
            else {col = 0; row++;}

            // Check if puzzle complete
            if (row == N) return 1;

            height = 1; // Reset height for new cell
        } else {
            height++; // Try next height
        }
    }
    return 0;
}

