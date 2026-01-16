/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:14:00 by ypachkou          #+#    #+#             */
/*   Updated: 2026/01/16 17:59:30 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Initialize the game structure to default values.
 * 
 * Sets all pointers to NULL, counters to 0, and player position to (0,0).
 * 
 * @param game Pointer to the game structure.
 */
void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->wall_img = NULL;
	game->floor_img = NULL;
	game->player_img = NULL;
	game->collect_img = NULL;
	game->exit_img = NULL;
	game->collected = 0;
	game->total_collect = 0;
	game->moves = 0;
	game->player.x = 0;
	game->player.y = 0;
}

/**
 * @brief Load and validate the map.
 * 
 * Opens the map file, checks its extension, reads it,
 * validates its structure and paths, and finds the player.
 * 
 * @param filename The map file path.
 * @param game Pointer to the game structure.
 */
static void	setup_map(char *filename, t_game *game)
{
	validate_ber_extension(filename, game);
	game->map = read_map(filename, game);
	validate_map(game);
	validate_paths(game);
	game->player = find_player(game);
	game->collected = 0;
	game->moves = 0;
}

/**
 * @brief Initialize MLX and create the game window.
 * 
 * Calculates window size from map dimensions, loads textures,
 * and renders the initial map.
 * 
 * @param game Pointer to the game structure.
 */
static void	setup_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error("MLX init failed", game);
	game->width = ft_strlen(game->map[0]) * TILE_SIZE;
	game->height = map_height(game->map) * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
	if (!game->win)
		error("MLX window creation failed", game);
	load_textures(game);
	render_map(game);
}

/**
 * @brief Entry point for the so_long game.
 * 
 * Loads the map, validates it, initializes MLX,
 * loads textures, renders the map, and starts the game loop.
 * 
 * @param argc Argument count.
 * @param argv Argument vector. argv[1] must be the map file.
 * @return int Exit status.
 */
int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	if (argc != 2)
		error("Usage: ./so_long map.ber", &game);
	setup_map(argv[1], &game);
	setup_mlx(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, DestroyNotify, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
