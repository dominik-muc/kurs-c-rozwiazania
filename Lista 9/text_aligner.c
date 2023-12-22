//Dominik Muc, 345952, Lista 9 zadanie 1
#include "text_aligner.h"

void add_char(char* ptr, char c, int current_length){
    ptr = realloc(ptr, sizeof(char) * (current_length + 1));
    ptr[current_length - 1] = c;
    ptr[current_length] = '\0';
}

void print_spaces(int n){
    for(int i = 0; i < n; i++) putchar(' ');
}

int text_align(FILE* input, int width, Direction direction){
    int swap = 0;
    if(direction == RANDOM){
        direction = LEFT;
        swap = 1;
    }
    char c;
    char* words[100];
    for(int i = 0; i < 100; i++){
        words[i] = malloc(sizeof(char*));
    }
    int length = 0;
    int current_length = 0;

    int iterator = 0;
    int count = 0;
    int is_first = 0;
    while((c = fgetc(input)) != EOF){
        if(isspace(c)){
            if(c == '\n'){
                count++;
                is_first = 1;
                continue;
            }
            
            is_first = 1;
            continue;
        }
        
        if(is_first){
            length += current_length;
            if(length + iterator - 1 >= width){
                int spaces = width-(length-current_length+iterator-1);
                for(int i = 0; i < iterator; i++){
                    printf("%s ", words[i]);
                    if(iterator == 1) continue;
                    int add = spaces/(iterator-1);
                    if(direction == LEFT){
                        if(swap) direction = RIGHT;
                        if(spaces != 0) add++;
                        print_spaces(add);
                        spaces -= add;
                        continue;
                    }
                    if(direction == RIGHT){
                        if(swap) direction = LEFT;
                        if(iterator - i -1 <= spaces) add++;
                        print_spaces(add);
                    }
                }
                //printf("%i %i %i\n", length-current_length+iterator-1, iterator, spaces);
                putchar('\n');
                words[0] = words[iterator];
                //printf("LEFTOVER: %s\n", words[0]);
                for(int i = 1; i < 100; i++){
                    words[i] = malloc(sizeof(char*));
                }
                length = current_length;
                iterator = 0;
            }
            iterator++;
            current_length = 0;
            

            if(count >= 2){
                for(int i = 0; i < iterator; i++){
                    printf("%s ", words[i]);
                }
                printf("\n\n");
                for(int i = 0; i < 100; i++){
                    words[i] = malloc(sizeof(char*));
                }
                length = current_length;
                iterator = 0;
                count = 0;
            }
        }
        is_first = 0;
        add_char(words[iterator], c, ++current_length);
        //printf("%c %i ", c, current_length);
    }
    length += current_length;
    if(length + iterator - 1 >= width){
                int spaces = width-(length-current_length+iterator-1);
                for(int i = 0; i < iterator; i++){
                    printf("%s ", words[i]);
                    if(iterator == 1) continue;
                    int add = spaces/(iterator-1);
                    if(direction == LEFT){
                        if(swap) direction = RIGHT;
                        if(spaces != 0) add++;
                        print_spaces(add);
                        spaces -= add;
                        continue;
                    }
                    if(direction == RIGHT){
                        if(swap) direction = LEFT;
                        if(iterator - i < spaces) add++;
                        print_spaces(add);
                    }
                }
                //printf("%i %i\n", length-current_length+iterator-1, iterator);
                putchar('\n');
                words[0] = words[iterator];
                //printf("LEFTOVER: %s\n", words[0]);
                for(int i = 1; i < 100; i++){
                    words[i] = malloc(sizeof(char*));
                }
                length = current_length;
                iterator = 0;
            }
    for(int i = 0; i < iterator+1; i++){
        printf("%s ", words[i]);
    }
    putchar('\n');
    return 0;
}