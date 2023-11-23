//Dominik Muc, 345952, Lista 5 zadanie 1
#include "plansza.h"
#include "gracz_losowy.h"
#include "gracz_ze_strategia.h"
#include <time.h>

int main(int argc, char** argv){
    srand(time(NULL));
    long n = 3;

    if(argc > 2){
        fprintf(stderr, "Zbyt dużo argumentów! Program przyjmuje jeden argument będący liczbą naturalną dodatnią.\n");
        return 0xFF;
    }
    if(argc == 2){
        char* dump = NULL;
        long input = strtol(argv[1], &dump, 0);
        if(dump[0] || input <= 0){
            fprintf(stderr, "Niepoprawny argument! Program przyjmuje jeden argument będący liczbą naturalną dodatnią.\n");
            return 0xFF;
        }
        n = input;
    }

    char** board = initialize_board(n);
    OnMove player_on_move = rand() % 2;
    GameState state = ONGOING;


    while(state == ONGOING)
    {
        Field move_coords;
        if(player_on_move == CIRCLE) move_coords = get_stupid_move(n, board);
        else move_coords = get_smart_move(CROSS, n, board);

        state = move(player_on_move, move_coords, n, board);
        
        system("clear||cls");
        show_board(n, board);
        printf("Nacisnij dowolny klawisz żeby kontynuować.");
        getchar();
        
        player_on_move = !player_on_move;
    }

    free_board(n, board);

    switch(state){
        case DRAW:
            printf("Remis.\n");
            break;
        case CIRCLE_WIN:
            printf("Gracz kółko (głupi) wygrał.\n");
            break;
        case CROSS_WIN:
            printf("Gracz krzyżyk (mądry) wygrał.\n");
            break;
        case WRONG_MOVE:
            printf("Niedozwolony ruch!\n");
            break;
        default:
            fprintf(stderr, "Wystąpił błąd programu.\n");
            return 0xFF;
    }
    return 0;
}