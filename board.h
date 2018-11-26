#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 9
#define BLANK 0
#define IS_VALUE_VALID(number) number > 0 && number < 10
#define IS_BLANK(number) number == BLANK


typedef struct MiniBoard {
    int row, col;
    int board[BOARD_SIZE / 3][BOARD_SIZE / 3];
} MiniBoard;

typedef struct SodokuBoard
{
    int (*board)[BOARD_SIZE][BOARD_SIZE];
} SodokuBoard;

MiniBoard * create_mini_board(SodokuBoard * board, int row, int col);
SodokuBoard * create_sodoku_board(int[BOARD_SIZE][BOARD_SIZE]);

int verify_mini_board(int number, MiniBoard *);
int verify_row(int number, int row, SodokuBoard *);
int verify_Column(int number, int column, SodokuBoard *);
void print_board(SodokuBoard *);



#endif // BOARD_H
