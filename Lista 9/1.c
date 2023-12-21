//Dominik Muc, 345952, Lista 9 zadanie 1
#include <stdio.h>
#include "text_aligner.h"

void bad_argument(char* arg);
void stream_null(char* arg);
void no_parameter();
void direction_set();
void reoccuring_flag(char* arg);

int main(int argc, char** argv){
    FILE* input = stdin;
    int width = 72;
    Direction direction = RANDOM;
    int width_set = 0;
    int file_set = 0;
    
    //parse argv
    for(int i = 1; i < argc; i++){
        if(argv[i][0] != '-' || argv[i][2] != '\0') bad_argument(argv[i]);
        switch(argv[i][1]){
            case 'i':
                if(file_set) reoccuring_flag(argv[i]);
                if(++i == argc) no_parameter();
                input = fopen(argv[i], "r");
                if(!input) stream_null(argv[i]);
                file_set = 1;
                break;
            case 'w':
                if(file_set) reoccuring_flag(argv[i]);
                if(++i == argc) no_parameter();
                char* dump;
                width = (int)strtol(argv[i], &dump, 10);
                if(dump[0] || width < 1 || width > 1000) bad_argument(argv[i]);
                width_set = 1;
                break;
            case 'l':
                if(direction != RANDOM) direction_set();
                direction = LEFT;
                break;
            case 'r':
                if(direction != RANDOM) direction_set();
                direction = RIGHT;
                break;
            default:
                bad_argument(argv[i]);
        }
    }

    int exit_code = text_align(input, stdout, width, direction);

    switch(exit_code){
        case 0:
            return EXIT_SUCCESS;
        default:
            fprintf(stderr, "Wystąpił nieoczekiwany błąd programu!\n");
            return EXIT_FAILURE;
    }
}

void bad_argument(char* arg){
    fprintf(stderr, "Niepoprawny argument: %s\n", arg);
    exit(EXIT_FAILURE);
}

void stream_null(char* arg){
    perror("Nie udało się otworzyć pliku");
    exit(EXIT_FAILURE);
}

void no_parameter(){
    fprintf(stderr, "Brak oczekiwanego parametru!\n");
    exit(EXIT_FAILURE);
}

void direction_set(){
    fprintf(stderr, "Już ustawiono kierunek wyrównywania tekstu!\n");
    exit(EXIT_FAILURE);
}

void reoccuring_flag(char* arg){
    fprintf(stderr, "Już ustawiono flagę '%s'!\n", arg);
    exit(EXIT_FAILURE);
}