#include "board.h";

MiniBoard * create_mini_board(SodokuBoard * sodokuBoard, int row, int col) {
    MiniBoard * miniBoard = malloc(sizeof(MiniBoard));
    miniBoard->row = row;
    miniBoard->col = col;

    int board[BOARD_SIZE][BOARD_SIZE] = *(sodokuBoard->board);

    for (int r = row; r < row + 3; r++) {
        for (int c = col; c < col + 3; c++) {
            miniBoard->board[r][c] = board[r][c];
        }
    }

    return miniBoard;
}

SodokuBoard * create_sodoku_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    SodokuBoard * sodokuBoard = malloc(sizeof(SodokuBoard));
    sodokuBoard->board = board;
    
    return sodokuBoard;
}

int verify_mini_board(int number, SodokuBoard * board) {
    return 0;
}
int verify_row(int number, int row, SodokuBoard * board) {
    return 0;
}
int verify_Column(int number, int column, SodokuBoard * board) {
    return 0;
}

void print_board(SodokuBoard * board) {
    return 0;
}