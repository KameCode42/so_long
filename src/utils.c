/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:35:24 by david             #+#    #+#             */
/*   Updated: 2024/12/07 14:03:25 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

bool	free_map_copy(t_game *game)
{
	size_t	y;

	if (game->map_copy == NULL)
		return (false);
	y = game->height;
	while (y > 0)
	{
		y--;
		if (game->map_copy[y] != NULL)
			free(game->map_copy[y]);
	}
	free(game->map_copy);
	game->map_copy = NULL;
	return (true);
}

int	ft_error(int error)
{
	if (error == 1)
		ft_printf("Error\n: invalid number of arguments\n");
	if (error == 2)
		ft_printf("Error\n: file must have .ber extension\n");
	if (error == 3)
		ft_printf("Error\n: the map is not rectangular\n");
	if (error == 4)
		ft_printf("Error\n: the map must contain only one player\n");
	if (error == 5)
		ft_printf("Error\n: the map must contain at least one item\n");
	if (error == 6)
		ft_printf("Error\n: the map must contain at least one exit\n");
	if (error == 7)
		ft_printf("Error\n: File does not exist\n");
	if (error == 8)
		ft_printf("Error\n: map file is empty\n");
	if (error == 9)
		ft_printf("Error\n: invalid character\n");
	if (error == 10)
		ft_printf("Error\n: invalid path\n");
	return (1);
}

void	remove_newline(char *line)
{
	size_t	len;

	if (line == NULL)
		return ;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}
