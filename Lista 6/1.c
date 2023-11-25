//Dominik Muc, 345952, Lista 6 zadanie 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int write_divison(long divident, long divisor);
int len(long number);

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

/*
 * Co z tego że C nie ma klas???
 * Klasa Number:
*/
typedef struct Number{
    //wyobraźmy sobie, że to jest prywatne...
    char* ascii;
    long dec;
    int iterator;
    int len;
} Number;

Number* Number_init(long n){
    Number* number = malloc(sizeof(Number));
    number->ascii = malloc(len(n));
    sprintf(number->ascii, "%li", n);
    number->dec = n;
    number->iterator = 0;
    number->len = len(n);
    return number;
}

void Number_destroy(Number* self){
    free(self->ascii);
    free(self);
}

int Number_get_next_digit(Number* self){
    if(self->iterator >= self->len) return -1;
    return (int)(self->ascii[self->iterator++]) - 48;
}

int Number_decrement(Number* self){
    if(self->iterator == 0) return -1;
    return --self->iterator;
}

int Number_get_len(Number* self){
    return self->len;
}

int Number_get_current_iterator(Number* self){
    return self->iterator;
}
/* Koniec klasy */

int len(long number){
    if(number == 0) return 1;
    return (int)log10(number) + 1;
}

void print_spaces(int n){
    for(int i = 0; i < n; i++) putchar(' ');
}

void print_lines(int n){
    for(int i = 0; i < n; i++) putchar('-');
    putchar('\n');
}

//kolejna rzecz której nie ma w c bez żadnego powodu:
#define bool __int8_t
#define true 1
#define false 0

int write_divison(long divident, long divisor){
    if(divisor == 0) return 0xFF;
    long result = divident / divisor;
    Number* number = Number_init(divident);
    
    print_spaces(Number_get_len(number) - len(result) + 1);
    printf("%li\n ", result);
    print_lines(Number_get_len(number));
    printf(" %li : %li\n", divident, divisor);

    if(divident < divisor){
        printf("-0\n -\n %li\n", divident);
        return 0;
    }
    if(divident == divisor){
        printf("-%li\n -\n 0\n", divident);
        return 0;
    }
    
    int current_divident = 0;
    int sub = 0;
    int digit = 0;
    bool first = 1;

    while((digit = Number_get_next_digit(number)) != -1){
        
        if(current_divident < divisor){
            current_divident *= 10;
            current_divident += digit;
            continue;
        }
        if(!first){
            print_spaces(Number_get_current_iterator(number) - len(current_divident));
            printf("%i\n", current_divident);
        }
        else first = false;
        
        sub = (current_divident / divisor) * divisor;
        print_spaces(Number_get_current_iterator(number) - len(sub) - 1);
        printf("-%i\n", sub);
        print_spaces(Number_get_current_iterator(number) - len(sub));
        print_lines(len(sub));
        current_divident %= divisor;
        Number_decrement(number);
    }
    print_spaces(Number_get_current_iterator(number) - len(current_divident) + 1);
    printf("%i\n", current_divident);
    sub = (current_divident / divisor) * divisor;
    print_spaces(Number_get_current_iterator(number) - len(sub));
    printf("-%i\n", sub);
    print_spaces(Number_get_current_iterator(number) - len(sub) + 1);
    print_lines(len(sub));
    current_divident %= divisor;

    //^ próbowałem to wrzucić do pętli ale nieważne jak próbowałem nie udało mi się

    print_spaces(Number_get_current_iterator(number) - len(current_divident) + 1);
    printf("%i\n", current_divident);

    Number_destroy(number);
    number = NULL;
    return 0;
}