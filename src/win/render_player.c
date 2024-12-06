/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:44:30 by david             #+#    #+#             */
/*   Updated: 2024/12/06 15:39:40 by dle-fur          ###   ########.fr       */
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
