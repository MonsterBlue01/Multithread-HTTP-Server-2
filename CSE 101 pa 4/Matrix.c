#include "List.h"
#include "Matrix.h"

Matrix newMatrix(int n) {
    Matrix a = (Matrix)malloc(2 * sizeof(MatrixObj));
    a->size = n;
    a->row = (List *)malloc(n * sizeof(List));
    for (int i = 0; i < n; i++) {
        a->row[i] = newList();
    }
    return a;
}

void freeMatrix(Matrix* pM) {
    free(*pM);
}

int size(Matrix M) {
    return M->size;
}