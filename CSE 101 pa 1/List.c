#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "List.h"

// Constructors-Destructors ---------------------------------------------------

List newList(void) {
    List l = (List)malloc(5 * sizeof(ListObj));
    l->back = l->front = l->cursor = NULL;
    l->length = 0;
    l->index = -1;
    return l;
}

void freeList(List* pL) {
    if(pL!=NULL && *pL!=NULL) { 
        while((*pL)->length > 0) { 
            deleteFront(*pL); 
        }
        free(*pL);
        *pL = NULL;
    }
}

// Access functions -----------------------------------------------------------

int length(List L) {
    return L->length;                                       //Checked
}

int index(List L) {
    if (L->cursor == NULL) {
        return -1;
    } else {
        if ((0 <= L->index) && (L->index < L->length)) {
            return L->index;
        } else {
            return -1;
        }
    }
}

int front(List L) {
    if (L->length <= 0) {
        fprintf(stderr, "List Error: calling front() on NULL List or empty List reference\n");
        exit(1);
    } else {
        return L->front->data;
    }
}

int back(List L) {
    if (L->length <= 0) {
        fprintf(stderr, "List Error: calling back() on NULL List or empty List reference\n");
        exit(1);
    } else {
        return L->back->data;
    }
}

int get(List L) {
    if ((L->length > 0) && (L->index >= 0)) {
        return (L->cursor->data);
    } else {
        fprintf(stderr, "List Error: calling front() on NULL List or with invalid index\n");
        exit(1);
    }
}

bool equals(List A, List B) {
    if (A->length != B->length) {
        return false;
    }

    Node fA = A->front;
    Node fB = B->front;

    while ((fA != A->back) && (fB != B->back)) {
        if (fA->data != fB->data) {
            return false;
        }
        fA = fA->next;
        fB = fB->next;
    }

    return true;
}

// Manipulation procedures ----------------------------------------------------

void clear(List L) {
    L->back = L->cursor = L->front = NULL;
    L->length = 0;
    L->index = -1;
}

void set(List L, int x) {
    L->cursor->data = x;
}

void moveFront(List L) {
    if (L->length != 0) {
        L->cursor = L->front;
        L->index = 0;
    }
}

void moveBack(List L) {
    if (L->length != 0) {
        L->cursor = L->back;
        L->index = L->length - 1;
    }
}

void movePrev(List L) {
    if (L->index == 0) {
        L->index--;
    }

    if (L->cursor != NULL) {
        if ((L->cursor->data != L->front->data) && (L->cursor->prev != NULL)) {
            L->cursor = L->cursor->prev;
            L->index--;
        } else {
            L->index--;
        }
    }
}

void moveNext(List L) {
    if (L->index == L->length - 1) {
        L->index++;
    }

    if (L->cursor != NULL) {
        if ((L->cursor->data != L->back->data) && (L->cursor->next != NULL)) {
            L->cursor = L->cursor->next;
            L->index++;
        } else {
            L->index++;
        }
    }
}

void prepend(List L, int x) {
    Node N = malloc(sizeof(NodeObj));
    N->data = x;
    N->next = NULL;
    N->prev = NULL;

    if(L == NULL){
        fprintf(stderr, "List Error: calling prepend() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    
    if(L->length == 0) { 
        L->front = L->back = N; 
    } else { 
        L->front->prev = N;
        L->front->prev->next = L->front;
        L->front = N;
    }

    if (L->cursor != NULL) {
        L->index++;
    }

    L->length++;
}

void append(List L, int x) {
    Node N = malloc(sizeof(NodeObj));
    N->data = x;
    N->next = NULL;
    N->prev = NULL;

    if(L == NULL){
        fprintf(stderr, "List Error: calling append() on NULL List reference\n");
        exit(1);
    }

    if(L->length == 0) { 
        L->front = L->back = N; 
    } else { 
        L->back->next = N;
        L->back->next->prev = L->back;
        L->back = N; 
    }
    
    L->length++;
}

void insertBefore(List L, int x) {
    if ((L->length <= 0) || (L->index < 0)) {
        fprintf(stderr, "List Error: calling insertBefore() with List with invalid length or index\n");
    } else {
        if (L->cursor == L->front) {
            prepend(L, x);
        } else {
            Node N = malloc(sizeof(NodeObj));
            N->data = x;
            N->next = NULL;
            N->prev = NULL;

            if (L->cursor != L->front) {
                L->cursor->prev->next = N;
                N->prev = L->cursor->prev;

                L->cursor->prev = N;
                N->next = L->cursor;
            } else {
                L->cursor->prev = N;
                N->next = L->cursor;
                L->front = N;
            }
            L->length++;
            L->index++;
        }
    }
}

void insertAfter(List L, int x) {
    if ((L->length <= 0) || (L->index < 0)) {
        fprintf(stderr, "List Error: calling insertAfter() with List with invalid length or index\n");
    } else {
        if (L->cursor == L->back) {
            append(L, x);
        } else {
            Node N = malloc(sizeof(NodeObj));
            N->data = x;
            N->next = NULL;
            N->prev = NULL;

            L->cursor->next->prev = N;
            N->next = L->cursor->next;
            L->cursor->next = N;
            N->prev = L->cursor;

            L->length++;
        }
    }
}

void deleteFront(List L) {
    if (L->length <= 0) {
        fprintf(stderr, "List Error: calling deleteFront() with List with invalid length or index\n");
        exit(1);
    }

    if (L == NULL) {
        return;
    }

    if (L->front == NULL) {
        return;
    }

    Node tmp = L->front;
    L->front = L->front->next;
    free(tmp);

    L->length--;
    if (L->index >= 0) {
        L->index--;
    }
}

void deleteBack(List L) {
    if (L->length <= 0) {
        fprintf(stderr, "List Error: calling deleteBack() with List with invalid length or index\n");
        exit(1);
    }

    if (L == NULL) {
        return;
    }

    if (L->back == NULL) {
        return;
    }

    Node tmp = L->back;
    L->back = L->back->prev;
    free(tmp);

    L->length--;
}

void delete(List L) {
    if (L->length == 1) {
        free(L->cursor);
        L->length--;
    } else if (L->cursor == L->front) {
        deleteFront(L);
    } else if (L->cursor == L->back) {
        deleteBack(L);
    } else {
        Node tmp = L->cursor;
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;

        free(tmp);
        L->length--;
    }
}

// Other operations -----------------------------------------------------------

void printList(FILE* out, List L) {
    Node head = L->front;

    do {
        if (head->next != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        if (head -> next == NULL) {
            printf("%d", head->data);
        }
    } while (head->next != NULL);
}

List copyList(List L) {
    if (L == NULL) {
        fprintf(stderr, "List Error: calling copyList() with nothing\n");
        exit(1);
    }

    if (!(L->length >= 0)) {
        fprintf(stderr, "List Error: calling copyList() with invlid List length\n");
        exit(1);
    }

    if (L->length == 0) {
        List new = newList();
        return new;
    }

    if (L->length == 1) {
        List new = newList();
        append(new, L->front->data);
        if (L->cursor != NULL) {
            moveFront(new);
        }
        return new;
    }
    List new = newList();
    Node tmp = L->front;

    while (tmp != NULL) {
        append(new, tmp->data);
        tmp = tmp->next;
    }

    if (L->cursor != NULL) {
        moveFront(new);
        while (new->index < L->index) {
            moveNext(new);
        }
    }

    return new;
}
