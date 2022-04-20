#include "List.h"
#include "Matrix.h"

typedef struct MatrixObj* Matrix;

Matrix newMatrix(int n) {
    Matrix a = (Matrix)malloc(2 * sizeof(MatrixObj));
    a->size = n;
    a->Entries = (List *)malloc(n * sizeof(List));
    return a;
}

void freeMatrix(Matrix* pM) {
    free(*pM);
}

int size(Matrix M) {
    return M->size;
}