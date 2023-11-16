//Dominik Muc, 345952, Lista 4, zadanie 3
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void read_square(int* result, int* max_layer, int layer);

int main(){
    int result[64] = {0};
    int max_layer = 0;
    read_square(result, &max_layer, 0);
    unsigned long long numerator = 0;
    unsigned long long denominator = 1;

    for(int i = 0; i <= max_layer; i++){
        numerator <<= 2;
        numerator += result[i];
    }

    if(numerator > 0) denominator <<= 2*(max_layer);

    while(numerator % 2 == 0 && numerator > 0){
        numerator /= 2;
        denominator /= 2;
    }
    
    printf("%llu/%llu", numerator, denominator);
    return 0;
}

void read_square(int* result, int* max_layer, int layer){
    int c;
    scanf("%i", &c);
    if(c == 1) result[layer]++;
    if(c == 2){
        if(*max_layer == layer) (*max_layer)++;
        for(int i = 0; i < 4; i++){
            read_square(result, max_layer, layer + 1);
        }
    }
}

