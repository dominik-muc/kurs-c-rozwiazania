#include <stdio.h>
#include <stdlib.h>

#define RANGE_MIN 32
#define RANGE_MAX 127

typedef struct Node{
    int value;
    struct Node* next;
} *List, Node;

void push_back(List* list, int value);
int find(List* char_map, int index, char s);
char first(List* char_map, int index, char a, char b);
int count(List* char_map, char f, int start, int end);

int main(){
    int n, q;
    List* char_map = malloc(RANGE_MAX * sizeof(List));
    for (int i = 0; i < RANGE_MAX; i++) {
        char_map[i] = NULL;
    }
    if(scanf("%i %i", &n, &q) != 2) return EXIT_FAILURE;
    char* buffer = malloc(sizeof(char)*(n+1));
    getchar();
    if(!fgets(buffer, n+1, stdin)) return EXIT_FAILURE;
    for(int i = 0; i < n+1; i++){
        push_back(&(char_map[(int)buffer[i]]), i);
    }
    int type, i1, i2;
    char p1, p2;
    while(q--){
        if(scanf("%i", &type) != 1) return EXIT_FAILURE;
        switch(type){
            case 1:
            if(scanf("%i %c", &i1, &p1) != 2) return EXIT_FAILURE;
            int r = find(char_map, i1, p1);
            if(r > 0) printf("%i\n", r);
            else printf("BRAK\n");
            break;
            case 2:
            if(scanf("%i %c %c", &i1, &p1, &p2) != 3) return EXIT_FAILURE;
            char res = first(char_map, i1, p1, p2);
            if(res > 0) printf("%c\n", res);
            else printf("BRAK\n");
            break;
            case 3:
            if(scanf(" %c %i %i", &p1, &i1, &i2) != 3) return EXIT_FAILURE;
            printf("%i\n", count(char_map, p1, i1, i2));
            break;
            default:
            return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < RANGE_MAX; i++) {
        free(char_map[i]);
    }
    free(char_map);
    free(buffer);
    return EXIT_SUCCESS;
}

void push_back(List* list, int value){
    List new_element = malloc(sizeof(Node));
    new_element->value = value;
    new_element->next = NULL;
    if(*list == NULL){
        *list = new_element;
        return;
    }
    List iterator = *list;
    while(iterator->next != NULL){
        iterator = iterator->next;
    }
    iterator->next = new_element;
}

int find(List* char_map, int index, char s){
    List iterator = char_map[(int)s];
    while(iterator != NULL){
        index--;
        if(index == 0) return iterator->value;
        iterator = iterator->next;
    }
    return -1;
}
char first(List* char_map, int index, char a, char b){
    List it_a = char_map[(int)a];
    List it_b = char_map[(int)b];
    int res_a = -1;
    int res_b = -1;
    while(it_a != NULL){
        if(it_a->value >= index){
            res_a = it_a->value;
            break;
        }
        it_a = it_a->next;
    }
    while(it_b != NULL){
        if(it_b->value >= index){
            res_b = it_b->value;
            break;
        }
        it_b = it_b->next;
    }
    if(res_a == -1 && res_b > 0) return b;
    if(res_b == -1 && res_a > 0) return a;
    if(res_a > res_b) return b;
    if(res_a < res_b) return a;
    return -1;

}
int count(List* char_map, char f, int start, int end){
    List it = char_map[(int)f];
    int res = 0;
    while(it != NULL){
        if(it->value >= start && it->value <= end) res++;
        it = it->next;
    }
    return res;
}