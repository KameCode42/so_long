/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:19:17 by david             #+#    #+#             */
/*   Updated: 2024/11/21 17:32:47 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(t_game *game)
{
	int		fd;
	char	*line;
	int		line_count;
	int		i;

	fd = open(game->map_file, O_RDONLY);
	line_count = count_line(game);
	if (fd < 0)
	{
		ft_printf("Erreur : fichier inexistant\n");
		return (NULL);
	}
	game->map = malloc(sizeof(char *) * (line_count + 1));
	if (game->map == NULL)
		return (NULL);
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		game->map[i++] = line;
	}
	game->map[i] = NULL;
	close(fd);
	return (game->map);
}
