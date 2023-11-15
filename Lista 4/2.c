//Dominik Muc, 345952, Lista 4, zadanie 2
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

//Działania bitowe
enum Operations{
    AND,
    OR,
    XOR,
    SHIFT_LEFT,
    SHIFT_RIGHT
};

//Zwraca losową liczbę z zakresu 0, ULL_MAX
unsigned long long rand_ull();

//Ustawia wszystkie bity starsze niż n w value na 0
void trim_after_n_bits(int n, unsigned long long* value);

//Drukuje do stdout n najmłodszych bitów liczby m
void print_n_bits(int n, unsigned long long m);

//Wczytuje z stdin liczbę w postaci binarnej
int scan_bits(unsigned long long* destination);

//Zwraca 0 przy poprawnym wykonaniu, liczba dodatnia oznacza przerwanie
int program_loop(int n);

#define MAX_BYTES sizeof(unsigned long long) * __CHAR_BIT__

int main(int argc, char* argv[]){
    int n = 8;

    if(argc > 2){
        fprintf(stderr, "Zbyt dużo argumentów! Program jako argument przyjmuje jedną wartość <1, %lu>\n", MAX_BYTES);
        return 255;
    }
    if(argc == 2){
        unsigned long long arg;
        arg = atoi(argv[1]);
        if(arg > MAX_BYTES || arg == 0){
            fprintf(stderr, "Niepoprawny argument! Program jako argument przyjmuje jedną wartość <1, %lu>\n", MAX_BYTES);
            return 255;
        }
        n = arg;
    }

    srand(time(NULL));
    while(program_loop(n) == 0);
    return 0;
}

unsigned long long rand_ull(){
    unsigned long long random = rand();
    for(unsigned long i = 0; i < sizeof(unsigned long long)/sizeof(int); i++){
        random <<= sizeof(int) * __CHAR_BIT__;
        random += rand();
    }
    return random;
}

void trim_after_n_bits(int n, unsigned long long* value){
    if(n == MAX_BYTES) return;
    *value &= ((1ULL << n) - 1);
}

void print_n_bits(int n, unsigned long long m){
    int size = n;
    int* output = malloc(sizeof(int)*(size+1));
    while(n > 0){
        output[n] = (int)(m % 2);
        m /= 2;
        n--;
    }
    for(int i = 1; i <= size; i++){
        printf("%i", output[i]);
    }
    free(output);
}

int scan_bits(unsigned long long* destination){
    int input[MAX_BYTES] = {0};
    int i = 0;
    int j = 0;
    int read = 0;
    char c;
    *destination = 0;

    while((c = getchar()) && i < (int)MAX_BYTES){
        int end = 0;
        switch(c){
            case '\n':
                end = 1;
                break;
            case '\t':
            case ' ':
                if (!read) continue;
                ungetc(c, stdin);
                return 0;
            case '0':
                read = 1;
                i++;
                break;
            case '1':
                read = 1;
                input[i] = 1;
                i++;
                break;
            default:
                ungetc(c, stdin);
                return 1;
        }
        if(end == 1) break;
    }
    
    while(i-- > 0){
        *destination += (unsigned long long)(input[i]) * (unsigned long long)pow(2, j);
        j++;
    }
    return 0;
}

int program_loop(int n){
    unsigned long long a, b, result, expected_result;
    enum Operations operation;
    char* operation_dialog;
   
    a = rand_ull();
    b = rand_ull();
    operation = rand() % 5;

    trim_after_n_bits(n, &a);
    trim_after_n_bits(n, &b);

    printf("Twoje działanie:\n    ");
    print_n_bits(n, a);
    printf(" %llu\n    ", a);
    if(operation < 3){
        print_n_bits(n, b);
        printf(" %llu\n", b);
    }
    else{
        printf("%llu \n", b % n);
    }

    switch(operation){     
        case AND:     
            operation_dialog = "&:  ";
            expected_result = a & b;
            break;
        case OR:
            operation_dialog = "|:  ";
            expected_result = a | b;
            break;
        case XOR:
            operation_dialog = "^:  ";
            expected_result = a ^ b;
            break;
        case SHIFT_LEFT:
            operation_dialog = "<<: ";
            expected_result = a << (b % n);
            break;
        case SHIFT_RIGHT:
            operation_dialog = ">>: ";
            expected_result = a >> (b % n);
            break;
    }

    trim_after_n_bits(n, &expected_result);

    while(1){
        printf(operation_dialog);
        if(scan_bits(&result) != 0){
            fprintf(stderr, "Złe wejście!\n");
            char c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
        else if(result != expected_result){
            printf("Niepoprawna odpowiedź!\n");
        }
        else{
            printf("Dobra odpowiedź!\n");
            return 0;
        }
    }
    return 0;
}