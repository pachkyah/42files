/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 02:45:16 by ypachkou          #+#    #+#             */
/*   Updated: 2026/01/11 13:51:07 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief	Handles what happens when player reaches the exit.
 *
 * If all collectibles are collected, prints win message, total moves,
 * and exits the game. Otherwise, does nothing.
 *
 * @param game	Pointer to game state.
 * @param x	New x-coordinate of player.
 * @param y	New y-coordinate of player.
 * @return int	1 if exit reached and game ended, 0 otherwise.
 */
static int	handle_exit(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->collected == game->total_collect)
		{
			game->moves++;
			ft_putstr_fd("You win!\n", 1);
			ft_putstr_fd("Total moves: ", 1);
			ft_putnbr_fd(game->moves, 1);
			ft_putchar_fd('\n', 1);
			clean_exit(game);
		}
		return (1);
	}
	return (0);
}

/**
 * @brief	Updates the map and player coordinates after a valid move.
 *
 * Sets the old position to '0', new position to 'P', updates player
 * struct, increments move counter, prints moves, and redraws the map.
 *
 * @param game	Pointer to game state.
 * @param x	New x-coordinate.
 * @param y	New y-coordinate.
 */
static void	update_position(t_game *game, int x, int y)
{
	game->map[game->player.y][game->player.x] = '0';
	game->map[y][x] = 'P';
	game->player.x = x;
	game->player.y = y;
	game->moves++;
	ft_putstr_fd("Move no: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putchar_fd('\n', 1);
	render_map(game);
}

/**
 * @brief	Moves the player in the specified direction if possible.
 *
 * Checks bounds, collisions, collectibles, exit, and calls helpers to
 * update the game state.
 *
 * @param game	Pointer to the t_game structure containing game state.
 * @param dx	Delta in x-axis.
 * @param dy	Delta in y-axis.
 */
void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x + dx;
	new_y = game->player.y + dy;
	if (new_x < 0 || new_y < 0
		|| new_y >= game->height / TILE_SIZE
		|| new_x >= game->width / TILE_SIZE)
		return ;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
		game->collected++;
	if (handle_exit(game, new_x, new_y))
		return ;
	update_position(game, new_x, new_y);
}
