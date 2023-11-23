//Dominik Muc, 345952, Lista 5 zadanie 1
#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef enum OnMove{
    CIRCLE,
    CROSS
} OnMove;

typedef enum GameState{
    CIRCLE_WIN,
    CROSS_WIN,
    DRAW,
    ONGOING,
    WRONG_MOVE
} GameState;

typedef struct Field{
    long row;
    long column;
} Field;

char** initialize_board(long side);

void free_board(long side, char** board);

GameState move(OnMove symbol, Field square, long side, char** board);

void show_board(long side, char** board);