#include "fonctions.h"

/**
 * post : Initialise une structire de pions
 * */ 
void initPawnStruct(Pawn *empty){
    empty->length = '0';
    empty->form = '0';
    empty->color = '0';
    empty->fill = '0';
}

/**
 * post : L'écran est néttoyé
 * */ 
void clear_screen(){
	system("cls || clear");
}

/**
 * post : Attend deux pressions sur la touche ENTREE
 * */ 
void press_any_key(){
	getchar();
	getchar();
}

/**
 * post : vide le buffer jusqu'au prochain saut de ligne ou fin de fichier
 * */ 
void clear_input_buffer(){
	int buffer = getchar();
	while(buffer != '\n' && buffer != EOF){
		buffer = getchar();
	}
}

/**
 * post : L'écran est néttoyé
 * */ 
void initGameBoardWithEmptyPawn(Pawn gameboard[ARRAY_SIZE][ARRAY_SIZE], Pawn empty){
    for(int i = 0; i < ARRAY_SIZE; i++){
        for(int j = 0; j < ARRAY_SIZE; j++){
            gameboard[i][j] = empty;
        }
    }
}

/**
 * post : Initialise le tableau list de pions en leur attribuant leur caractéristique respective
 * */ 
void initListOfPawn(Pawn list[]){
    int nbTour = (ARRAY_SIZE*ARRAY_SIZE)/8;
    int limit = (ARRAY_SIZE*ARRAY_SIZE)/2;
    char length = 'G';
    int j = 0;
    for(int i = 1; i <= nbTour; i++){
        while(j < limit){
            list[j].length = length;
            j++;
        }
        limit += limit+1;
        length = 'P';
    }

    char form = 'R';
    j = 0;
    nbTour = (ARRAY_SIZE*ARRAY_SIZE)/4;
    limit = nbTour;
    for(int i = 1; i <= nbTour; i++){
        while(j < limit){
            list[j].form = form;
            j++;
        }
        limit += 4;
        if(form == 'R'){
            form = 'C';
        }else{
            form = 'R';
        }
    }

    char color = 'J';
    j = 0;
    nbTour = (ARRAY_SIZE*ARRAY_SIZE)/2;
    limit = (ARRAY_SIZE*ARRAY_SIZE)/8;
    for(int i = 1; i <= nbTour; i++){
        while(j < limit){
            list[j].color = color;
            j++;
        }
        limit += 2;
        if(color == 'J'){
            color = 'B';
        }else{
            color = 'J';
        }
    }

    char fill = 'E';
    j = 0;
    limit = ARRAY_SIZE*ARRAY_SIZE;
    while(j < limit){
        list[j].fill = fill;
        if(fill == 'E'){
            fill = 'T';
        }else{
            fill = 'E';
        }
        j++;
    }  
}

/**
 * pre : list est entièrement initialisé
 * post : Les éléments du tableau list sont mélangés aléatoirement
 * */ 
void shuffleTab(Pawn list[]){
    srand(time(NULL));
    for(int i = (ARRAY_SIZE*ARRAY_SIZE) -1; i > 0; i --){
        int j = rand() % (i +1);
        Pawn temp = list[i];
        list[i] = list[j];
        list[j] = temp;
    }
}

/**
 * post : Affiche le menu principal
 * */ 
void displayMenu(){
    printf("\t\t\t===QUARTO===\n\n\n\n");
    printf("Veuillez choisir une option parmi les suivantes :\n\n");
    printf("1- LANCER UNE PARTIE\n");
    printf("2- RÈGLES DU JEU\n\n\n");
    printf("0- QUITTER LE JEU\n");
    printf("\nVeuillez entrer votre choix : \n");
}

/**
 * post : Les règles du jeu sont affichées, 
 * et l’utilisateur est invité à appuyer sur Entrée pour revenir au menu.
 * */ 
void displayRules(){
    printf("\t\t\t===RÈGLES DU JEU===\n\n\n");
    printf("Le but est d'aligner quatre pièces partageant au moins une caractéristique commune");
    printf("\nparmi les suivantes : Hauteur(haute ou basse), Couleur(Claire ou foncée)");
    printf("\nForme(Ronde ou Carrée), Remplissage(Plain ou creux), le premier qui y arrives gagne la partie");
    printf("\nSi aucun des deux joeurs ny arrive avant que le nombre de pion libre ne soit épuisé, il ya égalité");
    printf("\n\n\nAppuyer deux fois sur ENTREE pour retourner au menu");
    press_any_key();

}

/**
 * pre : input est la valeur qui sera verifier si elle se trouve entre min et max, les trois
 * variables sont inirialisés. min < max
 * post : les variables restent inchangés
 * res : retourne 0 si input est compris entre min et max, 1 sinon
 * */ 
unsigned short checkIfInputIsInBounds(char input, char min, char max){
    unsigned short valid = 1;
    input = tolower(input);
    if(input >= min && input <= max){
        valid = 0;
    }
    return valid;
}

/**
 * pre : whosHisTurn contient "Joueur 1 ou Joueur 2"
 * post : La chaîne est modifié pour représenter l'autre joueur
 * */ 
void changePlayer(char whoHisTurn[]){
    if(strcmp(whoHisTurn, "Joueur 1") == 0){
        strcpy(whoHisTurn, "Joueur 2");
    }else{
        strcpy(whoHisTurn, "Joueur 1");
    }
}

/**
 * pre : min < max 
 * post : min et max restent inchangé
 * 
 * res : Récupère et valide l’entrée utilisateur :
 * S’assure qu’elle est valide et
 * Permet à l’utilisateur de quitter le jeu en entrant '0'.
 * */ 
unsigned short getUserInput(char min, char max){
    char chaine[10] = {0};
    unsigned short valid = 0;

    while(valid == 0){
        if(fgets(chaine,10,stdin) == NULL){
            printf("[ERR] Lecture impossible.\n");
            printf("Veuillez réessayer : \n");
        }else{
            unsigned short length = strlen(chaine);
            if(length > 0 && chaine[length-1] == '\n'){
                chaine[length-1] = '\0';
                length --;
            }else{
				clear_input_buffer();
			}

			if(length == 0){
				printf("[ERR] Votre réponse ne peut pas être vide.\nVeuillez réessayer : \n");
			}else if(length > 1){
				printf("[ERR] ENTREE INVALIDE ! Veuillez entrer une seule valeur : \n");
			}else if(checkIfInputIsInBounds(chaine[0], min, max) == 1){
				printf("[ERR]ENTREE INVALIDE ! Veuillez entrer une valeur entre %c et %c \n", min, max);
			}else{
				valid = 1;
			}
        }
    }

    if(chaine[0] == '0'){
        printf("Vous avez quitté le jeu !\n");
        exit(1);
    }

    unsigned short validInput = chaine[0] - '0';
    if(chaine[0] >= 'a' && chaine[0] <= 'z'){
        validInput = 0;
        char lettre = 'a';


        while (lettre < chaine[0]){
        lettre ++;
        validInput++;
        }
    }
    
    return validInput;
}

/**
 * pre : list contient au moins interval +1 éléments initialisés
 * post : affiche les pions de l'indice 0 à interval, un par ligne
 * */ 
void displayListOfPawn(Pawn list[], unsigned short interval){
    printf("\nChaque lettre représente une caractéristique\n\n");
    printf("Taille : Grand(G) ou Petit(P)\n");
    printf("Forme : Rond(R) ou Carrée(C)\n");
    printf("Couleur : Jaune(J) ou Brun(B)\n");
    printf("Remplissage : Entier(E) ou Troué(T)\n\n\n");

    char lettre = 'A';
    for(int i = 0; i <= interval; i++, lettre ++){
        printf("%c- %c%c%c%c\n", lettre, list[i].length, list[i].form, list[i].color, list[i].fill);
    }
    printf("\nEntrer 0 pour quitter \n");
}

/**
 * pre : board est correctement initialisé
 * post : board est affiché avec ses pions et/ou ses cases vides
 * */ 
void displayGameBoard(Pawn board[ARRAY_SIZE][ARRAY_SIZE]){
    printf("\nChaque lettre représente une caractéristique\n\n");
    printf("Taille : Grand(G) ou Petit(P)\n");
    printf("Forme : Rond(R) ou Carrée(C)\n");
    printf("Couleur : Jaune(J) ou Brun(B)\n");
    printf("Remplissage : Entier(E) ou Troué(T)\n\n");
    printf("VIDE indique une case vide\n\n");

    for(int i = 0; i < ARRAY_SIZE; i++){
        for(int j = 0; j < ARRAY_SIZE; j++){
            if(board[i][j].length == '0'){
                printf("VIDE ");
            }else{
                printf("%c%c%c%c ",board[i][j].length, board[i][j].form, board[i][j].color, board[i][j].fill);
            }
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * pre : index est un indice valide de list et le pion a cet inidice est initialisé
 * post : Demande et retourne un numéro de ligne valide(compris entre 1 et ARRAY_SIZE) depuis l'entrée utilisateur
 * res : retourne le numéro de la ligne par l'utilisateur, la valeur retourné est valide
 * */ 
unsigned short getLine(Pawn list[], unsigned short index){
    printf("\nLes numéros de ligne vont de 1 à 4.\n");
    printf("\nVeuillez entrer le numéro de la ligne où vous voulez placer le pion %c%c%c%c :\n", list[index].length, 
    list[index].form, 
    list[index].color,
    list[index].fill);

    char min = '1';
    char max = '4';

    return getUserInput(min, max);
}

/**
 * pre : index est un indice valide de list et le pion a cet inidice est initialisé
 * post : Demande et retourne un numéro de colonne valide(compris entre 1 et ARRAY_SIZE) depuis l'entrée utilisateur
 * res : retourne le numéro de la colonne saisie par l'utilisateur, la valeur retourné est valide
 * */ 
unsigned short getColumn(Pawn list[], unsigned short index){
    printf("\nLes numéros de colonne vont de 1 à 4.\n");
    printf("\nVeuillez entrer le numéro de la colonne où vous voulez placer le pion %c%c%c%c:\n", list[index].length, 
    list[index].form, 
    list[index].color,
    list[index].fill);

    char min = '1';
    char max = '4';

    return getUserInput(min, max);
}

/**
 * pre : line et column sont des indices valides du tableau game.
 * post : Vérifie si la case est occupée (c’est-à-dire ces caractéristiques sont différentes de '0').
 * res : retourne 0 si la case est vide, 1 sinon.
 * */ 
unsigned short checkIfCaseIsValid(Pawn game[ARRAY_SIZE][ARRAY_SIZE], unsigned short line, unsigned short column){
    unsigned short valid = 0;
    if(game[line][column].length != '0'){
        valid = 1;
    }

    return valid;
}

/**
 * pre : line est un indice valide de game, et chaque case de cette ligne contient un pion.
 * post : Vérifie si les 4 pions de la ligne ont au moins une caractéristique en commun 
 * (length, form, color ou fill), game et line ne sont pas modifiés.
 * res : retourne 0 si une caractéristique est commune à toute la ligne, 1 sinon.
 * */ 
unsigned short ifPawnInLineAreEqual(Pawn game[ARRAY_SIZE][ARRAY_SIZE], unsigned short line){
    unsigned short equal = 0;
    for(int i = 0; i < ARRAY_SIZE && equal == 0; i++){
        for(int j = 0; j < ARRAY_SIZE && equal == 0; j++){
            if(game[line][i].length != game[line][j].length){
                equal = 1;
            }
        }
    }

    if(equal == 0){
        for(int i = 0; i < ARRAY_SIZE && equal == 0; i++){
            for(int j = 0; j < ARRAY_SIZE && equal == 0; j++){
                if(game[line][i].form != game[line][j].form){
                    equal = 1;
                }
            }
        }
    }

    if(equal == 0){
        for(int i = 0; i < ARRAY_SIZE && equal == 0; i++){
            for(int j = 0; j < ARRAY_SIZE && equal == 0; j++){
                if(game[line][i].color != game[line][j].color){
                    equal = 1;
                }
            }
        }
    }

    if(equal == 0){
        for(int i = 0; i < ARRAY_SIZE && equal == 0; i++){
            for(int j = 0; j < ARRAY_SIZE && equal == 0; j++){
                if(game[line][i].fill != game[line][j].fill){
                    equal = 1;
                }
            }
        }
    }
    return equal;
}

/**
 * pre : column est un indice valide de game, et chaque case de cette colonne contient un pion.
 * post : Vérifie si les 4 pions de la colonne ont au moins une caractéristique en commun 
 * (length, form, color ou fill), game et column ne sont pas modifiés.
 * res : retourne 0 si une caractéristique est commune à toute la colonne, 1 sinon.
 * */ 
unsigned short ifPawnInColumnAreEqual(Pawn game[ARRAY_SIZE][ARRAY_SIZE], unsigned short column){
    unsigned short equal = 0;
    for(int i = 0; i < ARRAY_SIZE && equal == 0; i++){
        for(int j = 0; j < ARRAY_SIZE && equal == 0; j++){
            if(game[i][column].length != game[j][column].length){
                equal = 1;
            }
        }
    }

    if(equal == 0){
        for(int i = 0; i < ARRAY_SIZE && equal == 1; i++){
            for(int j = 0; j < ARRAY_SIZE && equal == 1; j++){
                if(game[i][column].form != game[j][column].form){
                    equal = 1;
                }
            }
        }
    }

    if(equal == 0){
        for(int i = 0; i < ARRAY_SIZE && equal == 0; i++){
            for(int j = 0; j < ARRAY_SIZE && equal == 0; j++){
                if(game[i][column].color != game[j][column].color){
                    equal = 1;
                }
            }
        }
    }

    if(equal == 0){
        for(int i = 0; i < ARRAY_SIZE && equal == 0; i++){
            for(int j = 0; j < ARRAY_SIZE && equal == 0; j++){
                if(game[i][column].fill != game[j][column].fill){
                    equal = 1;
                }
            }
        }
    }

    return equal;
}

/**
 * pre : game est correctement initialisé et la ligne line ou la colonne column ne contient
 * pas de case vide et sont des lignes et colonnes valide
 * post : aucune des variables n'est modifié
 * res : retourne 0 si le dernier coup mène à une victoire sinon 1
 */
unsigned short ifWin(Pawn game[ARRAY_SIZE][ARRAY_SIZE], unsigned short line, unsigned short column){
    unsigned short win = 1;
    if(ifPawnInLineAreEqual(game, line) == 0 || ifPawnInColumnAreEqual(game, column) == 0){
        win = 0;
    }
    return win;
}

/**
 * pre-condition: le tableau game est entièrement initialisé par des pions vide.
 * line est initialisé et compris entre 1 et 4
 * post-condition : aucune des variables en paramètre n'est modifié
 * resultat : Vérifie s'il existe une case vide dans une colonne donnée du plateau de jeu.
 * Une case est considérée vide si son attribut `length` vaut '0'.
 */
unsigned short checkIfThereIsEmptyCaseInLine(Pawn game[ARRAY_SIZE][ARRAY_SIZE], unsigned short line){
    unsigned short empty = 1;
    for(int i = 0; i < ARRAY_SIZE && empty == 1; i ++){
        if(game[line][i].length == '0'){
            empty = 0;
        }
    }

    return empty;
}

/**
 * pre-condition: le tableau game est entièrement initialisé par des pions vide et normal
 * uniquement l'un des deux. line et column sont initialisés et compris entre 1 et 4
 * post-condition : aucune des variables en paramètre n'est modifié
 * resultat : Vérifie s'il existe une case vide dans une colonne donnée du plateau de jeu.
 * Une case est considérée vide si l'un de attributs vaut '0'. Retourne 0 si il trouve une case vide sinon
 * 1
 */
unsigned short checkIfThereIsEmptyCaseInColumn(Pawn game[ARRAY_SIZE][ARRAY_SIZE], unsigned short column){
    unsigned short empty = 1;

    for(int i = 0; i < ARRAY_SIZE && empty == 1; i ++){
        if(game[i][column].length == '0'){

            empty = 0;
        }
    }

    return empty;
}

/**
 * pre-condition: le tableau list est entièrement initialisé par des pions *interval est n pointeur vers 
 * la limite du tableau et index est compris entre 0 et la valeur pointé par interval, 
 * post-condition : Échange un pion dans la liste avec celui à la fin de l'intervalle,
 * puis réduit la taille de l'intervalle.
 */
void reduceInterval(Pawn list[], unsigned short *interval, unsigned short index){
    Pawn temp = list[index];
    list[index] = list[*interval];
    list[*interval] = temp;

    (*interval)--;
}