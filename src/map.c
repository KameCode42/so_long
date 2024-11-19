/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:19:17 by david             #+#    #+#             */
/*   Updated: 2024/11/19 16:09:22 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_game game)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(game->map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Erreur : aucun fichier");
		return (1);
	}
	game->map = malloc(sizeof(char) * 100);
	if (game->map == NULL)
		return (NULL);
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		game->map[i++] = line;
	}
}
