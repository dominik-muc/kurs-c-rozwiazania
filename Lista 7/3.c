#include <stdio.h>

int main(){

    int n, m;
    if(scanf("%d %d", &n, &m) != 2){
        fprintf(stderr, "Błąd podczas wczytywania danych!\n");
        return 0xFF;
    }

    int B[9];
    for (int i = 0; i < m; i++) {
        if (scanf("%d", &B[i]) != 1) {
            fprintf(stderr, "Błąd podczas wczytywania danych!\n");
            return 0xFF;
        }
    }

    printf("%d\n", count_encapsulations(n, m, B));
    return 0;
}