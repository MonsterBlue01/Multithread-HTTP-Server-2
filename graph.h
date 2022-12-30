typedef struct Node {
    int* dest;
    struct Node *next;
    int data;
} Node;

Node* createNode(int num);