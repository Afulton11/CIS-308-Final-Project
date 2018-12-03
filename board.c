#include "board.h"
#include <stdio.h>
#include <stdlib.h>

MiniBoard * create_mini_board(SudokuBoard * SudokuBoard, int row, int col) {
    MiniBoard * miniBoard = malloc(sizeof(MiniBoard));
    miniBoard->row = row;
    miniBoard->col = col;

    for (int r = 0; r < BOARD_SIZE / 3; r++) {
        for (int c = 0; c < BOARD_SIZE / 3; c++) {
            miniBoard->board[r][c] = &(SudokuBoard->board[r + row][c + col]);
        }
    }

    return miniBoard;
}

SudokuBoard * create_sodoku_board(FILE *fp) {
    SudokuBoard *sudokuBoard = malloc(sizeof(SudokuBoard));
    char ch;
    int row = 0, col = 0;

    printf("Reading board...\n");

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            row++;
            col = 0;
            printf("\n");
        }
        else
        {
            printf(" %c", ch);
            sudokuBoard->board[row][col] = atoi(&ch);
            col++;
        }
    }

    printf("\n");

    return sudokuBoard;
}

int verify_mini_board(int number, MiniBoard * board) {
    int i, j;

    for(i = 0; i < BOARD_SIZE / 3; i++)
    {
        for(j = 0; j < BOARD_SIZE / 3; j++)
        {
            if(number == *(board -> board[i][j]))
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}
int verify_row(int number, int row, SudokuBoard * board) {
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        if(number == board -> board[row][i])
        {
            return FALSE;
        }
    }
    return TRUE;
}
int verify_Column(int number, int column, SudokuBoard * board) {
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        if(number == board -> board[i][column])
        {
            return FALSE;
        }
    }
    return TRUE;
}

void write_board(SudokuBoard * board, FILE * stream) {
    char* dest;
    int i, j;

    for(i = 0; i < BOARD_SIZE; i++)
    {
        for(j = 0; j < BOARD_SIZE; j++)
        {
            printf("%d ", board->board[i][j]);
            fprintf(stream, "%d ", board->board[i][j]);
        }
        fprintf(stream, "\n");
        printf("\n");
      }
}
