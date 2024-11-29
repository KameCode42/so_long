/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:58:55 by dle-fur           #+#    #+#             */
/*   Updated: 2024/11/29 18:55:08 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initiation_map(t_game *game)
{
	if (!read_map(game))
		return (ft_error(7));
	if (!count_element_map(game))
		return (0);
	if (!valid_map(game))
		return (0);
	return (1);
}

void	create_images(t_game *game)
{
	images_objects(game);
	images_player_up(game);
	images_player_down(game);
	images_player_left(game);
	images_player_right(game);
}

int	create_game(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == FLOOR)
				place_floor(game, y, x);
			if (game->map[y][x] == ITEM)
				place_item(game, y, x);
			if (game->map[y][x] == WALL)
				place_wall(game, y, x);
			if (game->map[y][x] == EXIT)
				place_exit(game, y, x);
			if (game->map[y][x] == PLAYER)
				place_player(game, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
