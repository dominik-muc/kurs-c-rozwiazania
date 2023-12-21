#pragma once

#include <stdio.h>
#include <stdlib.h>
#define MAX_BUFFER 5

typedef enum Direction{
    RANDOM,
    LEFT,
    RIGHT
} Direction;

int text_align(FILE* input, FILE* output, int width, Direction direction);
