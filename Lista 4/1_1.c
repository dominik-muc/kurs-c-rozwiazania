//Dominik Muc, 345952, Lista 4, zadanie 1 pkt 1
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

void swap(int* array, int size, int first_index, int second_index){
    int value_to_swap = array[first_index];

    print_array(array, size);
    
    array[first_index] = array[second_index];
    array[second_index] = value_to_swap;

    print_array(array, size);
    putchar('\n');
    return;
}

int min_index(int* array, int size){
    int index = 0;
    int min = array[0];
    for(int i = 1; i < size; i++){
        if(array[i] < min){
            min = array[i];
            index = i;
        }
    }
    return index;
}

void sort(int* array, int size){
    if(size == 1) return;
    swap(array, size, 0, min_index(array, size));
    sort(array + 1, size - 1);
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