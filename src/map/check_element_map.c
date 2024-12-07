/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:19:17 by david             #+#    #+#             */
/*   Updated: 2024/12/07 10:16:22 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(t_game *game)
{
	int		fd;
	char	*line;
	int		count_line;

	fd = open(game->map_file, O_RDONLY);
	if (fd < 0)
		return (-1);
	count_line = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		count_line++;
	}
	close(fd);
	if (count_line == 0)
		return (ft_error(8));
	return (count_line);
}

char	**read_map(t_game *game)
{
	int		fd;
	char	*line;
	int		line_count;
	int		i;

	line_count = count_line(game);
	fd = open(game->map_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	game->map = malloc(sizeof(char *) * (line_count + 1));
	if (game->map == NULL)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		remove_newline(line);
		game->map[i++] = line;
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	close(fd);
	game->height = line_count;
	game->width = ft_strlen(game->map[0]);
	return (game->map);
}

int	count_element_map(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == PLAYER)
			{
				game->player_count++;
				game->player_y = y;
				game->player_x = x;
			}
			if (game->map[y][x] == EXIT)
				game->exit_count++;
			if (game->map[y][x] == ITEM)
				game->total_items++;
			x++;
		}
		y++;
	}
	return (0);
}

int	check_vertical_line(t_game *game)
{
	size_t	y;

	y = 0;
	while (game->map[y] != NULL)
	{
		if (game->map[y][0] != WALL)
			return (1);
		if (game->map[y][game->width - 1] != WALL)
			return (1);
		y++;
	}
	return (0);
}

int	check_horizontal_line(t_game *game)
{
	size_t	x;

	x = 0;
	while (game->map[0][x] != '\0')
	{
		if (game->map[0][x] != WALL)
			return (1);
		x++;
	}
	x = 0;
	while (game->map[game->height - 1][x] != '\0')
	{
		if (game->map[game->height - 1][x] != WALL)
			return (1);
		x++;
	}
	return (0);
}
