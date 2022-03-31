#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "List.h"

typedef struct NodeObj* Node;

typedef struct NodeObj{
    int data;
    Node next;
    Node prev;
} NodeObj;

typedef struct ListObj{
    Node front;
    Node cursor;
    Node back;
    int index;
    int length;
} ListObj;

// Constructors-Destructors ---------------------------------------------------

List newList(void) {
    List l = (List)malloc(5 * sizeof(ListObj));
    l->back = l->front = l->cursor = NULL;                  //Checked
    l->length = 0;
    l->index = -1;
    return l;
}

void freeList(List* pL) {
    if(pL != NULL && *pL != NULL) { 
        while((*pL)->length != 0) {                         //Checked
            deleteFront(*pL); 
        }
        free(*pL);
        *pL = NULL;
    }
}

// Access functions -----------------------------------------------------------

int length(List L) {
    return L->length;
}

int index(List L) {
    if (L->cursor == NULL) {
        return -1;
    } else {
        return L->index;
    }
}

int front(List L) {
    if (L->length <= 0) {
        printf("List Error: calling front() on NULL List or empty List reference\n");
    } else {
        return L->front->data;
    }
}

int back(List L) {
    if (L->length <= 0) {
        printf("List Error: calling back() on NULL List or empty List reference\n");
    } else {
        return L->back->data;
    }
}

int get(List L) {
    if ((L->length > 0) && (L->index >= 0)) {
        return (L->cursor->data);
    } else {
        printf("List Error: calling front() on NULL List or with invalid index\n");
    }
}

bool equals(List A, List B) {
    return A == B;
}

// Manipulation procedures ----------------------------------------------------

void clear(List L) {
    while (L->front != L->back) {
        L->front->next = L->front;
        free(L->front);
    }
    free(L->front);

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
    }
}

void moveBack(List L) {
    if (L->length != 0) {
        L->cursor = L->back;
    }
}

void movePrev(List L) {
    if (L->cursor != NULL) {
        if (L->cursor != L->front) {
            L->cursor = L->cursor->prev;
        }
    }
}

void moveNext(List L) {
    if (L->cursor != NULL) {
        if (L->cursor != L->back) {
            L->cursor = L->cursor->next;
        }
    }
}

void prepend(List L, int x) {
    Node N = malloc(sizeof(NodeObj));
    N->data = x;
    N->next = NULL;
    N->prev = NULL;

    if(L == NULL){
        printf("List Error: calling prepend() on NULL List reference\n");
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
        printf("List Error: calling append() on NULL List reference\n");
        exit(EXIT_FAILURE);
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
        printf("List Error: calling insertBefore() with List with invalid length or index\n");
    } else {
        Node N = malloc(sizeof(NodeObj));
        N->data = x;
        N->next = NULL;
        N->prev = NULL;

        L->cursor->prev->next = N;
        N->prev = L->cursor->prev;

        L->cursor->prev = N;
        N->next = L->cursor;
    }
}

void insertAfter(List L, int x) {
    if ((L->length <= 0) || (L->index < 0)) {
        printf("List Error: calling insertBefore() with List with invalid length or index\n");
    } else {
        Node N = malloc(sizeof(NodeObj));
        N->data = x;
        N->next = NULL;
        N->prev = NULL;

        L->cursor->next->prev = N;
        N->next = L->cursor->next;

        L->cursor->next = N;
        N->prev = L->cursor;
    }
}

void deleteFront(List L) {
    if (L->length <= 0) {
        printf("List Error: calling deleteFront() with List with invalid length or index\n");
        return;
    }

    Node tmp = L->front;                                        //Checked
    L->front = tmp->next;
    tmp->next->prev = NULL;
    free(tmp);
}

void deleteBack(List L) {
    if (L->length <= 0) {
        printf("List Error: calling deleteFront() with List with invalid length or index\n");
        return;
    }

    Node tmp = L->back;                                         //Checked
    L->back = tmp->prev;
    tmp->prev->next = NULL;
    free(tmp);
}

void delete(List L) {
    Node tmp = L->cursor;
    tmp->next->prev = tmp->prev;
    tmp->prev->next = tmp->next;

    free(tmp);
}

// Other operations -----------------------------------------------------------

void printList(FILE* out, List L) {
    Node head = L->front;

    while (head->next != NULL) {
        printf("%d", head->data);
        head = head->next;
        printf(" -> ");
        if (head -> next == NULL) {
            printf("%d", head->data);
        }
    }
    printf("\n");
}

int main() {
    FILE *out = NULL;
    out = fopen("output.txt", "w");

    List head = newList();
    append(head, 5);
    append(head, 6);
    append(head, 7);
    append(head, 8);
    append(head, 9);
    append(head, 10);
    prepend(head, 4);
    deleteFront(head);
    deleteBack(head);
    printList(out, head);

    fclose(out);
}
