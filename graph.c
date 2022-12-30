#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int main() {
    printf("Hello World!\n");
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
    int matrix[max][max];
}
