#include "Dictionary.h"

typedef std::string keyType;
typedef int valType;

Dictionary::Node::Node(keyType k, valType v){
    this->key = k;
    this->left = nullptr;
    this->right = nullptr;
    this->val = v;
}

Dictionary::Dictionary(){
    this->nil = new Node("dnE", INT32_MAX);
    this->root = nullptr;
    this->current = nullptr;
    this->num_pairs = 0;
}

Dictionary::~Dictionary(){
    this->nil = nullptr;
    this->root = nullptr;
    this->current = nullptr;
    this->num_pairs = 0;
}

void Dictionary::inOrderString(std::string& s, Node* R) const {
    if (R != nil) {
        inOrderString(s, R->left);
        s += R->key;
        inOrderString(s, R->right);
    }
}

int Dictionary::size() const{
    return num_pairs;
}

void Dictionary::setValue(keyType k, valType v) {
    root = new Node("Bee", 1);
    root->left = new Node("Apple", 2);
    root->right = new Node("Cat", 3);
    root->left->left = nil;
    root->left->right = nil;
    root->right->left = nil;
    root->right->right = nil;
}

std::string Dictionary::to_string() const{
    std::string s;
    inOrderString(s, root);
    return s;
}