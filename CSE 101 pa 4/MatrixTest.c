// -----------------------------
// Name: Dongjing Wang
// CruzID: 1823945
// Assignment: pa4
// -----------------------------

#include "List.h"
#include "Matrix.h"

int main() {
    Matrix A;
    Matrix B;
    Matrix C = newMatrix(15);
    if (!equals(A, B))
        printf("1\n");
    if (equals(A, C))
        printf("2\n");
    Matrix D = newMatrix(10);
    changeEntry(D, 5, 5, 5);
    makeZero(D);
    if (!equals(A, D))
        printf("3\n");
    return 0;

    // Matrix A = newMatrix(10); 
    // Matrix C = newMatrix(10); 
    // Matrix D = newMatrix(10); 
    // changeEntry(A, 1, 1, 4);
    // changeEntry(A, 1, 2, 2);
    // changeEntry(A, 1, 3, 0);
    // changeEntry(A, 2, 1, 2);
    // changeEntry(A, 3, 1, 0);
    // changeEntry(A, 2, 2, 2);
    // changeEntry(A, 3, 3, 0);
    // C = scalarMult(-20, A);
    // if (NNZ(C) != 4)
    //     return 1;
    // makeZero(A);
    // D = scalarMult(-20, A);
    // if (NNZ(D) != 0)
    //     return 2;
    // return 0;
    // Matrix M = newMatrix(3);
    // Matrix O = newMatrix(3);
    
    // changeEntry(M, 1, 1, 1.0);
    // changeEntry(M, 1, 2, 2.0);
    // changeEntry(M, 1, 3, 3.0);
    // changeEntry(M, 2, 1, 4.0);
    // changeEntry(M, 2, 2, 5.0);
    // changeEntry(M, 2, 3, 6.0);
    // changeEntry(M, 3, 1, 7.0);
    // changeEntry(M, 3, 2, 8.0);
    // changeEntry(M, 3, 3, 9.0);
    // changeEntry(O, 1, 1, 1.0);
    // changeEntry(O, 1, 2, 2.0);
    // changeEntry(O, 1, 3, 3.0);
    // changeEntry(O, 2, 1, 4.0);
    // changeEntry(O, 2, 2, 6.0);
    // changeEntry(O, 2, 3, 6.0);
    // changeEntry(O, 3, 1, 7.0);
    // changeEntry(O, 3, 2, 8.0);
    // changeEntry(O, 3, 3, 9.0);
    // Matrix N = product(O, M);
    // equals(M, O);
    // for (int i = 1; i <= N->size; i++) {
    //     if (N->row[i]->front != NULL) {
    //     moveFront(N->row[i]);
    //         while (index(N->row[i]) >= 0) {
    //             printf("The row and column: (%d, %d)\n", i, ((Entry)N->row[i]->cursor->data)->column);
    //             printf("The value: %f\n", ((Entry)N->row[i]->cursor->data)->num);
    //             moveNext(N->row[i]);
    //         }
    //     }
    // }
    // printMatrix(stdout, M);
    // printf("The number of all non-zero elements: %d\n", NNZ(N));
    // Entry new = (Entry)malloc(sizeof(EntryObj));
    // new->column = 3;
    // new->num = 3.0;
    // Node tmp = M->row[1]->front;
    // if (tmp == NULL) {
    //     append(M->row[1], new);
    // } else {
    //     if (3 < ((Entry)(M->row[1]->front->data))->column) {
    //         prepend(M->row[1], new);
    //     } else {
    //         moveFront(M->row[1]);
    //         while (index(M->row[1]) >= 0) {
    //             printf("%d\n", (((Entry)(M->row[1]->cursor->data))->column));
    //             moveNext(M->row[1]);
    //         }
    //     }
    // }

    // printf("%f\n", (((Entry)(M->row[1]->front->data))->num));
    // printf("%f\n", (((Entry)(M->row[1]->front->next->data))->num));
    // printf("%f\n", (((Entry)(M->row[1]->front->next->next->data))->num));

    // if (M->row[1]->front != NULL) {
    //     printf("%f\n", ((Entry)(M->row[1]->front->next->data))->num);
    // }
}
