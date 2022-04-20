#include "List.h"
#include "Matrix.h"

int main() {
    Matrix M = (Matrix)malloc(sizeof(MatrixObj));
    // input = 3;
    M->size = 3;
    M->row = (List *)malloc(3 * sizeof(List));
    for (int i = 0; i < 3; i++) {
        M->row[i] = newList();
    }
    if (M->row[0]->front == NULL) {
        printf("It's NULL\n");
    }
}
