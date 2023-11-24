//Dominik Muc, 345952, Lista 6 zadanie 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int write_divison(long divident, long divisor);

int main(int argc, char** argv){
    if(argc != 3){
        fprintf(stderr, "Niepoprawna liczba argumentów!\n");
        return 0xFF;
    }
    char* dump = NULL;
    char* dump_2 = NULL;
    long divident = strtol(argv[1], &dump, 0);
    long divisor = strtol(argv[2], &dump_2, 0);
    if(dump[0] || dump_2[0] || divident <= 0 || divisor <= 0){
        fprintf(stderr, "Niepoprawne argumenty!\n");
        return 0xFF;
    }

    if(write_divison(divident, divisor)){
        fprintf(stderr, "Wystąpił błąd dzielenia. Program zakończył działanie.\n");
        return 0xFF;
    }
    return 0;
}

int len(long number){
    if(number == 0) return 1;
    return (int)log10(number) + 1;
}

void print_spaces(int n){
    for(int i = 0; i < n; i++) putchar(' ');
}

void print_lines(int n){
    for(int i = 0; i < n; i++) putchar('-');
}

int write_divison(long divident, long divisor){
    if(divisor == 0) return 0xFF;
    long result = divident / divisor;

    char* number = malloc(len(divident));
    sprintf(number, "%li", divident);
    
    print_spaces(len(divident) - len(result) + 1);
    printf("%li\n ", result);
    print_lines(len(divident));
    putchar('\n');
    printf(" %li : %li\n", divident, divisor);

    if(divident < divisor){
        printf("-0\n -\n %li\n", divident);
        return 0;
    }

    int current_divident = 0;
    int iterator = 0;
    int spaces = 0;
    int first = 1;
    int remainder = 0;
    int skipped = 0;
    while(iterator <= len(divident)-1 ){
        while(current_divident < divisor && iterator <= len(divident)-skipped){
            current_divident *= 10;
            current_divident += (int)number[iterator] - 48;
            iterator++;
            spaces++;
        }
        if(!first){
            print_spaces(spaces);
            printf("%i\n", current_divident);
        }

        remainder = (current_divident / divisor ) * divisor;

        print_spaces(spaces-1);
        printf("-%i\n", remainder);
        print_spaces(spaces);
        print_lines(len(remainder));

        current_divident %= divisor;
        if(current_divident == 0) current_divident = -1;
        if(first){
            spaces = 1;
            first = 0;
        }
        getchar();
    }
    print_spaces(spaces+len(remainder)-len(current_divident));
    printf("%i\n", current_divident);
    return 0;
}