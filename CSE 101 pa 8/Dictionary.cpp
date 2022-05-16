#include "Dictionary.h"
#define red 1
#define black 0

Dictionary::Node::Node(keyType k, valType v){
    key = k;
    val = v;
    color = black;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

Dictionary::Dictionary(){
    nil = new Node("wRONg", INT32_MAX);
    root = nil;
    num_pairs = 0;
    current = nil;
}

Dictionary::Dictionary(const Dictionary& D) {
    this->nil = new Node("wRONg", INT32_MAX);
    root = nil;
    num_pairs = 0;
    current = nil;
}

Dictionary::~Dictionary() {
    nil = new Node("wRONg", INT32_MAX);
    root = nil;
    num_pairs = 0;
    current = nil;
}

Dictionary::Node* Dictionary::search(Node* R, keyType k) const {
    // R, k
    if (R == nil or k == R->key) {
        return R;
    } else if (k < R->key) {
        return search(R->left, k);
    } else {// k > R.key
        return search(R->right, k);
    }
}

int Dictionary::size() const{
    return num_pairs;
}

void Dictionary::inOrderString(std::string& s, Node* R) const {
    std::string s1 = " : ";
    std::string s2 = "\n";
    if (R != nil) {
        inOrderString(s, R->left);
        if (R->key != "") {
            s = s + R->key + s1 + std::to_string(R->val) + s2;
        }
        inOrderString(s, R->right);
    }
}

void Dictionary::preOrderString(std::string& s, Node* R) const {
    std::string s1 = "\n";
    if (R != nil) {
        s = s + R->key + s1;
        preOrderString(s, R->left);
        preOrderString(s, R->right);
    }
}

void Dictionary::LeftRotate(Node* N) {
    // set y......T, x
    Node* y = N->right; 
    
    // turn y's left subtree into x's right subtree
    N->right = y->left;
    if (y->left != nil) {     // not necessary if using sentinal nil node
        y->left->parent = N;
    }
    
    // link y's parent to x
    y->parent = N->parent;
    if (N->parent == nil) {
        root = y;
    } else if (N == N->parent->left) {
        N->parent->left = y;
    } else {
        N->parent->right = y;
    }
    y->left = N;
    N->parent = y;
}

void Dictionary::RightRotate(Node* N) {
    // set y......T, x
    Node* y = N->left;
    
   // turn y's right subtree into x's left subtree
    N->left = y->right;
    if (y->right != nil) {  // not necessary if using sentinal nil node
        y->right->parent = N;
    }
    
    // link y's parent to x
    y->parent = N->parent;
    if (N->parent == nil) {
        root = y;
    } else if (N == N->parent->right) {
        N->parent->right = y;
    } else {
        N->parent->left = y;
    }
    // put x on y's right
    y->right = N;
    N->parent = y;
}

void Dictionary::RB_InsertFixUp(Node* N) {
    //T, z
    while (N->parent->color == red) {
        if (N->parent == N->parent->parent->left) {
            Node* y = N->parent->parent->right;
            if (N->color == red) {
                N->parent->color = black;               // case 1
                y->color = black;                       // case 1
                N->parent->parent->color = red;         // case 1
                N = N->parent->parent;                  // case 1
            } else {
                if (N == N->parent->right) {
                    N = N->parent;                      // case 2
                    LeftRotate(N);                      // case 2
                }
                N->parent->color = black;               // case 3
                N->parent->parent->color = red;         // case 3
                RightRotate(N->parent->parent);         // case 3
            }
        } else {
            Node* y = N->parent->parent->left;
            if (y->color == red) {
                N->parent->color = black;               // case 4
                y->color = black;                       // case 4
                N->parent->parent->color = red;         // case 4
                N = N->parent->parent;                  // case 4
            } else {
                if (N == N->parent->left) {
                    N = N->parent;                      // case 5
                    RightRotate(N);                     // case 5
                }
                N->parent->color = black;               // case 6
                N->parent->parent->color = red;         // case 6
                LeftRotate(N->parent->parent);          // case 6
            }
        }
    }
    root->color = black;
}

void Dictionary::setValue(keyType k, valType v) {
    if (root != nil) {
        Node *tmp = search(root, k);
        if (tmp != nil) {
            tmp->key = k;
            return;
        }
    }

    Node* z = new Node(k, v);
    Node* y = nil;
    Node* x = root;
    while (x != nil) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == nil) {
        root = z;
    } else if (z->key < y->key){
        y->left = z;
    } else { 
        y->right = z;
    }
    z->left = nil;
    z->right = nil;
    z->color = red;
    RB_InsertFixUp(z);
    num_pairs++;
}

std::string Dictionary::to_string() const{
    std::string s;
    inOrderString(s, root);
    return s;
}