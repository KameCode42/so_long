/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:51:58 by david             #+#    #+#             */
/*   Updated: 2024/12/07 15:22:06 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_calc(t_game *game)
{
	size_t	y;
	size_t	x;

	game->map_copy = malloc(game->height * sizeof(int *));
	if (game->map_copy == NULL)
		return (false);
	y = 0;
	while (y < game->height)
	{
		game->map_copy[y] = malloc(game->width * sizeof(int));
		if (game->map_copy[y] == NULL)
		{
			free_map_copy(game);
			return (false);
		}
		x = 0;
		while (x < game->width)
		{
			game->map_copy[y][x] = false;
			x++;
		}
		y++;
	}
	return (true);
}

void	check_path(t_game *game, size_t y, size_t x)
{
	if (x >= game->width || y >= game->height)
		return ;
	if (game->map[y][x] == WALL)
		return ;
	if (game->map_copy[y][x] == true)
		return ;
	if (game->map[y][x] == EXIT)
	{
		game->map_copy[y][x] = true;
		return ;
	}
	game->map_copy[y][x] = true;
	if (y + 1 < game->height)
		check_path(game, y + 1, x);
	if (y > 0)
		check_path(game, y - 1, x);
	if (x + 1 < game->width)
		check_path(game, y, x + 1);
	if (x > 0)
		check_path(game, y, x - 1);
}

bool	check_path_valid(t_game *game)
{
	size_t	x;
	size_t	y;

	y = -1;
	if (!map_calc(game))
		return (false);
	check_path(game, game->player_y, game->player_x);
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == ITEM || game->map[y][x] == EXIT)
			{
				if (!game->map_copy[y++][x])
				{
					free_map_copy(game);
					return (false);
				}
			}
			x++;
		}
	}
	free_map_copy(game);
	return (true);
}
