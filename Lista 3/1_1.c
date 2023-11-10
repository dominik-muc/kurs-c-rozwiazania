//Dominik Muc, 345952, Lista 3, zadanie 1 pkt 1
#include <stdio.h>
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
    "-----",
    "--.--"
    };
    unsigned char out = 0;
    int curr_bit = 1;
    for(int i = 0; i < 28; i++){
        out = -32;
        curr_bit = 1;
        for(int j = strlen(codes[i])-1; j >= 0; j--){
            if(codes[i][j] == '-') out += curr_bit;
            curr_bit *= 2;
            out += 32;
        }
        printf("0x%02X,\n", out);
    }
    return 0;
}