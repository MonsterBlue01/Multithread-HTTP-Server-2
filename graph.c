#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "graph.h"

void initializeGraph(Graph **g, char* filename) {
    *g = (Graph*)malloc(sizeof(Graph));
    int x, y;
    (*g)->numEdges = 0, (*g)->numVertices = 0;
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    while (fscanf(fp, "%d%d", &x, &y) == 2) {
        printf("%d %d\n", x, y);
        (*g)->numVertices = fmax(fmax(x, y), (*g)->numVertices);
        if (x != y) {
            (*g)->numEdges++;
        }
    }
    fclose(fp);
}

void initializeAdjacencyMatrix(Graph *g, char* filename) {
    g->adjacencyMatrix = (int**)malloc(g->numVertices * sizeof(int*));
    for (int i = 0; i < g->numVertices; i++) {
        g->adjacencyMatrix[i] = (int*)malloc(g->numVertices * sizeof(int));
    }
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            g->adjacencyMatrix[i][j] = 0;
        }
    }
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    int x, y;
    while (fscanf(fp, "%d%d", &x, &y) == 2) {
        printf("%d %d\n", x, y);
        if (x != y) {
            g->adjacencyMatrix[x-1][y-1] = 1;
            if (x != y) {
                g->adjacencyMatrix[y-1][x-1] = 1;
            }
        }
    }
    fclose(fp);
}

void printMatrix(Graph *g) {
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            if (i != j) {
                printf("%d ", g->adjacencyMatrix[i][j]);
            } else {
                printf("x ");
            }
        }
        printf("\n");
    }
}

int main() {
    Graph *g = NULL;
    initializeGraph(&g, "node.txt");
    printf("Number of vertices: %d\n", g->numVertices);
    printf("Number of edges: %d\n", g->numEdges);
    initializeAdjacencyMatrix(g, "node.txt");
    printMatrix(g);
}
