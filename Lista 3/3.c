//Dominik Muc, 345952, Lista 3 zadanie 3
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Player{
    int id;
    int number;
};

struct Player* load_players(int k){
    struct Player* ret_players = (struct Player*)malloc(sizeof(struct Player)*pow(2, k));
    for(int i = 0; i < pow(2, k); i++){
        ret_players[i].id = i;
        scanf("%i", &ret_players[i].number);
    }
    return ret_players;
}

int different_factorials(int n){
    int ret = 0;
    int counted = 0;
    for(int i = 2; i < sqrt(n) + 1; i++){
        while(n % i == 0){
            counted = 1;
            n /= i;
        }
        ret += counted;
        counted = 0;
    }
    if(n > 1) ret++;
    return ret;
}

int main(){
    int k;
    int* results;
    struct Player* players;

    scanf("%i", &k);
    results = (int*)malloc(sizeof(int)*pow(2, k));
    players = load_players(k);

    for(int i = k; i > 0; i--){
        struct Player* next_round = (struct Player*)malloc(sizeof(struct Player)*pow(2, i-1));
        for(int j = 0; j < pow(2, i); j += 2){
            int result = different_factorials(abs(players[j].number - players[j+1].number));
            results[players[j + result % 2].id]++;
            next_round[j/2] = players[j + result % 2];
        }
        free(players);
        players = next_round;
    }

    for(int i = 0; i < pow(2, k); i++) printf("%i ", results[i]);

    free(players);
    return 0;
}
