//Dominik Muc, 345952, Lista 7 zadanie 1
#include "cezar.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static char* shift(char* message, int shift);

struct Cezar
{
    char* message;
    int shift;
};

Cezar* new_cezar(char* message){
    Cezar* object = malloc(sizeof(Cezar));
    object->message = malloc(sizeof(char) * strlen(message));
    strcpy(object->message, message);
    object->shift = 0;
    return object;
}

void destroy_cezar(Cezar* self){
    free(self->message);
    free(self);
    self = NULL;
}

int get_shift(Cezar* self){
    return self->shift;
}

void set_shift(Cezar* self, int shift){
    self->shift = shift;
}

void print_shifted(Cezar* self){
    char* to_print = shift(self->message, self->shift);
    printf("%s\n", to_print);
    free(to_print);
}

Cezar* clone_shifted(Cezar* base){
    Cezar* object = malloc(sizeof(int) + sizeof(char) * strlen(base->message));
    object->message = shift(base->message, base->shift);
    object->shift = 0;
    return object;
}

void set_message(Cezar* self, char* message){
    self->message = realloc(self->message, strlen(message));
    strcpy(self->message, message);
}

static char* shift(char* message, int shift){
    char* result = malloc(strlen(message) * sizeof(char));
    for(int i = 0; i < (int)strlen(message); i++){
        if(message[i] >= 65 && message[i] <= 90){
            result[i] = (message[i] + shift - 65) % 26 + 65;
            continue;
        }
        if(message[i] >= 97 && message[i] <= 122){
            result[i] = (message[i] + shift - 97) % 26 + 97;
            continue;
        }
        result[i] = message[i];
    }
    return result;
}
