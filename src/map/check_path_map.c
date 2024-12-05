/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:51:58 by david             #+#    #+#             */
/*   Updated: 2024/12/05 16:48:41 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_path(t_game *game)
{
	size_t	x;
	size_t	y;
	size_t	x_end;
	size_t	y_end;

	game->map_copy = malloc(game->height * sizeof(bool *));
	if (game->map_copy == NULL)
		return (false);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		game->map_copy[x] = malloc(game->width * sizeof(bool));
		y++;
		while (x < game->width)
		{
			game->map_copy[y][x] = false;
			x++;
		}
	}
}

bool	check_path_rec(t_game *game)
{
	if (game->map_copy[y][x] == WALL)
		return	(0);
	if (game->copy == true)
		return (0);
	if (x == x_end && y == y_end)
		return (1);
	if (game->map_copy[y][x] == 0)
		game->map_copy[y][x] = 1;
}


Fonction search(x, y):
    b. Si map[x][y] == '1':
        Retourner False (position est un mur)
    c. Si visited[x][y] est True:
        Retourner False (position déjà visitée dans le chemin actuel)
    d. Définir visited[x][y] = True
    e. Initialiser collected_this_node = False
    f. Si map[x][y] == 'C' et (x, y) n'est pas dans collected_positions:
        - collected_c += 1
        - Ajouter (x, y) à collected_positions
        - Définir collected_this_node = True
    g. Si x == E_x et y == E_y:
        - Si collected_c == total_c:
            Retourner True (tous les objets collectés et sortie atteinte)
        - Sinon:
            - Définir visited[x][y] = False
            - Si collected_this_node est True:
                - collected_c -= 1
                - Retirer (x, y) de collected_positions
            Retourner False (tous les objets de collection non collectés)
    h. Pour chaque direction dans [(0, 1), (1, 0), (0, -1), (-1, 0)]:
        - new_x = x + dx
        - new_y = y + dy
        - Si search(new_x, new_y) retourne True:
            Retourner True (chemin valide trouvé)
    i. Définir visited[x][y] = False
    j. Si collected_this_node est True:
        - collected_c -= 1
        - Retirer (x, y) de collected_positions
    k. Retourner False (aucun chemin valide depuis cette position)
