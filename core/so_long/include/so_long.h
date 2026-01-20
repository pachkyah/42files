/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:14:45 by ypachkou          #+#    #+#             */
/*   Updated: 2026/01/11 14:52:12 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//---stdlibs---
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

//---MLX/X11 Libs---
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>

# include "libft.h"

//---Size---
# define TILE_SIZE 64

//---Keycodes for Linux/X11---
# define KEY_ESC 65307
# define KEY_W   119
# define KEY_A   97
# define KEY_S   115
# define KEY_D   100

// Map element counts for validation
typedef struct s_check
{
	int	player;
	int	exit;
	int	collect;
}	t_check;

// Position helper
typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

// Game state
typedef struct s_game
{
	void	*mlx;
	void	*win;

	char	**map;
	int		width;
	int		height;

	t_pos	player;
	int		collected;
	int		total_collect;
	int		moves;

	void	*wall_img;
	void	*floor_img;
	void	*player_img;
	void	*collect_img;
	void	*exit_img;
}	t_game;

//---Map---
char	**read_map(char *file, t_game *game);
void	validate_map(t_game *game);
void	validate_paths(t_game *game);
void	free_map(char **map);
int		map_height(char **map);

//---Map Helpers ---
void	check_walls(t_game *game);
void	check_elements_and_count(t_game *game, t_check *t);
t_pos	find_player(t_game *game);

//---Game Logic---
void	move_player(t_game *game, int dx, int dy);
int		key_hook(int key, t_game *game);

//---Rendering---
void	render_map(t_game *game);
void	load_textures(t_game *game);

//---Utilities / Errors---
void	error(char *msg, t_game *game);
void	clean_exit(t_game *game);
int		close_window(t_game *game);
void	validate_ber_extension(char *filename, t_game *game);

#endif
