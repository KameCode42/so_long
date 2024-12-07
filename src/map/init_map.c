/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:58:55 by dle-fur           #+#    #+#             */
/*   Updated: 2024/12/07 14:00:38 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initiation_map(t_game *game)
{
	if (!read_map(game))
		return (ft_error(7));
	if (count_element_map(game))
		return (1);
	if (valid_map(game))
		return (1);
	return (0);
}

void	create_images(t_game *game)
{
	images_objects(game);
	images_player_up(game);
	images_player_down(game);
	images_player_left(game);
	images_player_right(game);
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

int	valid_char_map(t_game *game)
{
	size_t	x;
	size_t	y;

	if (check_vertical_line(game))
		return (1);
	if (check_horizontal_line(game))
		return (1);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] != FLOOR && game->map[y][x] != WALL
			&& game->map[y][x] != EXIT && game->map[y][x] != ITEM
			&& game->map[y][x] != PLAYER)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	valid_map(t_game *game)
{
	if (!valid_map_size(game))
		return (ft_error(3));
	if (game->player_count != 1)
		return (ft_error(4));
	if (game->total_items < 1)
		return (ft_error(5));
	if (game->exit_count != 1)
		return (ft_error(6));
	if (valid_char_map(game))
		return (ft_error(9));
	if (!check_path_valid(game))
		return (ft_error(10));
	return (0);
}
