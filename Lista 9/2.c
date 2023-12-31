#include <stdio.h>
#include <stdlib.h>

#define DEBUG

typedef struct Element{
    int value;
    struct Element* next;
} Element, *Node;

typedef struct Magazine{
    int size;
    int sum;
    Node values;
} Magazine;

void push_back(Node* list, int value) {
    Node new_element = (Node)malloc(sizeof(Element));
    new_element->value = value;
    new_element->next = NULL;

    if (*list == NULL) {
        *list = new_element;
        return;
    }

    Node current = *list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_element;
}

int main(){
    int M, Q;
    if(scanf("%i %i", &M, &Q) != 2) return 0xFF;
    Magazine* magazines = (Magazine*)malloc(sizeof(Magazine)*(M+1));
    for(int i = 1; i <= M; i++){
        if(scanf("%i", &(magazines[i].size)) != 1) return 0xFF;
        magazines[i].values = NULL;
        magazines[i].sum = 0;
        int value;
        for(int j = 0; j < magazines[i].size; j++){
            if(scanf("%i", &value) != 1) return 0xFF;
            push_back(&(magazines[i].values), value);
            magazines[i].sum += value;
        }
    }

    while(Q--){
        #ifdef DEBUG
        printf("-------\n");
        for(int i = 1; i <= M; i++){
            printf("Id: %i Size: %i Sum: %i\n", i, magazines[i].size, magazines[i].sum);
            Node current = magazines[i].values;
            while(current != NULL){
                printf("%i ", current->value);
                current = current->next;
            }
            putchar('\n');
        }
        #endif

        char query_type;
        if(scanf(" %c", &query_type) != 1) return 0xFF;

        #ifdef DEBUG
        printf("Query: %c \n", query_type);
        #endif

        if(query_type == 'K'){
            for(int i = 1; i <= M; i++){
                printf("%i ", magazines[i].sum);
            }
            putchar('\n');
        }
        if(query_type == 'R'){
            int from, to, start, end;
            if(scanf("%i %i %i %i", &from, &to, &start, &end) != 4) return 0xFF;
            #ifdef DEBUG
            printf("%i %i %i %i\n", from, to, start, end);
            #endif
            if(magazines[from].size == 0) continue;
            if(start < 0) start += magazines[from].size + 1;
            if(end < 0) end += magazines[from].size + 1;

            Node tail = magazines[to].values;
            if(tail != NULL){
                while(tail->next != NULL) tail = tail->next;
            }
            int iterator = 1;
            Node current = magazines[from].values;
            while(iterator++ < start) current = current->next;

            if(tail == NULL) tail = current;
            else tail->next = current;
            int delta = current->value;
            int moved = 1;
            while(iterator++ < end){
                current = current->next;
                delta += current->value;
                moved++;
            }
            Node temp = current->next;
            current->next = NULL;

            current = magazines[from].values;
            iterator = 1;
            while(iterator++ < start - 1) current = current->next;

            current->next = temp;

            magazines[from].size -= moved;
            magazines[from].sum -= delta;
            magazines[to].size += moved;
            magazines[to].sum += delta;

        }
    }
}