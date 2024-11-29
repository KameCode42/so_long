/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:44:30 by david             #+#    #+#             */
/*   Updated: 2024/11/29 10:37:34 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_player_up(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == PLAYER)
			{
					mlx_put_image_to_window(game->mlx, game->mlx_win,
						game->img_up1, game->img_width * j,
						game->img_height * i);
			}
			j++;
		}
		i++;
	}
}

void	place_player_down(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == PLAYER)
			{
					mlx_put_image_to_window(game->mlx, game->mlx_win,
						game->img_down1, game->img_width * j,
						game->img_height * i);
			}
			j++;
		}
		i++;
	}
}

void	place_player_left(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == PLAYER)
			{
					mlx_put_image_to_window(game->mlx, game->mlx_win,
						game->img_left1, game->img_width * j,
						game->img_height * i);
			}
			j++;
		}
		i++;
	}
}

void	place_player_right(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == PLAYER)
			{
					mlx_put_image_to_window(game->mlx, game->mlx_win,
						game->img_right1, game->img_width * j,
						game->img_height * i);
			}
			j++;
		}
		i++;
	}
}
