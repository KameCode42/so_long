/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:51:58 by david             #+#    #+#             */
/*   Updated: 2024/11/28 14:18:24 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_coordinates_map(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][ft_strlen(game->map[x]) - 1] != '\0')
		{
			x++;
		}
		y++;
	}
	return (1);
}
