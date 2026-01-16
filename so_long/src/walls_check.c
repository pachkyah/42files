/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 02:19:53 by ypachkou          #+#    #+#             */
/*   Updated: 2026/01/11 14:56:53 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Check that a horizontal line is fully walled.
 * 
 * Verifies that every character in the given line is '1'.
 * If any character is not '1', exits the program with an error.
 * 
 * @param game Pointer to the game structure.
 * @param y Index of the row to check.
 */
static void	check_horizontal_walls(t_game *game, int y)
{
	int	i;

	i = 0;
	while (game->map[y][i])
	{
		if (game->map[y][i] != '1')
			error("Map not closed by walls", game);
		i++;
	}
}

/**
 * @brief Check that the vertical walls (first and last columns) are closed.
 * 
 * Iterates over every row and ensures that the first and last character
 * is '1'. Exits with an error if any row violates this rule.
 * 
 * @param game Pointer to the game structure.
 */
static void	check_vertical_walls(t_game *game)
{
	int	y;
	int	last;

	y = 0;
	while (game->map[y])
	{
		last = ft_strlen(game->map[y]) - 1;
		if (game->map[y][0] != '1' || game->map[y][last] != '1')
			error("Map not closed by walls", game);
		y++;
	}
}

/**
 * @brief Validate that the map is fully surrounded by walls.
 * 
 * Checks the top and bottom rows (horizontal walls) and the first and last
 * columns (vertical walls) to ensure the map is closed.
 * 
 * @param game Pointer to the game structure.
 */
void	check_walls(t_game *game)
{
	int	height;

	height = 0;
	while (game->map[height])
		height++;
	check_horizontal_walls(game, 0);
	check_horizontal_walls(game, height - 1);
	check_vertical_walls(game);
}
