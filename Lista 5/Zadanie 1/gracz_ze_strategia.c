//Dominik Muc, 345952, Lista 5 zadanie 1
#include "gracz_ze_strategia.h"
#include "gracz_losowy.h"

Field get_smart_move(OnMove on_move, long side, char** board){
    char my_enemy = on_move ? 'o' : 'x';
    for(long row = 0; row < side; row++){
        int available_row = 1;
        int first_column = -1;
        for(long column = 0; column < side; column++){
            if(board[row][column] == '_') first_column = column;
            if(board[row][column] == my_enemy){
                available_row = 0;
                break;
            }
        }
        
        if(available_row && (first_column >= 0)){
            Field move;
            move.row = row;
            move.column = first_column;
            return move;
        }
    }
    return get_stupid_move(side, board);
}