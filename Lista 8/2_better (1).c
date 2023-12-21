#include <stdio.h>
#include <stdlib.h>

typedef enum Piece{
    EMPTY,
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT
} Piece;

void count_settings(int* counter, int iterator, int n, int m, int* board, int q, int r, int b, int k);

int main(){
    int n, m, q, r, b, k;
    int count = 0;
    if(scanf("%i %i", &n, &m) != 2) return 0;
    if(scanf("%i %i %i %i", &q, &r, &b, &k) != 4) return 0;

    int* board = calloc(n*m, sizeof(int));
    count_settings(&count, 0, n, m, board, q, r, b, k);
    printf("%i", count);
    return 0;
}

int check_setting(int n, int m, int* board){
    int arr_size = n*m;
    for(int i = 0; i < arr_size; i++){
        switch(board[i]){
            case QUEEN:;
                int row = i / m;
                int col = i % m;
                for(int j = 0; j < arr_size; j++){
                    if (board[j] != EMPTY && j != i) {
                        int j_row = j / m;
                        int j_col = j % m;
                        if (j_row == row || j_col == col || abs(j_row - row) == abs(j_col - col)) {
                            return 1;
                        }
                    }
                }
                break;
            case BISHOP:;
                int curr_row = i / m;
                int curr_col = i % m;
                for(int j = 0; j < arr_size; j++){
                    if (board[j] != EMPTY && j != i) {
                        int j_row = j / m;
                        int j_col = j % m;
                        if (abs(j_row - curr_row) == abs(j_col - curr_col)) {
                            return 1;
                        }
                    }
                }
                break;
            /* case KNIGHT:;
                int knight_moves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                                          {1, -2}, {1, 2}, {2, -1}, {2, 1}};
                int knight_row = i / m;
                int knight_col = i % m;
                for(int j = 0; j < 8; j++){
                    int new_row = knight_row + knight_moves[j][0];
                    int new_col = knight_col + knight_moves[j][1];
                    if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m){
                        int idx = new_row * m + new_col;
                        if(board[idx] != EMPTY){
                            return 1;
                        }
                    }
                }
                break; */
            case ROOK:;
                int vert_iter = i + m;
                while((vert_iter % arr_size) != i){
                    if(board[vert_iter % arr_size] != EMPTY){
                        return 1;
                    }
                    vert_iter += m;
                }
                //horizontal
                row = (i / m) * m;
                for(int j = 0; j < m; j++){
                    if((board[row+j] != EMPTY) && (row+j != i)){

                        return 1;
                        
                    }
                }
                break;
            default:
                break;
        }
    }
    return 0;
}

void count_settings(int* counter, int iterator, int n, int m, int* board, int q, int r, int b, int k){
    int arr_size = n*m;
    if(q < 0 || r < 0 || b < 0 || k < 0) return;
    if(check_setting(n, m, board)) return;
    if(!(q | r | b | k)){
        (*counter)++;
        return;
    }
    if(iterator >= arr_size) return;
    board[iterator] = EMPTY;
    count_settings(counter, iterator+1, n, m, board, q, r, b, k);
    board[iterator] = QUEEN;
    count_settings(counter, iterator+1, n, m, board, q-1, r, b, k);
    board[iterator] = ROOK;
    count_settings(counter, iterator+1, n, m, board, q, r-1, b, k);
    board[iterator] = BISHOP;
    count_settings(counter, iterator+1, n, m, board, q, r, b-1, k);
    /* board[iterator] = KNIGHT;
    count_settings(counter, iterator+1, n, m, board, q, r, b, k-1); */
    board[iterator] = EMPTY;
}