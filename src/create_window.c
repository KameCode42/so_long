/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:13:38 by dle-fur           #+#    #+#             */
/*   Updated: 2024/11/28 20:00:42 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_fond(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (game->map[i][j])
		{
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->img_floor, game->img_width * j,
				game->img_height * i);
			j++;
		}
		i++;
	}
}

void	create_game(t_game *game)
{
	images_objets(game);
	images_player_hd(game);
	images_player_lr(game);
	place_fond(game);
}
	/*
	while (i < game->height)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == WALL)
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img_wall, game->img_width * j,
					game->img_height * i);
			}
			if (game->map[i][j] == FLOOR)
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img_floor, game->img_width * j,
					game->img_height * i);
			}
			if (game->map[i][j] == PLAYER)
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img_haut1, game->img_width * j,
					game->img_height * i);
			}
			if (game->map[i][j] == ITEM)
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img_item, game->img_width * j,
					game->img_height * i);
			}
			if (game->map[i][j] == EXIT)
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img_exit, game->img_width * j,
					game->img_height * i);
			}
			j++;
		}
		i++;
	}
}
*/

void	create_window(t_game *game)
{
	create_game(game);
}
