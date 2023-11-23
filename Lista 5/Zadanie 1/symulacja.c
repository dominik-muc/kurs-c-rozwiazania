#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    int n = 3;
    if(argc > 2){
        fprintf(stderr, "Zbyt dużo argumentów! Program przyjmuje jeden argument będący liczbą naturalną.\n");
        return 255;
    }
    if(argc == 2){
        strtol()
    }
    return 0;
}