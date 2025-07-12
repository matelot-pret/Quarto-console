#include "fonctions.h"


int main(void){
    clear_screen();
    Pawn emptyPawn;
    initPawnStruct(&emptyPawn);

    Pawn gameBoard[ARRAY_SIZE][ARRAY_SIZE] = {0};
    initGameBoardWithEmptyPawn(gameBoard, emptyPawn);

    Pawn listOfPawn [ARRAY_SIZE*ARRAY_SIZE] = {0};
    initListOfPawn(listOfPawn);
    shuffleTab(listOfPawn);

    char whoHisTurn[] = "Joueur 2";
    
    unsigned short userInput = 0;
    char min = '0';
    char max = '2';
    displayMenu();
    userInput = getUserInput(min, max);
        while(userInput != 0){
            switch(userInput){
                case 1 :
                    unsigned short win = 1;
                    unsigned short intervalLimit = (ARRAY_SIZE*ARRAY_SIZE)-1;

                    while(win == 1 && intervalLimit > 1){
                        //clear_screen();
                        printf("%s Veuillez choisir le pion de votre adversaire\n", whoHisTurn);
                        displayListOfPawn(listOfPawn, intervalLimit);
                        printf("\n\nVeuillez entrer votre choix : \n");
                        min = 'a';
                        max = intervalLimit + min;
                        unsigned short indexOfPawn = getUserInput(min, max);
                        Pawn selectedPawn = listOfPawn[indexOfPawn];
                        clear_screen();
                        displayGameBoard(gameBoard);
                        changePlayer(whoHisTurn);
                        printf("%s \n", whoHisTurn);

                        unsigned short line = getLine(listOfPawn, indexOfPawn)-1;
                        unsigned short column = getColumn(listOfPawn, indexOfPawn)-1;

                        while(checkIfLineAndColumnIsValid(gameBoard, line, column) == 1){
                            printf("[ERR] Veuillez selectionner une case vide !");
                            line = getLine(listOfPawn, indexOfPawn)-1;
                            column = getColumn(listOfPawn, indexOfPawn)-1;
                        }

                        clear_screen();
                        gameBoard[line][column] = selectedPawn;
                        printf("\n\nPions placé avec succés !");
                        fflush(stdout);
                        displayGameBoard(gameBoard);
                        sleep(3);

                        if(checkIfThereIsEmptyCaseInColumn(gameBoard, column) == 1 || 
                        checkIfThereIsEmptyCaseInLine(gameBoard, line) == 1){
                            printf("check win\n");
                            win = ifWin(gameBoard, line, column);
                        }

                        reduceInterval(listOfPawn, &intervalLimit, indexOfPawn);
                    }
                    if(win == 0){
                        //clear_screen();
                        displayGameBoard(gameBoard);
                        printf("\n\nPartie Terminé. Victoire du %s \n", whoHisTurn);
                    }else if(intervalLimit < 1){
                        clear_screen();

                        displayGameBoard(gameBoard);
                        printf("Partie Terminé. Égalité");
                    }
                break;
                case 2 :
                    clear_screen();
                    displayRules();
                    clear_screen();
                    displayMenu();
                    min = '0';
                    max = '2';
                    userInput = getUserInput(min, max);
                break;
            }
            userInput = 0;
        }
    
}