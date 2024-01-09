#include <stdio.h>
#include <stdlib.h>

int get_time(char** maze, int N, int M, int x, int y);

typedef struct Point{
    int x;
    int y;
} Point;

void print_maze(char** maze, int N, int M){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("%c", maze[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
    getchar();
}

int main(){
    int N, M, Q;
    if(scanf("%i %i %i", &N, &M, &Q) != 3) return EXIT_FAILURE;
    char** maze = (char**)malloc(sizeof(char*)*(N+2));
    maze[0] = (char*)malloc(sizeof(char)*(M+2));
    for(int i = 0; i < M+2; i++){
        maze[0][i] = 'X';
    }
    for(int i = 1; i <= N; i++){
        maze[i] = (char*)malloc(sizeof(char)*(M+2));
        maze[i][0] = 'X';
        getchar();
        for(int j = 1; j <= M; j++){
            if(scanf("%c", &(maze[i][j])) != 1) return EXIT_FAILURE;
        }
        maze[i][M+1] = 'X';
    }
    maze[N+1] = (char*)malloc(sizeof(char)*(M+2));
    for(int i = 0; i < M+2; i++){
        maze[N+1][i] = 'X';
    }
    //print_maze(maze, N+2, M+2);
    int x, y;
    while(Q--){
        if(scanf("%i %i", &x, &y) != 2) return EXIT_FAILURE;
        printf("%i\n", get_time(maze, N+2, M+2, x, y));
    }

    for(int i = 0; i < N+2; i++){
        free(maze[i]);
    }
    free(maze);

    return EXIT_SUCCESS;
}

char** copy(char** maze, int N, int M){
    char** ret = (char**)malloc(sizeof(char*)*N);
    for(int i = 0; i < N; i++){
        ret[i] = (char*)malloc(sizeof(char)*M);
        for(int j = 0; j < M; j++){
            ret[i][j] = maze[i][j];
        }
    }
    return ret;
}
int is_plus = 0;
int is_minus = 0;
int update(char** maze, int N, int M){
    //print_maze(maze, N, M);
    Point to_update[10000] = {0};
    int iter = 0;
    for(int i = 1; i < N-1; i++){
        for(int j = 1; j < M-1; j++){
            if(!(maze[i-1][j] == '0' || maze[i][j-1] == '0' || maze[i+1][j] == '0' || maze[i][j+1] == '0')) continue;
            switch(maze[i][j]){
                case '0':
                    continue;
                case 'X':
                    continue;
                case '-':
                    is_minus = 1;
                    to_update[iter].x = i;
                    to_update[iter].y = j;
                    iter++;
                    break;
                case '+':
                    is_plus = 1;
                    to_update[iter].x = i;
                    to_update[iter].y = j;
                    iter++;
                    break;
                default:
                    to_update[iter].x = i;
                    to_update[iter].y = j;
                    iter++;
            }
        }
    }
    while(iter--){
        if(maze[to_update[iter].x][to_update[iter].y] == '-' || maze[to_update[iter].x][to_update[iter].y] == '+') maze[to_update[iter].x][to_update[iter].y] = '0';
        else maze[to_update[iter].x][to_update[iter].y]--;
    }
    return !(is_minus && is_plus);
}

int get_time(char** maze, int N, int M, int x, int y){
    int time = 0;
    char** my_maze = copy(maze, N, M);
    is_minus = 0;
    is_plus = 0;
    
    if(!(my_maze[x][y] == '-' || my_maze[x][y] == '+')){
        while(my_maze[x][y]-- > '0'+1) time++;
    }
    else{
        if(my_maze[x][y] == '-') is_minus = 1;
        my_maze[x][y] = 0;
    }
    while(update(my_maze, N, M)) time++;

    for(int i = 0; i < N; i++){
        free(my_maze[i]);
    }
    free(my_maze);
    return time+2;
}