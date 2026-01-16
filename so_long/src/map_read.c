/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:07:52 by ypachkou          #+#    #+#             */
/*   Updated: 2026/01/11 14:28:11 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Free a NULL-terminated 2D map array.
 * 
 * Frees each row, then the array itself.
 * Safe to call with NULL.
 * 
 * @param map The map array to free.
 */
void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/**
 * @brief Add a line to a map array.
 * 
 * Allocates a new map array with one additional line,
 * duplicates existing lines, trims the newline from the
 * new line, frees the old map, and returns the new array.
 * 
 * @param map Current map array (can be NULL for first line).
 * @param line Line to add.
 * @return char** New map array with the line added, or NULL on failure.
 */
static char	**add_line(char **map, char *line)
{
	char	**new_map;
	int		i;
	int		count;

	count = 0;
	while (map && map[count])
		count++;
	new_map = malloc(sizeof(char *) * (count + 2));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	new_map[count] = ft_strtrim(line, "\n");
	new_map[count + 1] = NULL;
	free_map(map);
	return (new_map);
}

/**
 * @brief Read a map from a .ber file.
 * 
 * Opens the file, reads it line by line using get_next_line,
 * and builds a NULL-terminated 2D map array.
 * Frees temporary lines and handles errors if the file
 * cannot be opened or if the map is empty.
 * 
 * @param file Path to the map file.
 * @param game Pointer to the game struct for error handling.
 * @return char** The allocated 2D map array.
 */
char	**read_map(char *file, t_game *game)
{
	int		fd;
	char	*line;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Cannot open map", game);
	map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		map = add_line(map, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!map)
		error("Empty map", game);
	return (map);
}
