#include<stdio.h>
#include<stdlib.h>

#include "List.h"
#include "Graph.h"

int main() {
    FILE *fp = NULL;
    fp = fopen("output.sh", "w+");
    
    int n = 35;
    int i = 35;

    Graph G = newGraph(n);
    for (i = 1; i < 3; i++){
        if(i % 7 != 0 ) addEdge(G, i, i+1);
        if(i <= 28) addEdge(G, i, i+7);
    }

    addEdge(G, 9, 31);
    addEdge(G, 17, 13);
    addEdge(G, 14, 33);

    /*for (int i = 1; i < 35; i++) {
        if (G->neighbor[i] != NULL) {
            fprintf(fp, "%d: ", i);
            printList(fp, G->neighbor[i]);
            fprintf(fp, "\n");
        }
    }*/

    //printf("%d\n", G->order);
    printGraph(stdout, G);
    BFS(G, 1);
    printf("G->distance[1]: %d\n", G->distance[1]);
    printf("G->parent[1]: %d\n", G->parent[1]);
    printf("G->color[1]: %d\n", G->color[1]);

    fclose(fp);
}