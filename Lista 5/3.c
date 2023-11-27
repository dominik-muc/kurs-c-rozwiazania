//Dominik Muc, 345952, Lista 5 zadanie 3
#include <stdio.h>
#include <unistd.h>

int pow_of_3[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};

int get_layer(int d, int n, int m);

void rle(char new_symbol, char* previous_symbol, int* counter);

int main(){
    int d, n, m;
    char carpet[11];
    scanf("%i %s %i %i", &d, carpet, &n, &m);

    if(d != 9) return 0;

    int x = 0;
    int y = 0;
    int p = pow_of_3[d];

    char previous_sign = carpet[0];
    int counter = 0;

    int skip = 1;
    for(int i = 1; i <= d; i++){
        if(carpet[i] != carpet[0]) skip = 0;
    }

    if(skip){
        printf("%i %c", pow_of_3[d] * pow_of_3[d], carpet[0]);
        return 0;
    }

    //spirala
    if(n == 0){
        sleep(1000);
        rle(carpet[get_layer(d, 0, 0)], &previous_sign, &counter);
        if(d > 0) counter += 2 * p + 2 * (p - 2) - 1;
        for(int i = 1; i < p / 2 + 1; i++){
            if(get_layer(d, i, i) == d) break;
            for(int j = i; j < p - i; j++) rle(carpet[get_layer(d, j, i)], &previous_sign, &counter);
            for(int j = i + 1; j < p - i; j++) rle(carpet[get_layer(d, p - i - 1, j)], &previous_sign, &counter);
            for(int j = p - i - 2; j >= i; j--) rle(carpet[get_layer(d, j, p - i - 1)], &previous_sign, &counter);
            for(int j = p - i - 2; j > i; j--) rle(carpet[get_layer(d, i, j)], &previous_sign, &counter);
        }
        rle(carpet[d], &previous_sign, &counter);
        counter += pow_of_3[d-1]*pow_of_3[d-1] - 1;
        printf("%i %c ", counter, previous_sign);
        return 0;
    }

    //reszta
    for(int i = 0; i < p; i++){
        for(int j = 0; j < p - 1; j++){
            rle(carpet[get_layer(d, x, y)], &previous_sign, &counter);
            x += n;
            y += m;
            x %= p;
            y %= p;
        }
        rle(carpet[get_layer(d, x, y)], &previous_sign, &counter);
        y += 1;
        y %= p;
    }
    printf("%i %c ", counter, previous_sign);
    
    return 0;
}

void rle(char current_sign, char* previous_sign, int* counter){
    if(current_sign == *previous_sign){
        (*counter)++;
        return;
    }
    printf("%i %c ", *counter, *previous_sign);
    *previous_sign = current_sign;
    *counter = 1;
}

int get_layer(int d, int n, int m){
    if(d == 0) return 0;
    if((n >= pow_of_3[d - 1]) && (n < 2 * pow_of_3[d - 1]) && (m >= pow_of_3[d - 1]) && (m < 2 * pow_of_3[d - 1])) return d;
    return get_layer(d - 1, n % pow_of_3[d - 1], m % pow_of_3[d - 1]);
}