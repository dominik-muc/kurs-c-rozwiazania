//Dominik Muc, 345952, Lista 5 zadanie 1
#include "gracz_losowy.h"

Field get_stupid_move(long side, char** board){
    while(1){
        Field move = {rand() % side, rand() % side};
        if(board[move.row][move.column] == '_') return move;
    }
}