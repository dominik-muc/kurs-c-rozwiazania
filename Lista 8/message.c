#include <stdio.h>
#include <stdlib.h>
typedef enum Piece{
    EMPTY,
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT
} Piece;
int checking(int n, int m, int board[n][m]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            switch(board[i][j]){
                case QUEEN:;
                    for(int x = 0; x < n; x++){
                        for(int y = 0; y < m; y++){
                            if (board[x][y] != EMPTY && (x != i || y != j)) {
                                if (x == i || y == j || abs(x - i) == abs(y - j)) {
                                    return 1;
                                }
                            }
                        }
                    }
                    break;
                case BISHOP:;
                    for(int x = 0; x < n; x++){
                        for(int y = 0; y < m; y++){
                            if (board[x][y] != EMPTY && (x != i || y != j)) {
                                if (abs(x - i) == abs(y - j)) {
                                    return 1;
                                }
                            }
                        }
                    }
                    break;
                case KNIGHT:;
                    int knight_moves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                                              {1, -2}, {1, 2}, {2, -1}, {2, 1}};
                    for(int k = 0; k < 8; k++){
                        int new_row = i + knight_moves[k][0];
                        int new_col = j + knight_moves[k][1];
                        if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m){
                            if(board[new_row][new_col] != EMPTY){
                                return 1;
                            }
                        }
                    }
                    break;
                case ROOK:;
                    for(int x = 0; x < n; x++){
                        if(board[x][j] != EMPTY && x != i){
                            return 1;
                        }
                    }
                    for(int y = 0; y < m; y++){
                        if(board[i][y] != EMPTY && y != j){
                            return 1;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}


void generate(int* count, int n, int m, int h, int w, int g, int s, int** board, int x, int y){
    if (h < 0 || w < 0 || g < 0 || s < 0){
        return;
    } else if (h + w + g + s == 0){
            (*count)++;
        return;
    }
    if (y == m){
        x += 1;
        y = 0;
    }
    int b = y;
    if (h > 0){
        for (int i = x; i < n; i++){
            if (i != x){
                b = 0;
            } 
            for (int j = b; j < m; j++){
                if (board[i][j] == 0){
                    board[i][j] = 1;
                    if (checking(n, m, board)){
                        generate(count, n, m, -1, w, g, s, board, i, j + 1);
                    } else generate(count, n, m, h - 1, w, g, s, board, i, j + 1);
                    board[i][j] = 0;
                }
            }
        }
    }
    if (w > 0){
        for (int i = x; i < n; i++){
            if (i != x){
                b = 0;
            }            
            for (int j = b; j < m; j++){
                if (board[i][j] == 0){     
                    board[i][j] = 2;
                    if (checking(n, m, board)){
                        generate(count, n, m, h, -1, g, s, board, i, j + 1);
                    } else generate(count, n, m, h, w - 1, g, s, board, i, j + 1);
                    board[i][j] = 0;
                    
                }
            }
        }
    }   
    if (g > 0){
        for (int i = x; i < n; i++){
            if (i != x){
                b = 0;
            }
            for (int j = b; j < m; j++){
                if (board[i][j] == 0){            
                    board[i][j] = 3;
                    if (checking(n, m, board)){
                        generate(count, n, m, h, w, -1, s, board, i, j + 1);
                    } else generate(count, n, m, h, w, g - 1, s, board, i, j + 1);
                    board[i][j] = 0;
                }
            }
        }
    }     
}

int main(){
    int n, m, h, w, g, s;
    int count = 0;
    if(scanf("%i %i", &n, &m) != 2) return 0;
    if(scanf("%i %i %i %i", &h, &w, &g, &s) != 4) return 0;

    int** board = malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++){
        board[i] = calloc(m, sizeof(int));
    }

    generate(&count, n, m, h, w, g, s, board, 0, 0);
    printf("%i", count);
    return 0;
}