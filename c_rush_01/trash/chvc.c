/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chvc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 20:23:07 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/20 20:28:31 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_visibility(int arr[4], int from_end, int expected);

int check_visibility_constraints(int grid[4][4], int *clues)
/*
	This function checks if placement adheres to visibility constraints
*/
{
    int temp[4];
    
    // Check columns from top (clues 0-3)
    for (int col = 0; col < 4; col++)
    {
        for (int row = 0; row < 4; row++)
            temp[row] = grid[row][col];
        
        // Top view (clues 0-3)
        if (clues[col] > 0 && check_visibility(temp, 0, clues[col]))
            return 0;
        
        // Bottom view (clues 4-7)
        if (clues[col + 4] > 0 && check_visibility(temp, 1, clues[col + 4]))
            return 0;
    }
    
    // Check rows from left (clues 8-11) and right (clues 12-15)
    for (int row = 0; row < 4; row++)
    {
        // Left view (clues 8-11)
        if (clues[row + 8] > 0 && check_visibility(grid[row], 0, clues[row + 8]))
            return 0;
        
        // Right view (clues 12-15)
        if (clues[row + 12] > 0 && check_visibility(grid[row], 1, clues[row + 12]))
            return 0;
    }
    
    return 1;
}