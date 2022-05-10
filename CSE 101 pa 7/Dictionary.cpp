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
    this->nil = nullptr;
    this->root = nullptr;
    this->current = nullptr;
    this->num_pairs = 0;
}

int Dictionary::size() const{
    return num_pairs;
}

void Dictionary::setValue(keyType k, valType v) {
    if (num_pairs == 0) {
        root->key = k;
        root->val = v;
        root->left = nullptr;
        root->right = nullptr;
        root->parent = nullptr;
    }
}