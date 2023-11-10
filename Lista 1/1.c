//Dominik Muc, 345952, Lista 1, zadanie 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

    srand(time(NULL));
    unsigned char liczba = rand() % 100;
    unsigned char guess = 0;
    printf("Witaj w grze o losowaniu. Komputer właśnie wylosował liczbę całkowitą z zakresu (0, 100).\nTwoim zadaniem jest ją zgadnąć.\nKiedy wpiszesz liczbę, program napisze, czy docelowa liczba jest większa, czy mniejsza od tej, którą podałeś.\nJeśli zgadniesz liczbę, program cię o tym powiadomi, po czym zakończy działanie.\nPowodzenia!\n");
    while(1){
        printf("Podaj liczbę: ");
        while((scanf("%hhu", &guess) != 1 ) || getchar() != '\n'){
            printf("Złe wejście!\nPodaj liczbę: ");
            while(getchar() != '\n');
        }
        if(guess == liczba){
            printf("Udało ci się zgadnąć liczbę!\n");
            return 0;
        }
        if(guess < liczba) printf("Twoja liczba jest za mała.\n");
        if(guess > liczba) printf("Twoja liczba jest za duża.\n");
    }
    return -1;
}
