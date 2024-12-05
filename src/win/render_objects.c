/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:13:38 by dle-fur           #+#    #+#             */
/*   Updated: 2024/12/05 14:06:56 by dle-fur          ###   ########.fr       */
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
	ft_printf("Number of movements = %d\n", game->count_move);
	return (0);
}
