/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:58:55 by dle-fur           #+#    #+#             */
/*   Updated: 2024/12/05 10:52:41 by david            ###   ########.fr       */
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

int	valid_wall_map(t_game *game)
{
	if (!check_vertical_line(game))
		return (0);
	if (!check_horizontal_line(game))
		return (0);
	return (1);
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
	if (!valid_wall_map(game))
		return (ft_error(9));
	return (1);
}
