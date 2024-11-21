/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:35:24 by david             #+#    #+#             */
/*   Updated: 2024/11/21 17:36:27 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

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

int	count_element_map(t_game *game)
{
	int	y;
	int	x;
	int	player_count;
	int	exit_count;
	int	item_count;

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
