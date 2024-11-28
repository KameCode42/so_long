/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:19:17 by david             #+#    #+#             */
/*   Updated: 2024/11/28 13:45:22 by david            ###   ########.fr       */
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
				game->player_count++;
			if (game->map[y][x] == EXIT)
				game->exit_count++;
			if (game->map[y][x] == ITEM)
				game->item_count++;
			x++;
		}
		y++;
	}
	return (1);
}

int	valid_map_size(t_game *game)
{
	size_t	i;

	if (!game->map || !game->map[0])
		return (0);
	game->width = ft_strlen(game->map[0]);
	game->height = 0;
	while (game->map[game->height])
		game->height++;
	i = 0;
	while (i < game->height)
	{
		if (ft_strlen(game->map[i]) != game->width)
			return (0);
		i++;
	}
	return (1);
}

int	valid_map(t_game *game)
{
	if (!valid_map_size(game))
		return (ft_error(3));
	if (game->player_count != 1)
		return (ft_error(4));
	if (game->item_count < 1)
		return (ft_error(5));
	if (game->exit_count != 1)
		return (ft_error(6));
	if (!valid_wall_map(game))
		return (ft_error(9));
	return (1);
}
