/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 02:44:14 by ypachkou          #+#    #+#             */
/*   Updated: 2026/01/11 14:05:46 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Load a single XPM image from a file.
 * 
 * @param game Pointer to the game structure containing mlx instance.
 * @param path Path to the XPM file.
 * @return void* Pointer to the loaded image.
 */
static void	*load_img(t_game *game, char *path)
{
	void	*img;
	int		w;
	int		h;

	img = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!img)
		error("Failed to load texture", game);
	return (img);
}

/**
 * @brief Load all game textures into the t_game structure.
 * 
 * @param game Pointer to the game structure.
 */
void	load_textures(t_game *game)
{
	game->wall_img = load_img(game, "textures/wall.xpm");
	game->floor_img = load_img(game, "textures/floor.xpm");
	game->player_img = load_img(game, "textures/player.xpm");
	game->collect_img = load_img(game, "textures/collect.xpm");
	game->exit_img = load_img(game, "textures/exit.xpm");
}

/**
 * @brief Draw a single tile at (x, y) coordinates.
 * 
 * Floor is always drawn first, then walls, 
 * collectibles, exit, and finally player.
 * 
 * @param g Pointer to the game structure.
 * @param x Tile x-coordinate.
 * @param y Tile y-coordinate.
 */
static void	draw_tile(t_game *g, int x, int y)
{
	int	px;
	int	py;

	px = x * TILE_SIZE;
	py = y * TILE_SIZE;
	mlx_put_image_to_window(g->mlx, g->win, g->floor_img, px, py);
	if (g->map[y][x] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->wall_img, px, py);
	if (g->map[y][x] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->collect_img, px, py);
	if (g->map[y][x] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->exit_img, px, py);
	if (g->map[y][x] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->player_img, px, py);
}

/**
 * @brief Get the height of the map in tiles.
 * 
 * @param map The map represented as a NULL-terminated array of strings.
 * @return int Number of rows in the map.
 */
int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

/**
 * @brief Render the entire map to the window.
 * 
 * Loops through each tile and calls draw_tile.
 * 
 * @param game Pointer to the game structure.
 */
void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
}
