#ifndef UNUSED_H
#define UNUSED_H

typedef struct UnusedNumberList {
    int * _numbers;
    int * _usedNumbers;
    int _actualLength;
    
    int numbersLength;
    int (* use)(struct UnusedNumberList * self, int index);
    int (* areAllUsed)(struct UnusedNumberList * self);
} UnusedNumberList;

UnusedNumberList * create_unused_number_list(int length);

#endif