//Dominik Muc, 345952, Lista 7 zadanie 2
#include <stdio.h>
#include <stdlib.h>

typedef struct Array{
    char bitmap[4096][3];
} Array;

typedef enum Operations{
    XOR,
    OR,
    AND
} Operations;

int main(){
    int n, m;
    scanf("%i %i", &n, &m);

    Array** dp = malloc(n * sizeof(Array*));
    for(int i = 0; i < n; i++){
        dp[i] = malloc(m * sizeof(Array));
    }

    int value = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%i", &value);           
            if(j == 0 && i == 0){
                dp[0][0].bitmap[value ^ 0][XOR] = 1;
                dp[0][0].bitmap[value | 0][OR] = 1;
                dp[0][0].bitmap[value & 0][AND] = 1;
                continue;
            }
            for(int x = 0; x < 4096; x++){
                if(i != 0){
                    if(dp[i-1][j].bitmap[x][XOR]){
                        dp[i][j].bitmap[x | value][OR] = 1;
                        dp[i][j].bitmap[x & value][AND] = 1;
                    }
                    if(dp[i-1][j].bitmap[x][OR]){
                        dp[i][j].bitmap[x ^ value][XOR] = 1;
                        dp[i][j].bitmap[x & value][AND] = 1;
                    }
                    if(dp[i-1][j].bitmap[x][AND]){
                        dp[i][j].bitmap[x ^ value][XOR] = 1;
                        dp[i][j].bitmap[x | value][OR] = 1;
                    }
                }

                if(j != 0){
                    if(dp[i][j-1].bitmap[x][XOR]){
                        dp[i][j].bitmap[x | value][OR] = 1;
                        dp[i][j].bitmap[x & value][AND] = 1;
                    }
                    if(dp[i][j-1].bitmap[x][OR]){
                        dp[i][j].bitmap[x ^ value][XOR] = 1;
                        dp[i][j].bitmap[x & value][AND] = 1;
                    }
                    if(dp[i][j-1].bitmap[x][AND]){
                        dp[i][j].bitmap[x ^ value][XOR] = 1;
                        dp[i][j].bitmap[x | value][OR] = 1;                   
                    }
                }   
            }
        }
    }

    int result = 0;
    for(int i = 0; i < 4096; i++) result += dp[n - 1][m - 1].bitmap[i][XOR] | dp[n - 1][m - 1].bitmap[i][OR] | dp[n - 1][m - 1].bitmap[i][AND];
    printf("%i\n", result);

    for(int i = 0; i < n; i++){
        free(dp[i]);
    }
    free(dp);

    return 0;
}