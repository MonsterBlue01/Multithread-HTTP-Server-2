#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void createconnet(int** matrix, int a, int b) {
    matrix[a - 1][b - 1] = 1;
    matrix[b - 1][a - 1] = 1;
}

void deleteMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

bool readbuild(int** matrix, char* filename) {
    bool same = false;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found!\n");
        exit(1);
    }
    int num1, num2;
    while (fscanf(fp, "%d %d", &num1, &num2) != EOF) {
        if (num1 == num2 && num1 != 0) {
            same = true;
        }
        if (num1 == 0 && num2 == 0) {
            break;
        } else {
            createconnet(matrix, num1, num2);
        }
    }
    fclose(fp);
    return same;
}

void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                printf("x ");
            } else {
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("node.txt", "r");
    if (fp == NULL) {
        printf("File not found!\n");
        exit(1);
    }
    int num;
    int max = 0;
    bool same;
    while (fscanf(fp, "%d", &num) != EOF) {
        if (num > max) {
            max = num;
        }
    }
    printf("max = %d\n", max);
    fclose(fp);
    int** matrix = initMatrix(max);
    same = readbuild(matrix, "node.txt");
    if (same == true) {
        fprintf(stderr, "\x1b[35mwarn: \x1b[0m");
        fprintf(stderr, "Although paths to the same node can be accepted, it doesn't make sense. You can choose to delete the path connected to the same node (for example, 3 3, 4 4) next time\n");
    }
    printMatrix(matrix, max);
    deleteMatrix(matrix, max);
}
