/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:35:00 by david             #+#    #+#             */
/*   Updated: 2024/11/28 14:23:38 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_vertical_line(t_game *game)
{
	size_t	y;

	y = 0;
	while (game->map[y] != NULL)
	{
		if (game->map[y][0] != WALL)
			return (0);
		if (game->map[y][game->width - 1] != WALL)
			return (0);
		y++;
	}
	return (1);
}

int	check_horizontal_line(t_game *game)
{
	size_t	x;

	x = 0;
	while (game->map[0][x] != '\0')
	{
		if (game->map[0][x] != WALL)
			return (0);
		x++;
	}
	x = 0;
	while (game->map[game->height - 1][x] != '\0')
	{
		if (game->map[game->height - 1][x] != WALL)
			return (0);
		x++;
	}
	return (1);
}

int	valid_wall_map(t_game *game)
{
	if (!check_vertical_line(game))
		return (0);
	if (!check_horizontal_line(game))
		return (0);
	return (1);
}
