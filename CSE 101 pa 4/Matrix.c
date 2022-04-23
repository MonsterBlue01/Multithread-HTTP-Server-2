#include "List.h"
#include "Matrix.h"

Matrix newMatrix(int n) {
    Matrix a = (Matrix)malloc(2 * sizeof(MatrixObj));
    a->size = n;
    a->row = (List *)malloc(n * sizeof(List));
    for (int i = 1; i <= n; i++) {
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
    if (x == 0) {
        moveFront(M->row[i]);
        while (index(M->row[i]) >= 0) {
            if (((Entry)(M->row[i]->cursor->data))->column == j) {
                delete(M->row[i]);
                return;
            }
            moveNext(M->row[i]);
        }
        return;
    }
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
            moveFront(M->row[i]);
            while (index(M->row[i]) >= 0) {
                if ((((Entry)(M->row[i]->cursor->data))->column) > j) {
                    insertBefore(M->row[i], new);
                    return;
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

void makeZero(Matrix M) {
    M->row = (List *)malloc(M->size * sizeof(List));
    for (int i = 0; i < M->size; i++) {
        M->row[i] = newList();
    }
}

int NNZ(Matrix M) {
    int num = 0;
    for (int i = 1; i <= M->size; i++) {
        if (M->row[i]->front != NULL) {         // If there is a segmentation fault in this line, it means that there is a problem with the initialization of 
            moveFront(M->row[i]);               // the List.
            while (index(M->row[i]) >= 0) {
                num++;
                moveNext(M->row[i]);
            }
        }
    }
    return num;
}

Matrix copy(Matrix A) {
    Matrix new = newMatrix(A->size);
    for (int i = 1; i <= A->size; i++) {
        if (A->row[i]->front != NULL) {
            moveFront(A->row[i]);
            while (index(A->row[i]) >= 0) {
                changeEntry(new, i, ((Entry)A->row[i]->cursor->data)->column, ((Entry)A->row[i]->cursor->data)->num);
                moveNext(A->row[i]);
            }
        }
    }
    return new;
}

Matrix transpose(Matrix A) {
    Matrix new = newMatrix(A->size);
    for (int i = 1; i <= A->size; i++) {
        if (A->row[i]->front != NULL) {
            moveFront(A->row[i]);
            while (index(A->row[i]) >= 0) {
                changeEntry(new, ((Entry)A->row[i]->cursor->data)->column, i, ((Entry)A->row[i]->cursor->data)->num);
                moveNext(A->row[i]);
            }
        }
    }
    return new;
}

Matrix scalarMult(double x, Matrix A) {
    Matrix new = newMatrix(A->size);
    for (int i = 1; i <= A->size; i++) {
        if (A->row[i]->front != NULL) {
            moveFront(A->row[i]);
            while (index(A->row[i]) >= 0) {
                changeEntry(new, i, ((Entry)A->row[i]->cursor->data)->column, x * ((Entry)A->row[i]->cursor->data)->num);
                moveNext(A->row[i]);
            }
        }
    }
    return new;
}

Matrix sum(Matrix A, Matrix B) {
    Matrix new = newMatrix(A->size);
    for (int i = 1; i <= A->size; i++) {
        for (int j = 1; j <= A->size; j++) {
            double a = 0;
            double b = 0;
            if (A->row[i]->front != NULL) {
                moveFront(A->row[i]);
                while (index(A->row[i]) >= 0) {
                    if (((Entry)A->row[i]->cursor->data)->column == j) {
                        a = ((Entry)A->row[i]->cursor->data)->num;
                        break;
                    }
                    moveNext(A->row[i]);
                }
            }

            if (B->row[i]->front != NULL) {
                moveFront(B->row[i]);
                while (index(B->row[i]) >= 0) {
                    if (((Entry)B->row[i]->cursor->data)->column == j) {
                        b = ((Entry)B->row[i]->cursor->data)->num;
                        break;
                    }
                    moveNext(B->row[i]);
                }
            }
            changeEntry(new, i, j, a + b);
        }
    }
    return new;
}

Matrix diff(Matrix A, Matrix B) {
    Matrix new = newMatrix(A->size);
    for (int i = 1; i <= A->size; i++) {
        for (int j = 1; j <= A->size; j++) {
            double a = 0;
            double b = 0;
            if (A->row[i]->front != NULL) {
                moveFront(A->row[i]);
                while (index(A->row[i]) >= 0) {
                    if (((Entry)A->row[i]->cursor->data)->column == j) {
                        a = ((Entry)A->row[i]->cursor->data)->num;
                        break;
                    }
                    moveNext(A->row[i]);
                }
            }

            if (B->row[i]->front != NULL) {
                moveFront(B->row[i]);
                while (index(B->row[i]) >= 0) {
                    if (((Entry)B->row[i]->cursor->data)->column == j) {
                        b = ((Entry)B->row[i]->cursor->data)->num;
                        break;
                    }
                    moveNext(B->row[i]);
                }
            }
            changeEntry(new, i, j, a - b);
        }
    }
    return new;
}