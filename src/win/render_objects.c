/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:13:38 by dle-fur           #+#    #+#             */
/*   Updated: 2024/11/29 18:46:44 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_floor(t_game *game, int y, int x)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->img_floor, game->img_width * x,
		game->img_height * y);
}

void	place_wall(t_game *game, int y, int x)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->img_wall, game->img_width * x,
		game->img_height * y);
}

void	place_item(t_game *game, int y, int x)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->img_item, game->img_width * x,
		game->img_height * y);
}

void	place_exit(t_game *game, int y, int x)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->img_exit, game->img_width * x,
		game->img_height * y);
}
