<img width="720" height="450" alt="Image" src="https://github.com/user-attachments/assets/171f686b-ef85-4dd0-9a84-02a0836d96ff" />

# Sujet :
so_long est un projet de jeu en 2D développé avec MiniLibX. L'objectif est de créer un jeu simple dans lequel un joueur doit collecter tous les objets d’une carte et atteindre la sortie pour gagner.

# Fonctionnement :
- Le jeu charge une carte .ber qui représente le terrain sous forme de texte.
- Chaque élément de la carte correspond à une image (sol, mur, joueur, sortie, objet...).
- L'utilisateur déplace son personnage à l'aide du clavier (WASD ou ZQSD).

Le jeu doit :
- Afficher la carte avec les bonnes textures
- Mettre à jour la position du joueur
- Incrémenter un compteur de mouvements
- Vérifier que tous les objets sont ramassés avant d’ouvrir la sortie
- Terminer la partie si le joueur atteint la sortie

La carte est un fichier texte structuré comme ceci : <br>
11111 <br>
1P0C1 <br>
10001 <br>
1C0E1 <br>
11111 <br>

1 = Mur <br>
0	= Sol <br>
P	= Joueur <br>
C	= Collectible <br>
E	= Sortie (accessible une fois les objets ramassés) <br>

# Conditions à respecter :
- Un seul joueur sur la map
- Minimum un item
- Une seul sortie sur la map
- La map doit être rectangulaire
- La map doit être fermée par des murs
- Un chemin valide pour atteindre item et sortie
- Le joueur doit pouvoir se deplacer dans toutes les directions

# Fonctions MLX utiles :
- `mlx_xpm_file_to_image` : permet d'enregistrer l'image xpm dans la structure
- `mlx_put_image_to_window` : permet d'inclure l'image dans la window
- `mlx_destroy_window` : permet de fermer la fenetre proprement
- `mlx_init` : permet d'initialiser la librairie MLX
- `mlx_new_window` : permet de créer une fenetre
- `mlx_key_hook` : permet d'initialiser les differents contrôle du player
- `mlx_hook` : permet de dire au programme quoi faire quand un certain événement se produit, comme appuyer sur une touche ou cliquer avec la souris
- `mlx_loop` : maintient le programme en marche, permettant à la fenêtre de rester ouverte et de réagir aux actions de l'utilisateur

# Compilation et exécution :
<img width="447" height="160" alt="Image" src="https://github.com/user-attachments/assets/fe944665-e07c-4692-8dec-5306e55d97c4" />
<br>
<img width="673" height="425" alt="Image" src="https://github.com/user-attachments/assets/46250321-8a75-4a27-8d59-dd1e4eb3e518" />
