//Dominik Muc, 345952, Lista 7 zadanie 1
#include "cezar.h"
#include <stdio.h>
#include <stdlib.h>

void failed_to_create_object_exception();

int main(){
    CezarObject cezar = new_cezar("Kocham programowanie obiektowe w C!");
    if(!cezar) failed_to_create_object_exception();

    set_shift(cezar, 100000);
    print_shifted(cezar);

    CezarObject shifted = clone_shifted(cezar);
    if(!shifted) failed_to_create_object_exception();

    if(set_message(cezar, "Nie mogę się doczekać programowania w C++")){
        fprintf(stderr, "Nie udało się zmienić wiadomości!\n");
    }
    print_shifted(cezar);
    print_shifted(shifted);
    printf("%i %i\n", get_shift(cezar), get_shift(shifted));

    destroy_cezar(cezar);
    destroy_cezar(shifted);
    return 0;
}

void failed_to_create_object_exception(){
    fprintf(stderr, "Nie udało się stworzyć obiektu!\n");
    exit(0xFF);
}