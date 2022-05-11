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

void Dictionary::preOrderString(std::string& s, Node* R) const {
    if (R != nil) {
        s += R->key;
        preOrderString(s, R->left);
        preOrderString(s, R->right);
    }
}

Dictionary::Node* Dictionary::search(Node* R, keyType k) const{
    if (R == nil or R->key == k) {
        return R;
    } else if (k < R->key) {
        return search(R->left, k);
    } else {
        return search(R->right, k);
    }
}

int Dictionary::size() const{
    return num_pairs;
}

void Dictionary::setValue(keyType k, valType v) {
    root = new Node ("Donkey", 1);
    root->left = new Node("Bee", 2);
    root->right = new Node("Font", 3);
    root->right->right = new Node("Glad", 7);
    root->right->left = new Node("Elon", 6);
    root->left->right = new Node("Cat", 5);
    root->left->left = new Node("Apple", 4);            //Don't forget parent in this part
    root->left->left->left = nil;
    root->left->left->right = nil;
    root->left->right->left = nil;
    root->left->right->right = nil;
    root->right->left->left = nil;
    root->right->left->right = nil;
    root->right->right->left = nil;
    root->right->right->right = nil;
}

std::string Dictionary::to_string() const{
    std::string s;
    inOrderString(s, root);
    return s;
}

std::string Dictionary::pre_string() const{
    std::string s;
    preOrderString(s, root);
    return s;
}