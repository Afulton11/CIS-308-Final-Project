#ifndef BOARD_H
#define BOARD_H

#define FALSE 0
#define TRUE 1

#define BOARD_SIZE 9
#define BLANK 0
#define IS_VALUE_VALID(number) number > 0 && number < 10
#define IS_BLANK(number) number == BLANK
#include <stdio.h>


/**
 * 
 * We need 5 user defined types! (enums, structs, unions)
 *  (we have 2)
 * 
 **/ 


typedef struct MiniBoard {
    int row, col;
    int* board[BOARD_SIZE / 3][BOARD_SIZE / 3];
} MiniBoard;

typedef struct SodokuBoard
{
    int board[BOARD_SIZE][BOARD_SIZE];
} SodokuBoard;

MiniBoard * create_mini_board(SodokuBoard * board, int row, int col);
SodokuBoard * create_sodoku_board(FILE *fp);

int verify_mini_board(int number, MiniBoard *);
int verify_row(int number, int row, SodokuBoard *);
int verify_Column(int number, int column, SodokuBoard *);
void write_board(SodokuBoard *, FILE *);

#endif // BOARD_H
