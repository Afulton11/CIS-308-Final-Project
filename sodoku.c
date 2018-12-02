#include <stdio.h>
#include <stdlib.h>
#include "board.h"

int sudokuHelper(SodokuBoard*, int, int);
int isValid(int, SodokuBoard*, int, int);

int main(int argc, char *args[]) {
    if (argc != 3)
        printf("Usage: ./sodoku <input-file> <output-file>\n");

    FILE *input_fp = fopen(args[1], "r");
    FILE *output_fp = fopen(args[2], "w");

    SodokuBoard *sodokuBoard = create_sodoku_board(input_fp);

    int isSolved = sudokuHelper(sodokuBoard, 0, 0);
    if (isSolved) {
        printf("\nSolved the board!\n\n");
        printf("Solution saved to file: %s\n", args[2]);
        write_board(sodokuBoard, output_fp);
    }
    else
    {
        printf("\nUnfortunately, the board you gave was unsolvable!\n");
    }

    fclose(input_fp);
    fclose(output_fp);
}

int sudokuHelper(SodokuBoard * board, int row, int column) {
    int nextNum = 1;
    if (BOARD_SIZE == row) {
        return TRUE;
    }
    if (board->board[row][column]) {

        if (column == BOARD_SIZE - 1) {
            if (sudokuHelper(board, row + 1, 0)) return TRUE;
        } else {
            if (sudokuHelper(board, row, column + 1)) return TRUE;
        }

        return FALSE;
    }

    for (; nextNum < 10; nextNum++) {
        if(isValid(nextNum, board, row, column)) {
            board->board[row][column] = nextNum;

            if (column == BOARD_SIZE - 1) {
                if (sudokuHelper(board, row + 1, 0)) return TRUE;
            } else {
                if (sudokuHelper(board, row, column + 1)) return TRUE;
            }

            board->board[row][column] = 0;
        }
    }

    return FALSE;
}

int isValid(int number, SodokuBoard * board, int row, int column) {

    /* Check for the value in the given row and column */
    if (!verify_Column(number, column, board)) return FALSE;
    if (!verify_row(number, row, board)) return FALSE;

    int miniRow = 3*(row/3);
    int miniCol = 3*(column/3);

    if (!verify_mini_board(number, create_mini_board(board, miniRow, miniCol))) return FALSE;

    /* Check the remaining four spaces in this sector */
    return TRUE;
}
