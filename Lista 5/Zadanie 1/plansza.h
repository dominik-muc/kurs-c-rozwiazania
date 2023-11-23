#include <stdio.h>
#include <stdlib.h>

typedef enum Symbol{
    CIRCLE,
    CROSS
} Symbol;

typedef struct Coordinates{
    long x;
    long y;
} Coordinates;

char** initialize_board(long side);

int move(Symbol symbol, Coordinates cords, char** board);

int show_board(FILE* stream, char** board);