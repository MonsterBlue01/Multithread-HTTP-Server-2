typedef struct {
    int numVertices;
    int numEdges;
    int** adjacencyMatrix;
} Graph;

typedef struct LLNode {
    int value;
    struct LLNode* next;
    struct LLNode* prev;
} LLNode;
