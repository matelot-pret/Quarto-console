# Jeu de Quarto

![Language](https://img.shields.io/badge/language-C-blue.svg)
![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey.svg)
![License](https://img.shields.io/badge/license-Educational-green.svg)

## Description

Ce projet implémente le jeu de **Quarto** en langage C. Il s'agit d'un projet réalisé dans le cadre du cours de **Méthodes de Programmation**.

Le Quarto est un jeu de stratégie pour deux joueurs qui se joue sur un plateau de 4×4 cases avec 16 pièces différentes. Chaque pièce possède 4 caractéristiques binaires :

- **Taille** : grande ou petite
- **Forme** : carrée ou ronde
- **Couleur** : claire ou foncée
- **Surface** : pleine ou creuse

## Objectif du jeu

Le but est d'aligner 4 pièces qui partagent au moins une caractéristique commune (même taille, même forme, même couleur ou même surface) horizontalement, verticalement ou en diagonale.

La particularité du Quarto est que c'est l'adversaire qui choisit la pièce que vous devez jouer !

## Structure du projet

```
├── src/                # Code source
│   ├── fonctions.c     # Implémentation des fonctions
│   ├── fonctions.h     # Déclarations des fonctions et structures
│   └── play.c          # Programme principal
├── docs/               # Documentation
│   ├── Quarto.txt      # Algorithme en pseudo-code
│   └── FonctionQuarto.txt # Description des fonctions
├── README.md           # Ce fichier
└── .gitignore          # Fichiers à ignorer par Git
```

## Compilation et exécution

### Prérequis

- Compilateur C (gcc, clang, ou Visual Studio)
- Make (optionnel)

#### Installation d'un compilateur C sur Windows

1. **MinGW-w64** : Télécharger depuis [mingw-w64.org](https://www.mingw-w64.org/)
2. **MSYS2** : Télécharger depuis [msys2.org](https://www.msys2.org/) puis installer gcc avec `pacman -S mingw-w64-x86_64-gcc`
3. **Visual Studio Community** : Télécharger depuis [visualstudio.microsoft.com](https://visualstudio.microsoft.com/)
4. **Clang** : Télécharger depuis [llvm.org](https://llvm.org/)

### Compilation manuelle

#### Sur Linux/macOS

```bash
# Compilation simple
gcc -o play src/play.c src/fonctions.c

# Avec options de debug
gcc -Wall -Wextra -g -o play src/play.c src/fonctions.c

# Avec make
make
```

#### Sur Windows

```powershell
# Avec gcc (si installé via MinGW ou MSYS2)
gcc -o play.exe src/play.c src/fonctions.c

# Avec Visual Studio (cl.exe)
cl /Fe:play.exe src/play.c src/fonctions.c

# Avec clang (si installé)
clang -o play.exe src/play.c src/fonctions.c

# Compilation automatique (détecte le compilateur disponible)
./compile.bat
```

### Exécution

#### Linux/macOS

```bash
./play
```

#### Windows

```powershell
./play.exe
# ou simplement
play
```

## Fonctionnalités

- Interface en mode console
- Gestion complète du plateau de jeu 4×4
- Validation automatique des coups
- Détection automatique des victoires
- Gestion de deux joueurs en alternance
- Mélange aléatoire des pièces

## Structures de données principales

### Structure Pawn

```c
typedef struct {
    char length;  // Taille de la pièce
    char form;    // Forme de la pièce
    char color;   // Couleur de la pièce
    char fill;    // Surface de la pièce
} Pawn;
```

## Fonctions principales

- `initPawnStruct()` : Initialisation d'une structure de pion
- `initGameBoardWithEmptyPawn()` : Initialisation du plateau de jeu
- `initListOfPawn()` : Création de la liste des 16 pièces
- `displayGameBoard()` : Affichage du plateau
- `ifWin()` : Vérification des conditions de victoire
- `getUserInput()` : Gestion des entrées utilisateur

## Règles du jeu

1. Le jeu se joue à deux joueurs en alternance
2. À chaque tour :
   - Le joueur actuel choisit une pièce pour son adversaire
   - L'adversaire place cette pièce sur le plateau
   - On vérifie s'il y a une victoire
3. La partie se termine quand un joueur forme un alignement de 4 pièces partageant une caractéristique commune

## Développement

Ce projet a été développé dans le cadre pédagogique pour apprendre :

- La programmation structurée en C
- La gestion des structures de données
- L'algorithme de détection de victoire
- L'interface utilisateur en mode console
- Les bonnes pratiques de programmation

## Auteur

Projet réalisé par **SAMOU Patrick** dans le cadre du cours de Méthodes de Programmation.

## Licence

Ce projet est réalisé à des fins pédagogiques.
# Quarto-console
