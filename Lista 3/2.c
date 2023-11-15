//Dominik Muc, 345952, Lista 3 zadanie 2

/*
Wprowadzone n musi się mieścić w zakresie int. Program nie weryfikuje wejścia.
Przykładowe wejście:
    4
    c.b.
    ....
    ...c
    .c.b
    LL
Wyjście:
    ....
    ...c
    ..bc
    ..bc 
*/

#include <stdio.h>
#include <stdlib.h>

enum Direction{
    LEFT = 0,
    RIGHT = 1
};

char** turn(int n, char** board, enum Direction direction){
    int row_iterator, column_iterator = 0;
    char** new_board = (char**)malloc(sizeof(char*)*(n+1));
    for(int i = 0; i <= n; i++){
        new_board[i] = (char*)malloc(sizeof(char)*(n+1));
        for(int j = 0; j <= n; j++){
            new_board[i][j] = '.';
        }
    } 
    
    for(int i = n*direction; (n-i)+(2*i-n)*(int)direction >= 0; i += 1 - 2 * direction){
        row_iterator = n;
        for(int j = n*direction; (n-j)+(2*j-n)*(int)direction >= 0; j += 1 - 2 * direction){
            if(board[i][j] != '.'){
                new_board[row_iterator][column_iterator] = board[i][j];
                row_iterator--;
            }
        }
        column_iterator++;
    }
    return new_board;
}

int main(){
    int n = 0;
    char c;
    scanf("%i", &n);
    char** board = (char**)malloc(sizeof(char*)*n);
    char** new_board;

    for(int i = 0; i < n; i++){
        board[i] = (char*)malloc(sizeof(char)*n);
        for(int j = 0; j < n; j++) board[i][j] = (c = getchar()) != '\n' ? c : getchar();
    }

    getchar(); //wyrzucamy '\n' które się pojawia po tablicy.

    while((c = getchar()) != '\n'){
        if(c == 'L') new_board = turn(n-1, board, LEFT);
        if(c == 'R') new_board = turn(n-1, board, RIGHT);

        for(int i = 0; i < n; i++) free(board[i]);
        free(board);
        board = new_board;
    }

    printf("Wyjście:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) printf("%c", board[i][j]);
        putchar('\n');
    }

    for(int i = 0; i < n; i++) free(board[i]);
    free(board);
    return 0;
}