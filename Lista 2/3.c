//Dominik Muc, 345952, Lista 2, Zadanie 3
#include <stdio.h>
#include <stdlib.h>

int* wczytaj_kolejke(int* counter){   
    int n;
    scanf("%i", &n);

    int* zwrot = (int*)malloc(sizeof(int)*2*(n+1));

    zwrot[0] = n; //pierwszy indeks zawiera naszą ilość grup
    zwrot[1] = 2; //drugi indeks zawiera iterator

    for(int i = 2; i < 2*(n+1); i++){
        scanf("%i", &zwrot[i]);
        if (i%2 == 0) *counter += zwrot[i]; //dodajemy do licznika maks pasazerow
    }

    return zwrot;
}


int main(){
    int stacje;
    int miejsca;
    long long przejazdy;
    int pasazerowie = 0;
    int bitmapa[1000] = {0};
    int zajete = 0;
    int stacja = 0;
    int maks_pasazerow = 0;
    int* kolejki[1000];

    scanf("%i %i %lli", &stacje, &miejsca, &przejazdy);

    for(int i = 0; i < stacje; i++){
        kolejki[i] = wczytaj_kolejke(&maks_pasazerow);     
    }

    for(long long i = 0; i <= przejazdy; i++){
        stacja = i % stacje;

        if(bitmapa[stacja] == 0 && zajete == miejsca) continue;
        zajete -= bitmapa[stacja];
        pasazerowie += bitmapa[stacja];
        bitmapa[stacja] = 0; //pasazerowie wysiadaja
        
        if(pasazerowie == maks_pasazerow) break;

        for(int* j = &kolejki[stacja][1]; *j < 2*((kolejki[stacja][0])+1); *j += 2){

            //jeżeli nie mozemy wziac pasazerow z wiecej niz jednej grupy
            if(kolejki[stacja][*j] >= miejsca-zajete){
                bitmapa[kolejki[stacja][*j+1]] += miejsca-zajete;
                kolejki[stacja][*j] -= miejsca-zajete;
                zajete = miejsca;           
                break;
            }

            bitmapa[kolejki[stacja][*j+1]] += kolejki[stacja][*j];
            zajete += kolejki[stacja][*j];
            kolejki[stacja][*j] = 0;
        }
    }
    
    printf("%u", pasazerowie);

    return 0;
}