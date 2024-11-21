/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:42:15 by dle-fur           #+#    #+#             */
/*   Updated: 2024/11/21 17:20:46 by dle-fur          ###   ########.fr       */
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
	char	**map;// tableau 2d pour la carte
	char	*map_file;//chemin du fichier
	int		height;//hauteur de la map
	int		width;//largeur de la map
	int		player_x;
	int		player_y;
	int		items;
}			t_game;

/*---------------------------------------------*/

int		ft_strcmp(char *s1, char *s2);
int		count_line(t_game *game);
void	free_map(t_game *game);
char	**read_map(t_game *game);

#endif