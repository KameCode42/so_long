/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:44:30 by david             #+#    #+#             */
/*   Updated: 2024/12/06 10:16:15 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_player(t_game *game, int y, int x)
{
	void	*img;
	
	if (game->direction == RIGHT)
		img = game->img_right;
	else if (game->direction == LEFT)
		img = game->img_left;
	else if (game->direction == DOWN)
		img = game->img_down;
	else
		img = game->img_up;
	
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		img, game->img_width * x, game->img_height * y);
		
	game->player_y = y;
	game->player_x = x;
}
