//Dominik Muc, 345952, Lista 2, zadanie 1
#include <stdio.h>

static int len(char string[]){
    int i = 0;
    while(string[i] != '\0') i++;
    return i;
}

int main(int argc, char* argv[]){
    if(argc == 1){
        printf("Brak argumentów!\n");
        return -1;
    }
    if(argc > 2 || len(argv[1])> 1){
        printf("Zle argumenty!\n");
        return -1;
    }
    char last_char = getchar();
    //int al = 1;
    while(last_char == *argv[1]){
        last_char = getchar();
        if(last_char == '\n'){
            //if(al == 1) al = 0;
            //else{
                printf("Zle wejscie!\n");
                return -1;
                
            //}
        }
    }//while(last_char == *argv[1]);
    //if(al == 1)
    char c;// = getchar();
    //char ex = argv[1];
    int count = 1;
    //scanf("%u");
    while((c = getchar()) != '\n'){
        //if(c == '\n') continue;
        //printf("%c", c);
        if(c == *argv[1]) continue;
        if(last_char == c){
            count++;
        }
        else{
            //if(c != '\n') 
                printf("%s%i%s%c", argv[1], count, argv[1], last_char);
            count = 1;
        }
        last_char = c;
        //printf("%c", c);
    }//while ((c = getchar()) != '\n');
    //if(c != '\n') 
        printf("%s%i%s%c", argv[1], count, argv[1], last_char);

    putchar('\n');
    return 0;
}
