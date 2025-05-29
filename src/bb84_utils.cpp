#include "bb84Utils.h"
#include <cstdlib>

int randomBit() {
    return rand() % 2;
}

char randomBasis() {
    return (rand() % 2 == 0) ? 'Z' : 'X';
}
