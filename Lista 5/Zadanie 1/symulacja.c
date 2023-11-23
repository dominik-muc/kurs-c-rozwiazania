#include "plansza.h"
#include "gracz_losowy.h"
#include "gracz_ze_strategia.h"
#include <time.h>

int main(int argc, char** argv){
    srand(time(NULL));
    long n = 3;

    if(argc > 2){
        fprintf(stderr, "Zbyt dużo argumentów! Program przyjmuje jeden argument będący liczbą naturalną dodatnią.\n");
        return 255;
    }
    if(argc == 2){
        char* dump = NULL;
        long input = strtol(argv[1], &dump, 0);
        if(dump[0] || input <= 0){
            fprintf(stderr, "Niepoprawny argument! Program przyjmuje jeden argument będący liczbą naturalną dodatnią.\n");
            return 255;
        }
        n = input;
    }

    char** board = initialize_board(n);
    Symbol player_on_move = rand() % 2;
    int result = 2;


    while(result == 2)
    {
        Coordinates move_coords;
        if(player_on_move == 0){
            move_coords = get_stupid_move(CIRCLE, board);
        }
        else{
            move_coords = get_smart_move(CROSS, board);
        }
        result = move(player_on_move, move_coords, board);
        
        show_board(stdin, board);
        getchar();
        
        player_on_move = !player_on_move;
    }

    if(result == 0){
        printf("Gracz kółko (głupi) wygrał.\n");
        return 0;
    }
    printf("Gracz krzyżyk (mądry) wygrał.\n");
    return 0;
}