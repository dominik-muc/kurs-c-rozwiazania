//Dominik Muc, 345952, Lista 6 zadanie 3
//Przy tworzeniu programu skorzystałem z pomocy Chat-GPT
#include <stdio.h>
#include <stdlib.h>

void update(int* bit, int index, int delta, int size) {
    index++;
    while (index <= size) {
        bit[index] += delta;
        index += index & -index;
    }
}

int sum(int* bit, int index) {
    int sum = 0;
    index++;
    while (index > 0) {
        sum += bit[index];
        index -= index & -index;
    }
    return sum;
}

int main() {
    int m, n;
    scanf("%i %i", &m, &n);

    int* array = (int*)malloc(sizeof(int) * m);
    int* bit = (int*)malloc(sizeof(int) * (m + 1));

    for (int i = 0; i < m; i++) {
        scanf("%i", &array[i]);
        update(bit, i, array[i], m);
    }

    for (int i = 0; i < n; i++) {
        char command;
        int p, q;
        scanf(" %c %i %i", &command, &p, &q);
        if (command == 'Q'){
            printf("%i\n", sum(bit, q) - sum(bit, p - 1));
        }
        else{
            update(bit, p, q - array[p], m);
            array[p] = q;
        }
    }

    free(array);
    free(bit);
    return 0;
}
