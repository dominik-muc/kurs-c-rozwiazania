#include <stdio.h>
#include <stdlib.h>
#define HASH_MAX 100000
void count_settings(int* counter, int n, int m, int h, int w, int g, int s, int** board, int* visited);

typedef enum Piece{
    EMPTY,
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT
} Piece;

int main(){
    int n, m, h, w, g, s;
    int count = 0;
    if(scanf("%i %i", &n, &m) != 2) return 0;
    if(scanf("%i %i %i %i", &h, &w, &g, &s) != 4) return 0;

    int** board = malloc(sizeof(int*)*n);
    for(int i = 0; i < n; i++){
        board[i] = calloc(m, sizeof(int));
    }
    /* int* visited = calloc(HASH_MAX, sizeof(int)); */

    count_settings(&count, n, m, h, w, g, s, board, visited);
    printf("%i", count);
    return 0;
}

/* void print_board(int n, int m, int** board) {
    char symbols[] = {'_', 'Q', 'R', 'B', 'K'};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c ", symbols[board[i][j]]);
        }
        printf("\n");
    }
} */

int check_setting(int n, int m, int** board) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int currentPiece = board[i][j];
            switch(currentPiece){
                case QUEEN:
                    for(int k = 1; k < n; k++){
                        if((board[(i+k)%n][j] != EMPTY)) return 1;
                    }
                    for(int l = 1; l < m; l++){
                        if((board[i][(j+l)%m] != EMPTY)) return 1;
                    }
                    for(int k = 1; k < m; k++){
                        if(((board[(i+k)%n][(j+k)%m] != EMPTY) || (board[(i+k)%n][(j-k)%m] != EMPTY)) && ((i+k)%n != i)) return 1;
                    }
                    break;
                case ROOK:
                    for(int k = 1; k < n; k++){
                        if((board[(i+k)%n][j] != EMPTY)) return 1;
                    }
                    for(int l = 1; l < m; l++){
                        if((board[i][(j+l)%m] != EMPTY)) return 1;
                    }
                    break;
                case BISHOP:
                    for(int k = 1; k < 10; k++){
                        if(((board[(i+k)%n][(j+k)%m] != EMPTY) || (board[(i+k)%n][(j-k)%m] != EMPTY)) && ((i+k)%n != i)) return 1;
                    }
                    break;
                case KNIGHT:
                    break;
                default:
                    continue;
            }
        }
    }

    return 0; // No piece can capture another
}

void count_settings(int* counter, int n, int m, int h, int w, int g, int s, int** board, int* visited){
    //print_board(n, m, board);
    //getchar();
    /* int hash = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            hash = hash * 3 + board[i][j];
        }
    }
    hash %= HASH_MAX;
    // Check if this configuration has already been visited
    if (visited[hash]) return;
    visited[hash] = 1; */

    if(check_setting(n, m, board)) return;
    if(!(h | w | g | s)){
        //printf("COUNT!\n");
        (*counter)++;
        return;
    }
    if(h > 0){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 0)
                {
                    board[i][j] = QUEEN;
                    count_settings(counter, n, m, h-1, w, g, s, board, visited);
                    board[i][j] = 0;

                }
            }
        }
    }
    if(w > 0){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 0)
                {
                    board[i][j] = ROOK;
                    count_settings(counter, n, m, h, w-1, g, s, board, visited);
                    board[i][j] = 0;

                }
            }
        }
    }
    if(g > 0){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 0)
                {
                    board[i][j] = BISHOP;
                    count_settings(counter, n, m, h, w, g-1, s, board, visited);
                    board[i][j] = 0;

                }
            }
        }
    }
    if(s > 0){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 0)
                {
                    board[i][j] = KNIGHT;
                    count_settings(counter, n, m, h, w, g, s-1, board, visited);
                    board[i][j] = 0;
                }
            }
        }
    }
}