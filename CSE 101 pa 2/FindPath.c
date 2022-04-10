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
        printf("\n");
        List L = newList();
        BFS(G, n1);
        if (getDist(G, n2) <= 0) {
            printf("The distance from %d to %d is infinity\n", n1, n2);
        } else {
            printf("The distance from %d to %d is %d\n", n1, n2, getDist(G, n2));
        }

        printf("A shortest 1-12 path is: 1 7 12\n")
        //getPath(L, G, n2);
        //printList(stdout, L);
        //printf("\n");
    }

    fclose(fp);
}