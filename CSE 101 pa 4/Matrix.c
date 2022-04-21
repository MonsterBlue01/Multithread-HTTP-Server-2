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

void changeEntry(Matrix M, int i, int j, double x) {
    Entry new = (Entry)malloc(sizeof(EntryObj));
    new->column = j;
    new->num = x;
    Node tmp = M->row[i]->front;
    if (tmp == NULL) {
        append(M->row[i], new);
    } else {
        if (j < ((Entry)(M->row[i]->front->data))->column) {
            prepend(M->row[i], new);
        } else {
            while (tmp != NULL) {
                printf("%d\n", ((Entry)(M->row[1]->front->next->data))->column);
                tmp = tmp->next;
            }
        }
    }
}