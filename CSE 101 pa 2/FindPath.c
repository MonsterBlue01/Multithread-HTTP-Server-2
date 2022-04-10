#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "List.h"

int main() {
    FILE *fp = NULL;            
    int num;
    int n1, n2;

    fp = fopen("input.sh", "r");
    if (fp == NULL) {
        fprintf(stderr, "main function Error: Can't find corresponding files.\n");
        exit(1);
    }

    fscanf(fp, "%d", &num);
    Graph G = newGraph(num);

    while (fscanf(fp, "%d", &n1) != EOF) {
        fscanf(fp, "%d", &n2);
        if ((n1 == 0) && (n2 == 0)) {
            break;
        }
        addEdge(G, n1, n2);
    }

    printGraph(stdout, G);

    while (fscanf(fp, "%d", &n1) != EOF) {
        fscanf(fp, "%d", &n2);
        if ((n1 == 0) && (n2 == 0)) {
            break;
        }
        List L = newList();
        BFS(G, n1);
        getPath(L, G, n2);
        printList(stdout, L);
        printf("\n");
    }

    fclose(fp);
}