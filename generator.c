#include "generator.h"
#include "random.h"

SudokuBoard * create_blank_board() {
    SudokuBoard * board = malloc(sizeof(SudokuBoard));
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            board -> board[i][j] = 0;                                                                                
        }    
    }
    return board;        
}

_DiagnolGeneratorBoard * create_diagnol_generator_board(SudokuBoard * board, int position) {
    _DiagnolGeneratorBoard * diagnolBoard = malloc(sizeof(_DiagnolGeneratorBoard));

    diagnolBoard->UnusedNumberList = create_unused_number_list(9);
    diagnolBoard->miniBoard = create_mini_board(board, position, position);

    return diagnolBoard;
}

void randomize_diagnol(_DiagnolGeneratorBoard * diagnol) {
    UnusedNumberList * numbers = diagnol->UnusedNumberList;
    MiniBoard * board = diagnol->miniBoard;

    int counter = 0;
    while (!(numbers->areAllUsed(numbers))) {
        int randomIndex = random_number(0, numbers->numbersLength - 1);
        int randomNumber = numbers->use(numbers, randomIndex);

        int row = counter % 3;
        int col = counter / 3;
        board->board[row][col] = &randomNumber;

        counter++;
    }
}

SudokuBoard * generate(int (* solver)(SudokuBoard *, int, int)) {
    SudokuBoard * sudokuBoard = create_blank_board();

    printf("Creating blank puzzle board...\n");

    for (int position = 0; position < 3; position++) {
        printf("Step %d of 3...\n", position + 1);
        _DiagnolGeneratorBoard * diagnolBoard = create_diagnol_generator_board(sudokuBoard, position);
        randomize_diagnol(diagnolBoard);
    }

    printf("... Is the generated board solvable? ");

    int isSolvable = solver(sudokuBoard, 0, 0);

    printf("%s\n", isSolvable == 0 ? "NO" : "YES");

    printf("Removing some digits...\n");

    // begin removing random digits from the board
    int digitsToRemove = random_number(BOARD_SIZE * 2, BOARD_SIZE * 5);

    printf("Removing %d digits!\n", digitsToRemove);

    while (digitsToRemove > 0) {
        int row = random_number(0, BOARD_SIZE);
        int col = random_number(0, BOARD_SIZE);
        int* digit_ptr = &(sudokuBoard->board[row][col]);

        if (!(IS_BLANK(*digit_ptr))) {
            *digit_ptr = BLANK;
            digitsToRemove--;
        }
    }

    printf("The sudoku board was successfully created.\n");
    return sudokuBoard;
}

SudokuGenerator * create_generator() {
    SudokuGenerator * generator = malloc(sizeof(SudokuGenerator));

    generator->generate = &generate;

    return generator;
}

