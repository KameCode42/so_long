/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:58:55 by dle-fur           #+#    #+#             */
/*   Updated: 2024/11/29 10:40:00 by david            ###   ########.fr       */
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

void	create_window(t_game *game)
{
	images_objects(game);
	images_player_up(game);
	images_player_down(game);
	images_player_left(game);
	images_player_right(game);
	place_floor(game);
	place_wall(game);
	place_item(game);
	place_exit(game);
	place_player_up(game);
	place_player_down(game);
	place_player_left(game);
	place_player_right(game);
}
