/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:39:16 by dle-fur           #+#    #+#             */
/*   Updated: 2024/11/29 17:25:26 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	game->direction = UP;
	game->map[game->player_y][game->player_x] = FLOOR;
	game->map[game->player_y - 1][game->player_x] = PLAYER;
	create_game(game);
}

void	move_down(t_game *game)
{
	game->direction = DOWN;
	game->map[game->player_y][game->player_x] = FLOOR;
	game->map[game->player_y + 1][game->player_x] = PLAYER;
	create_game(game);
}

void	move_left(t_game *game)
{
	game->direction = LEFT;
	game->map[game->player_y][game->player_x] = FLOOR;
	game->map[game->player_y][game->player_x - 1] = PLAYER;
	create_game(game);
}

void	move_right(t_game *game)
{
	game->direction = RIGHT;
	game->map[game->player_y][game->player_x] = FLOOR;
	game->map[game->player_y][game->player_x + 1] = PLAYER;
	create_game(game);
}

int	controls(int key, t_game *game)
{
	if (key == KEY_ESC)
	{
		close_game(game);
	}
	if (key == KEY_W || key == KEY_UP)
	{
		move_up(game);
	}
	if (key == KEY_S || key == KEY_DOWN)
	{
		move_down(game);
	}
	if (key == KEY_A || key == KEY_LEFT)
	{
		move_left(game);
	}
	if (key == KEY_D || key == KEY_RIGHT)
	{
		move_right(game);
	}
	return (0);
}
