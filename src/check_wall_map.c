/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:35:00 by david             #+#    #+#             */
/*   Updated: 2024/11/28 13:49:09 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_vertical_line(t_game *game)
{
	size_t	rows;

	rows = 0;
	while (game->map[rows] != NULL)
	{
		if (game->map[rows][0] != WALL)
			return (0);
		if (game->map[rows][ft_strlen(game->map[rows]) - 1] != WALL)
			return (0);
		rows++;
	}
	return (1);
}

int	check_horizontal_line(t_game *game)
{
	size_t	rows;
	size_t	cols;

	rows = 0;
	while (game->map[rows] != NULL)
		rows++;
	cols = 0;
	while (game->map[0][cols] != '\0')
	{
		if (game->map[0][cols] != WALL)
			return (0);
		cols++;
	}
	cols = 0;
	while (game->map[rows - 1][cols] != '\0')
	{
		if (game->map[rows - 1][cols] != WALL)
			return (0);
		cols++;
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
