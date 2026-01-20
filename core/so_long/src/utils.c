/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:41:21 by ypachkou          #+#    #+#             */
/*   Updated: 2026/01/11 14:51:57 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief	Cleans up all allocated resources and exits the game.
 *
 * Frees images, destroys the window, frees the map and mlx pointer,
 * then exits the program. Safe to call on partially-initialized game.
 *
 * @param game	Pointer to the game state.
 */
void	clean_exit(t_game *game)
{
	if (!game)
		exit(0);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->collect_img)
		mlx_destroy_image(game->mlx, game->collect_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
	if (game->map)
		free_map(game->map);
	exit(0);
}

/**
 * @brief	Callback for window close event.
 *
 * Cleans up and exits when the user closes the window.
 *
 * @param game	Pointer to the game state.
 * @return int	Always 0.
 */
int	close_window(t_game *game)
{
	clean_exit(game);
	return (0);
}

/**
 * @brief Check if the given filename ends with ".ber".
 *
 * Exits the program with an error if the extension is invalid.
 *
 * @param filename The name of the map file.
 * @param game Pointer to the game structure.
 */
void	validate_ber_extension(char *filename, t_game *game)
{
	int	len;

	if (!filename)
		error("Invalid filename", game);
	len = ft_strlen(filename);
	if (len < 4
		|| filename[len - 4] != '.'
		|| filename[len - 3] != 'b'
		|| filename[len - 2] != 'e'
		|| filename[len - 1] != 'r')
		error("Map file must have a .ber extension", game);
}
