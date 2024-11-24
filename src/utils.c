/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:35:24 by david             #+#    #+#             */
/*   Updated: 2024/11/24 17:50:36 by dle-fur          ###   ########.fr       */
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

int	ft_error(int error)
{
	if (error == 1)
		ft_printf("Error: invalid number of arguments\n");
	if (error == 2)
		ft_printf("Error: file must have .ber extension\n");
	if (error == 3)
		ft_printf("Error: the map is not rectangular\n");
	if (error == 4)
		ft_printf("Error: the map must contain only one player\n");
	if (error == 5)
		ft_printf("Error: the map must contain at least one item\n");
	if (error == 6)
		ft_printf("Error: the map must contain at least one exit\n");
	if (error == 7)
		ft_printf("Error: File does not exist\n");
	if (error == 8)
		ft_printf("Error: map file is empty\n");
	return (0);
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
