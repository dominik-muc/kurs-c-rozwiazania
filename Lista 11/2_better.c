#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex{
    int value;
    int parent;
    int depth;
    int distance;
} Vertex;

int lca(Vertex* tree, int a, int b);

int main(){
    int n, q;
    if(scanf("%i %i", &n, &q) != 2) return EXIT_FAILURE;
    Vertex* tree = calloc(n+1, sizeof(Vertex));
    tree[1] = (Vertex){1, 0, 1, 1};
    int index, parent, is_blocked;
    for(int i = 0; i < n-1; i++){
        if(scanf("%i %i %i", &parent, &index, &is_blocked) != 3) return EXIT_FAILURE;
        tree[index] = (Vertex){(is_blocked ? -1000000 : 1), parent, 0, 0};
    }
    

    for(int i = 1; i < n+1; i++){
        int distance = 0;
        int depth = 0;
        Vertex iter = tree[i];
        while(iter.value != 0){
            depth++;
            distance += iter.value;
            iter = tree[iter.parent];
        }
        tree[i].depth = depth;
        tree[i].distance = distance;
        #ifdef DEBUG
        printf("Vertex: %i Depth: %i Distance: %i\n", i, tree[i].depth, tree[i].distance);
        #endif
    }

    int a, b;
    while(q--){
        if(scanf("%i %i", &a, &b) != 2) return EXIT_FAILURE;

        int distance = tree[a].distance + tree[b].distance - 2*tree[lca(tree, a, b)].distance;

        if(distance > 0) printf("%i\n", distance);
        else printf("mission impossible\n");
    }
}

int lca(Vertex* tree, int a, int b){
    while(tree[a].depth != tree[b].depth){
        if(tree[a].depth > tree[b].depth) a = tree[a].parent;
        else b = tree[b].parent;
    }
    while(a != b){
        a = tree[a].parent;
        b = tree[b].parent;
    }
    return a;
}