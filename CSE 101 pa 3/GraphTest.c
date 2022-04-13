#include <stdio.h>

#include "Graph.h"
#include "List.h"

int main() {
    Graph G = newGraph(15);
    List L = newList();
    printf("\n");
    addArc(G, 1, 2);
    addArc(G, 1, 3);
    addArc(G, 2, 4);
    addArc(G, 2, 5);
    addArc(G, 3, 6);
    addArc(G, 3, 7);
    addArc(G, 4, 8);
    addArc(G, 4, 9);
    addArc(G, 5, 10);
    addArc(G, 5, 11);
    addArc(G, 6, 12);
    addArc(G, 6, 13);
    addArc(G, 7, 14);
    addArc(G, 7, 15);
    printGraph(stdout, G);
    visit(G, 1);
    //printf("The size: %d\n", G->size);
    //printf("The graph: %d\n", G->order);
    return 0;
}
