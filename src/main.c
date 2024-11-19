/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:51:28 by dle-fur           #+#    #+#             */
/*   Updated: 2024/11/19 15:40:31 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_args(int argc, char **argv)
{
	int	len;

	len = ft_strlen(argv[1]);
	if (argc != 2)
	{
		ft_printf("Erreur : nombre d'arguments invalide");
		return (1);
	}
	if (ft_strcmp(&argv[1][len - 4], ".ber") != 0)
	{
		ft_printf("Erreur : le fichier doit avoir l'extension .ber");
		return (1);
	}
	return (0);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (check_args(argc, argv))
		return (1);
	
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, 1920, 1080, "hello");
	
	mlx_hook(game.mlx_win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
