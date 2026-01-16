/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:41:48 by ypachkou          #+#    #+#             */
/*   Updated: 2026/01/11 14:36:02 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief	Duplicates the game's map into a temporary copy.
 *
 * Allocates a new array of strings and duplicates each row.
 * Used for pathfinding so the original map is not modified.
 *
 * @param game	Pointer to the game containing the map.
 * @return char**	Pointer to duplicated map, or NULL on malloc failure.
 */
static char	**copy_map(t_game *game)
{
	int		y;
	char	**tmp;

	y = 0;
	while (game->map[y])
		y++;
	tmp = malloc(sizeof(char *) * (y + 1));
	if (!tmp)
		return (NULL);
	y = 0;
	while (game->map[y])
	{
		tmp[y] = ft_strdup(game->map[y]);
		y++;
	}
	tmp[y] = NULL;
	return (tmp);
}

/**
 * @brief	Finds the player position in the map.
 *
 * @param game	Pointer to the game containing the map.
 * @return t_pos	Coordinates of player. Exits program if player not found.
 */
t_pos	find_player(t_game *game)
{
	t_pos	p;
	int		y;
	int		x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				p.x = x;
				p.y = y;
				return (p);
			}
			x++;
		}
		y++;
	}
	error("No player found", game);
	p.x = 0;
	p.y = 0;
	return (p);
}

/**
 * @brief	Recursive flood fill to mark reachable tiles.
 *
 * Tiles marked as 'V' are visited. Walls ('1') block the fill.
 *
 * @param map	Temporary map copy.
 * @param x	X coordinate.
 * @param y	Y coordinate.
 */
static void	flood_fill_map(char **map, int x, int y)
{
	if (!map[y] || !map[y][x])
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill_map(map, x + 1, y);
	flood_fill_map(map, x - 1, y);
	flood_fill_map(map, x, y + 1);
	flood_fill_map(map, x, y - 1);
}

/**
 * @brief	Checks for unreachable collectibles or exit.
 *
 * Frees the temporary map if map is unsolvable.
 *
 * @param map	Temporary map copy.
 * @param game	Game pointer for error handling.
 */
static void	check_unreachable(t_game *game, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
			{
				free_map(map);
				error("Map is unsolvable", game);
			}
			x++;
		}
		y++;
	}
}

/**
 * @brief	Validates that the player can reach all collectibles and exit.
 *
 * Creates a temporary copy of the map, finds the player, performs flood fill,
 * and checks for unreachable tiles.
 *
 * @param game	Pointer to the game containing the map.
 */
void	validate_paths(t_game *game)
{
	char	**tmp;
	t_pos	p;

	tmp = copy_map(game);
	if (!tmp)
		error("Malloc failed", game);
	p = find_player(game);
	flood_fill_map(tmp, p.x, p.y);
	check_unreachable(game, tmp);
	free_map(tmp);
}
