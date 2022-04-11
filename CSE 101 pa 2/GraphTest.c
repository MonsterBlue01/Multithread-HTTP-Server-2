#include <stdio.h>
#include <stdlib.h>

#include "List.h"
#include "Graph.h"

int main() {
    /*Graph G = newGraph(15);
    addEdge(G, 1, 2);
    addEdge(G, 1, 7);
    addEdge(G, 1, 10);
    addEdge(G, 1, 14);
    addEdge(G, 2, 5);
    addEdge(G, 2, 10);
    addEdge(G, 2, 13);
    addEdge(G, 3, 7);
    addEdge(G, 4, 6);
    addEdge(G, 4, 7);
    addEdge(G, 4, 10);
    addEdge(G, 4, 11);
    addEdge(G, 4, 12);
    addEdge(G, 5, 8);
    addEdge(G, 5, 9);
    addEdge(G, 5, 10);
    addEdge(G, 6, 9);
    addEdge(G, 6, 11);
    addEdge(G, 6, 13);
    addEdge(G, 7, 10);
    addEdge(G, 7, 13);
    addEdge(G, 7, 14);
    addEdge(G, 8, 10);
    addEdge(G, 8, 13);
    addEdge(G, 9, 15);
    addEdge(G, 10, 13);
    addEdge(G, 10, 14);
    addEdge(G, 11, 14);
    addEdge(G, 11, 15);
    addEdge(G, 13, 14);
    BFS(G, 12);
    List L = newList();
    printf("Distance: %d\n", getDist(G, 15));
    getPath(L, G, 15);
    printf("Path: ");
    printList(stdout, L);
    printf("\n");*/

    /*Graph G = newGraph(4);
    addArc(G, 1, 2);
    printf("The size: %d\n", G->size);
    printf("The neighbor List of 1: ");
    printf("%d\n", G->neighbor[1]->front->data);
    addArc(G, 1, 3);
    printf("The size: %d\n", G->size);
    printf("The neighbor List of 1: ");
    printf("%d ", G->neighbor[1]->front->data);
    printf("%d\n", G->neighbor[1]->front->next->data);
    addArc(G, 2, 1);
    printf("The size: %d\n", G->size);
    printf("The neighbor List of 2: ");
    printf("%d\n", G->neighbor[2]->front->data);
    addArc(G, 1, 4);
    printf("The size: %d\n", G->size);
    printf("The neighbor List of 1: ");
    printf("%d ", G->neighbor[1]->front->data);
    printf("%d ", G->neighbor[1]->front->next->data);
    printf("%d\n", G->neighbor[1]->front->next->next->data);
    addArc(G, 2, 3);
    printf("The size: %d\n", G->size);
    printf("The neighbor List of 2: ");
    printf("%d ", G->neighbor[2]->front->data);
    printf("%d\n", G->neighbor[2]->front->next->data);*/

    /*Graph G = newGraph(8);
    addEdge(G, 1, 2);
    addEdge(G, 1, 3);
    addEdge(G, 2, 3);
    addEdge(G, 1, 5);
    addEdge(G, 5, 7);
    addEdge(G, 6, 7);
    addEdge(G, 4, 6);
    addEdge(G, 7, 8);
    BFS(G, 1);
    printf("The source: %d\n", G->source);
    printGraph(stdout, G);

    List L = newList();
    getPath(L, G, 4);

    printList(stdout, L);
    printf("\n");*/

    //printf("G->distance: %d\n", G->distance[1]);
    //printf("G->distance: %d\n", G->distance[2]);
    //printf("G->distance: %d\n", G->distance[3]);
    //printf("G->distance: %d\n", G->distance[4]);
    //printf("G->distance: %d\n", G->distance[5]);
    //printf("G->distance: %d\n", G->distance[6]);
    //printf("G->distance: %d\n", G->distance[7]);
    //printf("G->distance: %d\n", G->distance[8]);

    /*FILE *fp = NULL;
    fp = fopen("output.sh", "w+");
    
    int i, s, max, min, d, n=35;
    List  C = newList(); // central vertices 
    List  P = newList(); // peripheral vertices 
    List  E = newList(); // eccentricities 
    Graph G = NULL;

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
    /*printGraph(stdout, G);
    BFS(G, 1);*/
    //printf("G->distance[1]: %d\n", G->distance[1]);
    //printf("G->parent[1]: %d\n", G->parent[1]);
    //printf("G->color[1]: %d\n", G->color[1]);
    
    /*printf("Distance of 1 from 1: %d\n", G->distance[1]);
    printf("Distance of 13 from 1: %d\n", G->distance[13]);

    printf("The parent of 1: %d\n", G->parent[1]);
    printf("The parent of 8: %d\n", G->parent[8]);
    printf("The parent of 31: %d\n", G->parent[31]);

    printf("The color of 1: %d\n", G->color[1]);
    printf("The color of 8: %d\n", G->color[8]);

    fclose(fp);*/
}