//Dominik Muc, 345952, Lista 7 zadanie 1
#include "cezar.h"
#include <stdio.h>

int main(){
    CezarObject cezar = new_cezar("Kocham programowanie obiektowe w C!");
    set_shift(cezar, 100000);
    print_shifted(cezar);
    CezarObject shifted = clone_shifted(cezar);
    set_message(cezar, "Nie mogę się doczekać programowania w C++");
    print_shifted(cezar);
    print_shifted(shifted);
    printf("%i %i\n", get_shift(cezar), get_shift(shifted));

    destroy_cezar(cezar);
    destroy_cezar(shifted);
    return 0;
}