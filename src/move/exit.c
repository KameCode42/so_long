/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:48:18 by david             #+#    #+#             */
/*   Updated: 2024/12/05 13:14:46 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	success_game(t_game *game)
{
	if (game->map[game->player_y][game->player_x] == EXIT)
	{
		if (game->count_items < game->total_items)
			return (1);
		else
		{
			ft_printf("Success: you finished the game\n");
			close_game(game);
		}
	}
	return (0);
}
