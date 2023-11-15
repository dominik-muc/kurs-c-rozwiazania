//Dominik Muc, 345952, Lista 4, zadanie 3
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Fraction{
    int numerator;
    int denominator;
};

void reduce_fraction(struct Fraction* fraction);
void add_fraction(struct Fraction* result, int numerator, int denominator);
void read_square(struct Fraction* result, int layer);

int main(){
    struct Fraction result;
    result.numerator = 0;
    result.denominator = 1;
    read_square(&result, 0);
    printf("%i/%i", result.numerator, result.denominator);
    return 0;
}


void reduce_fraction(struct Fraction* fraction){
    int i = 2;
    while(i <= fraction->numerator){
        while((fraction->numerator % i == 0) && (fraction->denominator % i == 0)){
            fraction->numerator /= i;
            fraction->denominator /= i;
        }
        i++;
    }
}

void add_fraction(struct Fraction* result, int numerator, int denominator){
    result->numerator *= denominator;
    result->numerator += numerator * result->denominator;
    result->denominator *= denominator;
    reduce_fraction(result);
}

void read_square(struct Fraction* result, int layer){
    int c;
    scanf("%i", &c);
    if(c == 1) add_fraction(result, 1, pow(4, layer));
    if(c == 2){
        for(int i = 0; i < 4; i++){
            read_square(result, layer + 1);
        }
    }
}

