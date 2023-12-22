//Dominik Muc, 345952, Lista 9 zadanie 1
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_BUFFER 5

typedef enum Direction{
    RANDOM,
    LEFT,
    RIGHT
} Direction;

int text_align(FILE* input, int width, Direction direction);
