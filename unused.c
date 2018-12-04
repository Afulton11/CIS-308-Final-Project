#include "unused.h"
#include <stdio.h>
#include <stdlib.h>

int get_number_index(UnusedNumberList * self, int index) {
    if (index >= self->numbersLength)
        printf("[DEBUG]: Attempted to access an index too large for our currently unused number list! [%d]:[%d]\n", index, self->numbersLength);

    int actualIndex = 0;

    while (index >= 0) {
        if (self->_numbers[actualIndex] != 0) index--;
        actualIndex++;
    }
    
    return actualIndex - 1;
}

int use(UnusedNumberList * self, int abstractedIndex) {
    // printf("Getting index: %d", abstractedIndex);
    int actualIndex = get_number_index(self, abstractedIndex);
    // printf(", actual index: %d", actualIndex);

    int number = self->_numbers[actualIndex];
    self->numbersLength--;
    self->_numbers[actualIndex] = 0;

    // printf(", returned: %d\n", number);
    return number;
}

int areAllUsed(UnusedNumberList * self) {
    return self->numbersLength == 0;
}

void add_numbers(int* numbersArray, int length) {
    
    for (int i = 0; i < length; i++) {
        numbersArray[i] = i + 1;
    }
}

UnusedNumberList * create_unused_number_list(int length) {
    UnusedNumberList * list = malloc(sizeof(UnusedNumberList));
    list->_numbers = malloc(length * sizeof(int));
    list->_usedNumbers = malloc(length * sizeof(int));
    list->_actualLength = length;

    add_numbers(list->_numbers, length);

    list->numbersLength = length;
    list->use = &use;
    list->areAllUsed = &areAllUsed;

    return list;
}