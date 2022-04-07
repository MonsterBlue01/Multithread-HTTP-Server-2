#include <stdio.h>

#include "List.h"
#include "Graph.h"

int main() {
    Graph new = newGraph(3);
    addEdge(new, 1, 2);
    printf("%d\n", new->neighbor[1]->front->data);
}