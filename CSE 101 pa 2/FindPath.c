#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "List.h"

int main(int argc, char *argv[]) {
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;

    int num;
    int n1, n2;

    fp1 = fopen("input.sh", "r");
    fp2 = fopen("output.sh", "r");
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

    printGraph(stdout, G);

    while (fscanf(fp1, "%d", &n1) != EOF) {
        fscanf(fp1, "%d", &n2);
        if ((n1 == 0) && (n2 == 0)) {
            break;
        }
        printf("\n");
        List L = newList();
        BFS(G, n1);
        if (getDist(G, n2) <= 0) {
            printf("The distance from %d to %d is infinity\n", n1, n2);
            printf("No %d-%d path exists\n", n1, n2);
        } else {
            printf("The distance from %d to %d is %d\n", n1, n2, getDist(G, n2));
            printf("A shortest 1-12 path is: ");
            getPath(L, G, n2);
            printList(stdout, L);
            printf("\n");
        }

        
        //getPath(L, G, n2);
        //printList(stdout, L);
        //printf("\n");
    }

    fclose(fp1);
    fclose(fp2);
}