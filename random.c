#include "random.h"

int random_number(int min, int max) {
   return (rand() % (max + 1 - min) + min);
}

