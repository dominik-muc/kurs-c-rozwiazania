//Dominik Muc, 345952, Lista 1, zadanie 3

#include <stdio.h>
#include <math.h>

int main(void){
    unsigned long long x, y;
    scanf("%llu %llu", &x, &y);
    if(x == y){
        printf("%i", 0);
        return 0;
    }
    unsigned long long n = y - x;
    //long double sqc = ceill(sqrt(n));
    printf("%llu", (unsigned long long)(roundl(sqrt(n))+ceill(sqrt(n))-1));
    //printf("%llu %Lf %Lf %Lf ", n, sqrtl(n), sqc, sqrtl(n)*sqrtl(n));
    //if(n > sqc*sqc - sqc) printf("%llu", (unsigned long long)(2*sqc-1));
    //else printf("%llu", (unsigned long long)(2*sqc-2));
    //long double sq = floorl(sqrtl(y-x));

    //printf("%i", (int)(roundl(sq)+(int)sq));
    return 0;
}

