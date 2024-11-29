/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:42:15 by dle-fur           #+#    #+#             */
/*   Updated: 2024/11/29 10:23:04 by david            ###   ########.fr       */
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

/*---------------------------------------------*/

typedef struct s_game
{
	void	*mlx; // Instance MLX pour gérer le rendu graphique
	void	*mlx_win;// Fenêtre créée via MLX
	void	*img_item;
	void	*img_exit;
	void	*img_wall;
	void	*img_floor;
	void	*img_left1;
	void	*img_left2;
	void	*img_left3;
	void	*img_left4;
	void	*img_right1;
	void	*img_right2;
	void	*img_right3;
	void	*img_right4;
	void	*img_up1;
	void	*img_up2;
	void	*img_up3;
	void	*img_up4;
	void	*img_down1;
	void	*img_down2;
	void	*img_down3;
	void	*img_down4;


	int		player_count;
	int		exit_count;
	int		item_count;
	char	**map;// tableau 2d pour la carte
	char	*map_file;//chemin du fichier
	size_t	height;//hauteur de la map
	size_t	width;//largeur de la map
	size_t	img_height;
	size_t	img_width;
}			t_game;

/*---------------------------------------------*/

int		ft_strcmp(char *s1, char *s2);
int		count_line(t_game *game);
int		count_element_map(t_game *game);
int		valid_map(t_game *game);
int		valid_map_size(t_game *game);
int		initiation_map(t_game *game);
int		ft_error(int error);
int		check_vertical_line(t_game *game);
int		check_horizontal_line(t_game *game);
int		valid_wall_map(t_game *game);
char	**read_map(t_game *game);
void	remove_newline(char *line);
void	free_map(t_game *game);
void	images_objects(t_game *game);
void	images_player_left(t_game *game);
void	images_player_right(t_game *game);
void	images_player_up(t_game *game);
void	images_player_down(t_game *game);
void	place_floor(t_game *game);
void	place_wall(t_game *game);
void	place_item(t_game *game);
void	place_exit(t_game *game);
void	place_player_up(t_game *game);
void	place_player_down(t_game *game);
void	place_player_left(t_game *game);
void	place_player_right(t_game *game);
void	create_window(t_game *game);

#endif