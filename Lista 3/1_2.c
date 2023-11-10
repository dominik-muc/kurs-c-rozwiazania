//Dominik Muc, 345952, Lista 3, zadanie 1 pkt 2

//NA WYJŚCIU BITY SĄ ODWRÓCONE - ZGODNIE Z UMOWĄ
//To znaczy: dla długości, pierwsze dwa bity z lewej to A, kolejne dwa to B itp; dla kodowania pierwsze cztery bity z lewej to A
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    char* codes[] = {
    ".-",   //A
    "-...", //B
    "-.-.", //C
    "-..",  //D
    ".",    //E
    "..-.", //F
    "--.",  //G
    "....", //H
    "..",   //I
    ".---", //J
    "-.-",  //K
    ".-..", //L
    "--",   //M
    "-.",   //N
    "---",  //O
    ".--.", //P
    "--.-", //Q
    ".-.",  //R
    "...",  //S
    "-",    //T
    "..-",  //U
    "...-", //V
    ".--",  //W
    "-..-", //X
    "-.--", //Y
    "--..", //Z
    };

    int curr_bit = 1;
    unsigned char len[7] = {0};
    int len_iter = -1;
    int code_iter = -1;
    unsigned char code[13] = {0};
    for(int i = 0; i < 26; i++){
        if(i%4 == 0) len_iter++;
        if(i%2 == 0) code_iter++;
        //out = -32;
        curr_bit = pow(2, (4-4*(i%2)));
        len[len_iter] -= pow(2, (6-2*(i%4)));
        for(int j = strlen(codes[i])-1; j >= 0; j--){
            if(codes[i][j] == '-'){
                code[code_iter] += curr_bit;
            }
            curr_bit *= 2;
            len[len_iter] += pow(2, (6-2*(i%4)));
        }      
    }
    printf("Tablica dlugosci:\n");
    for(int i = 0; i < 7; i++){
        printf("0x%02X,\n", len[i]);
    }
    printf("Tablica kodowania:\n");
    for(int i = 0; i < 13; i++){
        printf("0x%02X,\n", code[i]);
    }
    return 0;
}