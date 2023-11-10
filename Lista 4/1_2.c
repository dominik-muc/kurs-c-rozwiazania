//Dominik Muc, 345952, Lista 4, zadanie 1 pkt 2
#include <stdio.h>
#include <stdlib.h>

void scan_array(int* array, int size){
    for(int i = 0; i < size; i++){
        scanf("%i", &(array[i]));
    }
    return;
}

void print_array(int* array, int size){
    for(int i = 0; i < size; i++){
        printf("%i ", array[i]);
    }
    putchar('\n');
    return;
}

void insert_last(int* array, int size){
    int last_element = array[size - 1];
    int i = size - 2;

    print_array(array, size);

    while(i >= 0 && array[i] > last_element){
        array[i + 1] = array[i];
        i--;
    }
    array[i + 1] = last_element;
    print_array(array, size);
    putchar('\n');
    return;
}

void sort(int* array, int size){
    if(size == 1) return;
    sort(array, size - 1);  
    insert_last(array, size);
    return;
}

int main(){
    int size;
    int* array;

    printf("Podaj wielkość tablicy: ");
    scanf("%i", &size);
    printf("Wprowadź elementy tablicy, po spacji: ");

    array = malloc(sizeof(int)*size);
    scan_array(array, size);

    sort(array, size);
    printf("Posortowana tablica: ");
    print_array(array, size);
    return 0;
}