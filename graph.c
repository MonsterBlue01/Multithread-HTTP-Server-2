#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int** initMatrix(int n) {
    int** matrix = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

void deleteMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    FILE *fp = fopen("node.txt", "r");
    if (fp == NULL) {
        printf("File not found!\n");
        exit(1);
    }
    int num;
    int max = 0;
    while (fscanf(fp, "%d", &num) != EOF) {
        if (num > max) {
            max = num;
        }
    }
    printf("max = %d\n", max);
    fclose(fp);
    int** matrix = initMatrix(max);
    deleteMatrix(matrix, max);
}
