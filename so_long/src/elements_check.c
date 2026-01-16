/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 02:20:27 by ypachkou          #+#    #+#             */
/*   Updated: 2026/01/11 14:43:21 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Check if a character is valid in the map.
 * 
 * Allowed characters are: '0', '1', 'P', 'E', 'C'.
 * If the character is invalid, exits the program with an error.
 * 
 * @param c Character to check.
 * @param game Pointer to the game structure.
 */
static void	check_chars(char c, t_game *game)
{
	if (!ft_strchr("01PEC", c))
		error("Invalid character in map", game);
}

/**
 * @brief Count a single tile for elements.
 * 
 * Increments the player, exit, or collectible counter depending
 * on the tile. Also validates that the tile is allowed.
 * 
 * @param c The map character at a specific position.
 * @param t Pointer to t_check structure holding counts.
 * @param game Pointer to the game structure.
 */
static void	count_tile(char c, t_check *t, t_game *game)
{
	if (c == 'P')
		t->player++;
	else if (c == 'E')
		t->exit++;
	else if (c == 'C')
		t->collect++;
	check_chars(c, game);
}

/**
 * @brief Validate total element counts after scanning the map.
 * 
 * Ensures there is exactly one player, exactly one exit,
 * and at least one collectible. Exits with error if invalid.
 * 
 * @param t Pointer to t_check structure holding counts.
 * @param game Pointer to the game structure.
 */
static void	validate_counts(t_check *t, t_game *game)
{
	if (t->player != 1)
		error("Map must contain exactly 1 player", game);
	if (t->exit != 1)
		error("Map must contain exactly 1 exit", game);
	if (t->collect < 1)
		error("Map must contain at least 1 collectible", game);
}

/**
 * @brief Count and validate all elements on the map.
 * 
 * Iterates over the game map (game->map) and counts players, exits,
 * and collectibles. Uses count_tile for per-tile counting and validation.
 * Calls validate_counts at the end.
 * 
 * @param t Pointer to a t_check struct to store counts.
 * @param game Pointer to the game structure.
 */
void	check_elements_and_count( t_game *game, t_check *t)
{
	int	y;
	int	x;

	t->player = 0;
	t->exit = 0;
	t->collect = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			count_tile(game->map[y][x], t, game);
			x++;
		}
		y++;
	}
	validate_counts(t, game);
}
