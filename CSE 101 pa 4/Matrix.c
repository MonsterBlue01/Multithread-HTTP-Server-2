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
        if (j < ((Entry)(M->row[i]->front->data))->column) {                        // Still need to deal with the case when x = 0.
            prepend(M->row[i], new);
        } else {
            moveFront(M->row[i]);
            while (index(M->row[i]) >= 0) {
                if ((((Entry)(M->row[i]->cursor->data))->column) > j) {
                    insertBefore(M->row[i], new);
                } else if ((((Entry)(M->row[i]->cursor->data))->column) == j){
                    ((Entry)(M->row[i]->cursor->data))->num = x;
                    return;
                }
                moveNext(M->row[i]);
            }
            append(M->row[i], new);
        }
    }
}