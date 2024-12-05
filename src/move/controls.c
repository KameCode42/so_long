/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:39:16 by dle-fur           #+#    #+#             */
/*   Updated: 2024/12/05 13:13:30 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] != WALL &&
			(game->map[game->player_y - 1][game->player_x] != EXIT ||
			game->count_items == game->total_items))
	{
		game->direction = UP;
		if (game->map[game->player_y][game->player_x] != EXIT)
			game->map[game->player_y][game->player_x] = FLOOR;
		game->count_move++;
		ft_printf("number of movements = %d\n", game->count_move);
		if (game->map[game->player_y - 1][game->player_x] == ITEM)
		{
			game->count_items++;
			ft_printf("item collect = %d\n", game->count_items);
		}
		if (game->map[game->player_y - 1][game->player_x] != EXIT)
			game->map[game->player_y - 1][game->player_x] = PLAYER;
		game->player_y -= 1;
		success_game(game);
	}
	create_game(game);
}

void	move_down(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] != WALL &&
			(game->map[game->player_y + 1][game->player_x] != EXIT ||
			game->count_items == game->total_items))
	{
		game->direction = DOWN;
		if (game->map[game->player_y][game->player_x] != EXIT)
			game->map[game->player_y][game->player_x] = FLOOR;
		game->count_move++;
		ft_printf("number of movements = %d\n", game->count_move);
		if (game->map[game->player_y + 1][game->player_x] == ITEM)
		{
			game->count_items++;
			ft_printf("item collect = %d\n", game->count_items);
		}
		if (game->map[game->player_y + 1][game->player_x] != EXIT)
			game->map[game->player_y + 1][game->player_x] = PLAYER;
		game->player_y += 1;
		success_game(game);
	}
	create_game(game);
}

void	move_left(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] != WALL &&
			(game->map[game->player_y][game->player_x - 1] != EXIT ||
			game->count_items == game->total_items))
	{
		game->direction = LEFT;
		if (game->map[game->player_y][game->player_x] != EXIT)
			game->map[game->player_y][game->player_x] = FLOOR;
		game->count_move++;
		ft_printf("number of movements = %d\n", game->count_move);
		if (game->map[game->player_y][game->player_x - 1] == ITEM)
		{
			game->count_items++;
			ft_printf("item collect = %d\n", game->count_items);
		}
		if (game->map[game->player_y][game->player_x - 1] != EXIT)
			game->map[game->player_y][game->player_x - 1] = PLAYER;
		game->player_x -= 1;
		success_game(game);
	}
	create_game(game);
}

void	move_right(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] != WALL &&
			(game->map[game->player_y][game->player_x + 1] != EXIT ||
			game->count_items == game->total_items))
	{
		game->direction = RIGHT;
		if (game->map[game->player_y][game->player_x] != EXIT)
			game->map[game->player_y][game->player_x] = FLOOR;
		game->count_move++;
		ft_printf("number of movements = %d\n", game->count_move);
		if (game->map[game->player_y][game->player_x + 1] == ITEM)
		{
			game->count_items++;
			ft_printf("item collect = %d\n", game->count_items);
		}
		if (game->map[game->player_y][game->player_x + 1] != EXIT)
			game->map[game->player_y][game->player_x + 1] = PLAYER;
		game->player_x += 1;
		success_game(game);
	}
	create_game(game);
}

int	controls(int key, t_game *game)
{
	if (key == KEY_ESC)
		close_game(game);
	if (key == KEY_W || key == KEY_UP)
		move_up(game);
	if (key == KEY_S || key == KEY_DOWN)
		move_down(game);
	if (key == KEY_A || key == KEY_LEFT)
		move_left(game);
	if (key == KEY_D || key == KEY_RIGHT)
		move_right(game);
	return (0);
}
