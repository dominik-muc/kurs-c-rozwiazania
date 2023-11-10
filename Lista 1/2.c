//Dominik Muc, 345952, Lista 1, zadanie 2


#include <stdio.h>


unsigned short count_seven(unsigned long n){
    unsigned short count = 0;

    while(n > 10){
        if(n % 10 == 7) count++;
        n /= 10;
    }
    if(n % 10 == 7) count++;

    return count;
}

int main(void){
    unsigned x = 0;
    unsigned short max = 0;
    unsigned short a = 0;
    unsigned b = 0;

    scanf("%u", &x);

    for(unsigned short i = 1; i <= 10; i++){
        for(unsigned short j = 0; j <= 1000; j++){
            a = count_seven(x*i+j);
            if(a > max){
                max = a;
                b = x*i+j;
            }
        }
    }

    printf("%hu, %u \n", max, b);

    return 0;
}
