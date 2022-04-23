#include "List.h"
#include "Matrix.h"

int main() {
    Matrix M = newMatrix(3);
    // if (M->row[0]->front == NULL) {
    //     printf("It's NULL\n");
    // }
    
    changeEntry(M, 1, 1, 1.0);
    changeEntry(M, 1, 2, 2.0);
    // changeEntry(M, 1, 3, 3.0);
    changeEntry(M, 2, 1, 4.0);
    // changeEntry(M, 2, 2, 5.0);
    changeEntry(M, 2, 3, 6.0);
    // changeEntry(M, 3, 1, 7.0);
    changeEntry(M, 3, 2, 8.0);
    changeEntry(M, 3, 3, 9.0);
    Matrix N = scalarMult(1.5, M);
    for (int i = 1; i <= N->size; i++) {
        moveFront(N->row[i]);
        while (index(N->row[i]) >= 0) {
            printf("The row and column: (%d, %d)\n", i, ((Entry)N->row[i]->cursor->data)->column);
            printf("The value: %f\n", ((Entry)N->row[i]->cursor->data)->num);
            moveNext(N->row[i]);
        }
    }
    printf("The number of all non-zero elements: %d\n", NNZ(N));
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
