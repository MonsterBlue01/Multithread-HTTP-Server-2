#include <stdio.h>
#include <stdlib.h>

#include "List.h"
#include "Graph.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Main function Error: Fewer or more than two arguments were passed in.\n");
        exit(1);
    }
    FILE *fp = NULL;
    int n1, n2;
    int num;
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

    fp = fopen(argv[1], "r");
    fclose(fp);
}