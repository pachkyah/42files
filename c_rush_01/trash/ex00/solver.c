/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:46:19 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/20 22:48:34 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_unique(int N, int grid[N][N], int row, int col, int height);
int visible_count(int *array, int size);

int solve_puzzle_iterative(int N, int *clues, int grid[N][N])
{
    int (*stack)[3] = malloc(N*N * sizeof(*stack));
    int stack_pos = 0;
    int row = 0, col = 0, height = 1;

    // Initialize grid to zeros
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            grid[i][j] = 0;

    // Parse clues into directional arrays
    int top[N], bottom[N], left[N], right[N];
    for (int i = 0; i < N; i++) {
        top[i] = clues[i];
        bottom[i] = clues[N + i];
        left[i] = clues[2*N + i];
        right[i] = clues[3*N + i];
    }

    while (stack_pos >= 0) {
        if (height > N) { // Backtrack
            grid[row][col] = 0;
            if (--stack_pos < 0) {
                free(stack);
                return 0;
            }
            row = stack[stack_pos][0];
            col = stack[stack_pos][1];
            height = stack[stack_pos][2] + 1;
            continue;
        }

        if (is_unique(N, grid, row, col, height)) {
            grid[row][col] = height;
            bool valid = true;

            // Check row constraints if row complete
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

            // Check column constraints if column complete
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

            // Push to stack
            stack[stack_pos][0] = row;
            stack[stack_pos][1] = col;
            stack[stack_pos][2] = height;
            stack_pos++;

            // Move to next cell
            if (++col >= N) {
                col = 0;
                row++;
            }

            // Check if puzzle solved
            if (row >= N) {
                free(stack);
                return 1;
            }

            height = 1; // Reset height for new cell
        } else {
            height++; // Try next height
        }
    }

    free(stack);
    return 0;
}