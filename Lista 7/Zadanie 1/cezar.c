//Dominik Muc, 345952, Lista 7 zadanie 1
#include "cezar.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static char* shift(const char* message, const int shift);

struct Cezar
{
    char* message;
    int shift;
};

CezarObject new_cezar(const char* message){
    CezarObject object = malloc(sizeof(struct Cezar));
    if(!object) return NULL;
    object->message = malloc(sizeof(char) * strlen(message));
    strcpy(object->message, message);
    object->shift = 0;
    return object;
}

void destroy_cezar(CezarObject self){
    free(self->message);
    free(self);
    self = NULL;
}

int get_shift(const CezarObject self){
    return self->shift;
}

void set_shift(CezarObject self, const int shift){
    self->shift = shift;
}

void print_shifted(const CezarObject self){
    char* to_print = shift(self->message, self->shift);
    printf("%s\n", to_print);
    free(to_print);
}

CezarObject clone_shifted(const CezarObject base){
    CezarObject object = malloc(sizeof(int) + sizeof(char) * strlen(base->message));
    if(!object) return NULL;
    object->message = shift(base->message, base->shift);
    object->shift = 0;
    return object;
}

int set_message(CezarObject self, const char* message){
    char* ptr = realloc(self->message, strlen(message));
    if(!ptr) return 1;
    self->message = ptr;
    strcpy(self->message, message);
    return 0;
}

static char* shift(const char* message, const int shift){
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
