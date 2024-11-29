/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game_objects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:13:38 by dle-fur           #+#    #+#             */
/*   Updated: 2024/11/29 09:40:49 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_floor(t_game *game)
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

void	place_wall(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
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
			j++;
		}
		i++;
	}
}

void	place_item(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == ITEM)
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img_item, game->img_width * j,
					game->img_height * i);
			}
			j++;
		}
		i++;
	}
}

void	place_exit(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (game->map[i][j])
		{
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
