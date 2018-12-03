#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 9
#define BLANK 0
#define IS_BLANK(number) number == BLANK
#include <stdio.h>


/**
 * 
 * We need 5 user defined types! (enums, structs, unions)
 *  (we have 2)
 * 
 **/ 

typedef enum Boolean {
    FALSE = 0,
    TRUE = 1,
} Boolean;

typedef struct MiniBoard {
    int row, col;
    int* board[BOARD_SIZE / 3][BOARD_SIZE / 3];
} MiniBoard;

typedef struct SudokuBoard {
    int board[BOARD_SIZE][BOARD_SIZE];
} SudokuBoard;

MiniBoard * create_mini_board(SudokuBoard * board, int row, int col);
SudokuBoard * create_sodoku_board(FILE *fp);

int verify_mini_board(int number, MiniBoard *);
int verify_row(int number, int row, SudokuBoard *);
int verify_Column(int number, int column, SudokuBoard *);
void write_board(SudokuBoard *, FILE *);

#endif // BOARD_H
