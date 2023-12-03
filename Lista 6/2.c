//Dominik Muc, 345952, Lista 6 zadanie 2
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define BOLD  "\x1b[1m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define RESET "\x1b[0m"
#define DELIMITERS " \t\r\n\v\f"

int** initialize_array(int n, int m, int** sums);
void free_array(int n, int** array);
int rectangle_sum(int** sums, int params[4]);
void print_spaces(int n);
int len(int number);
int parse_input(int params[4], int n, int m);
void failed_to_create_object_exception();

int main(int argc, char** argv){
    if(argc != 3){
        fprintf(stderr, BOLD RED "Niepoprawna ilość argumentów wywołania!\n" RESET);
        return 0xFF;
    }
    long* args = (long*)malloc(sizeof(int) * 2);

    if(!args) failed_to_create_object_exception();

    for(int i = 0; i <= 1; i++){
        char* dump = NULL;
        args[i] = strtol(argv[i + 1], &dump, 10);
        if(dump[0] || args[i] <= 0 || args[i] > 1000){
            fprintf(stderr, BOLD RED "Niepoprawne argumenty! Program przyjmuje dwie liczby całkowite z zakresu <1, 1000>.\n" RESET);
            return 0xFF;
        }
    }

    int n = (int)args[0];
    int m = (int)args[1];
    free(args);
    srand(time(NULL));

    int** sums = (int**)malloc(sizeof(int*) * n);
    if(!sums) failed_to_create_object_exception();

    int** array = initialize_array(n, m, sums);

    int params[4] = {0};
    do{
        system("clear||cls");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i >= params[0] && i <= params[2] && j >= params[1] && j <= params[3]) printf(BOLD GREEN);
                print_spaces(3 - len(array[i][j]));
                printf("%i " RESET, array[i][j]);
            }
            putchar('\n');
        }
        printf(BOLD GREEN "Suma: %i\n" RESET, rectangle_sum(sums, params));    
    }while(parse_input(params, n, m));

    free_array(n, array);
    free_array(n, sums);
    return 0;
}

int** initialize_array(int n, int m, int** sums){
    int** array = (int**)malloc(sizeof(int*) * n);
    if(!array) failed_to_create_object_exception();
    int a = (rand() % 996) + 1;
    int b = (rand() % 996) + 1;

    array[0] = (int*)malloc(sizeof(int) * m);
    sums[0] = (int*)malloc(sizeof(int) * m);
    array[0][0] = b % 997;
    sums[0][0] = array[0][0];
    for(int j = 1; j < m; j++){           
        array[0][j] = (a * j + b) % 997;
        sums[0][j] = sums[0][j - 1] + array[0][j];
    }
    for(int i = 1; i < n; i++){
        array[i] = (int*)malloc(sizeof(int) * m);
        if(!array[i]) failed_to_create_object_exception();
        sums[i] = (int*)malloc(sizeof(int) * m);
        if(!sums[i]) failed_to_create_object_exception();

        array[i][0] = (a * (i * m) + b) % 997;
        sums[i][0] = sums[i - 1][0] + array[i][0];
        for(int j = 1; j < m; j++){           
            array[i][j] = (a * (j + i * m) + b) % 997;
            sums[i][j] = sums[i - 1][j] + sums[i][j - 1] + array[i][j] - sums[i - 1][j - 1];
        }
    }
    return array;
}

int rectangle_sum(int** sums, int params[4]){
    int x0 = params[0];
    int y0 = params[1];
    int x1 = params[2];
    int y1 = params[3];

    int sum = sums[x1][y1];
    if(x0 > 0) sum -= sums[x0 - 1][y1];
    if(y0 > 0) sum -= sums[x1][y0 - 1];
    if(x0 > 0 && y0 > 0) sum += sums[x0 - 1][y0 - 1];

    return sum;
}

void free_array(int n, int** array){
    if(array == NULL) return;

    for(int i = 0; i < n; i++){
        free(array[i]);
        array[i] = NULL;
    }

    free(array);
    array = NULL;
}

int len(int number){
    if(number == 0) return 1;
    return (int)log10(number) + 1;
}

void print_spaces(int n){
    for(int i = 0; i < n; i++) putchar(' ');
}

int parse_input(int params[4], int n, int m){
    while(1){
        printf("Podaj x_0 y_0 x_1 y_1: ");
        char input[256];
        fgets(input, sizeof input, stdin);
        char* parameter = strtok(input, DELIMITERS);

        int parsed[4] = {0};
        int is_valid = 1;

        for(int i = 0; i < 4; i++){
            if(!parameter){
                is_valid = 0;
                break;
            }
            char* dump = NULL;
            parsed[i] = strtol(parameter, &dump, 10);
            if(dump[0]){
                is_valid = 0;
                break;
            }
            parameter = strtok(NULL, DELIMITERS);
        }
        if(parsed[0] == -1 && is_valid) return 0;

        if(parsed[2] < parsed[0] || parsed[0] < 0 || parsed[2] >= n ||
           parsed[3] < parsed[1] || parsed[1] < 0 || parsed[3] >= m)    is_valid = 0;

        if(is_valid){ 
            for(int i = 0; i < 4; i++){
                params[i] = parsed[i];
            }
            return 1;
        }
        fprintf(stderr, BOLD RED "Niepoprawne wejście!\n" RESET);
    }
}

void failed_to_create_object_exception(){
    fprintf(stderr, BOLD RED "Błąd alokacji pamięci! Program zakończył działanie.\n" RESET);
    exit(0xFF);
}