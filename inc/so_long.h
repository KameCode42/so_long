/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:42:15 by dle-fur           #+#    #+#             */
/*   Updated: 2024/11/29 18:46:05 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "../libraries/libft/libft.h"
# include "../libraries/mlx/mlx.h"

/*---------------------------------------------*/

# define PLAYER 'P'
# define ITEM 'C'
# define EXIT 'E'
# define WALL '1'
# define FLOOR '0'
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define TRUE 1
# define FALSE 0
# define UP 1
# define DOWN 2
# define LEFT 3
# define RIGHT 4

/*---------------------------------------------*/

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*img_item;
	void	*img_exit;
	void	*img_wall;
	void	*img_floor;
	void	*img_left;
	void	*img_right;
	void	*img_up;
	void	*img_down;


	int		player_count;
	int		exit_count;
	int		item_count;
	size_t	player_y;
	size_t	player_x;
	char	**map;
	char	*map_file;
	size_t	height;
	size_t	width;
	size_t	img_height;
	size_t	img_width;
	int		direction;
}			t_game;

/*---------------------------------------------*/

//map
int		count_line(t_game *game);
char	**read_map(t_game *game);
int		count_element_map(t_game *game);
int		valid_map_size(t_game *game);
int		valid_map(t_game *game);
int		check_vertical_line(t_game *game);
int		check_horizontal_line(t_game *game);
int		valid_wall_map(t_game *game);
int		initiation_map(t_game *game);
void	create_images(t_game *game);
int		create_game(t_game *game);

//move
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
int		controls(int key, t_game *game);

//win
void	images_objects(t_game *game);
void	images_player_left(t_game *game);
void	images_player_right(t_game *game);
void	images_player_up(t_game *game);
void	images_player_down(t_game *game);
void	place_floor(t_game *game, int y, int x);
void	place_wall(t_game *game, int y, int x);
void	place_item(t_game *game, int y, int x);
void	place_exit(t_game *game, int y, int x);
void	place_player(t_game *game, int y, int x);

//main
int		close_game(t_game *game);

//utils
int		ft_strcmp(char *s1, char *s2);
void	free_map(t_game *game);
int		ft_error(int error);
void	remove_newline(char *line);

#endif