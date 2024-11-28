/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:51:28 by dle-fur           #+#    #+#             */
/*   Updated: 2024/11/28 19:44:12 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_args(int argc, char **argv)
{
	int	len;

	len = ft_strlen(argv[1]);
	if (argc != 2)
		return (ft_error(1));
	if (ft_strcmp(&argv[1][len - 4], ".ber") != 0)
		return (ft_error(2));
	return (0);
}

static int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (check_args(argc, argv))
		return (1);
	ft_memset(&game, 0, sizeof(t_game));
	game.map_file = argv[1];
	if (!initiation_map(&game))
		return (1);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.width * 32,
			game.height * 32, "so_long");
	create_window(&game);
	mlx_hook(game.mlx_win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	free_map(&game);
	return (0);
}
