Projet so_long :
- projet qui consiste a creer son propre jeu 2D en vue de face ou vu du haut mettant en scene un personnage
  ramassant un nombre d'item pour deverouiller la sortie et finir le jeu

-------------------------------------------------------------------------------------------------------------

Condition a respecter :
- un seul joueur sur la map
- minimum un item
- une seul sortie sur la map
- la map doit etre rectangulaire
- la map doit etre fermer par des murs
- un chemin valide pour atteindre item et sortie
- le joueur doit pouvoir se deplacer dans toutes les directions

-------------------------------------------------------------------------------------------------------------

Fonctions MLX :

mlx_xpm_file_to_image : permet d'enregistrer l'image xpm dans la structure

mlx_put_image_to_window : permet d'inclure l'image dans la window

mlx_destroy_window : permet de fermer la fenetre proprement

mlx_init : permet d'initialiser la librairie MLX

mlx_new_window : permet de creer une fenetre

mlx_key_hook : permet d'initialiser les differents controle du player

mlx_hook : permet de dire à ton programme quoi faire quand un certain événement se produit, comme appuyer sur une touche ou cliquer avec la souris

mlx_loop : maintient le programme en marche, permettant à ta fenêtre de rester ouverte et de réagir aux actions de l'utilisateur

-------------------------------------------------------------------------------------------------------------

Fonctions map :

check_element_map :
- count line : permet de compter le nombre de ligne que contient la map

- read_map : permet de lire la map ligne par ligne qui se trouve dans le fichier

- count_element_map : permet de compter les elements tels que le player, item et sortie

- check_vertical_map : permet de verifier si les cotes de la map sont fermer par des murs

- check_horizontal_line : permet de verifier si les bords inferieur et superieur sont fermer par des murs

check_path_map :
- check_path = initialise une map copy rempli de false, false signifiant que la case n'a pas encore ete explore
evite de repasser sur une case deja visite




init_map :
- initiation_map : permet d'initialiser la map

- create_image : creer les images utiliser dans le jeu

- valid_map_size : permet de valider que la map est bien rectangulaire

- valid_map_wall : permet de valider que les map est bien entourer de mur

valid_map : effectue les differentes validation sur la carte

-------------------------------------------------------------------------------------------------------------

Fonctions move :

controls :
move_up,down,left,right :
- permet de deplacer le joueur dans toutes les directions
- permet de gerer la collison avec les murs
- permet de rammasser les items et de les compter
- permet de compter le nombre de pas que fais le joueur sur la map
- permet d'atteindre la sortie si tous les items sont rammasser

- controls : permet d'initialiser les differents controle au touche du clavier 

- exit : permet de fermer le jeu et d'afficher un message success si le joueur fini la partie

-------------------------------------------------------------------------------------------------------------

Fonctions win :

create_images_struct :
- images_objects : permet d'enregistrer les images objets xpm dans la structure avec mlx_xpm_file_to_image

- images_player : permet d'enregistrer les images du player xpm dans la structure

render_objects :
- les fonctions place : permettent de placer les images dans la fenetre de jeu avec mlx_put_image_to_window

- create_game : fonction regroupant le placement des sprites 
sur la carte

render_player :
- placer_player : permet de placer toutes les directions du sprite sur la map

-------------------------------------------------------------------------------------------------------------

Fonctions main

check_args :
- permet de checker si les arguments pour lancer le jeu sont valide

init_game :
- regroupe les fonctions pour initialiser la map, creer les images et creer le jeu

setup_hook :
- regroupe les fonctions mlx pour initialiser les controles et gerer les touches clavier et permet de gerer l'evenement de fermeture de la fenetre
17 = code de la fermeture de la fenetre par la croix
0 = aucun filtre n'est appliquer, gerer de facon de globale

close_game
- permet de fermer le jeu proprement avec mlx_destroy_window

-------------------------------------------------------------------------------------------------------------