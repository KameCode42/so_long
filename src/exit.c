/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:48:18 by david             #+#    #+#             */
/*   Updated: 2024/12/13 17:08:01 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	success_game(t_game *game)
{
	if (game->map[game->player_y][game->player_x] == EXIT)
	{
		ft_printf("Success: you finished the game\n");
		close_game(game);
	}
	return (0);
}

void	destroy_images(t_game *game)
{
	if (game->img_item)
		mlx_destroy_image(game->mlx, game->img_item);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_left)
		mlx_destroy_image(game->mlx, game->img_left);
	if (game->img_right)
		mlx_destroy_image(game->mlx, game->img_right);
	if (game->img_up)
		mlx_destroy_image(game->mlx, game->img_up);
	if (game->img_down)
		mlx_destroy_image(game->mlx, game->img_down);
}
