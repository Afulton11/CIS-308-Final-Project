#ifndef GENERATOR_H
#define GENERATOR_H
#include "board.h"
#include "unused.h"

typedef struct SudokuGenerator {
    SudokuBoard * (* generate)(int (* solver)(SudokuBoard *, int, int));
} SudokuGenerator;

typedef struct _DiagnolGeneratorBoard {
    MiniBoard * miniBoard;
    UnusedNumberList * UnusedNumberList;
} _DiagnolGeneratorBoard;

SudokuGenerator * create_generator();

#endif