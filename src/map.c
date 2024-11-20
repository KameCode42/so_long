/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:19:17 by david             #+#    #+#             */
/*   Updated: 2024/11/20 16:34:24 by david            ###   ########.fr       */
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
/*
char	**read_map(t_game *game)
{
	int		fd;
	char	*line;
	int		count_line;

	fd = open(game->map_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
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
