/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:19:17 by david             #+#    #+#             */
/*   Updated: 2024/11/23 20:27:11 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(t_game *game)
{
	int		fd;
	char	*line;
	int		count_line;

	fd = open(game->map_file, O_RDONLY);
	if (fd < 0)
		return (-1);
	count_line = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		count_line++;
	}
	close(fd);
	return (count_line);
}

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
	game->height = line_count;
	game->width = ft_strlen(game->map[0]);
	return (game->map);
}

int	count_element_map(t_game *game)
{
	size_t	x;
	size_t	y;

	game->player_count = 0;
	game->item_count = 0;
	game->exit_count = 0;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == PLAYER)
				game->player_count++;
			if (game->map[y][x] == EXIT)
				game->exit_count++;
			if (game->map[y][x] == ITEM)
				game->item_count++;
			x++;
		}
		y++;
	}
	return (1);
}

int	valid_map_size(t_game *game)
{
	size_t	i;

	if (!game->map || !game->map[0])
		return (0);
	game->width = ft_strlen(game->map[0]);
	game->height = 0;
	while (game->map[game->height])
		game->height++;
	ft_printf("Dimensions calculées : largeur = %d, hauteur = %d\n", game->width, game->height);
	i = 0;
	while (i < game->height)
	{
		if (ft_strlen(game->map[i]) != game->width)
			return (0);
		i++;
	}
	return (1);
}

int	valid_map(t_game *game)
{
	if (!valid_map_size(game))
	{
		ft_printf("Erreur la carte n est pas rectangulaire\n");
		return (0);
	}
	if (game->player_count != 1)
	{
		ft_printf("la map doit contenir un seul joueur\n");
		return (0);
	}
	if (game->item_count < 1)
	{
		ft_printf("la map doit contenir au moins un item");
		return (0);
	}
	if (game->exit_count != 1)
	{
		ft_printf("la map doit contenir au moins une sortie\n");
		return (0);
	}
	return (1);
}
