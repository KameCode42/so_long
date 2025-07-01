![so_long](https://github.com/user-attachments/assets/fb91097d-0820-4e7a-98ad-9c24582f02a3)

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

1 = Mur
0	= Sol
P	= Joueur
C	= Collectible
E	= Sortie (accessible une fois les objets ramassés)
