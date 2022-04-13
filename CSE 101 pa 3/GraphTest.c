#include <stdio.h>

#include "Graph.h"
#include "List.h"

int main() {
    Graph G = newGraph(10);
    List L = newList();
    printf("\n");
    addArc(G, 1, 2);
    addArc(G, 2, 1);
    addArc(G, 1, 1);
    printGraph(stdout, G);
    //printf("The size: %d\n", G->size);
    //printf("The graph: %d\n", G->order);
    return 0;
}
