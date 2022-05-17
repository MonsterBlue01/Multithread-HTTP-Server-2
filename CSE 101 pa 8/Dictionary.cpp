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

Dictionary::Node* Dictionary::findMin(Node* R) {
    while (R->left != nil){
        R = R->left;
    }
    return R;
}

Dictionary::Node* Dictionary::findMax(Node* R) {
    while (R->right != nil){
        R = R->right;
    }
    return R;
}

Dictionary::Node* Dictionary::findNext(Node* N) {
    if (N->right != nil) {
        return findMin(N->right);
    }
    Node* y = N->parent;
    while ((y != nil) && (N == y->right)) {
        N = y;
        y = y->parent;
    }
    return y;
}

Dictionary::Node* Dictionary::findPrev(Node* N) {
    if (N->left != nil) {
        return findMax(N->left);
    }
    Node* y = N->parent;
    while ((y != nil) && (N == y->left)) {
        N = y;
        y = y->parent;
    }
    return y;
}

int Dictionary::size() const{
    return num_pairs;
}

bool Dictionary::contains(keyType k) const{
    if (search(root, k) == nil) {
        return false;
    } else {
        return true;
    }
}

valType& Dictionary::getValue(keyType k) const {
    Node* tmp = search(root, k);
    return tmp->val;
}

bool Dictionary::hasCurrent() const {
    if (current == nil) {
        return false;
    } else {
        return true;
    }
}

keyType Dictionary::currentKey() const {
    if (hasCurrent() == false){
        throw std::logic_error("Dictionary: currentKey(): current undefined");
    }
    return current->key;
}

valType& Dictionary::currentVal() const {
    if (hasCurrent() == false){
        throw std::logic_error("Dictionary: currentVal(): current undefined");
    }
    return current->val;
}

void Dictionary::clear() {
    postOrderDelete(root);
    root = nil;
    current = nil;
    num_pairs = 0;
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

void Dictionary::preOrderCopy(Node* R, Dictionary &T) {
    if (R->key != "123AbC"){
        T.setValue(R->key, R->val);
        preOrderCopy(R->left, T);
        preOrderCopy(R->right, T);
    }
}

void Dictionary::postOrderDelete(Node* R) {
    if (R != nil) {
        postOrderDelete(R->left);
        postOrderDelete(R->right);
        delete R;
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

void Dictionary::RB_Transplant(Node* u, Node* v) {
    // T, u, v
    if (u->parent == nil) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

void Dictionary::RB_DeleteFixUp(Node* N) {
    // T, x
    while ((N != root) && (N->color == black)) {
        if (N == N->parent->left) {
            Node* w = N->parent->right;
            if (w->color == red) {
                w->color = black;                        // case 1
                N->parent->color = red;                   // case 1
                LeftRotate(N->parent);                // case 1
                w = N->parent->right;                     // case 1
            }
            if ((w->left->color == black) && (w->right->color == black)) {
                w->color = red;                          // case 2
                N = N->parent;                           // case 2
            } else {
                if (w->right->color == black) {
                    w->left->color = black;                // case 3
                    w->color = red;                       // case 3
                    RightRotate(w);                   // case 3
                    w = N->parent->right;                  // case 3
                }
                w->color = N->parent->color;               // case 4
                N->parent->color = black;                 // case 4
                w->right->color = black;                  // case 4
                LeftRotate(N->parent);                // case 4
                N = root;                             // case 4
            }
        } else {
            Node* w = N->parent->left;
            if (w->color == red) {
                w->color = black;                        // case 5
                N->parent->color = red;                   // case 5
                RightRotate(N->parent);               // case 5
                w = N->parent->left;                      // case 5
            }
            if ((w->right->color == black) && (w->left->color == black)) {
                w->color = red;                          // case 6
                N = N->parent;                           // case 6
            } else {
                if (w->left->color == black)
                    w->right->color = black;               // case 7
                    w->color = red;                       // case 7
                    LeftRotate(w);                    // case 7
                    w = N->parent->left;                   // case 7
                w->color = N->parent->color;               // case 8
                N->parent->color = black;                 // case 8
                w->left->color = black;                   // case 8
                RightRotate(N->parent);               // case 8
                N = root;                             // case 8
            }
        }
   }
   N->color = black;
}

void Dictionary::RB_Delete(Node* N) {
    Node* y = N;
    Node* x;
    int y_original_color = y->color;
    if (N->left == nil) {
        Node* x = N->right;
        RB_Transplant(N, N->right);
    } else if (N->right == nil) {
        Node* x = N->left;
        RB_Transplant(N, N->left);
    } else {
        y = findMin(N->right);
        y_original_color = y->color;
        Node* x = y->right;
        if (y->parent == N) {
            x->parent = y;
        } else {
            RB_Transplant(y, y->right);
            y->right = N->right;
            y->right->parent = y;
        }
        RB_Transplant(N, y);
        y->left = N->left;
        y->left->parent = y;
        y->color = N->color;
    }
    if (y_original_color == black) {
        RB_DeleteFixUp(x);
    }
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

void Dictionary::remove(keyType k) {
    Node* tmp = search(root, k);
    if (tmp != nil) {
        RB_Delete(tmp);
    }
}

std::string Dictionary::to_string() const{
    std::string s;
    inOrderString(s, root);
    return s;
}