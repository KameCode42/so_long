/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:07:14 by dle-fur           #+#    #+#             */
/*   Updated: 2024/11/29 10:22:51 by david            ###   ########.fr       */
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

	game->img_left1 = mlx_xpm_file_to_image(game->mlx, "./assets/left1.xpm",
			&width, &height);
	game->img_left2 = mlx_xpm_file_to_image(game->mlx, "./assets/left2.xpm",
			&width, &height);
	game->img_left3 = mlx_xpm_file_to_image(game->mlx, "./assets/left3.xpm",
			&width, &height);
	game->img_left4 = mlx_xpm_file_to_image(game->mlx, "./assets/left4.xpm",
			&width, &height);
	game->img_width = width;
	game->img_height = height;
}

void	images_player_right(t_game *game)
{
	int	width;
	int	height;

	game->img_right1 = mlx_xpm_file_to_image(game->mlx, "./assets/right1.xpm",
			&width, &height);
	game->img_right2 = mlx_xpm_file_to_image(game->mlx, "./assets/right2.xpm",
			&width, &height);
	game->img_right3 = mlx_xpm_file_to_image(game->mlx, "./assets/right3.xpm",
			&width, &height);
	game->img_right4 = mlx_xpm_file_to_image(game->mlx, "./assets/right4.xpm",
			&width, &height);
	game->img_width = width;
	game->img_height = height;
}

void	images_player_up(t_game *game)
{
	int	width;
	int	height;

	game->img_up1 = mlx_xpm_file_to_image(game->mlx, "./assets/up1.xpm",
			&width, &height);
	game->img_up2 = mlx_xpm_file_to_image(game->mlx, "./assets/up2.xpm",
			&width, &height);
	game->img_up3 = mlx_xpm_file_to_image(game->mlx, "./assets/up3.xpm",
			&width, &height);
	game->img_up4 = mlx_xpm_file_to_image(game->mlx, "./assets/up4.xpm",
			&width, &height);
	game->img_width = width;
	game->img_height = height;
}

void	images_player_down(t_game *game)
{
	int	width;
	int	height;

	game->img_down1 = mlx_xpm_file_to_image(game->mlx, "./assets/down1.xpm",
			&width, &height);
	game->img_down2 = mlx_xpm_file_to_image(game->mlx, "./assets/down2.xpm",
			&width, &height);
	game->img_down3 = mlx_xpm_file_to_image(game->mlx, "./assets/down3.xpm",
			&width, &height);
	game->img_down4 = mlx_xpm_file_to_image(game->mlx, "./assets/down4.xpm",
			&width, &height);
	game->img_width = width;
	game->img_height = height;
}
