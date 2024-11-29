/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:07:14 by dle-fur           #+#    #+#             */
/*   Updated: 2024/11/29 18:31:34 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images_objects(t_game *game)
{
	int	width;
	int	height;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "./assets/wall.xpm",
			&width, &height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "./assets/floor.xpm",
			&width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "./assets/exit.xpm",
			&width, &height);
	game->img_item = mlx_xpm_file_to_image(game->mlx, "./assets/item.xpm",
			&width, &height);
	game->img_width = width;
	game->img_height = height;
}

void	images_player_left(t_game *game)
{
	int	width;
	int	height;

	game->img_left = mlx_xpm_file_to_image(game->mlx, "./assets/left.xpm",
			&width, &height);
	game->img_width = width;
	game->img_height = height;
}

void	images_player_right(t_game *game)
{
	int	width;
	int	height;

	game->img_right = mlx_xpm_file_to_image(game->mlx, "./assets/right.xpm",
			&width, &height);
	game->img_width = width;
	game->img_height = height;
}

void	images_player_up(t_game *game)
{
	int	width;
	int	height;

	game->img_up = mlx_xpm_file_to_image(game->mlx, "./assets/up.xpm",
			&width, &height);
	game->img_width = width;
	game->img_height = height;
}

void	images_player_down(t_game *game)
{
	int	width;
	int	height;

	game->img_down = mlx_xpm_file_to_image(game->mlx, "./assets/down.xpm",
			&width, &height);
	game->img_width = width;
	game->img_height = height;
}
