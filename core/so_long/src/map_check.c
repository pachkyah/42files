/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:08:51 by ypachkou          #+#    #+#             */
/*   Updated: 2026/01/11 14:38:48 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief	Checks if the map is rectangular.
 *
 * Loops through each row of the map and compares its length to the
 * first row. If any row has a different length, the game exits with
 * an error message.
 *
 * @param map	2D array of map characters.
 * @param game	Pointer to the game state for clean exit.
 */
static void	check_rectangular(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != len)
			error("Map is not rectangular", game);
		i++;
	}
}

/**
 * @brief	Validates the map for walls, elements, and rectangular shape.
 *
 * Initializes a counter structure, checks the map is rectangular,
 * validates walls, counts elements, and updates total collectibles.
 *
 * @param map	2D array of map characters.
 * @param game	Pointer to the game state.
 */
void	validate_map(t_game *game)
{
	t_check	t;

	t.player = 0;
	t.exit = 0;
	t.collect = 0;
	check_rectangular(game);
	check_walls(game);
	check_elements_and_count(game, &t);
	game->total_collect = t.collect;
}
