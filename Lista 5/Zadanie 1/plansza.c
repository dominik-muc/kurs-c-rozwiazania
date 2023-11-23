//Dominik Muc, 345952, Lista 5 zadanie 1
#include "plansza.h"

char** initialize_board(long side){
    char** board = malloc(sizeof(char*)*side);
    for(long row = 0; row < side; row++){
        board[row] = malloc(sizeof(char)*side);
        for(long column = 0; column < side; column++){
            board[row][column] = '_';
        }
    }
    return board;
}

void free_board(long side, char** board){
    for(long row = 0; row < side; row++){
        free(board[row]);
    }
    free(board);
}

GameState move(OnMove on_move, Field square, long side, char** board){
    if(board[square.row][square.column] != '_') return WRONG_MOVE;
    char symbol = on_move ? 'x' : 'o';

    board[square.row][square.column] = symbol;
    
    int diagonal_win = 1;
    int draw = 1;
    for(long row = 0; row < side; row++){
        if(board[row][row] != symbol) diagonal_win = 0;
        if(board[side - row - 1][row] != symbol) diagonal_win = 0;
        int horizontal_win = 1;
        int vertical_win = 1;
        for(long column = 0; column < side; column++){
            if(board[row][column] != symbol) horizontal_win = 0;
            if(board[column][row] != symbol) vertical_win = 0;
            if(board[row][column] == '_') draw = 0;
        }
        if(vertical_win || horizontal_win) return on_move ? CROSS_WIN : CIRCLE_WIN;
    }
    if(diagonal_win) return on_move ? CROSS_WIN : CIRCLE_WIN;

    return draw ? DRAW : ONGOING;
}

void show_board(long side, char** board){
    for(long row = 0; row < side; row++){
        for(long column = 0; column < side; column++){
            printf("%c ", board[row][column]);
        }
        putchar('\n');
    }
}