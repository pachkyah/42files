/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 02:44:32 by ypachkou          #+#    #+#             */
/*   Updated: 2026/01/11 13:45:16 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief	Handles key presses and moves the player or exits.
 * 
 * This function is registered as the key hook callback for MiniLibX.
 * Depending on the key pressed, it moves the player in the corresponding
 * direction or exits the game if ESC is pressed.
 * 
 * @param key	Keycode of the pressed key.
 * @param game	Pointer to the t_game structure containing game state.
 * 
 * @return int	Always returns 0 (required by MiniLibX hook signature).
 */
int	key_hook(int key, t_game *game)
{
	if (key == KEY_ESC)
		clean_exit(game);
	else if (key == KEY_W)
		move_player(game, 0, -1);
	else if (key == KEY_S)
		move_player(game, 0, 1);
	else if (key == KEY_A)
		move_player(game, -1, 0);
	else if (key == KEY_D)
		move_player(game, 1, 0);
	return (0);
}
