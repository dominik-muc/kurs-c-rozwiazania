//Dominik Muc, 345952, Lista 2, Zadanie 2
#include <stdio.h>
#include <stdlib.h>


int* wczytaj_towar(){   
    int n;
    int ciezar = 0;
    int* towar = malloc(2*sizeof(int));

    scanf("%i", &n);
    scanf("%i", &towar[0]);

    for(int i = 1; i < n; i++){
        scanf("%i", &ciezar);

        if(ciezar <= towar[0]){
            if(ciezar > towar[1]){
                towar[1] = ciezar;
            }
        }
        if(ciezar > towar[0]){
            towar[1] = towar[0];
            towar[0] = ciezar;
        }
    }

    return towar;
}


int main(){
    int dni;
    int waga;
    int ciezar = 0;

    scanf("%i", &dni);

    int** towary = (int**)malloc(sizeof(int*)*dni);

    for(int i = 0; i < dni; i++){
        towary[i] = wczytaj_towar();
    }

    scanf("%i", &waga);

    for(int i = 0; i < dni; i++){
        if(towary[i][0] >= waga) ciezar += towary[i][0];
        if(towary[i][1] >= waga) ciezar += towary[i][1];
    }

    printf("%i", ciezar);

    return 0;
}