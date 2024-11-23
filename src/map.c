/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:19:17 by david             #+#    #+#             */
/*   Updated: 2024/11/22 13:39:10 by david            ###   ########.fr       */
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
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		count_line++;
	}
	close(fd);
	return (count_line);
}

char	**read_map(t_game *game)
{
	int		fd;
	char	*line;
	int		line_count;
	int		i;

	fd = open(game->map_file, O_RDONLY);
	line_count = count_line(game);
	if (fd < 0)
	{
		ft_printf("Erreur : fichier inexistant\n");
		return (NULL);
	}
	game->map = malloc(sizeof(char *) * (line_count + 1));
	if (game->map == NULL)
		return (NULL);
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		game->map[i++] = line;
	}
	game->map[i] = NULL;
	close(fd);
	return (game->map);
}
/*
int	count_element_map(t_game *game, int x, int y)
{
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == PLAYER)
				player_count++;
			x++;
		}
		y++;
	}
	return (0);
}
*/
void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}
