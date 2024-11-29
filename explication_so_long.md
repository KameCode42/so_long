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
mlx_hook :
mlx_loop : 

-------------------------------------------------------------------------------------------------------------

Fonctions map :

check_element_map :
- count line : permet de compter le nombre de ligne que contient la map
- read_map : permet de lire la map ligne par ligne qui se trouve dans le fichier
- count_element_map : permet de compter les elements tels que le player, item et sortie
- valid_map_size : permet de valider que la map est bien rectangulaire
- valide_map : fonction regroupant les fonctions check

check_path_map :


check_wall_map :
- check_vertical_map : permet de verifier si les cotes de la map sont fermer par des murs
- check_horizontal_line : permet de verifier si les bords inferieur et superieur sont fermer par des murs
  valid_wall_map : fonction regroupant les fonctions check

init_map :
- initiation_map : permet d'initialiser la map

-------------------------------------------------------------------------------------------------------------

Fonctions create :

create_game_struct
- images_objects : permet d'enregistrer les images objets xpm dans la structure
- images_player : permet d'enregistrer les images du player xpm dans la structure

creat_game_objects
- les fonctions place_... permettent de placer les images dans la windows

create_window
- fonctions regroupant les fonctions permettant d'afficher les sprites a l'ecran

-------------------------------------------------------------------------------------------------------------

Fonctions main

check_args
- permet de checker si les arguments pour lancer le jeu sont valide
close_game
- permet de fermer le jeu proprement

-------------------------------------------------------------------------------------------------------------