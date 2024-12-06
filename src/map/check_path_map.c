/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:51:58 by david             #+#    #+#             */
/*   Updated: 2024/12/06 12:30:30 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_calc(t_game *game, size_t y, size_t x)
{
	game->map_copy = malloc(game->height * sizeof(bool *));
	if (game->map_copy == NULL)
		return (false);
	y = 0;
	while (y < game->height)
	{
		game->map_copy[y] = malloc(game->width * sizeof(bool));
		if (game->map_copy[y] == NULL)
		{
			free_map_copy(game);
			return (false);
		}
		x = 0;
		while (x < game->width)
		{
			game->map_copy[y][x] = false;
			x++;
		}
		y++;
	}
	return (true);
}

bool	check_path(t_game *game, size_t y, size_t x)
{
	y = 0;
	x = 0;
	
	if (x >= game->width || y >= game->height)
		return (0);
	if (game->map[y][x] == WALL)
		return (0);
	return (true);
}






/*
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


fonction check_path_validity(game)
    VARIABLES :
        - `x_start`, `y_start` : coordonnées de la position initiale du joueur (`P`).
        - `C_count` : nombre total de collectables (`C`) sur la carte.
        - `C_collected` : nombre de collectables ramassés (initialisé à 0).
        - `found_exit` : booléen, vrai si la sortie (`E`) est atteinte (initialisé à FALSE).

    1. **Trouver les positions clés :**
        - Identifier `x_start, y_start` (position de `P`).
        - Compter les `C` pour initialiser `C_count`.

    2. **Préparer la carte de suivi :**
        - Utiliser `game->map_copy` comme matrice booléenne pour marquer les cases visitées.
        - Toutes les cases sont initialisées à FALSE (non visitées).

    3. **Appeler la fonction récursive `explorer` :**
        - Appeler `explorer(game, x_start, y_start, &C_collected, C_count, &found_exit)`.

    4. **Valider le résultat :**
        - Si `C_collected == C_count` **et** `found_exit == TRUE` :
            Retourner TRUE (le chemin est valide).
        - Sinon :
            Retourner FALSE (chemin invalide ou incomplet).





fonction explorer(game, x, y, C_collected, C_count, found_exit)
    VARIABLES :
        - `x, y` : coordonnées de la case actuelle.
        - `C_collected` : pointeur vers le compteur des collectables ramassés.
        - `C_count` : nombre total de collectables.
        - `found_exit` : pointeur vers le booléen indiquant si la sortie est atteinte.

    1. **Vérifications préliminaires :**
 
        - Si `(x, y)` est déjà marquée comme visitée dans `game->map_copy` :
            Retourner (case déjà explorée).

    2. **Traiter la case actuelle :**
        - Marquer `(x, y)` comme visitée dans `game->map_copy`.
        - Si la case contient un collectable (`C`) :
            - Incrémenter `*C_collected`.
        - Si la case est la sortie (`E`) :
            - Si `*C_collected == C_count` :
                - Mettre `*found_exit = TRUE`.

    3. **Explorer les cases voisines :**
        - Appeler récursivement `explorer` dans les 4 directions :
            - `explorer(game, x + 1, y, C_collected, C_count, found_exit)` (vers le bas).
            - `explorer(game, x - 1, y, C_collected, C_count, found_exit)` (vers le haut).
            - `explorer(game, x, y + 1, C_collected, C_count, found_exit)` (vers la droite).
            - `explorer(game, x, y - 1, C_collected, C_count, found_exit)` (vers la gauche).

    4. **Retour :**
        - Retourner lorsque toutes les directions sont explorées.
*/