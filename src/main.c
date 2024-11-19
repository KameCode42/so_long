/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:51:28 by dle-fur           #+#    #+#             */
/*   Updated: 2024/11/18 17:00:59 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, 1920, 1080, "hello");
	mlx_loop(game.mlx);
	//mlx_destroy_window(game.mlx, game.mlx_win);
	//mlx_destroy_display(game.mlx);
	close_game(&game);
	return (0);
}
