#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

#define ARRAY_SIZE 4  

typedef struct{
    char length;
    char form;
    char color;
    char fill;
}Pawn;

extern void initPawnStruct(Pawn *empty);
extern void initGameBoardWithEmptyPawn(Pawn gameboard[ARRAY_SIZE][ARRAY_SIZE], Pawn empty);
extern void initListOfPawn(Pawn listOfPawn[]);
extern void shuffleTab(Pawn list[]);
extern void displayMenu();
extern void press_any_key();
extern unsigned short checkIfInputIsInBounds(char input, char min, char max);
extern void clear_input_buffer();
extern unsigned short getUserInput(char min, char max);
extern void changePlayer(char whoHisTurn[]);
extern void displayListOfPawn(Pawn list[], unsigned short interval);
extern void displayGameBoard(Pawn board[ARRAY_SIZE][ARRAY_SIZE]);
extern void clear_screen();
extern unsigned short getLine(Pawn list[], unsigned short index);
extern unsigned short getColumn(Pawn list[], unsigned short index);
extern unsigned short checkIfCaseIsValid(Pawn game[ARRAY_SIZE][ARRAY_SIZE], unsigned short line, unsigned short column);
extern unsigned short checkIfThereIsEmptyCaseInLine(Pawn game[ARRAY_SIZE][ARRAY_SIZE], unsigned short line);
extern unsigned short checkIfThereIsEmptyCaseInColumn(Pawn game[ARRAY_SIZE][ARRAY_SIZE], unsigned short column);
extern unsigned short ifPawnInLineAreEqual(Pawn game[ARRAY_SIZE][ARRAY_SIZE], unsigned short column);
extern unsigned short ifPawnInColumnAreEqual(Pawn game[ARRAY_SIZE][ARRAY_SIZE], unsigned short column);
extern unsigned short ifWin(Pawn game[ARRAY_SIZE][ARRAY_SIZE], unsigned short line, unsigned short column);
extern void displayRules();
extern void reduceInterval(Pawn list[], unsigned short *interval, unsigned short index);
#endif