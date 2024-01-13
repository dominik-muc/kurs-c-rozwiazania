#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, q;
    if(scanf("%i %i", &n, &q) != 2) return EXIT_FAILURE;
    int* tree = calloc(n--, sizeof(int));
    tree[1] = 0;
    int index, parent, is_blocked;
    while(n--){
        if(scanf("%i %i %i", &parent, &index, &is_blocked) != 3) return EXIT_FAILURE;
        tree[index] = is_blocked ? -1 : parent;
    }
    int fish1, fish2;
    while(q--){
        if(scanf("%i %i", &fish1, &fish2) != 2) return EXIT_FAILURE;
        int node1 = fish1;
        int node2 = fish2;
        int found = 0;
        int distance = 0;
        int iter = 0;
        while(1){
            if(node1 == node2) break;
            iter++;
            node1 = tree[node1];
            node2 = fish2;
            while(1){
                distance++;
                if(node1 == node2){
                    found = 1;
                    break;
                }
                node2 = tree[node2];
            }
            if(found) break;
            else distance = iter;
        }

        if(found) printf("%i\n", distance);
        else printf("mission impossible\n");
    }
}