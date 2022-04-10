#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "List.h"

int main(int argc, char *argv[]) {
    if(argc != 3) {
        fprintf(stderr, "main function Error: Fewer or more than two arguments were passed in.\n");
        exit(1);
    }

    FILE *fp1 = NULL;
    FILE *fp2 = NULL;

    int num;
    int n1, n2;

    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "r");
    if ((fp1 == NULL) || (fp2 == NULL)) {
        fprintf(stderr, "main function Error: Can't find corresponding files.\n");
        exit(1);
    }

    fscanf(fp1, "%d", &num);
    Graph G = newGraph(num);

    while (fscanf(fp1, "%d", &n1) != EOF) {
        fscanf(fp1, "%d", &n2);
        if ((n1 == 0) && (n2 == 0)) {
            break;
        }
        addEdge(G, n1, n2);
    }

    printGraph(fp2, G);

    while (fscanf(fp1, "%d", &n1) != EOF) {
        fscanf(fp1, "%d", &n2);
        if ((n1 == 0) && (n2 == 0)) {
            break;
        }
        fprintf(fp2, "\n");
        List L = newList();
        BFS(G, n1);
        if (getDist(G, n2) <= 0) {
            fprintf(fp2, "The distance from %d to %d is infinity\n", n1, n2);
            fprintf(fp2, "No %d-%d path exists\n", n1, n2);
        } else {
            fprintf(fp2, "The distance from %d to %d is %d\n", n1, n2, getDist(G, n2));
            fprintf(fp2, "A shortest 1-12 path is: ");
            getPath(L, G, n2);
            printList(fp2, L);
            printf("\n");
        }
    }

    fclose(fp1);
    fclose(fp2);
}