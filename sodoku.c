#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "board.h"
#include "generator.h"

int solver(SudokuBoard*, int, int);
int isValid(int, SudokuBoard*, int, int);

int main(int argc, char *args[]) {
    if (argc < 2 || argc > 3) {
        printf("Usage for solving: ./sodoku <input-file> <output-file>\n");
        printf("Usage for generating: ./sodoku <output-file>");
        return -1;
    }

    if(argc == 3) //Solve puzzle code
    {
        char * inputFilename = args[1];
        char * outputFilename = args[2];

        if (access(inputFilename, F_OK | R_OK)) {
            printf("The input file %s either doesn't exist or we don't have read access!\n", inputFilename);
            printf("Please try again with another input file.\n");
            return -1;
        } else if (access(outputFilename, F_OK) && !access(outputFilename, W_OK)) {
            printf("We do not have write access to the output file %s!", outputFilename);
            printf("Please try again with another output file.\n");
            return -1;
        }
        

        FILE *input_fp = fopen(inputFilename, "r");
        FILE *output_fp = fopen(outputFilename, "w");

        SudokuBoard *SudokuBoard = create_sodoku_board(input_fp);

        int isSolved = solver(SudokuBoard, 0, 0);
        if (isSolved) {
            printf("\nSolved the board!\n\n");
            printf("Solution saved to file: %s\n", args[2]);
            write_board(SudokuBoard, output_fp);
        }
        else
        {
            printf("\nUnfortunately, the board you gave was unsolvable!\n");
        }

        fclose(input_fp);
        fclose(output_fp);
    }
    else //generate puzzle code
    {
        char * outputFilename = args[1];
        if (access(outputFilename, F_OK) && !access(outputFilename, W_OK)) {
            printf("We do not have write access to the output file %s!", outputFilename);
            printf("Please try again with another output file.\n");
            return -1;
        }
        FILE *output_fp = fopen(outputFilename, "w");

        // initialize random functions with a random seed
        srand(time(0) + (int) outputFilename);

        SudokuBoard *SudokuBoard = create_generator()->generate(solver);

        write_board(SudokuBoard, output_fp);
        printf("Successfully saved a Sudoku board to %s", args[1]);

        fclose(output_fp);
    }
}

int solver(SudokuBoard * board, int row, int column) {
    int nextNum = 1;
    if (BOARD_SIZE == row) {
        return TRUE;
    }
    if (board->board[row][column]) {

        if (column == BOARD_SIZE - 1) {
            if (solver(board, row + 1, 0)) return TRUE;
        } else {
            if (solver(board, row, column + 1)) return TRUE;
        }

        return FALSE;
    }

    for (; nextNum < 10; nextNum++) {
        if(isValid(nextNum, board, row, column)) {
            board->board[row][column] = nextNum;

            if (column == BOARD_SIZE - 1) {
                if (solver(board, row + 1, 0)) return TRUE;
            } else {
                if (solver(board, row, column + 1)) return TRUE;
            }

            board->board[row][column] = BLANK;
        }
    }

    return FALSE;
}

int isValid(int number, SudokuBoard * board, int row, int column) {

    /* Check for the value in the given row and column */
    if (!verify_Column(number, column, board)) return FALSE;
    if (!verify_row(number, row, board)) return FALSE;

    int miniRow = 3 * (row / 3);
    int miniCol = 3 * (column / 3);

    if (!verify_mini_board(number, create_mini_board(board, miniRow, miniCol))) return FALSE;
    return TRUE;
}
