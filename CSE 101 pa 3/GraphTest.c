#include <stdio.h>

#include "Graph.h"
#include "List.h"

int main() {
    Graph G = newGraph(20);
    printf("The graph: %d\n", G->order);
}
