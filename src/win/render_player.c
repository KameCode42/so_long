/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:44:30 by david             #+#    #+#             */
/*   Updated: 2024/11/29 18:29:31 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_player(t_game *game, int y, int x)
{
	if (game->direction == RIGHT)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img_right, game->img_width * x,
			game->img_height * y);
		game->player_y = y;
		game->player_x = x;
	}
	else if (game->direction == LEFT)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img_left, game->img_width * x,
			game->img_height * y);
		game->player_y = y;
		game->player_x = x;
	}
	else if (game->direction == DOWN)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img_down, game->img_width * x,
			game->img_height * y);
		game->player_y = y;
		game->player_x = x;
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img_up, game->img_width * x,
			game->img_height * y);
		game->player_y = y;
		game->player_x = x;
	}
}
