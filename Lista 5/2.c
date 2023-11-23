//Dominik Muc, 345952, Lista 5 zadanie 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Fraction{
    long numerator;
    long denominator;
} Fraction;

Fraction get_fraction(int arg_id, char** argv){
    Fraction result;
    char* dump = NULL;
    char* dump_2 = NULL;
    result.numerator = strtol(argv[arg_id], &dump, 0);
    result.denominator = strtol(argv[arg_id + 1], &dump_2, 0);
    if(dump[0] || dump_2[0] || result.numerator <= 0 || result.numerator > result.denominator){       
        fprintf(stderr, "Niepoprawne argumenty wywołania!\n");
        exit(0xFF);
    }
    return result;
}

long gcd(int a, int b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void reduce_fraction(Fraction* fraction){
    long fraction_gcd = gcd(fraction->numerator, fraction->denominator);
    fraction->numerator /= fraction_gcd;
    fraction->denominator /= fraction_gcd;
}

void egyptianize(Fraction fraction, int odd){  
    long a = (long)ceill((long double)fraction.denominator/(long double)fraction.numerator);
    if(odd) a = a % 2 ? a : a + 1;
    printf("1/%li", a);
    fraction.numerator = a * fraction.numerator - fraction.denominator;
    fraction.denominator = a * fraction.denominator;
    reduce_fraction(&fraction);
    if(fraction.numerator == 0) return;
    printf(" + ");
    egyptianize(fraction, odd);
}

int main(int argc, char** argv){
    Fraction fraction;
    int odd = 0;
    switch(argc){
        case 3:
            fraction = get_fraction(1, argv);
            break;
        case 4:
            if(strlen(argv[1]) == 1 && argv[1][0] == 'N'){
                fraction = get_fraction(2, argv);
                odd = 1;
                break;
            }
            if(strlen(argv[3]) == 1 && argv[3][0] == 'N'){
                fraction = get_fraction(1, argv);
                odd = 1;
                break;
            }
            fprintf(stderr, "Niepoprawne argumenty wywołania!\n");
            return 0xFF;
        default:
            fprintf(stderr, "Niepoprawna ilość argumentów!\n");
            return 0xFF;
    }
    reduce_fraction(&fraction);
    if(fraction.denominator % 2 == 0 && odd){
        fprintf(stderr, "Po uproszczeniu ułamka mianownik jest parzysty - program nie zakończy działania.\n");
        return 0xFF;
    }
    egyptianize(fraction, odd);
    putchar('\n');
    return 0;
}