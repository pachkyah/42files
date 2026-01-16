/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:41:55 by ypachkou          #+#    #+#             */
/*   Updated: 2026/01/11 13:43:41 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief	Prints an error message and exits the program cleanly.
 * 
 * This function writes "Error\n" followed by the provided message
 * to standard error. It then calls clean_exit() to free all
 * allocated resources and close the program.
 * 
 * @param msg	Error message to display.
 * @param game	Pointer to the t_game structure. Can be NULL if
 *		we are exiting before initialization.
 */
void	error(char *msg, t_game *game)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	clean_exit(game);
}
