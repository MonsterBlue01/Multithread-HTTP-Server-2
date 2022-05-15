#include "Dictionary.h"

Dictionary::Node::Node(keyType k, valType v){
    key = k;
    val = v;
    color = 0;
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
    nil = new Node("wRONg", INT32_MAX);
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

void Dictionary::setValue(keyType k, valType v) {
    // T, z
    Node* z = new Node(k, v);
    Node* y = nil;
    Node* x = root;
    while (x != nil) {
        y = x;
        if (z->key< x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == nil) {
        root = z ;
    } else if (z->key < y->key){
        y->left = z;
    } else { 
        y->right = z;
    }
}