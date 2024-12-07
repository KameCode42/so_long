/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:48:18 by david             #+#    #+#             */
/*   Updated: 2024/12/07 16:44:33 by dle-fur          ###   ########.fr       */
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
